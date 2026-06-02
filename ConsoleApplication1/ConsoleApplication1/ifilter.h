#pragma once
#include <opencv2/opencv.hpp>

class IFilter {
public:
	virtual cv::Mat applyFilter(const cv::Mat& frame) = 0;
	virtual ~IFilter() = default;
};
