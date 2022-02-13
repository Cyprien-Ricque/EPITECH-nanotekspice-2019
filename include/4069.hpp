/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#ifndef OOP_NANOTEKSPICE_2019_4069_HPP
#define OOP_NANOTEKSPICE_2019_4069_HPP

#include "nts.hpp"

class C4069 : public nts::AComponent {
public:
    explicit C4069(std::string);

    nts::Tristate compute(std::size_t) override;
    void dump() const override;
    std::string getType() const override;
    void reset() override;
    std::vector<std::pair<nts::IComponent *, std::size_t>>getLinks(std::size_t) override;

private:
    nts::Tristate invert(nts::Tristate);
    std::vector<int> _pins{ 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13 };
    std::size_t _in[6] = {1, 3, 5, 9, 11, 13};
    std::size_t _out[6] = {2, 4, 6, 8, 10, 12};
};


#endif //OOP_NANOTEKSPICE_2019_4069_HPP
