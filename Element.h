
#ifndef HOMEWORK5GIT_ELEMENT_H
#define HOMEWORK5GIT_ELEMENT_H
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
class Element {

    // this class hold element data
private:

    //size of n_value
    int n_val;
    //Line of vector
    double * xVector;

    // size of m
    int m;

    //result of the function;
    double * funcResult;

    // rank of Element
    int rank;

// constructor
public:
    Element(int nVal, double *xVector, int m);
    // calc the (xVector - e)square
    void func();

    int getRank() const;

    void setRank(int rank);

    bool operator<=(const Element &  other)const;

     ~Element();

    string getfuncResult()const;

    double getvalue(int index);

    int operator[](int x) const ;


    };


#endif //HOMEWORK5GIT_ELEMENT_H
