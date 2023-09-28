#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"Image.h"

// Stores and reads
Header::Header(string name) {
    ifstream input;
    input.open(name, ios_base::binary);
//
//    if (input.is_open()) {
//        cout << "Open" << endl;
//        cout << "" << endl;
//    }
//    else {
//        cout << "Not open "<< endl;
//        cout << "" << endl;
//    }

    input.read(&idLength, sizeof(idLength));
    input.read(&colorMapType, sizeof(colorMapType));
    input.read(&dataTypeCode, sizeof(dataTypeCode));
    input.read((char*)&colorMapOrigin, sizeof(colorMapOrigin));
    input.read((char*)&colorMapLength, sizeof(colorMapLength));
    input.read(&colorMapDepth, sizeof(colorMapDepth));
    input.read((char*)&xOrigin, sizeof(xOrigin));
    input.read((char*)&yOrigin, sizeof(yOrigin));
    input.read((char*)&width, sizeof(width));
    input.read((char*)&height, sizeof(height));
    input.read(&bitsPerPixel, sizeof(bitsPerPixel));
    input.read(&imageDescriptor, sizeof(imageDescriptor));


    size = 3 * width * height;
    pixelData = new unsigned char[size];

    for (int i = 0; i <= size - 1; i++) {
        input.read((char*) &pixelData[i], 1);
    }

//    cout << "ID Length: " << (int)idLength << endl;
//    cout << "Color Map Type: " << (int)colorMapType << endl;
//    cout << "Data Type Code: " << (int)dataTypeCode << endl;
//    cout << "Color Map Origin: " << (int)colorMapOrigin << endl;
//    cout << "Color Map Depth: " << (int)colorMapDepth << endl;
//    cout << "x Origin: " << (int)xOrigin << endl;
//    cout << "y Origin: " << (int)yOrigin << endl;
//    cout << "Width: " << width << endl;
//    cout << "Height: " << height << endl;
//    cout << "Bits Per Pixel: " << (int)bitsPerPixel << endl;
//    cout << "Image Descriptor: " << (int)imageDescriptor << endl;
//    cout << "" << endl;

    input.close();

//    if (input.is_open()) {
//        cout << "its still open " << endl;
//    }
//    else {
//        cout << "Closed  " << endl << endl;
//    }


}

// Write
void Header::write(string name, unsigned char* pixels) {
    ofstream output(name + ".tga", ios_base::binary);

    output.write((char*)&idLength, sizeof(idLength));
    output.write((char*)&colorMapType,  sizeof(colorMapType));
    output.write((char*)&dataTypeCode, sizeof(dataTypeCode));
    output.write((char*)&colorMapOrigin, sizeof(colorMapOrigin));
    output.write((char*)&colorMapLength, sizeof(colorMapLength));
    output.write((char*)&colorMapDepth, sizeof(colorMapDepth));
    output.write((char*)&xOrigin, sizeof(xOrigin));
    output.write((char*)&yOrigin, sizeof(yOrigin));
    output.write((char*)&width, sizeof(width));
    output.write((char*)&height, sizeof(height));
    output.write((char*)&bitsPerPixel, sizeof(bitsPerPixel));
    output.write((char*)&imageDescriptor, sizeof(imageDescriptor));

    for (int i = 0; i <= size - 1; i++) {
        output.write((char*)&pixels[i], 1);
    }

//    cout << "ID Length: " << (int)idLength << endl;
//    cout << "Color Map Type: " << (int)colorMapType << endl;
//    cout << "Data Type Code: " << (int)dataTypeCode << endl;
//    cout << "Color Map Origin: " << (int)colorMapOrigin << endl;
//    cout << "Color Map Depth: " << (int)colorMapDepth << endl;
//    cout << "x Origin: " << (int)xOrigin << endl;
//    cout << "y Origin: " << (int)yOrigin << endl;
//    cout << "Width: " << width << endl;
//    cout << "Height: " << height << endl;
//    cout << "Bits Per Pixel: " << (int)bitsPerPixel << endl;
//    cout << "Image Descriptor: " << (int)imageDescriptor << endl;
//    cout << "" << endl;

    output.close();

}

unsigned char* Header::getPixelData() const{
    return pixelData;
}
int Header::getSize() const{
    return size;
}


