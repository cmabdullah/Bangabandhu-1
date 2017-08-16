APPNAME = SpaceShip
CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		${APPNAME}.o

LIBS = -lGL -lGLU -lglut
ifeq "$(APPNAME)" "SpaceShip"
LDFLAGS = -framework GLUT -framework OpenGL -framework Carbon -framework Cocoa -L/usr/X11/lib -lglu -lgl -lglut 
CFLAGS += -D__APPLE__
endif  
$(APPNAME):	$(OBJS)
	g++ -o $(APPNAME) $(OBJS) $(LIBS) $(LDFLAGS) 

all:	$(APPNAME)

clean:
	rm -f $(OBJS) $(APPNAME)
