//#define cimg_display 0;
#include "CImg.h"
#include <iostream>
//#include <string>

using namespace std;
using namespace cimg_library;

int main (const int argc, const char * argv[])
{
  cimg_usage("Retrieve command line arguments");
  const char* filename = cimg_option("-i","image.jpg","Input image file");
  const int height = cimg_option("-h",480,"desired height of the output image");
  const int width = cimg_option("-w",640,"desired width of the output image");
  const double scale = cimg_option("-s",0.5,"scale down the image with desired modifier");
  const char* newfile = cimg_option("-o","image_new.jpg","output image file");
  CImg<unsigned char> img(filename);
  if(scale)
    {
      int width_s = img.width()*scale;
      int height_s = img.height()*scale;
      img.resize(width_s, height_s);
      img.save(newfile);
    }
  else
    {
    img.resize(width, height);
    img.save(newfile);
    }
  return 0;
}
