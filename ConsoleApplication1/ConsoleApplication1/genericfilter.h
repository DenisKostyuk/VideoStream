#pragma once
#include <opencv2/opencv.hpp>
#include "ifilter.h"

/**
* Generic frame that returns the defualt frame that was captured. 
**/

class GenericFilter : public IFilter {
public:
	cv::Mat applyFilter(const cv::Mat& frame) {
		return frame;
	}
};