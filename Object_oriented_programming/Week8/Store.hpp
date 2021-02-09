#pragma once

#include "Department.hpp"

class Store
{
public:
    Store(const std::string &foodPath, const std::string &techPath);

    Department food;
    Department tech;
};