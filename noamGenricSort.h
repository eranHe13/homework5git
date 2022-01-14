//
// Created by noame on 1/14/2022.
//

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


#endif //HOMEWORK5GIT_NOAMGENRICSORT_H
