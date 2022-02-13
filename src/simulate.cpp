/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#include "simulate.hpp"

bool Simulate::_sigint = false;
std::size_t nts::nbSimulate::nb_simulate = 0;

Simulate::Simulate(std::string &filename) : Parser(filename)
{
    parse();

    _simuMap[std::string("display")] = [this]()-> void {display();};
    _simuMap[std::string("exit")] = [this]()-> void {exit();};
    _simuMap[std::string("simulate")] = [this]()-> void {simul();};
    _simuMap[std::string("loop")] = [this]()-> void {loop();};
    _simuMap[std::string("dump")] = [this]()-> void {dump();};
}

void Simulate::run()
{
    std::string line;

    std::cout << "> ";
    std::getline(std::cin, line);

    if(!std::cin) {
        if(std::cin.eof())
            return;
        else
            throw ntsError("Invalid read", "standard input");
    }
    if (_simuMap.find(std::string(line)) != _simuMap.end())
        _simuMap[std::string(line)]();
    else if (std::regex_match(line, std::regex("^[^\\s]+=[0-1]$")))
        setInput(line);
    else if (!line.data())
        return;
    else
        std::cerr << "Invalid command" << std::endl;
    run();
}

void Simulate::exit()
{
    std::exit(0);
}

void Simulate::display()
{
    std::sort(_chipsets.begin(), _chipsets.end());
    std::for_each(_chipsets.begin(), _chipsets.end(),
        [this](nts::ptrComponent &c) {
        if (c->getType() == "output") { std::cout << c->getValue() << "="; printState(c->getState(1));}});
}

void Simulate::loop()
{
    _sigint = false;
    signal(SIGINT, _todoSig);

    while (!_sigint)
        simul();

    signal(SIGINT, _todoSigEnd);
}

void Simulate::dump()
{
    std::for_each(_chipsets.begin(), _chipsets.end(), [this](nts::ptrComponent &c) {c->dump();});
}

void Simulate::simul()
{
    endOfSim();
    std::for_each(_chipsets.begin(), _chipsets.end(), [this](nts::ptrComponent &c)
    {if (c->getType() == "output")
        c->compute(1);});
    display();
    setClock();
    ++nts::nbSimulate::nb_simulate;
}

void Simulate::printState(nts::Tristate st)
{
    if (st == nts::UNDEFINED)
        std::cout << "U" << std::endl;
    else
        std::cout << st << std::endl;
}

void Simulate::endOfSim()
{
    for (auto &e : _chipsets)
        if (e->getType() != "clock" && e->getType() != "input")
            e->reset();
}

void Simulate::setClock()
{
    std::for_each(_chipsets.begin(), _chipsets.end(), [this](nts::ptrComponent &c)
    {if (c->getType() == "clock")
        c->changeState();});
}

void Simulate::_todoSig(int sig)
{
    if (sig == SIGINT)
        _sigint = true;
}

void Simulate::_todoSigEnd(int sig)
{
    if (sig == SIGINT)
        std::exit(0);
}
