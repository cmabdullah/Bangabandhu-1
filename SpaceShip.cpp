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
float animxT=0;
float animyT=0;
float animxB=0;
float animyB=0;
void circle(float r, float g, float b, float x, float y, float init, float last, float radx, float rady){
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    for(float i=init;i<=last;i++)
    {
        float j=(i*PI)/180;
        glVertex2f(x+(radx*cos(j)),y+(rady*sin(j)));
    }
    glEnd();

}
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
void rocketTop(){

	//body top
	rectangle(0.4,0.0,0.0, 0.10,-0.70,  0.20,-0.70, 0.20,-0.82, 0.10,-0.82);

	//bonet
	triangle(0,0.5,0.5,   0.10,-0.7,   0.20,-0.7,   0.15,-0.57);
	//Wings right top
	triangle(0,0.5,0.5,   0.20,-0.75,   0.25,-0.75,   0.20,-0.70);
	//Wings left top
	triangle(0,0.5,0.5,   0.05,-0.75,   0.10,-0.75,   0.10,-0.70);
	//body bottom

}

void rocketBottom(){

	//body bottom
	rectangle(0.4,1.0,1.0, 0.10,-0.82,  0.20,-0.82, 0.20,-0.90, 0.10,-0.90);
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

void field(){
	rectangle(0.957, 0.643, 0.376, 0.01,-0.66, 0.99,-0.66, 0.99,-0.99, 0.01,-0.99);
}
void sky(){
	rectangle(0.000, 1.000, 0.000, 0.01,-0.66, 0.99,-0.66, 0.99,-0.01, 0.01,-0.01);
}
void DarkSky(){
	rectangle(0.0, 0.0, 0.0, 0.01,-0.01, 0.99,-0.01, 0.99,-0.99, 0.01,-0.99);
}
void house(){
	rectangle(0.0,1.5,1.60, 0.85,-0.57, 0.93,-0.57, 0.93,-0.66, 0.85,-0.66);
}

void tree(){
	rectangle(0.0,1.5,1.60,  0.69,-0.60, 0.71,-0.60, 0.71,-0.66, 0.69,-0.66);
	triangle(0,0.5,0.5,   0.71,-0.60,   0.72,-0.59,   0.75,-0.59);
	triangle(0,0.5,0.5,   0.69,-0.60,   0.71,-0.60,   0.70,-0.55);
	triangle(0,0.5,0.5,   0.69,-0.60,   0.68,-0.59,   0.65,-0.59);

}



void box(){
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(1,.8,0);
    rectangle(0.4,0.5,0.60, 0.20,-0.60, 0.20,-0.70, 0.30,-0.70, 0.30,-0.60);
    glPopMatrix();
}
void box2(){
	rectangle(0.4,0.5,0.60, 0.20,-0.60, 0.20,-0.70, 0.30,-0.70, 0.30,-0.60);
}
void box3(){
	glPushMatrix();
	box();
	glTranslated(0,0.1,0);
	glPopMatrix();
}


void box4(){
	glPushMatrix();
	box();
	glTranslated(0,0.3,0);
	glPopMatrix();
}


void rocketMotion(){
	glPushMatrix();
    rocketTop();
    rocketBottom();
	glTranslated(0,0,0);
	glPopMatrix();
}

void rocketMotionU(){
	glPushMatrix();
    rocketTop();
    rocketBottom();
	glTranslated(0,0.3,0);
	glPopMatrix();
}

void rocketMotionD(){
	glPushMatrix();
   // rocketTop();
    rocketBottom();
	glTranslated(0,0.3,0);
	glPopMatrix();
}


void sun()
{
    circle(01,0,0,  0.78,-0.18,1,500,0.1,0.1);
}


void init(){
	//screen color setup
	    glClearColor(0.0,0.0,0.0,1.0);
	    //glClear(GL_COLOR_BUFFER_BIT);
	glOrtho(0,1, -1,0, 0,1);
}








void myDisplay(){

    glClear(GL_COLOR_BUFFER_BIT);
    field();
    sky();
    house();
    box2();
    frem();


    glPushMatrix();
    glTranslated(-0.1,0,0);
    tree();
    glTranslated(-0.1,0,0);
    tree();
    glTranslated(0.29,0,0);
        tree();
    glTranslated(-0.06,-0.3,0);
        tree();
    glTranslated(0.2,-0.01,0);
        tree();
    glPopMatrix();


    glPushMatrix();
    glTranslated(animx,animy,0);
    rocketTop();
    rocketBottom();
    glPopMatrix();
    if(animy<=.1){
    	animy=animy+0.0005;
    }
       glutPostRedisplay();

    /* sky changes*/
    if(animy<=.1){
        // rectangle(0.678, 0.847, 0.902, 50,40, 50,-40, -50,-40,-50,40);
    	sun();

    }
    else{

    		DarkSky();

            glPushMatrix();
            //animy = 0;
            glTranslated(animx,animy,0);
            rocketTop();
            rocketBottom();
            glPopMatrix();
            	if(animy<=.2){
                	animy=animy+0.0005;
             }


                glPushMatrix();
                glTranslated(animx,animy,0);
                rocketMotionU();
                glPopMatrix();
                	if(animy<=.3){
                    	animy=animy+0.0005;
                    	animyB=animyB+0.0005;
                 }

	                glPushMatrix();
	                glTranslated(animxB,animyB,0);
	                rocketMotionD();
	                glPopMatrix();
	                	if(animyB>=.3){
	                    	animyB=animyB-0.0005;
	                 }


        }

/***


       glPushMatrix();
       glTranslated(animx,animy,0);
       box();
       glPopMatrix();
       if(animy<=.1){
       	animy=animy+0.0005;
       }


       glPushMatrix();
       glTranslated(animx,animy,0);
       box3();
       glPopMatrix();
       	if(animy<=.2){
           	animy=animy+0.0005;
        }

        glPushMatrix();
        glTranslated(animx,animy,0);
        box4();
        glPopMatrix();
        	if(animy<=.3){
            	animy=animy+0.0005;
         }

***/
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
