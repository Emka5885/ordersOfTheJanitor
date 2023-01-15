#pragma once
#include "Task.h"
#include <vector>

struct room
{
    std::string name;
    std::vector<task> dailyTasks;
    void implementation(std::string name);
};
