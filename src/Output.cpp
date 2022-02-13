/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#include "Output.hpp"

Output::Output(std::string value) : AComponent(std::move(value))
{
    for (auto i : _pins) {
        _pinsSt[i] = nts::UNDEFINED;
        _pinsLk[i] = std::make_pair(nullptr, -1);
    }
}

nts::Tristate Output::compute(std::size_t pin)
{
    _pinsSt[pin] = _pinsLk[pin].first->compute(_pinsLk[pin].second);
    return _pinsSt[pin];
}

void Output::dump() const
{
    std::cout << "dump output" << std::endl;
}

std::string Output::getType() const
{
    return (std::string("output"));
}

void Output::reset()
{
    _pinsSt.at(1) = nts::UNDEFINED;
}

std::vector<std::pair<nts::IComponent *, std::size_t>> Output::getLinks(std::size_t pin)
{
    std::vector<std::pair<IComponent *, std::size_t>> output;

    std::pair<IComponent *, std::size_t> tmp = std::make_pair(_pinsLk[pin].first, _pinsLk[pin].second);
    output.push_back(tmp);
    tmp = std::make_pair(nullptr, -1);
    output.push_back(tmp);
    return (output);
}