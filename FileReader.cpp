#include "FileReader.h"

FileReader::FileReader(char *fileName) : fileName(fileName), size(0), N(0) {

    this->arguments = new int[4];

    argumentsForContainer();
    validationForSize();
    this->matrixOfPop=new double *[size];
    readMatrix();
    printMatrixHelper();


}


FileReader::~FileReader() {
    for (int i = 0; i < size; ++i) {
        delete [] matrixOfPop[i];
    }
    delete [] arguments;

//    delete matrixOfPop;
//    delete arguments;
}


void FileReader::validationForSize() const {
    ifstream file(fileName);
    if (!file.is_open()) {
        string err="ERROR: ";
        throw logic_error( err+ fileName + " does not exist or cannot be opened\n");
    }
    string line;
    int counter = 0;
    while (getline(file, line)) {
        counter++;
    }
    if ((counter - 1) != size) {
        string err = "ERROR: simulation definition in ";
        throw logic_error( err + fileName + " is invalid\n");
    }
    file.close();
}


void FileReader::argumentsForContainer() {
    ifstream file(fileName);
    if (!file.is_open()) {
        string err="ERROR: ";
        throw logic_error( err+ fileName + " does not exist or cannot be opened\n");
    }
    int elem;
    int j = 0;

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
        string err="ERROR: simulation definition in ";
        throw logic_error( err+ fileName + " is invalid\n");
    }
    size = arguments[0];
    N = arguments[1];
    return ;

}

void FileReader::printMatrixHelper() const {

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrixOfPop[i][j] << " ";
        }
        cout << endl;
    }
}


double **FileReader::getMatrix() const {
    return matrixOfPop;
}

void FileReader::readMatrix() {
    ifstream file(fileName);
    if (!file.is_open()) {
        string err="ERROR: ";
        throw logic_error( err+ fileName + " does not exist or cannot be opened\n");
    }
    double numberInMatrix;
    int j = 0;

    string line;
    getline(file, line);// first line to skip

    while (file.good()) {
        for (int i = 0; i < size; i++) {
            matrixOfPop[i] = new double[N];
            getline(file, line);
            istringstream innerLine(line);
            string element;
            stringstream ss;
            while (getline(innerLine, element, ' ')) {
                ss << element;
                ss >> numberInMatrix;
                matrixOfPop[i][j] = numberInMatrix;
                ss.clear();
                j++;
            }
            if (j != N) {
                stringstream ss;
                ss <<i;
                string str = ss.str();
                string err;
                err.append("ERROR: population definition in ").append(fileName).append("at line ")
                        .append(str).append("is invalid\n");
                throw logic_error(err);
            }
            j = 0;
        }
        file.close();
    }

}

int *FileReader::getArguments() const {
    return arguments;
}