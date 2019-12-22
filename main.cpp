#include "CImg.h"
#include <iostream>

using namespace std;
using namespace cimg_library;

int main (const int argc, const char * argv[])
{
  //options
  cimg_usage("Retrieve command line arguments");
  const char* filename = cimg_option("-i","image.jpg","Input image file");
  const int height = cimg_option("-h",0,"desired height of the output image");
  const int width = cimg_option("-w",0,"desired width of the output image");
  const double scale = cimg_option("-s",0.0,"scale down the image with desired modifier");
  const char* newfile = cimg_option("-o","image_new.jpg","output image file");
  //creating cimg object
  CImg<unsigned char> img(filename);
  
  int width_s = img.width()*scale;
  int height_s = img.height()*scale;
  
  //scaledown options
  if(scale)
    {
      img.resize(width_s, height_s, 1, 3, 3);
      img.save(newfile);
    }
  
  //given width and height
  if(width &  height)
    {
      if(width<img.width() && height<img.height())
	{
	  img.resize(width, height, 1, 3, 3);
	  img.save(newfile);
	}
      else if(width>=img.width() || height>=img.height())
	{
	  img.resize(width, height, 1, 3, );
	  img.save(newfile);
	}
    }
  
  else if(width)
    {
      img.resize(width, img.height(), 1, 3, 3);
      img.save(newfile);
    }
  
  else if(height)
    {
      img.resize(img.width(),height, 1, 3, 3);
      img.save(newfile);
    }
  
  return 0;
}
