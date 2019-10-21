#pragma once
#include "Vector.h"
#include <iostream>
class Debugger
{
public:
	Debugger();
	const void operator << (const Vector &vector);
};
