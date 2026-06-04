#pragma once
#include <chrono>

class FpsCounter {
private:
	int frameCount;
	int fps;
	std::chrono::steady_clock::time_point lastTime;
public:
	FpsCounter();
	void Tick();
	int get_fps();
};
