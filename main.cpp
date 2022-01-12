#include <iostream>
#include "FileReader.h"

int main(int argc, char** argv) {
    if(argc!=3){
        cerr << "ERROR: Invalid input.";
        exit(1);
    }
    char* file=argv[1];
    FileReader fileReader(file);
    double ** matrix=fileReader.getMatrix();
    int * arguments=fileReader.argumentsForContainer();
// test update
int a;
    return 0;
}
