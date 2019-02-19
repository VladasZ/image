//
//  ImageConfig.hpp
//  image
//
//  Created by Vladas Zakrevskis on 2/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

namespace image {

class ImageLoader;

struct config {
    static void set_loader(ImageLoader*);
    static ImageLoader* loader();
};

}
