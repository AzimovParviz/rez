# rez - simple image resizing CLI tool
Single header program written only using C++

## Dependencies
libpng-dev and libjpeg-dev

libx11-dev if you get X11lib.h error

xQuartz for any MacOS newer than Mountain Lion

ImageMagick on machines running *nix

On Linux, it only works with xorg installed

I have absolutely no idea how to make this work on Windows, maybe when I install it one day I'll try but you are free to attempt to
## Compilation
Please edit Makefile accordingly if you did not install xQuartz on Mac through homebrew

$ make

## Example usage
$ ./rez -i test.png -h 480 -w 640 -o testnew.png 

$ ./rez -i test.jpg -s 0.3 -o testnew.jpg

$ ./rez -i test.png -s 0.5 -c 1 -o testnew.png 
