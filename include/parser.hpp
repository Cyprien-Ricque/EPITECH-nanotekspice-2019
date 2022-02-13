/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#ifndef OOP_NANOTEKSPICE_2019_PARSER_HPP
#define OOP_NANOTEKSPICE_2019_PARSER_HPP

#include "component_factory.hpp"

class Parser {
    public:
        enum parse_st {
            WAITING,
            CHIPSETS,
            LINKS
        };

        Parser(std::string &filename);
        void parse();
        void setupInput(char **av);
        void setInput(std::string val);
        void check_short();
        void check_spe_short(nts::IComponent *o, std::vector<std::pair<nts::IComponent *, size_t>> l, size_t pin);

    protected:
        void parseLinks(std::string l);
        void parseChipsets(std::string l);
        void getChipsets();
        int findChipset(std::string value);

        std::ifstream _file;
        std::vector<nts::ptrComponent> _chipsets;

    private:
        bool already_in(std::vector<std::pair<nts::IComponent *, size_t>> l);

};

#endif //OOP_NANOTEKSPICE_2019_PARSER_HPP
