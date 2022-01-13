//
// Created by User on 12/01/2022.
//

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
    delete [] xVector;
}

void Element::func() {
    double * e=new double [n_val];;
    for (int i = 0; i < m; ++i) {
        //init e vector;

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
    delete [] e;
}

bool Element::operator<=(const Element &  other)const {

    int equalCounter=0;
    int smallCounter=0;
    for (int i = 0; i < m; ++i) {
        if(this->funcResult[i]==other.funcResult[i]){
            equalCounter++;
            smallCounter++;
        }
        if(this->funcResult[i]<other.funcResult[i]){
            smallCounter++;
        }
        if (smallCounter==m&&equalCounter>1){
            return true;
        }
    }
    return false;
}

int Element::getRank() const {
    return rank;
}

void Element::setRank(int rank) {
    Element::rank = rank;
}

string Element::getfuncResult() const {
stringstream ss;
string  toReturn;
    for (int i = 0; i < m; ++i) {
        double temp=funcResult[i];
        ss<<setprecision(6)<<fixed<<temp;
        toReturn.append(ss.str()).append(" ");
    }
    return toReturn;
}

