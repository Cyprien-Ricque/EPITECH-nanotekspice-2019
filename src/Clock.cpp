/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#include "Clock.hpp"

Clock::Clock(std::string unnamed) : AComponent(std::move(unnamed))
{
    _pinsSt[1] = nts::UNDEFINED;
    _pinsLk[1] = std::make_pair(nullptr, -1);
}

void Clock::changeState()
{
    if (_pinsSt.at(1) == nts::TRUE)
        setState(1, nts::FALSE);
    else
        setState(1, nts::TRUE);
}

nts::Tristate Clock::compute(std::size_t pin)
{
    return (_pinsSt[pin]);
}

void Clock::dump() const
{
    std::cout << "dump Clock" << std::endl;
}

std::string Clock::getType() const
{
    return (std::string("clock"));
}

