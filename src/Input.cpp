/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#include "Input.hpp"

Input::Input(std::string value) : AComponent(std::move(value))
{
    for (auto i : _pins) {
        _pinsSt[i] = nts::UNDEFINED;
        _pinsLk[i] = std::make_pair(nullptr, -1);
    }
}

nts::Tristate Input::compute(std::size_t pin)
{
    return _pinsSt[pin];
}

void Input::dump() const
{
    std::cout << "dump input" << std::endl;
}

std::string Input::getType() const
{
    return (std::string("input"));
}

std::vector<std::pair<nts::IComponent *, std::size_t>> Input::getLinks(std::size_t pin __attribute__((unused)))
{
    std::vector<std::pair<IComponent *, std::size_t>> output;

    std::pair<IComponent *, std::size_t> tmp = std::make_pair(nullptr, -1);
    output.push_back(tmp);
    return (output);
}