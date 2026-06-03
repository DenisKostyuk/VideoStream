#include "ifilter.h"
#include "greyscalefilter.h"
#include <opencv2/opencv.hpp>

cv::Mat GreyScaleFilter::applyFilter(const cv::Mat& frame) {
	cv::Mat gray;
	cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

	cv::Mat output;
	cv::cvtColor(gray, output, cv::COLOR_GRAY2BGR);


	return output;
}