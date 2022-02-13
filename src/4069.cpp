/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#include "4069.hpp"

C4069::C4069(std::string value) : AComponent(std::move(value))
{
    for (auto i : _pins) {
        _pinsSt[i] = nts::UNDEFINED;
        _pinsLk[i] = std::make_pair(nullptr, -1);
    }
}

//A l'occasion, bien vérifier le compute
nts::Tristate C4069::compute(std::size_t pin)
{
    int position = 0;

    for (int a = 0; a < 6; ++a)
        if (_out[a] == pin)
            position = a;
    if (_pinsLk.at(_in[position]).first == nullptr)
        _pinsSt[_in[position]] = nts::UNDEFINED;
    else
        _pinsSt[_in[position]] = _pinsLk.at(_in[position]).first->compute(_pinsLk.at(_in[position]).second);
    _pinsSt[_out[position]] = this->invert(_pinsSt[_in[position]]);
    return (_pinsSt[_out[position]]);
}

void C4069::dump() const
{
    std::cout << "Dump 4069" << std::endl;
}

nts::Tristate C4069::invert(nts::Tristate input)
{
    if (input == nts::TRUE)
        return (nts::FALSE);
    else if (input == nts::FALSE)
        return (nts::TRUE);
    else
        return (nts::UNDEFINED);
}

std::string C4069::getType() const
{
    return ("4069");
}

void C4069::reset()
{
    for (auto p : _pins)
        _pinsSt.at(p) = nts::UNDEFINED;
}

std::vector<std::pair<nts::IComponent *, std::size_t>> C4069::getLinks(std::size_t pin)
{
    std::vector<std::pair<IComponent *, std::size_t>> output;
    int position = 0;

    for (int a = 0; a < 6; ++a)
        if (_out[a] == pin)
            position = a;
    std::pair<IComponent *, std::size_t> tmp = std::make_pair(_pinsLk[_in[position]].first, _pinsLk[_in[position]].second);
    output.push_back(tmp);
    tmp = std::make_pair(_pinsLk[_in[position]].first, _pinsLk[_in[position]].second);
    output.push_back(tmp);
    tmp = std::make_pair(nullptr, -1);
    output.push_back(tmp);
    return (output);
}
