#include "videosourcefactory.h"
#include "sourcetype.h"
#include "webcamsource.h"
#include "videofilesource.h"

IVideoSource* VideoSourceFactory::create(SourceType type){
	switch (type) {
	case SourceType::Webcam:
		return new WebcamSource();


	case SourceType::File:
		return new VideoFileSource();

	default:
		return nullptr;
	}
}