/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#ifndef OOP_NANOTEKSPICE_2019_TRUE_HPP
#define OOP_NANOTEKSPICE_2019_TRUE_HPP

#include "nts.hpp"

class Ctrue : public nts::AComponent {
    public:
        explicit Ctrue(std::string);

        nts::Tristate compute(std::size_t) override;
        void dump() const override;
        std::string getType() const override;
    private:
        std::vector<int> _pins{ 1 };
};

#endif //OOP_NANOTEKSPICE_2019_TRUE_HPP
