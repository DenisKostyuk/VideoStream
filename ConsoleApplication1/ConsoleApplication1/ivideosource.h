#pragma once
#include <opencv2/opencv.hpp>

/**
* Interface for a video handler (will be inherited by Webcam and VideoFile)

**/
class IVideoSource {
public:
	virtual ~IVideoSource() = default;

	virtual bool Open() = 0;
	virtual bool GetFrame(cv::Mat& frame) = 0;
	virtual void Close() = 0;
	virtual bool CanRestart() = 0;
	virtual void Restart() = 0;
		
};
