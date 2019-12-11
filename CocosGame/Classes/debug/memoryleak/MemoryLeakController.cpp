#ifndef __MEMORYLEAKCONTROLLER_CPP__
#define __MEMORYLEAKCONTROLLER_CPP__

#include "MemoryLeakController.h"

MemoryLeakController memoryLeakController;

MemoryLeakController::MemoryLeakController()
{

}

void MemoryLeakController::addAllocation(Pointer pointer, int size, string file, int line)
{
	mMemoryLeaks.insert(pair<Pointer, MemoryLeak>(pointer, MemoryLeak(file, line, size)));
}

void MemoryLeakController::removeAllocation(Pointer pointer)
{
	mMemoryLeaks.erase(pointer);
}

string MemoryLeakController::toString()
{
	string output = "\n\n";
	output += "The following Memory Leaks were found:\n";
	unsigned int counter = 0;

	for (map<Pointer, MemoryLeak>::iterator element = mMemoryLeaks.begin(); element != mMemoryLeaks.end(); ++element)
	{
		output += element->second.mFile + "(" + to_string(element->second.mLine) + "): ";
		output += "Direction: '"              + to_string(int(element->first))   + "', ";
		output += "Size: '"                   + to_string(element->second.mSize) + "'.\n",

		++counter;
	}

	if (counter == 0) output += "None.\n";

	output += "\n\n";
	return output;
}

#endif