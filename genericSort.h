//
// Created by User on 12/01/2022.
//

#ifndef HOMEWORK5GIT_GENERICSORT_H
#define HOMEWORK5GIT_GENERICSORT_H

template<class e>
class genericSort {
private:

public:
   e* ParetoRanking(e* container, int index , int n_elements){
       e* curr = container[index];
        for (int i = 0; i < 2 * n_elements; i++) { //loop on the elements
            if(index != i ){ //  check if its not the same elem
               if(curr->value <= container[i]->value){
                   curr++; // adding 1 for the rank
               }
            }
        }
       return container;
   }

   e* sort(e* container ,  int n_elements){
        /// sorting the container by there rank
}


   void ElementsReordering(e* container ,  int n_elements){
        // resize the container to n_elements/2
        // remove all the big half of elements by there rank
        int counter_same_rank;
        for (int i = 0; i < n_elements; i++) {


       }

}
   e* ParetoSorting(genericSort<e> *elements, int n_elements){
       e* container =dynamic_cast<e*>(elements);
       for (int i = 0; i < n_elements ; i++) {
           ParetoRanking(container, i , n_elements);
           sort(container , n_elements);
           ElementsReordering(container , n_elements);
       }
       return container;
   }
};


#endif //HOMEWORK5GIT_GENERICSORT_H
