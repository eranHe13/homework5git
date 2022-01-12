
#ifndef HOMEWORK5GIT_FILEREADER_H
#define HOMEWORK5GIT_FILEREADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include <cstdlib>

using namespace std;

class FileReader {
private:
    char *fileName;
    int size;
    int N;


public:

    // constructor
    FileReader(char *fileName);

    virtual ~FileReader();

    void validationForSize() const;

    int *argumentsForContainer();

    void printMatrixHelper() const;

    double **getMatrix() const;
};


#endif //HOMEWORK5GIT_FILEREADER_H
