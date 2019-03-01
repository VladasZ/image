//
//  Image.cpp
//  image
//
//  Created by Vladas Zakrevskis on 2/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#if DESKTOP_BUILD
#include "SOIL.h"
#endif

#include "Image.hpp"
#include "ImageBinder.hpp"
#include "ImageLoader.hpp"
#include "ImageConfig.hpp"

using namespace image;

Image::Image(const std::string& path) {

    int width;
    int height;
    int channels;

    #if DESKTOP_BUILD

    _data = SOIL_load_image(path.c_str(),
                            &width,
                            &height,
                            &channels,
                            SOIL_LOAD_RGBA);

    if (_data == nullptr)
        throw std::string() + "Failed to load image: " + path;

    _width    = static_cast<float>(width);
    _height   = static_cast<float>(height);
    _channels = static_cast<uint8_t>(channels);

    _binder = config::loader()->create_binder_for(this);

    #endif
}

Image::Image(void* data, float width, float height, uint8_t channels) : _data(data), _width(width), _height(height),  _channels(channels) {
    _binder = config::loader()->create_binder_for(this);
}

Image::~Image() {
    delete _binder;
    _free_data();
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
    _binder->bind();
}

void Image::unbind() const {
    _binder->unbind();
}

void Image::_free_data() {
    if (_data) {
        free(_data);
        _data = nullptr;
    }
}
