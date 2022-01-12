//
// Created by noame on 1/11/2022.
//

#include "FileReader.h"

FileReader::FileReader(char *fileName) : fileName(fileName), size(0), N(0) {

    argumentsForContainer();
    validationForSize();

    printMatrixHelper();


}


FileReader::~FileReader() {

}


void FileReader::validationForSize() const {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "ERROR: " << fileName << " does not exist or cannot be opened\n";
        exit(1);
    }
    string line;
    int counter = 0;
    while (getline(file, line)) {
        counter++;
    }
    if ((counter - 1) != size) {
        cerr << "ERROR: simulation definition in " << fileName << " is invalid\n";
        exit(-1);
    }
    file.close();
}


int *FileReader::argumentsForContainer() {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "ERROR: " << fileName << " does not exist or cannot be opened\n";
        exit(1);
    }
    int elem;
    int *arguments = new int[4];
    int j = 0;

    if (!file.is_open()) {
        cerr << "ERROR: Invalid input.";
        exit(1);
    }
    string line;
    getline(file, line);
    istringstream innerLine(line);
    string element;
    stringstream ss;
    while (getline(innerLine, element, ' ')) {
        ss << element;
        ss >> elem;
        arguments[j] = elem;
        ss.clear();
        j++;
    }
    if (j != 4) {
        cerr << "ERROR: simulation definition in " << fileName << " is invalid\n";
    }
    size = arguments[0];
    N = arguments[1];
    return arguments;

}

void FileReader::printMatrixHelper() const {
    double **matrixToPrint = getMatrix();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrixToPrint[i][j] << " ";
        }
        cout << endl;
    }
}


double **FileReader::getMatrix() const {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "ERROR: " << fileName << " does not exist or cannot be opened\n";
        exit(1);
    }
    double numberInMatrix;
    double **matrixToReturn = new double *[size];
    int j = 0;

    if (!file.is_open()) {
        cerr << "ERROR: Invalid input.";
        exit(1);
    }
    string line;
    getline(file, line);// first line to skip

    while (file.good()) {
        for (int i = 0; i < size; i++) {
            matrixToReturn[i] = new double[N];
            getline(file, line);
            istringstream innerLine(line);
            string element;
            stringstream ss;
            while (getline(innerLine, element, ' ')) {
                ss << element;
                ss >> numberInMatrix;
                matrixToReturn[i][j] = numberInMatrix;
                ss.clear();
                j++;
            }
            if (j != N) {
                cerr << "ERROR: population definition in " << file << "at line " << i << " is invalid\n";
                exit(1);
            }
            j = 0;
        }
        file.close();
    }
    return matrixToReturn;
}

