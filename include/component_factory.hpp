/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#ifndef OOP_NANOTEKSPICE_2019_COMPONENT_FACTORY_HPP
#define OOP_NANOTEKSPICE_2019_COMPONENT_FACTORY_HPP

#include "Output.hpp"
#include "Input.hpp"
#include "Clock.hpp"
#include "true.hpp"
#include "false.hpp"
#include "4081.hpp"
#include "4071.hpp"
#include "4069.hpp"
#include "4030.hpp"
#include "4017.hpp"
#include "4011.hpp"
#include "4001.hpp"

class ComponentFactory {
    public:
        ComponentFactory();
        typedef std::function<nts::ptrComponent (std::string)> pfnCreate;

        nts::ptrComponent createComponent(const std::string &type, const std::string &value);

    private:
        void Register(const std::string &, pfnCreate);
        std::map<std::string, pfnCreate> _FactoryMap;
};

#endif //OOP_NANOTEKSPICE_2019_COMPONENT_FACTORY_HPP
