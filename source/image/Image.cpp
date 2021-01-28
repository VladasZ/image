//
//  Image.cpp
//  image
//
//  Created by Vladas Zakrevskis on 2/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <stdexcept>
#include <SoilInclude.hpp>

#include "Log.hpp"
#include "Image.hpp"
#include "ImageLoader.hpp"
#include "ImageConfig.hpp"

using namespace std;
using namespace image;


Image::Image(const string& path) : _path(path) {

#ifdef USING_SOIL

    int width;
    int height;
    int channels;

    _data = SOIL_load_image(path.c_str(),
                            &width,
                            &height,
                            &channels,
                            SOIL_LOAD_RGBA);

    if (_data == nullptr) {
        Fatal("Failed to load image: " + path);
    }

    _width    = static_cast<float>(width);
    _height   = static_cast<float>(height);
    _channels = static_cast<uint8_t>(channels);

    _binder = config::loader()->create_binder_for(this);
    
#ifdef IMAGES_LOADING_OUTPUT
    cout << path << " " << _width << " " << _height << endl;
#endif

    SOIL_free_image_data(static_cast<unsigned char*>(_data));

    _ok = true;

#endif
    
}

Image::Image(void* data, float width, float height, uint8_t channels) : _data(data), _width(width), _height(height),  _channels(channels) {
    _binder = config::loader()->create_binder_for(this);
    _ok = true;
}

Image::~Image() {
    delete _binder;
}

float Image::width() const {
    return _width;
}

float Image::height() const {
    return _height;
}

void* Image::data() const {
    return _data;
}

uint8_t Image::channels() const {
    return _channels;
}

bool Image::is_monochrome() const {
    return _channels == 1;
}

void Image::bind() const {
    if (!_ok) return;
    _binder->bind();
}
