#rez - lightweight image resizing CLI tool
Single header program written only using C++
#Dependencies
xQuartz for any MacOS newer than Mountain Lion
Only works on Linux with xorg
#Compilation on MacOS with xQuartz installed through brew package manager (linking the X11 library location)
clang++ -I .. -I /usr/local/X11/include main.cpp -L /opt/X11/lib -lX11 -o rez
#Example usage
./rez -i test.png -h 480 -w 640 -o testkik.png
