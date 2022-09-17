#ifndef PIXEL_H
#define PIXEL_H

#include <string>
#include <sstream>

bool identifyFloatPixel(std::string colorValue);

class Pixel
{
private:
    enum Colors{
        RED,
        GREEN,
        BLUE
    };
    int colorRed = 0;
    int colorGreen = 0;
    int colorBlue = 0;

    int getColor(Colors c);
    void setColor(Colors c, int value);
    void setColor(Colors c, float value);
public:
    Pixel();
    Pixel(int colorR, int colorG, int colorB);
    Pixel(float percentR, float percentG, float percentB);
    Pixel(std::string colorR, std::string colorG, std::string colorB);
    Pixel(std::string colorRGB);
    Pixel(const Pixel& p);

    Pixel operator* (float f);
    Pixel operator+ (const Pixel& b);
    void operator= (const Pixel& b);

    int getColorRed();
    int getColorGreen();
    int getColorBlue();

    std::string getPixel();
};

bool identifyFloatPixel(std::string colorValue){
    int isFloat = colorValue.find('.');
    return (isFloat == -1) ? false : true;
}

Pixel::Pixel(){
    colorRed = 0;
    colorGreen = 0;
    colorBlue = 0;
}

Pixel::Pixel(int colorR, int colorG, int colorB){
    setColor(RED,colorR);
    setColor(GREEN,colorG);
    setColor(BLUE,colorB);
}
Pixel::Pixel(float percentR, float percentG, float percentB){
    setColor(RED,percentR);
    setColor(GREEN,percentG);
    setColor(BLUE,percentB);
}
Pixel::Pixel(std::string colorR, std::string colorG, std::string colorB){

    if(identifyFloatPixel(colorR)){
        float valueRed = std::stof(colorR);
        setColor(RED,valueRed);
    }
    else{
        int valueRed = std::stoi(colorR);
        setColor(RED,valueRed);
    }

    if(identifyFloatPixel(colorG)){
        float valueGreen = std::stof(colorG);
        setColor(GREEN,valueGreen);
    }
    else{
        int valueGreen = std::stoi(colorG);
        setColor(GREEN,valueGreen);
    }
    
    if(identifyFloatPixel(colorB)){
        float valueBlue = std::stof(colorB);
        setColor(BLUE,valueBlue);
    }
    else{
        int valueBlue = std::stoi(colorB);
        setColor(BLUE,valueBlue);
    }
    
}
Pixel::Pixel(std::string colorRGB){
    std::stringstream ss(colorRGB);
    std::string strR,strG,strB;
    ss >> strR;
    ss >> strG;
    ss >> strB;
    new (this) Pixel(strR,strG,strB);
}


Pixel::Pixel(const Pixel& p){
    this->colorRed = p.colorRed;
    this->colorGreen = p.colorGreen;
    this->colorBlue = p.colorBlue;
}


Pixel Pixel::operator* (float f){
    float newRed = colorRed * f;
    float newGreen = colorGreen * f;
    float newBlue = colorBlue * f;
    return Pixel((int) newRed,(int) newGreen,(int) newBlue);
}

Pixel Pixel::operator+ (const Pixel& b){
    int resultRed = this->colorRed + b.colorRed;
    int resultGreen = this->colorGreen + b.colorGreen;
    int resultBlue = this->colorBlue + b.colorBlue;
    return Pixel(resultRed,resultGreen,resultBlue);
}

void Pixel::operator= (const Pixel& b){
    this->colorRed = b.colorRed;
    this->colorGreen = b.colorGreen;
    this->colorBlue = b.colorBlue;
}

int Pixel::getColor(Colors c){
    int colorValue;
    switch (c)
    {
    case RED:
        colorValue = colorRed;
        break;
    
    case GREEN:
        colorValue = colorGreen;
        break;
    
    case BLUE:
        colorValue = colorBlue;
        break;
    
    default:
        break;
    }

    return colorValue;
}
void Pixel::setColor(Colors c, int value){
    switch (c)
    {
    case RED:
        colorRed = value;
        break;
    
    case GREEN:
        colorGreen = value;
        break;
    
    case BLUE:
        colorBlue = value;
        break;
    
    default:
        break;
    }
}
void Pixel::setColor(Colors c, float value){
    switch (c)
    {
    case RED:
        colorRed = 255.0 * value;
        break;
    
    case GREEN:
        colorGreen = 255.0 * value;
        break;
    
    case BLUE:
        colorBlue = 255.0 * value;
        break;
    
    default:
        break;
    }
}

int Pixel::getColorRed(){
    return getColor(RED);
}
int Pixel::getColorGreen(){
    return getColor(GREEN);
}
int Pixel::getColorBlue(){
    return getColor(BLUE);
}

std::string Pixel::getPixel(){
    std::string result = std::to_string(colorRed) + " " + std::to_string(colorGreen) + " " + std::to_string(colorBlue) + "\t";
    return result;
}

#endif
