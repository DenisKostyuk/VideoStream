#include "videoprocessor.h"
#include "videosourcefactory.h"
#include <opencv2/opencv.hpp>
#include <Windows.h>
#include "renderapi.h"
#include "filtertype.h"
#include "genericfilter.h"
#include "greyscalefilter.h"
#include "filtersourcefactory.h"
#include "Logger.h"
#include <thread>

VideoProcessor::~VideoProcessor() { 
    delete video;
    delete currentFilter;
}

static VideoProcessor* processor = nullptr;

static std::thread worker;



void VideoProcessor::Run() {
    //gLogger.Log("[RUN] Run Function started...");
    video->Open();

    cv::Mat frame;

    while (!stopFlag) {
        if (video->GetFrame(frame)) {
            cv::Mat processedFrame;
            {
                std::lock_guard<std::mutex> lock(this->filterMutex);
                processedFrame = currentFilter->applyFilter(frame);
            }
            cv::Mat resized;
            cv::resize(processedFrame, resized, cv::Size(776, 345));
            cv::Mat safe = resized.clone();
            
            this->fpsCounter.Tick();
            std::string text = "FPS: " + std::to_string(this->fpsCounter.get_fps());
            cv::putText(safe, text, cv::Point(20, 40), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0, 255, 0), 2);
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

/**
* Function that sets a filter to a frame
**/
void VideoProcessor::SetFilter(FilterType type) {
    //gLogger.Log("[SETFILTER] Applied new filter ");
    IFilter* newFilter = FilterSourceFactory::create((FilterType)type);
    std::lock_guard<std::mutex> lock(this->filterMutex);
    delete this->currentFilter;
    this->currentFilter = newFilter;

}


extern "C" __declspec(dllexport)
void StartVideo(int type) {
    //gLogger.Log("[StartVideo] Video started. ");
	IVideoSource* source = VideoSourceFactory::create((SourceType)type);
    IFilter* filter = FilterSourceFactory::create((FilterType)FilterType::Generic);
	processor = new VideoProcessor(source, filter);
    worker = std::thread(&VideoProcessor::Run, processor);
	//processor->Run();
}

extern "C" __declspec(dllexport)
void StopVideo() {
    //gLogger.Log("[StopVideo] Video stoped");
    if (processor) {
        processor->Stop();
        if (worker.joinable())
            worker.join();
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

extern "C" __declspec(dllexport)
void Setfilter(FilterType type) {
    if(processor) processor->SetFilter(type);
}