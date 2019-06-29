// FunctionPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Event.h"
#include <iostream>

//Example Class 1
class SomeClass
{
public:

	void SomeFunction()
	{
		printf("SomeFunction\n");
	}

	void FunctionWithFloat(float Number)
	{
		printf("This is a value: %f\n", Number);
	}

	void FunctionWithString(const std::string& string) 
	{
		printf("This is a string: %s\n", string.c_str());
	}

	void FunctionWithMultiple(bool boolean, const std::string& string) 
	{	
		if (boolean) 
		{
			printf("This statement is true: %s\n", string.c_str());
		}
		else 
		{
			printf("This statement is false: %s\n", string.c_str());
		}
	}

};

//Example Class 2
class SomeOtherClass 
{

public:

	void SomeOtherFunction() 
	{
		printf("SomeOtherFunction\n");
	}

	void SomeOtherStringfunction(const std::string& string) 
	{
		printf("SomeOtherStringFunction: %s\n", string.c_str());
	}

	void  SomeOtherFunctionWithMultiple(bool boolean, const std::string& string) 
	{
		if (boolean) 
		{
			printf("This is another true statement: %s\n", string.c_str());
		}
		else 
		{
			printf("This is another false statement: %s\n", string.c_str());
		}
	}

};

int main()
{
	//Instantiate possible subscriber objects
	SomeClass* ClassOne = new SomeClass();
	SomeOtherClass* ClassTwo = new SomeOtherClass();

	//Event with no dispatch Arguments;
	Event<> VoidEvent = Event<>();

	//Event with float as dispatch argument
	Event<float> FloatEvent = Event<float>();

	//Event With String as dispatch argument
	Event<const std::string&> StringEvent = Event<const std::string&>();

	//Event with multiple dispatch arguments
	Event<bool, const std::string&> MultipleEvent = Event<bool, const std::string&>();

	//Register Memberfunctions of objects to a VoidEvent
	VoidEvent.Register<SomeClass>(ClassOne, &SomeClass::SomeFunction);
	VoidEvent.Register<SomeOtherClass>(ClassTwo, &SomeOtherClass::SomeOtherFunction);
	
	//Register Memberfunctions of objects to a FloatEvent
	FloatEvent.Register<SomeClass>(ClassOne, &SomeClass::FunctionWithFloat);

	//Register Memberfunctions of objects to a string event
	StringEvent.Register<SomeClass>(ClassOne, &SomeClass::FunctionWithString);
	StringEvent.Register<SomeOtherClass>(ClassTwo, &SomeOtherClass::SomeOtherStringfunction);
	
	//Register Memberfunctions of objects to multiple argument events
	MultipleEvent.Register<SomeClass>(ClassOne, &SomeClass::FunctionWithMultiple);
	MultipleEvent.Register<SomeOtherClass>(ClassTwo, &SomeOtherClass::SomeOtherFunctionWithMultiple);

	VoidEvent.Dispatch();
	FloatEvent.Dispatch(1000.0f);
	StringEvent.Dispatch("String Event Dispatched!");
	MultipleEvent.Dispatch(true, "Apples are a fruit");
	MultipleEvent.Dispatch(false, "Apples are meat");
	
	printf("Unregister String event");

	StringEvent.UnregisterAll();

	StringEvent.Dispatch("String Event Dispatched Again!");

	delete ClassOne;
	delete ClassTwo;

	return 0;
}

