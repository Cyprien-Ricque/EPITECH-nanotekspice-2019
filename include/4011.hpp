/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#ifndef OOP_NANOTEKSPICE_2019_4011_HPP
#define OOP_NANOTEKSPICE_2019_4011_HPP

#include "nts.hpp"

class C4011 : public nts::AComponent {
public:
    explicit C4011(std::string);

    nts::Tristate compute(std::size_t) override;
    void dump() const override;
    std::string getType() const override;
    void reset() override;
    std::vector<std::pair<nts::IComponent *, std::size_t>>getLinks(std::size_t) override;

private:
    std::vector<int> _pins { 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13 };
    std::size_t _in[4][2] = {{1, 2}, {5, 6}, {8, 9}, {12, 13}};
    std::size_t _out[4] = {3, 4, 10, 11};
};

#endif //OOP_NANOTEKSPICE_2019_4011_HPP
