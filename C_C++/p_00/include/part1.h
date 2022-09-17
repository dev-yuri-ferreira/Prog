#ifndef PART_1
#define PART_1

#include "image.h"

class Part1 : public Image
{
public:
    using Image::Image;
    Part1(int w, int h, int mc);
    void fillImage();
};

Part1::Part1(int w, int h, int mc):Image(w,h,mc)
{
}
void Part1::fillImage(){
    float h = getHeight();
    float w = getWidth();
    for (float i = 1.0f; i <= h; i++)
    {
        for (float j = 1.0f; j <= w; j++)
        {
            addPixel( Pixel(j/w, 1.0f - i/h,0.2) );
        }
        
    }
    
}


#endif