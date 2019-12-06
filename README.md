#Compilation
clang++ -I .. -I /usr/local/X11/include main.cpp -L /opt/X11/lib -lX11 -Dcimg_display=0 -o rez
