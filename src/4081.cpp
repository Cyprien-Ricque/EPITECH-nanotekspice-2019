/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#include "4081.hpp"
#include <utility>

C4081::C4081(std::string value) : AComponent(std::move(value))
{
    for (auto i : _pins) {
        _pinsSt[i] = nts::UNDEFINED;
        _pinsLk[i] = std::make_pair(nullptr, -1);
    }
}

nts::Tristate C4081::compute(std::size_t pin)
{
    int position = 0;

    for (int a = 0; a < 4; ++a)
        if (_out[a] == pin)
            position = a;
    if (_pinsLk.at(_in[position][0]).first != nullptr && _pinsLk.at(_in[position][1]).first != nullptr) {
        _pinsSt[_in[position][0]] = _pinsLk.at(_in[position][0]).first->compute(_pinsLk.at(_in[position][0]).second);
        _pinsSt[_in[position][1]] = _pinsLk.at(_in[position][1]).first->compute(_pinsLk.at(_in[position][1]).second);
    } else {
        _pinsSt[_in[position][0]] = nts::UNDEFINED;
        _pinsSt[_in[position][1]] = nts::UNDEFINED;
    }
    if (_pinsSt[_in[position][0]] == nts::UNDEFINED || _pinsSt[_in[position][1]] == nts::UNDEFINED)
        _pinsSt[_out[position]] = nts::UNDEFINED;
    else if (_pinsSt[_in[position][0]] == nts::TRUE && _pinsSt[_in[position][1]] == nts::TRUE)
        _pinsSt[_out[position]] = nts::TRUE;
    else
        _pinsSt[_out[position]] = nts::FALSE;
    return (_pinsSt[pin]);
}

void C4081::dump() const
{
    std::cout << "Dump 4081" << std::endl;
}

std::string C4081::getType() const
{
    return (std::string("4081"));
}

void C4081::reset()
{
    for (auto p : _pins)
        _pinsSt.at(p) = nts::UNDEFINED;
}

std::vector<std::pair<nts::IComponent *, std::size_t>> C4081::getLinks(std::size_t pin)
{
    std::vector<std::pair<IComponent *, std::size_t>> output;
    int position = 0;

    for (int a = 0; a < 4; ++a)
        if (_out[a] == pin)
            position = a;
    std::pair<IComponent *, std::size_t> tmp = std::make_pair(_pinsLk[_in[position][0]].first, _pinsLk[_in[position][0]].second);
    output.push_back(tmp);
    tmp = std::make_pair(_pinsLk[_in[position][1]].first, _pinsLk[_in[position][1]].second);
    output.push_back(tmp);
    tmp = std::make_pair(nullptr, -1);
    output.push_back(tmp);
    return (output);
}
