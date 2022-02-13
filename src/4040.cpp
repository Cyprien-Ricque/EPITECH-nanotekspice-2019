/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#include "4040.hpp"

C4040::C4040(std::string value) : AComponent(std::move(value))
{
    for (auto i : _pins) {
        _pinsSt[i] = nts::UNDEFINED;
        _pinsLk[i] = std::make_pair(nullptr, -1);
    }
}

nts::Tristate C4040::compute(std::size_t pin __attribute__((unused)))
{
    return (nts::UNDEFINED);
}

void C4040::dump() const
{
    std::cout << "Dump 4040" << std::endl;
}

std::string C4040::getType() const
{
    return ("4040");
}

void C4040::reset()
{
    for (auto p : _pins)
        _pinsSt.at(p) = nts::UNDEFINED;
}