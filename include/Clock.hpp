/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#ifndef OOP_NANOTEKSPICE_2019_CLOCK_HPP
#define OOP_NANOTEKSPICE_2019_CLOCK_HPP

#include "nts.hpp"

class Clock : public nts::AComponent {
    public:
        Clock(std::string unnamed);

        void changeState() override;
        nts::Tristate compute(std::size_t pin) override;
        void dump() const override;
        std::string getType() const override;
};

#endif //OOP_NANOTEKSPICE_2019_CLOCK_HPP
