#include "cannyedge.h"
#include <opencv2/opencv.hpp>
#include "gaussianblurfilter.h"

cv::Mat CannyEdgeDetection::applyFilter(const cv::Mat& frame) {
	cv::Mat gray, blur, edges;
	cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(gray, blur, cv::Size(10, 10), 0);
	cv::Canny(blur, edges, 50, 150, 3);
	return edges;
}