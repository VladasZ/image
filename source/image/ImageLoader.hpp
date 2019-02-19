//
//  ImageLoader.hpp
//  image
//
//  Created by Vladas Zakrevskis on 2/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

class Image;

namespace image {

class ImageBinder;

class ImageLoader {
public:
    virtual ~ImageLoader();
    virtual ImageBinder* create_binder_for(Image*) = 0;
};

}
