//
// Created by User on 12/01/2022.
//

#ifndef HOMEWORK5GIT_CONTAINER_H
#define HOMEWORK5GIT_CONTAINER_H
#import<vector>
#include <random>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#import"Element.h"

using namespace std;
class Element;


class Container {
private:
    int n_of_elements; // mue
    int n_values; // n
    int n_values_after_func; //m
    vector <Element*> elements;
    double* randomVector;


public:
    Container(double** matrix , int n_elems , int n_values , int n_after_func);

    void simulates(int n_simulate);
    void resize_elements();
    void get_random_vector();
    double add_vectors(int curr_elem , int curr_index);
    void  print_results(char* file_name);



    // run on all the element and rank each one
    void rankTheElement();
    void writeToFile()const;
};


#endif //HOMEWORK5GIT_CONTAINER_H
