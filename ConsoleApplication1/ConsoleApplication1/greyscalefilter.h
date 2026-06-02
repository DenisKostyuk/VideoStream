#pragma once
#include "ifilter.h"
#include <opencv2/opencv.hpp>

class GreyScaleFilter : public IFilter {
public:
	cv::Mat applyFilter(const cv::Mat& frame) override;
	

};