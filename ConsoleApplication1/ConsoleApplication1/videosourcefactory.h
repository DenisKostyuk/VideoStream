#pragma once
#include "ivideosource.h"
#include "sourcetype.h"
class VideoSourceFactory {
public:
	static IVideoSource* create(SourceType type);
};
