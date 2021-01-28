//
//  ImageBinder.hpp
//  image
//
//  Created by Vladas Zakrevskis on 2/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once


namespace image {

class ImageBinder {
public:

    virtual ~ImageBinder();

    virtual void bind() const = 0;
};

}
