# rez - simple image resizing CLI tool
Single header program written only using C++

## Dependencies
xQuartz for any MacOS newer than Mountain Lion

ImageMagick on machines running *nix

Only works on Linux with xorg

## Compilation
Please edit Makefile accordingly if you did not install xQuartz on Mac through homebrew

$ make

## Example usage
$ ./rez -i test.png -h 480 -w 640 -o testnew.png 

$ ./rez -i test.jpg -s 0.3 -o testnew.jpg

$ ./rez -i test.png -s 0.5 -c 1 -o testnew.png 
