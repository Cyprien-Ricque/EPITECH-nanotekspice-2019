/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#include "false.hpp"

Cfalse::Cfalse(std::string value) : AComponent(std::move(value))
{
    _pinsSt[1] = nts::FALSE;
    _pinsLk[1] = std::make_pair(nullptr, -1);
}

nts::Tristate Cfalse::compute(std::size_t pin)
{
    return _pinsSt[pin];
}

void Cfalse::dump() const
{
    std::cout << "dump false" << std::endl;
}

std::string Cfalse::getType() const
{
    return (std::string("false"));
}
