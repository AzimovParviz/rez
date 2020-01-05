#include "CImg.h"
#include <iostream>
#define cimg_use_png
#define cimg_use_jpeg
#define cimg_use_magick

using namespace std;
using namespace cimg_library;

int main (const int argc, const char * argv[])
{
  //options
  cimg_usage("Retrieve command line arguments");
  const char* filename = cimg_option("-i","image.jpg","Input image file");
  CImg<unsigned char> img(filename);
  const int height = cimg_option("-h",img.height(),"desired height of the output image");
  const int width = cimg_option("-w",img.width(),"desired width of the output image");
  const double scale = cimg_option("-s",1.0,"scale the image with desired modifier");
  const int rotate = cimg_option("-r",0,"rotate the image INT degrees");
  const int color = cimg_option("-c", img.spectrum(),"choose color scheme, default - unchanged, 1 - black and white, 3 - RGB, 4 - RGBA");
  const char* newfile = cimg_option("-o","image_new.jpg","output image file");
  //creating cimg object
  cout<<height<<" "<<width<<"h and w of the image kek"<<endl;
  if(rotate)
    img.rotate(rotate, 2);
  /* setting up interpolation type based on whenever the image is upscaled or downscaled*/
  if(height<img.height() || width<img.width() || scale<1.0)
    img.resize(height*scale,width*scale, 1, color, 6);//using cubic interpolation if upscaling
  else
    img.resize(height*scale,width*scale, 1, color, 3);//using linear if downscaling
  img.save(newfile);
  return 0;
}
