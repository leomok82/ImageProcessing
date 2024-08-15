# Advanced Programming Project
This is a versatile tool for processing both 2D and 3D image data, offering a range of features including filters, color correction, volume slicing, and projections.


# CT Scans
Download CT Scan datasets here:
*Redacted*

## Prerequisites

* C++17 Compiler

## Compiling the tool from command line

Go to the ./src directory by running the following command on the command line:
```
cd src
```

```
g++ *.cpp -std=c++17
```

To run tests you should be inside the test folder
```
g++ -O3 -o test *.cpp ../src/*.cpp -std=c++17
```

**Enter the Image path when prompted**

Based on your choice, the subsequent options relevant would be printed. Continue picking the desired options.

**The main menu**
* 1 for 2D Image type
* 2 for 3D Image type
* 3 for Exit

## 2D Image Types

### 2D Filters

Apply various filters including:

##### 1.Colour Correction:
* Grayscale
* Brightness
* Histogram Equalisation
* Thresholding
* Salt and Pepper Noise

##### 2.Image Blur:
* Median
* Box
* Gaussian

##### 3.Egde Detection:
* Sobel
* Prewitt
* Scharr
* Robert's Cross
* End

## 3D Image Types

### 3D Filters

You can choose to perform various operations:
1. Apply 3D filter:
* 3D Gaussian Filter
* 3D Median Filter
2. Slice volume
3. Apply projection
4. Finish processing

## Save Image
After applying filters, save the generated image as a png file by entering the output location filepath.

## Documentation

The documentation for all the functions can be found in html format at

```
./doc/html/index.html
```

Or be generated on your system by running 

```
cd doc
doxygen dconfig
```
Note: Require doxygen and its dependencies to be installed.
