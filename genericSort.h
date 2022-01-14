#ifndef HOMEWORK5GIT_GENERICSORT_H
#define HOMEWORK5GIT_GENERICSORT_H

#include "vector"
using namespace std;
template<class  e>
class genericSort {
public:

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
void swap(e *felm, e *selm)
{
    int temp = *felm;
    *felm = *selm;
    *selm = temp;
}

e* sortNoam(e* container ,  int n_elements){
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

void ElementsReordering(e* container ,  int n_elements){
    // resize the container to n_elements/2
    // remove all the big half of elements by there rank
    int counter_same_rank;
    for (int i = 0; i < n_elements; i++) {


    }

}
e* ParetoSorting(const std::vector<e> *elements , int n_elements){
    e* container = elements;
    for (int i = 0; i < n_elements ; i++) {
        container = ParetoRanking(container, i , n_elements);
    }
    container =sort(container , n_elements);
    container =ElementsReordering(container , n_elements);
    return container;
}

};



#endif //HOMEWORK5GIT_GENERICSORT_H