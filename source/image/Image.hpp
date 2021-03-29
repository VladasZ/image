//
//  Image.hpp
//  image
//
//  Created by Vladas Zakrevskis on 2/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <string>
#include <cstdint>

#include "NonCopyable.hpp"
#include "ImageBinder.hpp"


class Image// : cu::NonCopyable
        {

protected:

    bool _ok = false;

    void*   _data = nullptr;
    float   _width;
    float   _height;
    uint8_t _channels;

    image::ImageBinder* _binder = nullptr;

    std::string _path;

public:

    explicit Image() = default;
    explicit Image(const std::string& path);
    explicit Image(void* data, float width, float height, uint8_t channels);
    virtual ~Image();

    float   width        () const;
    float   height       () const;
    void*   data         () const;
    uint8_t channels     () const;
    bool    is_monochrome() const;

    void bind() const;

    std::string path() const;
    void set_path(const std::string&);

    std::string to_string() const;

};
