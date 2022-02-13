/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#ifndef OOP_NANOTEKSPICE_2019_OUTPUT_HPP
#define OOP_NANOTEKSPICE_2019_OUTPUT_HPP

#include "nts.hpp"

class Output : public nts::AComponent {
    public:
        explicit Output(std::string);

        nts::Tristate compute(std::size_t) override;
        void dump() const override;
        std::string getType() const override;
        void reset() override;
        std::vector<std::pair<nts::IComponent *, std::size_t>>getLinks(std::size_t) override;
private:
        std::vector<int> _pins{ 1 };
};

#endif //OOP_NANOTEKSPICE_2019_OUTPUT_HPP
