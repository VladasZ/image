//
//  ImageConfig.cpp
//  image
//
//  Created by Vladas Zakrevskis on 2/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <string>

#include "ImageConfig.hpp"

using namespace image;

static ImageLoader* _loader = nullptr;

void config::set_loader(ImageLoader* loader) {
    _loader = loader;
}

ImageLoader* config::loader() {
#ifdef DEBUG
    if (_loader == nullptr)
        throw std::string() + "image::config::loader is not set up";
#endif
    return _loader;
}
