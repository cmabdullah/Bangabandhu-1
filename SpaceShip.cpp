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
/*******
g++
-I/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers
-I/usr/include -I/Library/Developer/CommandLineTools/usr/lib/llvm-gcc/4.2.1/include
-I/usr/include/c++/4.2.1/backward -I/usr/include/c++/4.2.1 -I/usr/local/Cellar/llvm/4.0.1/include
-I/System/Library/Frameworks/GLUT.framework/Versions/A/Headers
-O0 -g3 -Wall -c -fmessage-length=0
-arch i386 -MMD -MP  -MF"SpceShip"
-MT"SpceShip.o"  "SpceShip.o"  "SpceShip.cpp"
 */
/***
g++ -L/usr/X11/lib -arch i386 -o  "SpceShip"  "SpceShip.o"  -lglu -lgl -lglut
 * */

/***
 * -arch i386
 * op1
 * op2
 * op3
 * */
/**
-+,xy	|	++
		|
--------------------
		|
--		|	+-
***/

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>

#define PI 3.1416

float animx=0;
float animy=0;
void rectangle( float r, float g, float b,  float ulx, float uly, float urx, float ury,  float brx, float bry,  float blx, float bly){
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(ulx,uly);
    glVertex2f(urx,ury);
    glVertex2f(brx,bry);
    glVertex2f(blx,bly);
    glEnd();
}

void triangle( float r, float g, float b, float lx, float ly,float rx, float ry, float tbx, float tby){
    glColor3f(r,g,b);
    glBegin(GL_TRIANGLES);
    glVertex2f(lx,ly);
    glVertex2f(rx,ry);
    glVertex2f(tbx,tby);
    glEnd();
}

void frem(){
	rectangle(0.4,0.0,0.0, 0.01,-0.80,  0.02,-0.81, 0.02,-0.99, 0.01,-0.99);
	rectangle(0.4,0.0,0.0, 0.01,-0.80,  0.3,-0.80, 0.29,-0.81, 0.02,-0.81);
	rectangle(0.4,0.0,0.0, 0.29,-0.81,  0.30,-0.80, 0.30,-0.99, 0.29,-0.99);
}
void boat2(){

	//body
	rectangle(0.4,0.0,0.0, 0.10,-0.70,  0.20,-0.70, 0.20,-0.90, 0.10,-0.90);
	//bonet
	triangle(0,0.5,0.5,   0.10,-0.7,   0.20,-0.7,   0.15,-0.57);
	//Wings right top
	triangle(0,0.5,0.5,   0.20,-0.75,   0.25,-0.75,   0.20,-0.70);
	//Wings left top
	triangle(0,0.5,0.5,   0.05,-0.75,   0.10,-0.75,   0.10,-0.70);
	//Wings right bottom
	triangle(0,0.5,0.5,   0.20,-0.90,   0.25,-0.93,   0.20,-0.82);
	//Wings left bottom
	triangle(0,0.5,0.5,   0.05,-0.93,   0.10,-0.90,   0.10,-0.82);
	//Exhaust left
	triangle(0,0.5,0.5,   0.10,-0.90,   0.12,-0.90,   0.11,-0.95);
	//Exhaust right
	triangle(0,0.5,0.5,   0.18,-0.90,   0.20,-0.90,   0.19,-0.95);
	//Exhaust middel
	triangle(0,0.5,0.5,   0.13,-0.90,   0.17,-0.90,   0.15,-0.97);



}
void box2(){
	rectangle(0.4,0.5,0.60, 0.20,-0.60, 0.20,-0.70, 0.30,-0.70, 0.30,-0.60);
}


void box(){
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(1,1,0);
    rectangle(0.4,0.5,0.60, 0.20,-0.60, 0.20,-0.70, 0.30,-0.70, 0.30,-0.60);
    glPopMatrix();
}

void init(){
	//screen color setup
	    glClearColor(0.0,0.0,0.0,1.0);
	    //glClear(GL_COLOR_BUFFER_BIT);
	glOrtho(0,1, -1,0, 0,1);
}
void myDisplay(){

    glClear(GL_COLOR_BUFFER_BIT);
    frem();
    box2();
    boat2();


    glPushMatrix();
    glTranslated(animx,animy,0);
    box();
    glPopMatrix();

    if(animy<=0.5){
    	animy=animy+0.0005;
    }
       glutPostRedisplay();

	glFlush();

}

int main(int argc,char*argv[]){
glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(466,466);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Demo App");
	init();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
