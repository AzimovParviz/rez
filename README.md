#rez - lightweight image resizing CLI tool
Single header program written only using C++
#Compilation on MacOS with xQuartz installed through brew package manager
clang++ -I .. -I /usr/local/X11/include main.cpp -L /opt/X11/lib -lX11 -Dcimg_display=0 -o rez
