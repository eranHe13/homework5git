#include "Element.h"

Element::Element(int nVal, double *xVector1, int m) : n_val(nVal), m(m),
                                                      rank(0) {

    // deep copy-
    this->xVector=new double [nVal];
    for (int i = 0; i < nVal; ++i) {
        this->xVector[i]=xVector1[i];
    }
    // create f result
    funcResult=new double [m];
    func();

}

Element::~Element() {

    delete [] funcResult;
    delete [] xVector;
}

double Element::getvalue(int index){
    return xVector[index];
}
void Element::func() {
    double sum =0;
    for (int i = 0; i < m; i++) {
        sum=0;
        for (int j = 0; j < n_val; j++) {
            sum+=pow((xVector[j]-(i+1)) , 2);
        }
        funcResult[i] =sum;
    }

    /*double * e=new double [n_val];;
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
    delete [] e;*/
}

bool Element::operator<(const Element*  other)const {
    double x;
    double y;
    int equalCounter=0;
    int smallCounter=0;
    for (int i = 0; i < m; i++) {
        //cout <<this->funcResult[i]<<" -- " << other->funcResult[i] << endl;
        x = this->funcResult[i];
        y = other->funcResult[i];
        if(this->funcResult[i]<=other->funcResult[i]){ // x<=y
            smallCounter++;
        }
        if(this->funcResult[i]==other->funcResult[i]){ //x == y
            equalCounter++;
        }
    }
    if ((equalCounter <m) && (smallCounter == m) ){ //
        return true;
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
    string  toReturn;
    for (int i = 0; i < m; ++i) {
        double temp=funcResult[i];
        stringstream ss;
        ss.clear();
        ss<<setprecision(6)<<fixed<<temp;
        toReturn+=ss.str();
        if (i<m-1)
            toReturn+=" ";


    }
    return toReturn;
}

int Element::operator[](int x) const {
    return this->rank;
}

void Element:: operator++()  {
    this->rank+=1;
}
Element:: Element():n_val(NULL) , xVector(NULL),m(NULL),funcResult(NULL),rank(NULL){}

Element:: Element(const Element *p1){

    this->n_val = p1->n_val;
    this->xVector = p1->xVector;
    this->m = p1->m;
    this->funcResult = p1->funcResult;
    this->rank = p1->rank;
}


bool Element::operator>(const Element* other) const{
    return this->rank > other->rank;
}