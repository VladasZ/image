//
//  ImageMapping.hpp
//  image
//
//  Created by Vladas Zakrevskis on 12/03/21.
//  Copyright © 2021 VladasZ. All rights reserved.
//

#pragma once

#include "Image.hpp"
#include "Mapper.hpp"


namespace image {

    MAKE_CLASS_INFO(Image,
        MAKE_GETTER_PROPERTY(Image, path)
    );

}
