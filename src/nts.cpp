/*
** EPITECH PROJECT, 2020
** nts
** File description:
** nts
*/

#include "nts.hpp"

nts::AComponent::AComponent(std::string value) : _value(std::move(value))
{
}

bool nts::AComponent::operator<(const nts::IComponent &other)
{
    return getType() < other.getType();
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other,
    std::size_t otherPin)
{
    _pinsLk[pin] = std::make_pair(&other, otherPin);
}

void nts::AComponent::setState(std::size_t pin, nts::Tristate state)
{
    _pinsSt[pin] = state;
}

std::string nts::AComponent::getValue() const
{
    return _value;
}

std::string nts::AComponent::getType() const
{
    return std::string("Unknown");
}

nts::Tristate nts::AComponent::getState(std::size_t pin) const
{
    return _pinsSt.at(pin);
}

bool nts::AComponent::isLinked(size_t pin) const
{
    return _pinsLk.at(pin).first != nullptr;
}

void nts::AComponent::reset()
{
}

void nts::AComponent::changeState()
{
}

std::vector<std::pair<nts::IComponent *, std::size_t>> nts::AComponent::getLinks(std::size_t)
{
    return std::vector<std::pair<IComponent *, std::size_t>>();
}
