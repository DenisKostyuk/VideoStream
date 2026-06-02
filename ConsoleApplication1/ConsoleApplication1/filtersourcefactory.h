#pragma once
#include "ifilter.h"
#include "filtertype.h"
#include "genericfilter.h"
#include "greyscalefilter.h"
#include "gaussianblurfilter.h"
class FilterSourceFactory {
public:
	static IFilter* create(FilterType type);
};
