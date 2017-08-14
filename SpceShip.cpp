//============================================================================
// Name        : SpaceShip.cpp
// Author      : C M Abdullah Khan
// Version     : 1.1
// Copyright   : OpenSource
// Compiler    : Eclipse CDT ( C/C++ Development Tools)
// Problem     : Project no 3
// Description : Hello World in C, Ansi-style
// Date        : 20-07-17
//============================================================================

/***
➜  ~ gcc --version
Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 8.0.0 (clang-800.0.42.1)
Target: x86_64-apple-darwin16.3.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin

➜  ~ cd
➜  ~ cd /Library/Developer/CommandLineTools/usr/include
➜  include pwd
/Library/Developer/CommandLineTools/usr/include

➜  ~ cd
➜  ~ cd /Library/Developer/CommandLineTools/usr/include/c++/v1
➜  v1 pwd
/Library/Developer/CommandLineTools/usr/include/c++/v1

➜  v1 ../../
➜  include ../
➜  lib clang
clang: error: no input files
➜  lib cd clang
➜  clang ls
8.0.0
➜  clang cd 8.0.0
➜  8.0.0 ls
asan_blacklist.txt include            lib
➜  8.0.0 include
➜  include pwd
/Library/Developer/CommandLineTools/usr/lib/clang/8.0.0/include

➜  ~ cd
➜  ~ cd /Library/Frameworks
➜  Frameworks pwd
/Library/Frameworks

➜  ~ cd
➜  ~ cd /System/Library/Frameworks
➜  Frameworks pwd
/System/Library/Frameworks

➜  ~ cd
➜  ~ cd /usr/include
➜  include pwd
/usr/include

➜  ~ cd
➜  ~ cd /usr/local/include
➜  include pwd
/usr/local/include




//caution IDE must know this library Path....
/Library/Developer/CommandLineTools/usr/include
/Library/Developer/CommandLineTools/usr/include/c++/v1
/Library/Developer/CommandLineTools/usr/lib/clang/8.0.0/include
/Library/Frameworks
/System/Library/Frameworks
/usr/include
/usr/local/include

**/

/**** RUN FROM TERMINAL   *****/
/***
➜  SpceShip pwd
/Users/abdullah/desktop/GraphicsTesting
➜  SpceShip ls
Makefile           problem_opengl.cpp
➜  SpceShip cat Makefile
APPNAME = problem_opengl

CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		${APPNAME}.o

LIBS =

LDFLAGS = -framework GLUT -framework OpenGL

$(APPNAME):	$(OBJS)
	g++ -o $(APPNAME) $(OBJS) $(LIBS) $(LDFLAGS)

all:	$(APPNAME)

clean:
	rm -f $(OBJS) $(APPNAME)

➜  SpceShip ls
Makefile           problem_opengl.cpp
➜  SpceShip make all
c++ -O2 -g -Wall -fmessage-length=0   -c -o problem_opengl.o problem_opengl.cpp

➜  SpceShip ls
Makefile           problem_opengl     problem_opengl.cpp problem_opengl.o
➜  SpceShip ./problem_opengl
➜  SpceShip make all
make: Nothing to be done for `all'.

 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


void init(){
	glClearColor(2.0f,2.0f,1.0f,1.0f);
	glOrtho(-30,30,-30,30,-30,30);
}
void myDisplay(){

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f ,0.0f, 0.0f);//print vertical red
	glBegin(GL_QUADS);
		glVertex3d(-1.0,9.0,0.0);
		glVertex3d(-1.0,-9.0,0.0);
		glVertex3d(1.0,-9.0,0.0);
		glVertex3d(1.0,9.0,0.0);
	glEnd();

	glFlush();
}

int main(int argc,char*argv[]){
glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(200,200);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Demo App");
	init();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
