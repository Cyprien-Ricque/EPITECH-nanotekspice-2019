/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#ifndef OOP_NANOTEKSPICE_2019_4017_HPP
#define OOP_NANOTEKSPICE_2019_4017_HPP

#include "nts.hpp"

class C4017 : public nts::AComponent {
public:
    explicit C4017(std::string);

    nts::Tristate compute(std::size_t) override;
    void dump() const override;
    std::string getType() const override;
    void reset() override;
    std::vector<std::pair<nts::IComponent *, std::size_t>>getLinks(std::size_t) override;

private:
    //fonctions
    nts::Tristate setupPinsSt(std::size_t);
    void updateCounter();
    //variables
    std::vector<std::size_t> _pins{1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15};
    std::size_t _in[3] = {13, 14, 15};
    std::size_t _out[12] = {3, 2, 4, 7, 10, 1, 5, 6, 9, 11, 12};
    std::vector<nts::Tristate> _statusPinsOut;
    nts::Tristate previousClock[2]{}; //0 : CP1 | 1 : CP0
    bool initialised;
};

#endif //OOP_NANOTEKSPICE_2019_4017_HPP
