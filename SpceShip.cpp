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


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("Hello World!!!");
	return EXIT_SUCCESS;
}
