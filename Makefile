UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
rez: main.cpp CImg.h
	g++ `Magick++-config --cxxflags --cppflags` -o rez main.cpp  -O2 -L/usr/X11R6/lib -lm -lpthread -lX11 -lpng -ljpeg `Magick++-config --ldflags --libs`
endif
ifeq ($(UNAME), Darwin)
rez: main.cpp CImg.h
	clang++ -I .. -I /usr/local/X11/include main.cpp -L /opt/X11/lib -lX11 -lpng -ljpeg -o rez
endif
