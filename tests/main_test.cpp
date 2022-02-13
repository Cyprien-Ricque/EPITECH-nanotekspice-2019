/*
** EPITECH PROJECT, 2020
** nanotekspice
** File description:
** Created by emilien
*/

#include <gtest/gtest.h>
#include "../include/false.hpp"
#include "../include/true.hpp"
#include "../include/Clock.hpp"
#include "../include/Input.hpp"
#include "../include/Output.hpp"
#include "../include/4001.hpp"
#include "../include/4011.hpp"
#include "../include/4017.hpp"
#include "../include/4030.hpp"
#include "../include/4040.hpp"
#include "../include/4069.hpp"
#include "../include/4071.hpp"
#include "../include/4081.hpp"

bool test_chipset(nts::IComponent *classe, const std::string& dump, const std::string& type)
{
    std::string output_stdout;
    bool status_test = true;

    testing::internal::CaptureStdout();
    classe->dump();
    output_stdout = testing::internal::GetCapturedStdout();
    if (dump != output_stdout)
        status_test = false;
    if (type != classe->getType())
        status_test = false;
    return (status_test);
}

TEST (test_chipset, true)
{
    auto chipset = Ctrue("true");

    ASSERT_EQ(true, test_chipset(&chipset, "dump true\n", "true"));
}

TEST (test_chipset, false)
{
    auto chipset = Cfalse("false");

    ASSERT_EQ(true, test_chipset(&chipset, "dump false\n", "false"));
}

TEST (test_chipset, Clock)
{
    auto chipset = Clock("clock");

    ASSERT_EQ(true, test_chipset(&chipset, "dump Clock\n", "clock"));
}

TEST (test_chipset, Output)
{
    auto chipset = Output("output");

    ASSERT_EQ(true, test_chipset(&chipset, "dump output\n", "output"));
}

TEST (test_chipset, Input)
{
    auto chipset = Input("input");

    ASSERT_EQ(true, test_chipset(&chipset, "dump input\n", "input"));
}

TEST (test_chipset, 4081)
{
    auto chipset = C4081("4081");

    ASSERT_EQ(true, test_chipset(&chipset, "Dump 4081\n", "4081"));
}

TEST (test_chipset, 4071)
{
    auto chipset = C4071("4071");

    ASSERT_EQ(true, test_chipset(&chipset, "Dump 4071\n", "4071"));
}

TEST (test_chipset, 4069)
{
    auto chipset = C4069("4069");

    ASSERT_EQ(true, test_chipset(&chipset, "Dump 4069\n", "4069"));
}

TEST (test_chipset, 4040)
{
    auto chipset = C4040("4040");

    ASSERT_EQ(true, test_chipset(&chipset, "Dump 4040\n", "4040"));
}

TEST (test_chipset, 4030)
{
    auto chipset = C4030("4030");

    ASSERT_EQ(true, test_chipset(&chipset, "Dump 4030\n", "4030"));
}

TEST (test_chipset, 4017)
{
    auto chipset = C4017("4017");

    ASSERT_EQ(true, test_chipset(&chipset, "Dump 4017\n", "4017"));
}

TEST (test_chipset, 4011)
{
    auto chipset = C4011("4011");

    ASSERT_EQ(true, test_chipset(&chipset, "Dump 4011\n", "4011"));
}

TEST (test_chipset, 4001)
{
    auto a = C4001("4001");

    ASSERT_EQ(true, test_chipset(&a, "Dump 4001\n", "4001"));
}

int main(int ac, char **av)
{
    ::testing::InitGoogleTest(&ac, av);
    return (RUN_ALL_TESTS());
}