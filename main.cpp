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
    int * arguments=fileReader.getArguments();
    cout<<arguments[1]<<endl;
    cout<<matrix[1][1]<<endl;
// test update
int a;
int b;
    return 0;
}
