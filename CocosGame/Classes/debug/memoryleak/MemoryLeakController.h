#ifndef __MEMORYLEAKCONTROLLER_H__
#define __MEMORYLEAKCONTROLLER_H__

#include <map>
#include <string>
#include <iostream>

using namespace std;

typedef const void* Pointer;

struct MemoryLeak
{
	//Name of the file where it was allocated
	string mFile;

	//Code line in which it was allocated
	int mLine;

	//Size in bytes
	int mSize;

	MemoryLeak(string file, int line, int size)
	{
		mFile = file;
		mLine = line;
		mSize = size;
	}
};

class MemoryLeakController
{
private:
	//Key:   Direction of memory where it was allocated
	//Value: Struct containin info about the memory allocation
	map<Pointer, MemoryLeak> mMemoryLeaks;

public:
	MemoryLeakController()/* : m_memoryLeaks() {}*/;

	//Adds a memory allocation to the map
	void addAllocation(Pointer pointer, int size, string file, int line);

	//Removes a memory allocation from the map
	void removeAllocation(Pointer pointer);

	//Print the memory allocation map
	string toString();
};

#endif