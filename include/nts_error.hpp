/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#ifndef OOP_NANOTEKSPICE_2019_NTS_ERROR_HPP
#define OOP_NANOTEKSPICE_2019_NTS_ERROR_HPP

#include <iostream>
#include <memory>
#include <map>
#include <functional>
#include <utility>
#include <vector>
#include <regex>
#include <fstream>
#include <csignal>
#include <unistd.h>

class ntsError : public std::exception {
    public:
        ntsError(std::string message,
            std::string section = "Unknown",
            std::string component = "Unknown");

        std::string const getComponent() const;
        std::string const getSection() const;
        const char* what() const noexcept override;
        void print() const noexcept;

    private:
        std::string _message;
        std::string _section;
        std::string _component;
};

namespace ExecError_nm {
    class ExecError : public ntsError {
        public:
            ExecError(std::string const &message,
                std::string const &section = "Unknown");
    };
}

namespace ParserError_nm {

    class ParserError : public ntsError {
        public:
            ParserError(std::string const &message,
                std::string const &section = "Unknown");
    };

    class InvalidChipset : public ParserError_nm::ParserError {
        public:
        InvalidChipset(std::string const &message);
    };
    class InvalidLink : public ParserError_nm::ParserError {
        public:
        InvalidLink(std::string const &message);
    };
}

#endif //OOP_NANOTEKSPICE_2019_NTS_ERROR_HPP
