//
//  Image.hpp
//  image
//
//  Created by Vladas Zakrevskis on 2/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <cstdint>
#include <string>

namespace image {
class ImageBinder;
}

class Image {

protected:

    void*   _data;
    float   _width;
    float   _height;
    uint8_t _channels;

    image::ImageBinder* _binder;

public:

    explicit Image(const std::string& path);
    explicit Image(void* data, float width, float height, uint8_t channels);
    virtual ~Image();

    float   width        () const;
    float   height       () const;
    void*   data         () const;
    uint8_t channels     () const;
    bool    is_monochrome() const;

    void bind() const;

protected:

    void _free_data();
};
