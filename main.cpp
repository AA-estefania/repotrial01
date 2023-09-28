#include<iostream>
#include "Image.h"

using namespace std;



//Check the files are the same
bool equal(const string& fileOne, const string& fileTwo){

    Header one (fileOne);
    Header two (fileTwo);

    bool equal = true;

    if (one.idLength == two.idLength) {
        //cout << "idLength same" << endl;

    }
    else {
        //cout << "idLength different" << endl;
        return false;
    }
    if (one.colorMapType == two.colorMapType) {
        //cout << "colorMapType same" << endl;

    }
    else {
        //cout << "colorMapType  different " << endl;
        return false;
    }
    if (one.dataTypeCode == two.dataTypeCode) {
        //cout << "dataTypeCode same" << endl;

    }
    else {
        //cout << "dataTypeCode different" << endl;
        return false;
    }
    if (one.colorMapOrigin == two.colorMapOrigin) {
        //cout << "colorMapOrigin same" << endl;

    }
    else {
        //cout << "colorMapOrigin different" << endl;
        return false;
    }
    if (one.colorMapLength == two.colorMapLength) {
        //cout << "colorMapLength same" << endl;

    }
    else {
        //cout << "colorMapLength different" << endl;
        return false;
    }
    if (one.colorMapDepth == two.colorMapDepth) {
        //cout << "colorMapDepth same" << endl;

    }
    else {
        //cout << "colorMapDepth different" << endl;
        return false;
    }
    if (one.xOrigin == two.xOrigin) {
        //cout << "xOrigin same" << endl;

    }
    else {
        //cout << "xOrigin different" << endl;
        return false;
    }
    if (one.yOrigin == two.yOrigin) {
        //cout << "yOrigin same" << endl;

    }
    else {
        //cout << "yOrigin different" << endl;
        return false;
    }
    if (one.width == two.width) {
        //cout << "width same" << endl;

    }
    else {
        //cout << "width different" << endl;
        return false;
    }
    if (one.height == two.height) {
        //cout << "height same" << endl;

    }
    else {
        //cout << "height different" << endl;
        return false;
    }
    if (one.bitsPerPixel == two.bitsPerPixel) {
        //cout << "bitsPerPixel same" << endl;

    }
    else {
        //cout << "bitsPerPixel different" << endl;
        return false;
    }
    if (one.imageDescriptor == two.imageDescriptor) {
        //cout << "imageDescriptor same" << endl;

    }
    else {
        cout << "imageDescriptor different" << endl;
        return false;
    }

    return equal;
}


//Avoid overflow for float variable
float overflowFloat(float& temp) {
    if (temp < 0) {
        temp = 0;
    }
    else if (temp > 255) {
        temp = 255;
    }
    else {
        temp = temp;
    }
    return temp;
}

//Avoid overflow for int variable
int overflowInt(int& temp) {
    if (temp < 0) {
        temp = 0;
    }
    else if (temp > 255) {
        temp = 255;
    }
    else {
        temp = temp;
    }
    return temp;
}


//Test
void Tests() {

    if (equal("examples/EXAMPLE_part1.tga", "output/part1.tga"))
    {
        cout<<"Test 1 Passed"<<endl;

    }
    else {
        cout<< "Test 1 Failed"<<endl;

    }

    if (equal("examples/EXAMPLE_part2.tga", "output/part2.tga")) {
        cout << "Test 2 Passed" << endl;

    }
    else {
        cout << "Test 2 Failed" << endl;

    }

    if (equal("examples/EXAMPLE_part3.tga", "output/part3.tga")) {
        cout << "Test 3 Passed" << endl;

    }
    else {
        cout << "Test 3 Failed" << endl;

    }

    if (equal("examples/EXAMPLE_part4.tga", "output/part4.tga")) {
        cout << "Test 4 Passed" << endl;

    }
    else {
        cout << "Test 4 Failed" << endl;

    }

    if (equal("examples/EXAMPLE_part5.tga", "output/part5.tga")) {
        cout << "Test 5 Passed" << endl;

    }
    else {
        cout << "Test 5 Failed" << endl;

    }

    if (equal("examples/EXAMPLE_part6.tga", "output/part6.tga")) {
        cout << "Test 6 Passed" << endl;

    }
    else {
        cout << "Test 6 Failed" << endl;

    }

    if (equal("examples/EXAMPLE_part7.tga", "output/part7.tga")) {
        cout << "Test 7 Passed" << endl;

    }
    else {
        cout << "Test 7 Failed" << endl;

    }

    //red
    if (equal("examples/EXAMPLE_part8_r.tga", "output/part8_r.tga")) {
        cout << "Test 8 Red Passed" << endl;

    }
    else {
        cout << "Test 8 Red Failed" << endl;

    }

    //green
    if (equal("examples/EXAMPLE_part8_g.tga", "output/part8_g.tga")) {
        cout << "Test 8 Green Passed" << endl;

    }
    else {
        cout << "Test 8 Green Failed" << endl;

    }

    //blue
    if (equal("examples/EXAMPLE_part8_b.tga", "output/part8_b.tga")) {
        cout << "Test 8 Blue Passed" << endl;

    }
    else {
        cout << "Test 8 Blue Failed" << endl;

    }

    if (equal("examples/EXAMPLE_part9.tga", "output/part9.tga")) {
        cout << "Test 9 Passed" << endl;

    }
    else {
        cout << "Test 9 Failed" << endl;
        cout << "" << endl;
    }

    if (equal("examples/EXAMPLE_part10.tga", "output/part10.tga")) {
        cout << "Test 10 Passed" << endl;

    }
    else {
        cout << "Test 10 Failed" << endl;

    }

}


int main(){

    int size;
    int count;

    unsigned char* image1Pixels;
    unsigned char* image2Pixels;
    unsigned char* image3Pixels;
    unsigned char* totalPixels;

    //Part 1
    // Use the Multiply blending mode to combine “layer1.tga” (top layer) with “pattern1.tga” (bottom layer)

    // Load  images
    Header layer1_1("input/layer1.tga");
    Header pattern1_1("input/pattern1.tga");

    image1Pixels = layer1_1.getPixelData();
    image2Pixels = pattern1_1.getPixelData();
    totalPixels = image2Pixels;
    size = layer1_1.getSize();

    for (int i = 0; i <= size - 1; i++) {
        auto pixel1 = (float)image1Pixels[i] / 255;
        auto pixel2 = (float)image2Pixels[i] / 255;
        float pixelCombo = (pixel1 * pixel2 * 255) + .5f;
        totalPixels[i] = (unsigned char)pixelCombo;
    }
    layer1_1.write("output/part1",totalPixels);


    //Part 2
    // Use Subtract blending mode to combine “layer2.tga” (top layer) with “car.tga” (bottom layer). This mode subtracts the top layer from the bottom layer.

    // Load  images
    Header layer2_1("input/layer2.tga");
    Header car_1("input/car.tga");

    image1Pixels = layer2_1.getPixelData();
    totalPixels = image1Pixels;
    image2Pixels = car_1.getPixelData();
    size = layer2_1.getSize();

    for (int i = 0; i < size; i++) {
        int pixel1 = (int)image1Pixels[i];
        int pixel2 = (int)image2Pixels[i];
        int pixelCombo = pixel2 - pixel1;
        pixelCombo = overflowInt(pixelCombo);
        totalPixels[i] = (unsigned char)pixelCombo;
    }
    layer2_1.write("output/part2", totalPixels);



    //Part 3
    // Use the Multiply blending mode to combine “layer1.tga” with “pattern2.tga”, and store the results temporarily.
    // Load the image “text.tga” and, using that as the top layer, combine it with the previous results of layer1/pattern2 using the Screen blending mode.

    // Load  images
    Header layer1_2("input/layer1.tga");
    Header pattern2_1("input/pattern2.tga");
    Header text("input/text.tga");

    image1Pixels = layer1_2.getPixelData();
    image2Pixels = pattern2_1.getPixelData();
    size = pattern2_1.getSize();

    for (int i = 0; i <= size - 1; i++) {
        auto pixel1 = (float)image1Pixels[i] / 255;
        auto pixel2 = (float)image2Pixels[i] / 255;
        float pixelCombo = (pixel1 * pixel2 * 255) + .5f;
        totalPixels[i] = (unsigned char)pixelCombo;
    }
    image3Pixels = text.getPixelData();
    for (int i = 0; i <= size - 1; i++) {
        auto pixel1 = (float)totalPixels[i] / 255;
        auto pixel2 = (float)image3Pixels[i] / 255;
        float pixelCombo = ((1 - (1 - pixel1) * (1 - pixel2)) * 255)+.5f;
        totalPixels[i] = (unsigned char)pixelCombo;
    }
    text.write("output/part3", totalPixels);


    //Part 4
    // Multiply “layer2.tga” with “circles.tga”, and store it. Load “pattern2.tga” and, using that as the top layer,
    // combine it with the previous result using Subtract blending mode.

    // Load  images
    Header layer2_2("input/layer2.tga");
    Header circles_1("input/circles.tga");
    Header pattern2_2("input/pattern2.tga");

    image1Pixels = layer2_2.getPixelData();
    image2Pixels = circles_1.getPixelData();
    size = circles_1.getSize();

    for (int i = 0; i <= size - 1; i++) {
        auto pixel1 = (float)image1Pixels[i] / 255;
        auto pixel2 = (float)image2Pixels[i] / 255;
        float pixelMultiply = (pixel1 * pixel2 * 255) + .5f;
        totalPixels[i] = (unsigned char)pixelMultiply;
    }
    image3Pixels = pattern2_2.getPixelData();
    for (int i = 0; i <= size - 1; i++) {
        auto pixel1 = (float)totalPixels[i];
        auto pixel2 = (float)image3Pixels[i];
        int pixelSubtract = pixel1 - pixel2;
        pixelSubtract = overflowInt(pixelSubtract);
        totalPixels[i] = (unsigned char)pixelSubtract;

    }
    pattern2_2.write("output/part4", totalPixels);



    //Part 5
    // Combine “layer1.tga” (as the top layer) with “pattern1.tga” using the Overlay blending mode.

    // Load  images
    Header layer1_3("input/layer1.tga");
    Header pattern1_2("input/pattern1.tga");

    image1Pixels = layer1_3.getPixelData();
    image2Pixels = pattern1_2.getPixelData();
    size = pattern1_2.getSize();

    float pixelOverlay;
    for (int i = 0; i <= size - 1; i++) {
        auto pixel1 = (float)image1Pixels[i] / 255;
        auto pixel2 = (float)image2Pixels[i] / 255;
        if (pixel2 <= .5) {
            pixelOverlay = (2 * pixel1 * pixel2 * 255) + .5f;
            pixelOverlay = overflowFloat(pixelOverlay);
            totalPixels[i] = (unsigned char)pixelOverlay;
        }
        else {
            pixelOverlay = (1 - 2 * (1 - pixel1) * (1 - pixel2)) * 255 + 0.5f;
            pixelOverlay = overflowFloat(pixelOverlay);
            totalPixels[i] = (unsigned char)pixelOverlay;
        }
    }
    layer1_3.write("output/part5", totalPixels);



    //Part 6
    // Load “car.tga” and add 200 to the green channel.

    // Load  images
    Header car2("input/car.tga");

    image1Pixels = car2.getPixelData();
    size = car2.getSize();

    for (int i = 0; i <= size - 1; i++) {
        totalPixels[i] = image1Pixels[i];
    }
    for (int i = 1; i <= size - 1; i += 3) {
        int pixel = image1Pixels[i] + 200;
        pixel = overflowInt(pixel);
        totalPixels[i] = pixel;
    }
    car2.write("output/part6", totalPixels);



    //Part 7
    // Load “car.tga” and scale (multiply) the red channel by 4, and the blue channel by 0.
    // This will increase the intensity of any red in the image, while negating any blue it may have.

    // Load  images
    Header car3("input/car.tga");

    image1Pixels = car3.getPixelData();

    //red
    for (int i = 0; i <= size - 1; i++) {
        totalPixels[i] = image1Pixels[i];
    }
    for (int i = 2; i <= size - 1; i += 3) {
        int pixel = image1Pixels[i] * 4;
        pixel = overflowInt(pixel);
        totalPixels[i] = pixel;
    }

    //blue
    for (int i = 0; i <= size - 1; i += 3) {
        int pixel = totalPixels[i] * 0;
        pixel = overflowInt(pixel);
        totalPixels[i] = pixel;
    }
    car3.write("output/part7", totalPixels);



    //Part 8
    // Load “car.tga” and write each channel to a separate file:
    // the red channel should be “part8_r.tga”, the green channel should be “part8_g.tga”, and the blue channel should be  “part8_b.tga”
    // (Hint: If your red channel image appears all red, try writing [Red, Red, Red] instead of [Red, 0, 0] to the file—ditto for green and blue!)

    // Load  images
    Header car4("input/car.tga");

    image1Pixels = car3.getPixelData();
    auto* pixel = new unsigned char[car4.getSize()];

    //red
    count = 0;
    for (unsigned int i = 2; i < car4.getSize(); i += 3) {
        pixel[count] = image1Pixels[i];
        pixel[count + 1] = image1Pixels[i];
        pixel[count + 2] = image1Pixels[i];
        count += 3;
    }
    car4.write("output/part8_r", pixel);

    //green
    count = 0;
    for (unsigned int i = 1; i < car4.getSize(); i += 3) {
        pixel[count] = image1Pixels[i];
        pixel[count + 1] = image1Pixels[i];
        pixel[count + 2] = image1Pixels[i];
        count += 3;
    }
    car4.write("output/part8_g", pixel);

    //blue
    count = 0;
    for (unsigned int i = 0; i < car4.getSize(); i += 3) {
        pixel[count] = image1Pixels[i];
        pixel[count + 1] = image1Pixels[i];
        pixel[count + 2] = image1Pixels[i];
        count += 3;
    }
    car4.write("output/part8_b", pixel);



    //Part 9
    // Load “layer_red.tga”, “layer_green.tga” and “layer_blue.tga”, and combine the three files into one file.
    // The data from “layer_red.tga” is the red channel of the new image, layer_green is green, and layer_blue is blue.

    // Load  images
    Header layerRed("input/layer_red.tga");
    Header layerGreen("input/layer_green.tga");
    Header layerBlue("input/layer_blue.tga");

    image1Pixels = layerRed.getPixelData();
    image2Pixels = layerGreen.getPixelData();
    image3Pixels = layerBlue.getPixelData();

    for (unsigned int i = 2; i < layerRed.getSize(); i += 3) {
        totalPixels[i] = image1Pixels[i];
    }
    for (unsigned int i = 1; i < layerRed.getSize(); i += 3) {
        totalPixels[i] = image2Pixels[i];
    }
    for (unsigned int i = 0; i < layerRed.getSize(); i += 3) {
        totalPixels[i] = image3Pixels[i];
    }
    layerRed.write("output/part9", totalPixels);



    //Part 10
    // Load “text2.tga”, and rotate it 180 degrees, flipping it upside down.

    // Load  images
    Header text2("input/text2.tga");

    image1Pixels = text2.getPixelData();
    count = 0;

    for (int i = text2.getSize() - 1; i >= 0; i--) {
        totalPixels[i] = image1Pixels[count];
        count++;
    }
    text2.write("output/part10", totalPixels);

    Tests();

    return 0;
}


