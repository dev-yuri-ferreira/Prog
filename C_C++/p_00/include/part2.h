#ifndef PART_2
#define PART_2

#include "image.h"

class Part2 : public Image
{
private:
enum Corners{
        BOTTOM_LEFT,
        TOP_LEFT,
        BOTTOM_RIGHT,
        TOP_RIGHT
    };
    Pixel colorBottomLeft;
    Pixel colorBottomRight;
    Pixel colorTopLeft;
    Pixel colorTopRight;

public:
    using Image::Image;
    Part2(int w, int h, int mc, Pixel bl, Pixel tl,Pixel br, Pixel tr);
    Pixel interpolatePoints(Pixel a, Pixel b, float pos);
    Pixel generatePoint(float y, float x);
    void fillImage();
    void setCorners(Corners c, Pixel p);
};

Part2::Part2(int w, int h, int mc,  Pixel bl, Pixel tl,Pixel br, Pixel tr):Image(w,h,mc)
{
    colorBottomLeft = bl;
    colorBottomRight = br;
    colorTopLeft = tl;
    colorTopRight = tr;
}
Pixel Part2::interpolatePoints(Pixel a, Pixel b, float pos){
    Pixel aRes( ( a* (1.0f - pos) ) );
    Pixel bRes( ( b * pos ) );
    Pixel result = aRes + bRes;
    return result;
}

Pixel Part2::generatePoint(float x, float y){
    Pixel lower = interpolatePoints(colorBottomLeft,colorBottomRight,x);
    Pixel upper = interpolatePoints(colorTopLeft,colorTopRight,x);
    Pixel result = interpolatePoints(lower,upper,y);
    return result;
}

void Part2::fillImage(){
    float h = getHeight();
    float w = getWidth();
    for (float i = 1.0f; i <= h; i++)
    {
        for (float j = 1.0f; j <= w; j++)
        {
            addPixel(generatePoint( j/w, (1.0f - i/h) ));
        }
        
    }
    
}

void Part2::setCorners(Corners c, Pixel p){
    switch (c)
    {
    case BOTTOM_LEFT:
        colorBottomLeft = p;
        break;
    
    case TOP_LEFT:
        colorTopLeft = p;
        break;
    
    case BOTTOM_RIGHT:
        colorBottomRight = p;
        break;
    
    case TOP_RIGHT:
        colorTopRight = p;
        break;
    
    default:
        break;
    }
}

#endif