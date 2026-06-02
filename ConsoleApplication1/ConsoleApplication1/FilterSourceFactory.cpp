#include "filtersourcefactory.h"
#include "ifilter.h"

IFilter* FilterSourceFactory::create(FilterType type) {
    switch (type) {
    case FilterType::Generic:
        return new GenericFilter();

    case FilterType::Gray:
        return new GreyScaleFilter();

    case FilterType::GaussianBlur:
        return new GaussianBlurFilter();
    default:
        return nullptr;

    }
}
