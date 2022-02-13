/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#include "4017.hpp"

C4017::C4017(std::string value) : AComponent(std::move(value))
{
    for (auto i : _pins) {
        _pinsSt[i] = nts::UNDEFINED;
        _pinsLk[i] = std::make_pair(nullptr, -1);
    }
    for (auto j __attribute__((unused)): _out)
        _statusPinsOut.push_back(nts::UNDEFINED);
    previousClock[0] = nts::FALSE;
    previousClock[1] = nts::FALSE;
    initialised = false;
}

void C4017::updateCounter()
{
    if (_statusPinsOut[_statusPinsOut.size() - 2] == nts::TRUE) {
        _statusPinsOut[_statusPinsOut.size() - 2] = nts::FALSE;
        _statusPinsOut[0] = nts::TRUE;
        return;
    }
    for (unsigned int a = 0; a < (_statusPinsOut.size() - 1); ++a) {
        if (_statusPinsOut[a] == nts::TRUE) {
            _statusPinsOut[a] = nts::FALSE;
            _statusPinsOut[a + 1] = nts::TRUE;
        }
    }
}

//A l'occasion, bien vérifier le compute
nts::Tristate C4017::compute(std::size_t pin)
{
    std::size_t position = _pins[0];

    for (auto i : _pins)
        if (_pins[i] == pin)
            position = _pins[i];
    for (unsigned long a : _in) {
        if (_pinsLk.at(a).first != nullptr)
            _pinsSt[a] = _pinsLk.at(a).first->compute(_pinsLk.at(a).second);
        else
            _pinsSt[a] = nts::UNDEFINED;
    }
    /* Bloc de gestion du pin reset */
    if (_pinsSt[_in[2]] == nts::TRUE) {
        for (unsigned int a = 0; a < _statusPinsOut.size(); ++a)
            _statusPinsOut[a] = (a == 2 || a == 10 ? nts::TRUE : nts::FALSE);
        initialised = true;
        return (setupPinsSt(position));
    } else if (_pinsSt[_in[2]] == nts::UNDEFINED) {
        for (auto & a : _statusPinsOut)
            a = nts::UNDEFINED;
        initialised = false;
        return (setupPinsSt(position));
    }
    /* Si un pin est pas undefined ou que le chipset est pas init */
    if (_pinsSt[_in[0]] == nts::UNDEFINED || _pinsSt[_in[1]] == nts::UNDEFINED ||
        _pinsSt[_in[2]] == nts::UNDEFINED || !initialised) {
        for (auto &a : _statusPinsOut)
            a = nts::UNDEFINED;
        return (setupPinsSt(position));
    }
    /* Condition d'update de l'output */
    if ((_pinsSt[_in[0]] == nts::TRUE && previousClock[0] == nts::FALSE && _pinsSt[_in[1]] == nts::FALSE) ||
        (_pinsSt[_in[1]] == nts::FALSE && previousClock[1] == nts::TRUE && _pinsSt[_in[0]] == nts::TRUE)) {
        updateCounter();
    }
    //Définition des saves des status
    previousClock[0] = _pinsSt[_in[0]];
    previousClock[1] = _pinsSt[_in[1]];
    return (setupPinsSt(position));
}

nts::Tristate C4017::setupPinsSt(std::size_t position)
{
    for (unsigned int a = 0; a < _statusPinsOut.size(); ++a)
        _pinsSt[a] = _statusPinsOut[a];
    return (_pinsSt[position]);
}

void C4017::dump() const
{
    std::cout << "Dump 4017" << std::endl;
}

std::string C4017::getType() const
{
    return ("4017");
}

void C4017::reset()
{
    for (auto p : _pins)
        _pinsSt.at(p) = nts::UNDEFINED;
}

std::vector<std::pair<nts::IComponent *, std::size_t>> C4017::getLinks(std::size_t pin __attribute__((unused)))
{
    std::vector<std::pair<IComponent *, std::size_t>> output;
    std::pair<IComponent *, std::size_t> tmp;

    for (unsigned long a : _in) {
        tmp = std::make_pair(_pinsLk[a].first, _pinsLk[a].second);
        output.push_back(tmp);
    }
    tmp = std::make_pair(nullptr, -1);
    output.push_back(tmp);
    return (output);
}
