/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#ifndef OOP_NANOTEKSPICE_2019_4040_HPP
#define OOP_NANOTEKSPICE_2019_4040_HPP

#include "nts.hpp"

class C4040 : public nts::AComponent {
public:
    explicit C4040(std::string);

    nts::Tristate compute(std::size_t) override;
    void dump() const override;
    std::string getType() const override;
    void reset() override;

private:
    std::vector<int> _pins{ 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13 };
};

#endif //OOP_NANOTEKSPICE_2019_4040_HPP
