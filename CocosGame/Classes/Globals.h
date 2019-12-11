#ifndef __GLOBALS_H__
#define __GLOBALS_H__

	#include "CCPlatformMacros.h"
	#include "./debug/memoryleak/MemoryLeakController.h"

	#define ENABLE_ASSERTS 1

	#if ENABLE_ASSERTS == 0
		#define CC_DISABLE_ASSERT 1
	#endif

	#define ENABLE_LEAK_CONTROL 1

	#if ENABLE_LEAK_CONTROL  == 1
		extern MemoryLeakController memoryLeakController;
	
		template<typename T, typename ... Types>
		T* safe_new(string file, int line, Types... parameters)
		{
			T* ptr = new T(parameters...);
			memoryLeakController.addAllocation(ptr, sizeof(T), file, line);
			return ptr;
		}

		template<typename T, typename ... Types>
		T* safe_new_array(int size, string file, int line, Types... parameters)
		{
			T* ptr = new T[size](parameters...);
			memoryLeakController.addAllocation(ptr, sizeof(T) * size, file, line);
			return ptr;
		}

		template<typename T>
		void safe_delete(T*& ptr)
		{
			memoryLeakController.removeAllocation(ptr);
			delete ptr;
			ptr = nullptr;
		}

		template<typename T>
		void safe_delete_array(T*& ptr)
		{
			memoryLeakController.removeAllocation(ptr);
			delete[] ptr;
			ptr = nullptr;
		}

        #define SAFE_NEW(type, ...)             safe_new<type>(__FILE__, __LINE__, ##__VA_ARGS__)
        #define SAFE_NEW_ARRAY(type, size, ...) safe_new_array<type>(size, __FILE__, __LINE__, ##__VA_ARGS__)
		#define SAFE_DELETE(ptr)                safe_delete(ptr)
		#define SAFE_DELETE_ARRAY(ptr)          safe_delete_array(ptr)

	#endif

	#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		#include "../proj.win32/debug/includes/WindowsIncludes.h"

	#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
		#include "../proj.android/debug/includes/AndroidIncludes.h"

	#endif

	#if ENABLE_ASSERTS == 1
		#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		#define POW2_ASSERTS_ENABLED 1
		#include "../proj.win32/debug/asserts/pow2assert.h"
		#define ASSERT     POW2_ASSERT
		#define ASSERT_MSG POW2_ASSERT_MSG

		#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
		#include <assert.h>
		#define ASSERT(condition) assert(condition);

		#endif
	#endif

#endif