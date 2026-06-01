#include <iostream>
#include <opencv2/opencv.hpp>
#include "webcamsource.h"


bool WebcamSource::Open() {
	if (!cap.open(0)) {
		std::cerr << "Could not open the Webcam source\n";
		return false;
	}
	return cap.isOpened();

}

bool WebcamSource::GetFrame(cv::Mat& frame) {
	return cap.read(frame);
}

void WebcamSource::Close(){
	cap.release();
}
bool WebcamSource::CanRestart() {
	return false;
}

void WebcamSource::Restart(){
	//
}