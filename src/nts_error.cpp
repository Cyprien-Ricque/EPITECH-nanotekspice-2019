/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2019
** File description:
** OOP_nanotekspice_2019,
*/

#include "nts_error.hpp"

ntsError::ntsError(std::string message, std::string section,
    std::string component
) : _message(message), _section(section), _component(component)
{
}

void ntsError::print() const noexcept
{
    if (getSection() == std::string("Unknown"))
        std::cerr << getComponent() << ": " << what() << std::endl;
    else
        std::cerr << getComponent() << " -> " << getSection() << ": " << what() << std::endl;
}

std::string const ntsError::getComponent() const
{
    return _component;
}

std::string const ntsError::getSection() const
{
    return _section;
}

const char *ntsError::what() const noexcept
{
    return _message.data();
}

ParserError_nm::ParserError::ParserError(std::string const &message,
    const std::string &section
) : ntsError(message, section, "Parser")
{
}

ParserError_nm::InvalidChipset::InvalidChipset(
    std::string const &message
) : ParserError_nm::ParserError(message, "Chipset")
{
}

ParserError_nm::InvalidLink::InvalidLink(
    std::string const &message
) : ParserError_nm::ParserError(message, "Links")
{
}

ExecError_nm::ExecError::ExecError(std::string const &message,
    const std::string &section
) : ntsError(message, section, "Execution")
{
}
