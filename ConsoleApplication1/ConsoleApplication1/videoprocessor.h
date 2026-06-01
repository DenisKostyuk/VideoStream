#pragma once
#include "ivideosource.h"
#include <windows.h>
class VideoProcessor {
private:
	IVideoSource* video;
	std::atomic<bool> stopFlag{ false };

public:
	VideoProcessor(IVideoSource* source) : video(source) {};
	~VideoProcessor();

	void Run();
	void Stop();
};

extern "C" __declspec(dllexport)
void StopVideo();

extern "C" __declspec(dllexport)
void StartVideo(int type);

extern "C" __declspec(dllexport)
void DrawFrameOnCSharpWindow(HWND hwnd, uchar* frameData, int width, int height);