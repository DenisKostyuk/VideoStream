#include "gaussianblurfilter.h"
#include <opencv2/opencv.hpp>

cv::Mat GaussianBlurFilter::applyFilter(const cv::Mat& frame) {
	cv::Mat output;

	cv::GaussianBlur(frame, output, cv::Size(15, 15), 0);
	return output;
}
