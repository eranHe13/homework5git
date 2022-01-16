#ifndef HOMEWORK5GIT_GENERICSORT_H
#define HOMEWORK5GIT_GENERICSORT_H
#include <iostream>
#include "vector"
using namespace std;
template<class C , class E>
class genericSort {
private:
    C container;
    E* curr;
    E* other;
    E* tmp;
public:
    genericSort(C v ):container(v),curr(NULL), other(NULL),tmp(NULL){}

    void ParetoRanking( int index , int n_elements){
        curr = container[index];
        for (int i = 0; i <  n_elements; i++)
        {//loop on the elements
            if(index != i ){ //  check if its not the same elem
                other = container[i];
                if(curr->operator<(other) ){
                    //curr->operator++(); // ככה זה היה עד עכשיו וזה לא נכון
                     other->operator++(); // adding 1 for the rank
                }
            }
        }
    }

    void ElementsReordering(int n_elements){
        int currIndex, otherIndex;
        for (currIndex = 0; currIndex < n_elements-1; currIndex++) {
            for (otherIndex = 0; otherIndex < n_elements - currIndex - 1; otherIndex++) {
                curr = container[otherIndex];
                other = container[otherIndex+1];
                if (curr->operator>(other)){
                    tmp = container[otherIndex+1];
                    container[otherIndex+1] = container[otherIndex];
                    container[otherIndex]=tmp;
                }}
        }
    }

    C ParetoSorting( int n_elements){
        for (int i = 0; i < n_elements ; i++) {
            ParetoRanking( i , n_elements);
        }
        ElementsReordering( n_elements);
        return container;
    }

    };



#endif //HOMEWORK5GIT_GENERICSORT_H