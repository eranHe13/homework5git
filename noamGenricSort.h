#ifndef HOMEWORK5GIT_NOAMGENRICSORT_H
#define HOMEWORK5GIT_NOAMGENRICSORT_H

using namespace std;
template<typename Elem>;
class noamGenricSort {
private:


public:

    void addToarray(Elem elem ,int index){
        array[index]=elem;
    }

    e* ParetoRanking(e* container, int index , int n_elements){
        e* curr = container[index];
        for (int i = 0; i < 2 * n_elements; i++) { //loop on the elements
            if(index != i ){ //  check if its not the same elem
                if(curr[index] <= container[i]){
                    curr++; // adding 1 for the rank
                }
            }
        }
        return container;
    }
    ParetoSorting(){
    }



};


/*
 * #ifndef HOMEWORK5GIT_GENERICSORT_H
#define HOMEWORK5GIT_GENERICSORT_H
#include <typeinfo>
#include <iostream>
#include "vector"
using namespace std;
template<class C , class E>
class genericSort {
private:
    C container;
    E* curr;
    E* other;
public:
    genericSort(C v ):container(v),curr(NULL), other(NULL)
    {
    }

    void ParetoRanking( int index , int n_elements){
        curr = container[index];
         //curr = dynamic_cast<E*>( container[index]);
        //cout<<"cur == " <<  typeid(curr).name() << endl;
        for (int i = 0; i < 2 * n_elements; i++) { //loop on the elements
            if(index != i ){ //  check if its not the same elem
                other = container[i];
                //other =  dynamic_cast<E*>( container[i]);
                //cout<<"other = " <<typeid(other).name()<< endl ;
                if(curr->operator<=(other) ){
                     curr->operator++(); // adding 1 for the rank
                }
            }
        }
    }

    void swap(C *felm, C *selm)
    {
        int temp = *felm;
        *felm = *selm;
        *selm = temp;
    }

    void sortNoam(   int n_elements){
        container ;
        /// sorting the container by there rank
        // using bubble sort algorithm
        int i, j;
        for (i = 0; i < n_elements-1; i++) {
            for (j = 0; j < n_elements - i - 1; j++) {
                if (container[j] > container[j + 1])
                    swap(&container[j], &container[j + 1]);
            }
        }
        return *container;
    }

    void ElementsReordering(C* container ,  int n_elements){
        // resize the container to n_elements/2
        // remove all the big half of elements by there rank
        int counter_same_rank;
        for (int i = 0; i < n_elements; i++) {


        }

    }
    void ParetoSorting( int n_elements){
        for (int i = 0; i < n_elements ; i++) {
            //curr = dynamic_cast<E*>(container[i])  ;
            ParetoRanking( i , n_elements);
        }
        //container =sort(container , n_elements);
        //container =ElementsReordering(container , n_elements);
        //return container;
    }

    };



#endif //HOMEWORK5GIT_GENERICSORT_H
*/

#endif //HOMEWORK5GIT_NOAMGENRICSORT_H