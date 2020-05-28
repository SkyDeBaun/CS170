/*
File:			Timer.h
Author:			Dr Glenn Stevenson
Description:	Provides timer functionality... useful for time-interval measurements, ie the time taken to run a given function (or series of them.)
				To start timer simply call startTimer(). To end timer call stopTimer(). After stopping the timer.. the elapsed time can be
				retrieved by calling one of the get functions: getMilli(), getSeconds(), or getMicro()
*/


#pragma once

#include <windows.h>

/*
Class			Timer
Author:			Dr Glenn Stevenson
Description:	Provides timer functionality... useful for time-interval measurements, ie the time taken to run a given function (or series of them.)
				To start timer simply call startTimer(). To end timer call stopTimer(). After stopping the timer.. the elapsed time can be
				retrieved by calling one of the get functions: getMilli(), getSeconds(), or getMicro()
Input:			None
Output:			Returns time as a double value (in seconds)
*/
class Timer
{
private:
	LARGE_INTEGER start;
	LARGE_INTEGER stop;
	LARGE_INTEGER freq;
	double PCFreq; 
__int64 CounterStart; 

public:
	/*
	Function:		Timer() -> default constructor
	Author:			Dr Glenn Stevenson
	Description:	Instantiates timer object
	Input:			None
	Output:			None
	*/
	Timer();

	/*
	Function:		startTimer()
	Author:			Dr Glenn Stevenson
	Description:	Starts time-interval measurement
	Input:			None
	Output:			None
	*/
	void startTimer();

	/*
	Function:		stopTimer() 
	Author:			Dr Glenn Stevenson
	Description:	Stops time-interval measurement
	Input:			None
	Output:			None
	*/
	void stopTimer();	

	/*
	Function:		getMicro()
	Author:			Dr Glenn Stevenson
	Description:	Returns time-interval of last start-stop sequence
	Input:			None
	Output:			Double representing micro-seconds (10^-6)
	*/
	double getMicro();

	/*
	Function:		getMilli()
	Author:			Dr Glenn Stevenson
	Description:	Returns time-interval of last start-stop sequence
	Input:			None
	Output:			Double representing milli-seconds (10^-3)
	*/
	double getMilli();

	/*
	Function:		getSeconds()
	Author:			Dr Glenn Stevenson
	Description:	Returns time-interval of last start-stop sequence
	Input:			None
	Output:			Double representing seconds
	*/
	double getSeconds();

};