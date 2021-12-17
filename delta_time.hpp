#pragma once

#include <iostream>
#include <chrono>

using namespace std;

class Mytime
{
private:
	std::chrono::steady_clock::time_point start, end;
	std::chrono::duration<float> duration;
public:
	Mytime() {
		start = std::chrono::high_resolution_clock::now();
	}

	void retime() { start = std::chrono::high_resolution_clock::now(); }

	void get_time()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		cout << "Time is code = " << duration.count() << "s" << endl;
	}

	~Mytime() {
		cout << "Destructor: ";
		get_time();
	}
};