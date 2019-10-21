#include "pch.h"
#include "Debugger.h"

Debugger::Debugger(){}

const void Debugger::operator << (const Vector &vector) {
	printf("(%.3f, %.3f, %.3f)", vector.x, vector.y, vector.z);
}	
