#pragma once
#include<string>
#include<vector>

using namespace std;

// Variables
struct Header{
public:
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;

    explicit Header(string);
    void write(string fileName, unsigned char* pixels);

    unsigned char* pixelData;
    unsigned char* getPixelData() const;


    int size;
    int getSize() const;

};



