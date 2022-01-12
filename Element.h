
#ifndef HOMEWORK5GIT_ELEMENT_H
#define HOMEWORK5GIT_ELEMENT_H


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

     ~Element();

};


#endif //HOMEWORK5GIT_ELEMENT_H
