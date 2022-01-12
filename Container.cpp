
#include "Container.h"




Container::Container(double** matrix , int n_elems , int n_values , int n_after_func):
        n_of_elements(n_elems), n_values(n_values) , n_values_after_func(n_after_func)
{   for(int i = 0 ; i < n_of_elements ; i++)
    {   Element* curr = new Element(&matrix[i]);
        if(elements.size() == 0){
            elements.insert(elements.begin()  , curr);
        }
        elements.push_back(curr);
    }}


void Container::simulates(int n_simulate)
{
    for(int i = 0 ; i < n_simulate ; i++)
    {   resize_elements();
        //pareToSorting(&elements)

    }
}

void Container:: resize_elements()
{   int j ;
    for(int i =n_of_elements;i < 2*n_of_elements ; i++)
    {
        get_random_vector();
        vector<double> res = mrandomVector + eleents[j];
        j++;
    }
}

void Container::get_random_vector()
{
    srand( (unsigned)time( NULL ) );
    double val;
    for(int i = 0;i < n_values;i++){
          val =    (double ) rand()/RAND_MAX << endl; }
}
