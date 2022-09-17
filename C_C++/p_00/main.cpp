#include <iostream>
#include <fstream>
#include "include/part1.h"
#include "include/part2.h"

using namespace std;

int main(){

    ofstream part1File("pics/part1_image.ppm");
    Part1 ppmImage01(400,200,255);
    ppmImage01.fillImage();
    part1File << ppmImage01.generateImageFile();
    part1File.close();

    ofstream part2File("pics/part2_image.ppm");
    Part2 ppmImage02(400,200,255,Pixel(255, 0, 255),Pixel(255, 255, 0),Pixel(0, 255, 255),Pixel(75,0,130));
    ppmImage02.fillImage();
    part2File << ppmImage02.generateImageFile();
    part2File.close();

    

    return 0;
}