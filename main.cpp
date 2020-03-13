#define cimg_use_png 1
#define cimg_use_jpeg 1
#include "CImg.h"
#include <iostream>

using namespace std;
using namespace cimg_library;

int main (const int argc, const char * argv[])
{
  //options
  cimg_usage("Retrieve command line arguments");
  const char* filename = cimg_option("-i","image.jpg","Input image file");
  CImg<unsigned char> img(filename);  //creating cimg object
  const int width = cimg_option("-w",img.width(),"desired width of the output image");
  const int height = cimg_option("-h",img.height(),"desired height of the output image");
  const double scale = cimg_option("-s",1.0,"scale the image with desired modifier");
  const int rotate = cimg_option("-r",0,"rotate the image INT degrees");
  const int color = cimg_option("-c", img.spectrum(),"choose color scheme, default - unchanged, 1 - black and white, 3 - RGB, 4 - RGBA");
  const char* newfile = cimg_option("-o","image_new.jpg","output image file");
  cout<<width<<" "<<height<<" width and height of the input image and "<<color<<" is the channel number"<<endl;
  if(rotate)
    img.rotate(rotate, 2);
  /* setting up interpolation type (6 - cubic, 3 - linear) based on whenever the image is upscaled or downscaled*/
  if(height<img.height() || width<img.width() || scale<1.0)
    img.resize(width*scale,height*scale, 1, color, 6);//using cubic interpolation if upscaling
  else
    img.resize(width*scale,height*scale, 1, color, 3);//using linear if downscaling
  cout<<img.width()<<" "<<img.height()<<" width and height of the output image and "<<img.spectrum()<<" is the channel number"<<endl;
  img.save(newfile);
  return 0;
}
