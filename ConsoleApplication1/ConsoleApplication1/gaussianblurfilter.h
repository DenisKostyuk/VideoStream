#pragma once
#include "ifilter.h"

class GaussianBlurFilter : public IFilter {
public:
	cv::Mat applyFilter(const cv::Mat& frame) override;

};