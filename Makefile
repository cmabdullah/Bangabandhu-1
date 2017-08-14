APPNAME = SpceShip
CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		${APPNAME}.o

LIBS =

LDFLAGS = -framework GLUT -framework OpenGL 

$(APPNAME):	$(OBJS)
	g++ -o $(APPNAME) $(OBJS) $(LIBS) $(LDFLAGS)

all:	$(APPNAME)

clean:
	rm -f $(OBJS) $(APPNAME)
