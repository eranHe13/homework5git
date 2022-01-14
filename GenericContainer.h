//
// Created by User on 13/01/2022.
//

#ifndef HOMEWORK5GIT_GENERICCONTAINER_H
#define HOMEWORK5GIT_GENERICCONTAINER_H

#include <ctime>
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;
template<class C , class E>
struct node{
    E* data;
    int key;

    struct node* next;
};


class GenericContainer {
private:
    int n_of_elements; // mue
    int n_values; // n
    int n_values_after_func; //m
    multimap <int,E> elements;
    C* randomVector;

public:
    /*GenericContainer(C** matrix , int n_elems , int n_values , int n_after_func)
                    : n_of_elements(n_elems),n_values(n_values),n_values_after_func(n_after_func), elements(NULL) , randomVector(NULL)
    {
        randomVector = new C[n_values];
        for(int i = 0 ; i < n_of_elements ; i++)
        {   E* curr = new E(&matrix[i]);
            if(elements.size() == 0){
                elements.insert(elements.begin()  , curr);
            }
            elements.push_back(curr);
        }}*/

    void set(C matrix , int n_elems , int n_values , int n_after_func){
        n_of_elements= n_elems;
        n_values=n_values;
        n_values_after_func=n_after_func;
        randomVector = new C[n_values];
        for(int i = 0 ; i < n_of_elements ; i++)
        {
            E* curr = new E( n_values,matrix[i] , n_after_func);
            elements.insert({-1 , curr});
            elements.insert( {-1,curr});
        }
    };

    void get_random_vector()
    {
        srand( (unsigned)time( NULL ) );
        C val;
        for(int i = 0;i < n_values;i++){
            randomVector[i] = (C ) rand()/RAND_MAX;
        }
    }

    double add_vectors(int curr_elem , int curr_index){
        double res;
        res = randomVector[curr_index] + elements[curr_elem][curr_index];
        return res;
    }

    void resize_elements() {
        int curr_elem; // index for the exists elements
        double res[n_values]; // the new value of this new element
        for (int i = n_of_elements; i < 2 * n_of_elements; i++) { // loop for n_elements times
            get_random_vector(); // set randomVector
            for (int curr_index = 0; curr_index < n_values; curr_index++) {
                res[curr_index] = add_vectors(curr_elem,
                                              curr_index); // crate new value -  adding element[j] value with randomVector
            }
            curr_elem++;
        }
    };



    void simulates(int n_simulate){
        for(int i = 0 ; i < n_simulate ; i++)
        {   resize_elements(); // crate more n_elems
            //pareToSorting(&elements)

        }
    };


    void  print_results(char* file_name){
        for (int i = 0; i < n_of_elements; i++) {
            elements[i].print_results();
        }
    }



    // run on all the element and rank each one
    void rankTheElement();
    void writeToFile()const{
        string filename="out.dat";
        // need to change for  file name !!!!!
        ofstream resultFile(filename.c_str(),ios::out);
        if (!resultFile.is_open()) {
            string err="ERROR: ";
            throw logic_error( err+ filename + " does not exist or cannot be opened\n");
        }
        for (int i = 0; i < n_of_elements; ++i) {
            resultFile<<elements[i]->getfuncResult().c_str()<<endl;
        }
        resultFile.close();
    };

};

#endif //HOMEWORK5GIT_GENERICCONTAINER_H
