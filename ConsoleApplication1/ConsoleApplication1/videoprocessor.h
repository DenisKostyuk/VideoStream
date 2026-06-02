#pragma once
#include "ivideosource.h"
#include <windows.h>
#include "ifilter.h"
#include "filtertype.h"
#include <mutex>
class VideoProcessor {
private:
	IVideoSource* video;
	IFilter* currentFilter;
	std::atomic<bool> stopFlag{ false };
	std::mutex filterMutex;

public:
	VideoProcessor(IVideoSource* source, IFilter* currFilter) : video(source), currentFilter(currFilter) {};
	~VideoProcessor();

	void Run();
	void Stop();
	void SetFilter(FilterType type);
};

extern "C" __declspec(dllexport)
void StopVideo();

extern "C" __declspec(dllexport)
void StartVideo(int type);

extern "C" __declspec(dllexport)
void DrawFrameOnCSharpWindow(HWND hwnd, uchar* frameData, int width, int height);

extern "C" __declspec(dllexport)
void SetFilter(FilterType type);