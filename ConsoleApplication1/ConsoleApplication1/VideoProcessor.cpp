#include "videoprocessor.h"
#include "videosourcefactory.h"
#include <opencv2/opencv.hpp>
#include <Windows.h>
#include "renderapi.h"

VideoProcessor::~VideoProcessor() { delete video; }

static VideoProcessor* processor = nullptr;

void VideoProcessor::Run() {
    video->Open();

    cv::Mat frame;
    
    while (!stopFlag) {
        if (video->GetFrame(frame)) {
            cv::Mat resized;
            cv::resize(frame, resized, cv::Size(776, 345));
            cv::Mat safe = resized.clone();

            DrawFrameOnCSharpWindow(g_hwnd, safe.data, safe.cols, safe.rows);
        }
        else if(video->CanRestart()) video->Restart();
    }
	this->video->Close();
	cv::destroyAllWindows();
}

void VideoProcessor::Stop() {
	this->stopFlag = true;
}

extern "C" __declspec(dllexport)
void StartVideo(int type) {
	IVideoSource* source = VideoSourceFactory::create((SourceType)type);
	processor = new VideoProcessor(source);
	processor->Run();
}

extern "C" __declspec(dllexport)
void StopVideo() {
    if (processor) {
        processor->Stop();
        Sleep(30);
        delete processor;
        processor = nullptr;
    }
}


extern "C" __declspec(dllexport)
void DrawFrameOnCSharpWindow(HWND hwnd, uchar* frameData, int width, int height)
{
    if (!hwnd || !frameData) return;

    HDC hdc = GetDC(hwnd);
    if (!hdc) return;

    RECT rc;
    GetClientRect(hwnd, &rc);

    BITMAPINFO bmi = {};
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = width;
    bmi.bmiHeader.biHeight = -height;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 24;
    bmi.bmiHeader.biCompression = BI_RGB;

    StretchDIBits(
        hdc,
        0, 0, rc.right, rc.bottom,
        0, 0, width, height,
        frameData,
        &bmi,
        DIB_RGB_COLORS,
        SRCCOPY
    );

    ReleaseDC(hwnd, hdc);
}