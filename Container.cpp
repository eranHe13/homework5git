
#include "Container.h"




Container::Container(double** matrix , int n_elems , int n_values , int n_after_func):
        n_of_elements(n_elems), n_values(n_values) , n_values_after_func(n_after_func)
{/// \param counstructor set data members of containers initializing the elements
/// \param matrix elements values
/// \param n_elems number of elements
/// \param n_values number of values in each element
/// \param n_after_func number of values after func in each element

    randomVector = new double[n_values];
    for(int i = 0 ; i < n_of_elements ; i++)
    {   Element* curr = new Element(n_values , matrix[i] , n_after_func);
        if(elements.size() == 0){
            elements.insert(elements.begin()  , curr);
        }
        elements.push_back(curr);
    }}

/// \param simulate - control func on the simulations
/// \param n_simulate number of simulation from the user
void Container::simulates(int n_simulate)
{
    for(int i = 0 ; i < n_simulate ; i++)
    {   resize_elements(); // crate more n_elems
        //pareToSorting(&elements)

    }
}


/// \param resize_elements - crate new n_elements
void Container:: resize_elements()
{   int j ; // index for the exists elements
    double res[n_values]; // the new value of this new element
    for(int i =n_of_elements;i < 2*n_of_elements ; i++)
    { // loop for n_elements times
        get_random_vector(); // set randomVector
        for(int k = 0;k <n_values ; k++){
         res[k] = add_vectors(j, k); // crate new value -  adding element[j] value with randomVector
        }
        j++;
    }
    Element* e = new Element(n_values , res , n_values_after_func);// crate new element
    elements.push_back(e);// adding to the container
}

/// \param add_vectors - crate new vector
/// \param curr_elem - elem[curr_elem].value[i]
/// \param curr_index - index for the randomVector
double Container:: add_vectors(int curr_elem , int curr_index){
    double res;
    res = randomVector[curr_index] + elements[curr_elem][curr_index]; // un finish
    return res;
}

/// \param get_random_vector - get random number [0,1]
void Container::get_random_vector()
{
    srand( (unsigned)time( NULL ) );
    double val;
    for(int i = 0;i < n_values;i++){
        randomVector[i] = (double ) rand()/RAND_MAX;
    }
}



void Container:: print_results(char* file_name)
{
    for (int i = 0; i < n_of_elements; i++) {
        elements[i].print_results();
    }

}


// check how many of elements "control" on other element
// and set the current rank for the element
void Container::rankTheElement() {

    int rankPoints;
    for (int i = 0; i < n_of_elements; ++i) {
        rankPoints=0;
        for (int j = 0; j < n_of_elements; ++j) {
            if (i==j){
                continue;
            }
            if (elements[i]->operator<=(*elements[j])){
                rankPoints++;
            }
        }
        elements[i]->setRank(rankPoints);
    }

}

void Container::writeToFile() const {
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
}
