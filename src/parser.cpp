/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#include "parser.hpp"

Parser::Parser(std::string &filename)
{
    _file = std::ifstream(filename);
    if (!_file)
        throw ParserError_nm::ParserError("Invalid filename");
}

void Parser::setInput(std::string val)
{
    std::smatch m;
    int chip;
    nts::Tristate state;

    if (!std::regex_match(val, std::regex("^[^\\s]+=[0-1]$")))
        throw ParserError_nm::InvalidChipset("Invalid input assignement");
    std::regex_search(val, m, std::regex("^([^\\s=]+)="));
    chip = findChipset(m[1]);
    if (chip < 0)
        throw ParserError_nm::InvalidLink(std::string("Chipset \"") + std::string(m[1]) + std::string("\" doesn't exist"));
    if (_chipsets[chip]->getType() != std::string("input") and _chipsets[chip]->getType() != std::string("clock"))
        throw ParserError_nm::InvalidChipset(std::string("Chipset ") + std::string(m[1]) + std::string(" is not an input"));
    std::regex_search(val, m, std::regex("=([0-9]+)$"));
    state = static_cast<nts::Tristate>(std::stoi(m[1]));
    _chipsets[chip]->setState(1, state);
}

void Parser::setupInput(char **av)
{
    std::string tmp;

    for (int i = 2; av[i]; ++i) {
        tmp = std::string(av[i]);
        try {
            setInput(tmp);
        } catch (ParserError_nm::ParserError const &e) {
            e.print();
            throw ntsError("Invalid Argument", "Arguments Parsing", "Parser");
        }
    }
    for (auto &chipset : _chipsets)
        if ((chipset->getType() == std::string("input") or chipset->getType() == std::string("clock")) and chipset->getState(1) == nts::UNDEFINED)
            throw ParserError_nm::ParserError(std::string("\"") +
            chipset->getValue() + std::string("\" input is not set"));
}

int Parser::findChipset(std::string value)
{
    for (size_t i = 0; i < _chipsets.size(); ++i) {
        if (_chipsets[i]->getValue() == value)
            return i;
    }
    return (-1);
}

void Parser::parseLinks(std::string l)
{
    if (!std::regex_match(l, std::regex("^[^\\s:]+:[0-9]+[\\s]+[^\\s:]+:[0-9]+$")))
        throw ParserError_nm::InvalidLink("Invalid line");

    std::smatch m;
    std::vector<int> dt;
    std::vector<int> pins;
    auto tmp = std::string(l);
    int pos;

    while (std::regex_search(tmp, m, std::regex("([^\\s:]+):"))) {
        pos = findChipset(m[1]);
        if (pos < 0)
            throw ParserError_nm::InvalidLink(std::string("Chipset \"") + std::string(m[1]) + std::string("\" doesn't exist"));
        dt.push_back(pos);
        tmp = m.suffix().str();
    }
    tmp = l;
    while (std::regex_search(tmp, m, std::regex(":([0-9]+)"))) {
        pins.push_back(std::stoi(m[1]));
        tmp = m.suffix().str();
    }
    _chipsets.at(dt.at(0))->setLink(pins.at(0), *(_chipsets.at(dt.at(1))), pins.at(1));
    _chipsets.at(dt.at(1))->setLink(pins.at(1), *(_chipsets.at(dt.at(0))), pins.at(0));
}

void Parser::parseChipsets(std::string l)
{
    ComponentFactory cf;
    std::smatch m;
    std::vector<std::string> dt;

    if (!std::regex_match(l, std::regex("^[^\\s]+[\\s]+[^\\s]+$")))
        throw ParserError_nm::InvalidChipset("Invalid definition");

    while (std::regex_search(l, m, std::regex("[^\\s]+"))) {
        dt.push_back(m[0]);
        l = m.suffix().str();
    }
    if (findChipset(dt.at(1)) != -1)
        throw ParserError_nm::InvalidChipset("Double definition of chipset \"" + std::string(dt.at(1)) + "\"");
    _chipsets.push_back(cf.createComponent(dt.at(0), dt.at(1)));
}

void Parser::getChipsets()
{
    std::string l;
    parse_st state = WAITING;

    while (getline(_file, l)) {
        if (std::regex_match(l, std::regex("^\\s*#.*$")) or
            std::regex_match(l, std::regex("^[\\s]*$")))
            continue;
        if (state == WAITING and
            std::regex_match(l, std::regex("^\\s*.chipsets:\\s*$")))
            state = CHIPSETS;
        else if (state == CHIPSETS and
            std::regex_match(l, std::regex("^\\s*.links:\\s*$")))
            state = LINKS;
        else {
            if (state == WAITING)
                throw ParserError_nm::ParserError("First line out of section");
            else if (state == CHIPSETS)
                parseChipsets(l);
            else
                parseLinks(l);
        }
    }
    if (state == WAITING)
        throw ParserError_nm::ParserError("No chipsets section");
    if (state == CHIPSETS)
        throw ParserError_nm::ParserError("No links section");
    for (auto &chipset : _chipsets) {
        if (chipset->getType() == std::string("output") and !chipset->isLinked(1))
            throw ParserError_nm::ParserError(std::string("\"") +
                chipset->getValue() + std::string("\" output is not set"));
    }
}

void Parser::parse()
{
    try {
        getChipsets();
    } catch (ParserError_nm::ParserError const &e) {
        e.print();
        throw ntsError("Parsing error", "File parsing", "Parser");
    }
}

bool Parser::already_in(std::vector<std::pair<nts::IComponent *, size_t>> l)
{
    for (size_t i = 0; i < l.size(); ++i)
        for (size_t j = 0; j < l.size(); ++j)
            if (i != j && l.at(i) == l.at(j))
                return true;
    return false;
}

void Parser::check_spe_short(nts::IComponent *o, std::vector<std::pair<nts::IComponent *, size_t>> l, size_t pin)
{
    if (!o)
        return;
    l.emplace_back(o, pin);
    if (already_in(l))
        throw ntsError("Invalid links, infinite loop", "Links error");
    std::vector<std::pair<nts::IComponent *, size_t>> c(o->getLinks(pin));

    for (auto &e : c)
        check_spe_short(e.first, l, e.second);
}

void Parser::check_short()
{
    std::vector<std::pair<nts::IComponent *, size_t>> l;

    for (auto &e : _chipsets) {
        if (e->getType() == "output")
            check_spe_short(e->getLinks(1).at(0).first, l,
                e->getLinks(1).at(0).second);
        l.clear();

    }
}