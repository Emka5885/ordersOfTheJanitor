#pragma once
#include <array>
#include <string>
#include "Room.h"
#include "Values.h"

class State
{
public:
	virtual void Run() = 0;
};