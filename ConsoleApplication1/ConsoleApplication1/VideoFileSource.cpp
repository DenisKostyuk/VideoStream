#include "videofilesource.h"
#include "filehandler.h"
#include <opencv2/opencv.hpp>


bool VideoFileSource::Open() {
	//FileHandler fh;
	this->path = FileHandler::GetFilePathFromDialog();
	if (path.empty()) return false;
	return cap.open(std::string(this->path.begin(), this->path.end()));
	
}

bool VideoFileSource::GetFrame(cv::Mat& frame) {
	return cap.read(frame);
}

void VideoFileSource::Close() {
	cap.release();
	
}

bool VideoFileSource::CanRestart() {
	return true;
}

void VideoFileSource::Restart() {
	cap.release();
	cap.open(std::string(this->path.begin(), this->path.end()));
}
