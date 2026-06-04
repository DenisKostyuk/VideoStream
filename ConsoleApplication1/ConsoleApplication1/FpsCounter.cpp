#include "fpscounter.h"

FpsCounter::FpsCounter() : frameCount(0), fps(0), lastTime(std::chrono::steady_clock::now()) {};

void FpsCounter::Tick() {
	this->frameCount++;

	auto now = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastTime);

	if (elapsed.count() >= 1000) {
		fps = frameCount;
		frameCount = 0;
		lastTime = now;
	}
}


int FpsCounter::get_fps() {
	return this->fps;
}