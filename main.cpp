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
  const int height = cimg_option("-h",0,"desired height of the output image");
  const int width = cimg_option("-w",0,"desired width of the output image");
  const double scale = cimg_option("-s",0.0,"scale the image with desired modifier");
  const int color = cimg_option("-c", 0,"choose color scheme, 0 - unchanged, 1 - black and white");
  const char* newfile = cimg_option("-o","image_new.jpg","output image file");
  //creating cimg object
  CImg<unsigned char> img(filename);

  int width_s = img.width()*scale;
  int height_s = img.height()*scale;
  
  //scaling options
  if(scale)
    {
      switch(color)
      {
      case 0:
	img.resize(width_s, height_s, 1, img.spectrum(), 3);
	img.save(newfile);
	break;
      case 1://black and white
	img.resize(width_s, height_s, 1, 1, 3);
	img.save(newfile);
	break;
      default://default is keep color settings
	img.resize(width_s, height_s, 1, img.spectrum(), 3);
	img.save(newfile);
	break;
      }
    }
  
  //given width and height
  if(width & height)
    {
      switch(color)
	{	
	case 0:
	  if(width<img.width() && height<img.height())
	    {
	      img.resize(width, height, 1, img.spectrum(), 3);
	      img.save(newfile);
	    }	
	else if(width>=img.width() || height>=img.height())
	  {
	    img.resize(width, height, 1, img.spectrum(), 6);
	    img.save(newfile);
	  }
	break;	
	case 1://b&w
	  if(width<img.width() && height<img.height())
	    {
	      img.resize(width, height, 1, 1, 3);
	      img.save(newfile);
	    }	
	else if(width>=img.width() || height>=img.height())
	  {
	    img.resize(width, height, 1, 1, 6);
	    img.save(newfile);
	  }      
	  break;      	
      default:
	if(width<img.width() && height<img.height())
	  {
	    img.resize(width, height, 1, img.spectrum(), 3);
	    img.save(newfile);
	  }	
	else if(width>=img.width() || height>=img.height())
	  {
	    img.resize(width, height, 1, img.spectrum(), 6);
	    img.save(newfile);
	  }
	}
    } 
  
  
  //if only width is provided
  else if(width)
    {
      switch(color){
      case 0:
	if(width<img.width())
	  {
	    img.resize(width, img.height(), 1, img.spectrum(), 3);
	    img.save(newfile);
	  }
	else if(width>img.width())
	  {
	    img.resize(width, img.height(), 1, img.spectrum(), 6);
	    img.save(newfile);
	  }
	break;
      case 1://black&white
	if(width<img.width())
	  {
	    img.resize(width, img.height(), 1, 1, 3);
	    img.save(newfile);
	  }
	else if(width>img.width())
	  {
	    img.resize(width, img.height(), 1, 1, 6);
	    img.save(newfile);
	  }
	break;
      default:
	if(width<img.width())
	  {
	    img.resize(width, img.height(), 1, img.spectrum(), 3);
	    img.save(newfile);
	  }
	else if(width>img.width())
	  {
	    img.resize(width, img.height(), 1, img.spectrum(), 6);
	    img.save(newfile);
	  }
	break;
      }
    }
  
  //if only height is provided
  else if(height)
    {
      switch(color){
      case 0:
	if(height<img.height())
	  {
	    img.resize(img.width(),height, 1, img.spectrum(), 3);
	    img.save(newfile);
	  }
	else if(height>=img.height())
	  {
	    img.resize(img.width(),height,1, img.spectrum(), 6);
	    img.save(newfile);
	  }
	break;
      case 1://b&w
	if(height<img.height())
	  {
	    img.resize(img.width(),height, 1, 1, 3);
	    img.save(newfile);
	  }
	else if(height>=img.height())
	  {
	    img.resize(img.width(),height,1, 1, 6);
	    img.save(newfile);
	  }
	break;
      default://normal colour
	if(height<img.height())
	  {
	    img.resize(img.width(),height, 1, img.spectrum(), 3);
	    img.save(newfile);
	  }
	else if(height>=img.height())
	  {
	    img.resize(img.width(),height,1, img.spectrum(), 6);
	    img.save(newfile);
	  }
	break;
      }
    }
      
  return 0;
}
