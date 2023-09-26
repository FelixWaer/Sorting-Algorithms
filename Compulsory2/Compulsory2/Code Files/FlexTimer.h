#pragma once
#include <iostream>
#include <chrono>

class Timer
{
public:
		Timer(bool activateAutoTimer = false)
		{
			autoTimerActive = activateAutoTimer;
			if (autoTimerActive == true)
			{
				start = std::chrono::high_resolution_clock::now();
			}
		}

		~Timer()
		{
			if (autoTimerActive == true)
			{
				end = std::chrono::high_resolution_clock::now();
				duration = end - start;
				float ms = duration.count() * 1000.f;
				std::cout << "time it took in ms: " << ms << std::endl;
				std::cout << "time it took in s: " << duration.count() << std::endl;
			}
		}

	void start_Timer()
		{
			start = std::chrono::high_resolution_clock::now();
		}

	void stop_Timer()
		{
			end = std::chrono::high_resolution_clock::now();
			duration = end - start;
		}

	float TimeResult_InSeconds()
		{
			return duration.count();
		}

	float TimeResult_InMilliseconds()
		{
			return duration.count() * 1000.f;
		}

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	std::chrono::duration<float> duration;

	bool autoTimerActive;

};