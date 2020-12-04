#pragma once
#include <iostream>

template <typename T>
class Singleton
{
public:

	static T* mInstance;

	// Creating the instance of the class
	static void CreateInstance()
	{

		if (mInstance == nullptr)
		{
			mInstance = new T();
		}
	}

	static void DestroyInstance()
	{
		delete mInstance;
		mInstance = nullptr;
	}

	// Method to return the reference of instance of the singleton.
	static T* GetInstance()
	{
		return mInstance;
	}

protected:

	// Contructor of the singleton.
	Singleton() {};

	Singleton(const Singleton& other) = delete;

	Singleton& operator = (const Singleton& other) = delete;
};
