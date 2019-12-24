# rez - lightweight image resizing CLI tool
Single header program written only using C++

## Dependencies
xQuartz for any MacOS newer than Mountain Lion

ImageMagick on machines running *nix

Only works on Linux with xorg

## Compilation on MacOS with xQuartz installed through brew package manager (linking the X11 library location)
$ clang++ -I .. -I /usr/local/X11/include main.cpp -L /opt/X11/lib -lX11 -o rez
## Compilation on Linux as per cimg.eu
$ g++ -o rez main.cpp -Dcimg_use_png -O2 -L/usr/X11R6/lib -lm -lpthread -lX11 -lpng
## Example usage
$ ./rez -i test.png -h 480 -w 640 -o testnew.png 

$ ./rez -i test.jpg -s 0.3 -o testnew.jpg

$ ./rez -i test.png -s 0.5 -c 1 -o testnew.png 
