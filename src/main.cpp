/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#include "simulate.hpp"

int main(int ac, char **av)
{
    std::string file;

    try {
        if (ac < 2)
            throw ntsError("No file provided");
        file = std::string(av[1]);
        auto p = Simulate(file);
        p.setupInput(av);
        p.check_short();
        p.simul();
        p.run();
    } catch (ntsError const &e) {
        e.print();
        return (84);
    }
    return (0);
}