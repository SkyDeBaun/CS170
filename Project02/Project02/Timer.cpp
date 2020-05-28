/*
File:			Timer.cpp
Author:			Dr Glenn Stevenson
Description:	Provides timer functionality... useful for time-interval measurements, ie the time taken to run a given function (or series of them.)
				To start timer simply call startTimer(). To end timer call stopTimer(). After stopping the timer.. the elapsed time can be
				retrieved by calling one of the get functions: getMilli(), getSeconds(), or getMicro()
*/


#include <iostream>
#include "Timer.h"

using std::cout;
using std::endl;

/*
Function:		Timer() -> default constructor
Author:			Dr Glenn Stevenson
Description:	Instantiates timer object
Input:			None
Output:			None
*/
Timer::Timer()
{
	if(!QueryPerformanceFrequency(&freq)) 
		cout << "QueryPerformanceFrequency failed!\n"; 

}

/*
Function:		startTimer()
Author:			Dr Glenn Stevenson
Description:	Starts time-interval measurement
Input:			None
Output:			None
*/
void Timer::startTimer()
{	
   QueryPerformanceCounter(&start);
    
}

/*
Function:		stopTimer()
Author:			Dr Glenn Stevenson
Description:	Stops time-interval measurement
Input:			None
Output:			None
*/
void Timer::stopTimer()
{
	QueryPerformanceCounter(&stop);  

}

/*
Function:		getMicro()
Author:			Dr Glenn Stevenson
Description:	Returns time-interval of last start-stop sequence
Input:			None
Output:			Double representing micro-seconds (10^-6)
*/
double Timer::getMicro()
{
	PCFreq = freq.QuadPart / 1000000.0;
	return double((stop.QuadPart - start.QuadPart)) / PCFreq;
}

/*
Function:		getMilli()
Author:			Dr Glenn Stevenson
Description:	Returns time-interval of last start-stop sequence
Input:			None
Output:			Double representing milli-seconds (10^-3)
*/
double Timer::getMilli()
{
	PCFreq = freq.QuadPart / 1000.0;
	return double((stop.QuadPart - start.QuadPart)) / PCFreq;
}

/*
Function:		getSeconds()
Author:			Dr Glenn Stevenson
Description:	Returns time-interval of last start-stop sequence
Input:			None
Output:			Double representing seconds
*/
double Timer::getSeconds()
{
	return double(stop.QuadPart - start.QuadPart)/ freq.QuadPart;

}