/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#ifndef OOP_NANOTEKSPICE_2019_SIMULATE_HPP
#define OOP_NANOTEKSPICE_2019_SIMULATE_HPP

#include "parser.hpp"

class Simulate : public Parser {
    public:
        Simulate(std::string &filename);

        typedef std::function<void ()> pfnExec;

        void run();
        void exit();
        void display();
        void loop();
        void dump();
        void simul();
        static bool _sigint;

    private:
        void printState(nts::Tristate);
        void endOfSim();
        void setClock();
        static void _todoSig(int sig);
        static void _todoSigEnd(int sig);

        std::map<std::string, pfnExec> _simuMap;
};

#endif //OOP_NANOTEKSPICE_2019_SIMULATE_HPP
