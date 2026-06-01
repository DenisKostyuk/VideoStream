#pragma once
#include "ivideosource.h"
#include <opencv2/opencv.hpp>


class VideoFileSource : public IVideoSource {
private:
	cv::VideoCapture cap;
	std::wstring path;
public:
	bool Open() override;
	bool GetFrame(cv::Mat& frame) override;
	void Close() override;
	bool CanRestart() override;
	void Restart();
};
