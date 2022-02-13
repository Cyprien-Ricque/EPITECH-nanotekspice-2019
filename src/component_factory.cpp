/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#include "component_factory.hpp"

ComponentFactory::ComponentFactory()
{
    Register("input", [](std::string value)-> nts::ptrComponent {return nts::ptrComponent{new Input(std::move(value))}; });
    Register("clock", [](std::string value)-> nts::ptrComponent {return nts::ptrComponent{new Clock(std::move(value))}; });
    Register("output", [](std::string value)-> nts::ptrComponent {return nts::ptrComponent{new Output(std::move(value))}; });
    Register("true", [](std::string value)-> nts::ptrComponent {return nts::ptrComponent{new Ctrue(std::move(value))}; });
    Register("false", [](std::string value)-> nts::ptrComponent {return nts::ptrComponent{new Cfalse(std::move(value))}; });
    Register("4001", [](std::string value)-> nts::ptrComponent {return nts::ptrComponent{new C4001(std::move(value))}; });
    Register("4011", [](std::string value)-> nts::ptrComponent {return nts::ptrComponent{new C4011(std::move(value))}; });
    Register("4017", [](std::string value)-> nts::ptrComponent {return nts::ptrComponent{new C4017(std::move(value))}; });
    Register("4030", [](std::string value)-> nts::ptrComponent {return nts::ptrComponent{new C4030(std::move(value))}; });
    Register("4069", [](std::string value)-> nts::ptrComponent {return nts::ptrComponent{new C4069(std::move(value))}; });
    Register("4071", [](std::string value)-> nts::ptrComponent {return nts::ptrComponent{new C4071(std::move(value))}; });
    Register("4081", [](std::string value)-> nts::ptrComponent {return nts::ptrComponent{new C4081(std::move(value))}; });
}

nts::ptrComponent ComponentFactory::createComponent(
    const std::string &type, const std::string &value)
{
    if (_FactoryMap.find(type) == _FactoryMap.end())
        throw ParserError_nm::InvalidChipset("Invalid chipset type");
    return _FactoryMap[type](value);
}

void ComponentFactory::Register(const std::string &type,
    ComponentFactory::pfnCreate lbd)
{
    _FactoryMap[type] = std::move(lbd);
}