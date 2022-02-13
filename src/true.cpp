/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#include "true.hpp"

Ctrue::Ctrue(std::string value) : AComponent(std::move(value))
{
    _pinsSt[1] = nts::TRUE;
    _pinsLk[1] = std::make_pair(nullptr, -1);
}

nts::Tristate Ctrue::compute(std::size_t pin)
{
    return _pinsSt[pin];
}

void Ctrue::dump() const
{
    std::cout << "dump true" << std::endl;
}

std::string Ctrue::getType() const
{
    return (std::string("true"));
}
