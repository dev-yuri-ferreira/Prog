#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include "pixel.h"

class Image
{
private:
    int width;
    int height;
    int maxColor;
    std::vector<Pixel> imagePixels;
public:
    Image(int w, int h, int mc);
    int getWidth();
    int getHeight();
    int getMaxColor();
    void addPixel(Pixel p);
    std::string generateImageFile();
};

Image::Image(int w, int h, int mc)
{
    width = w;
    height = h;
    maxColor = mc;
}

int Image::getWidth(){
    return width;
}
int Image::getHeight(){
    return height;
}
int Image::getMaxColor(){
    return maxColor;
}
void Image::addPixel(Pixel p){
    imagePixels.push_back(p);
}

std::string Image::generateImageFile(){
    std::string fileText = "";
    fileText += "P3\n";
    fileText += std::to_string(width) + " ";
    fileText += std::to_string(height) + "\n";
    fileText += std::to_string(maxColor) + "\n";
    int endOfLine = 1;
    for (auto p : imagePixels)
    {
        fileText+= p.getPixel() + "\t";
        if(endOfLine <= width) {endOfLine++;} else {endOfLine = 1; fileText+="\n";}
    }
    return fileText;
    
}


#endif