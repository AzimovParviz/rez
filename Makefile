UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
rez: main.cpp CImg.h
	g++ -o rez main.cpp -Dcimg_use_png -O2 -L/usr/X11R6/lib -lm -lpthread -lX11 -lpng
endif
ifeq ($(UNAME), Darwin)
rez: main.cpp CImg.h
	clang++ -I .. -I /usr/local/X11/include main.cpp -Dcimg_use_png -L /opt/X11/lib -lX11 -lpng -o rez
endif
