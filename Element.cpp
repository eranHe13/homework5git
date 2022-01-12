//
// Created by User on 12/01/2022.
//
#include <cmath>
#include "Element.h"

Element::Element(int nVal, double *xVector, int m) : n_val(nVal), m(m),
rank(-1) {

    // deep copy-
    this->xVector=new double [nVal];
    for (int i = 0; i < nVal; ++i) {
        this->xVector[i]=xVector[i];
    }
    // create f result
    funcResult=new double [m];

}

Element::~Element() {

    delete [] funcResult;

}

void Element::func() {

    for (int i = 0; i < m; ++i) {
        //init e vector;
        double * e=new double [n_val];
        for (int j = 0; j < n_val; ++j) {
            e[j]=i+1;
        }
        // sumOf calc
        double sum=0;
        for (int k = 0; k < n_val; ++k) {
            sum+= pow((this->xVector[k]-e[k]),2);
        }
        funcResult[i]=sum;
    }

}
