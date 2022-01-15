#include "Container.h"
#include <typeinfo>



Container::Container(double** matrix , int n_elems , int n_values , int n_after_func):
        n_of_elements(n_elems), n_values(n_values) , n_values_after_func(n_after_func)
{/// \param counstructor set data members of containers initializing the elements
/// \param matrix elements values
/// \param n_elems number of elements
/// \param n_values number of values in each element
/// \param n_after_func number of values after func in each element

    srand( (unsigned)time( NULL ) );

    randomVector = new double[n_values];
    for(int i = 0 ; i < n_of_elements ; i++)
    {   Element* curr = new Element(n_values , matrix[i] , n_after_func);
        elements.push_back(curr);

    }}

/// \param simulate - control func on the simulations
/// \param n_simulate number of simulation from the user
void Container::simulates(int n_simulate)
{   int x = 0;
    for(int i = 0 ; i < n_simulate ; i++)
    {
        resize_elements(); // crate more n_elems
        genericSort< vector<Element* > , Element > G(elements );
        elements =  G.ParetoSorting(2*n_of_elements);
        elements.erase(elements.begin()+(n_of_elements) , elements.end() );
        clearRank();
    }



}


/// \param resize_elements - crate new n_elements
void Container:: resize_elements()
{   int curr_elem ; // index for the exists elements
    double res[n_values]; // the new value of this new element
    for(int i =n_of_elements;i < 2*n_of_elements ; i++)
    { // loop for n_elements times
        get_random_vector(); // set randomVector
        for(int curr_index = 0;curr_index <n_values ; curr_index++){
            res[curr_index] = add_vectors(curr_elem, curr_index); // crate new value -  adding element[j] value with randomVector
        }
        curr_elem++;
        Element* e = new Element(n_values , res , n_values_after_func);// crate new element

        elements.push_back(e);// adding to the container

    }

}

/// \param add_vectors - crate new vector
/// \param curr_elem - elem[curr_elem].value[i]
/// \param curr_index - index for the randomVector
double Container:: add_vectors(int curr_elem , int curr_index){
    double res;
    res = randomVector[curr_index] + elements[curr_elem]->getvalue(curr_index); // un finish
    return res;
}

/// \param get_random_vector - get random number [0,1]
void Container::get_random_vector()
{
    double val;
    for(int i = 0;i < n_values;i++){
        randomVector[i] = (double ) rand()/RAND_MAX;

    }
}



//void Container:: print_results(char* file_name)
//{
//    for (int i = 0; i < n_of_elements; i++) {
//        elements[i].print_results();
//    }
//
//}


// check how many of elements "control" on other element
// and set the current rank for the element
/*void Container::rankTheElement() {

    int rankPoints;
    for (int i = 0; i < 2*n_of_elements; ++i) {
        rankPoints=0;
        for (int j = 0; j < 2*n_of_elements; ++j) {
            if (i==j){
                continue;
            }
            if (elements[i]->operator<=(*elements[j])){
                rankPoints++;
            }
        }
        elements[i]->setRank(rankPoints);
    }

}*/

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
        cout << elements[i]->getfuncResult().c_str()<<endl;
    }
    resultFile.close();
}

Element* Container::operator[](int x) const {
    return this->elements[x];
}

Container::Container():n_of_elements(NULL),n_values(NULL),n_values_after_func(NULL),elements(NULL),randomVector(NULL)
{}
Container::Container(const Container *p1){
    this->n_of_elements = p1->n_of_elements;
    this->n_values = p1->n_values;
    this->n_values_after_func = n_values_after_func;
    this->elements = p1->elements;
    this->randomVector = p1->randomVector;
}
void Container:: clearRank(){
    for(int i =0 ; i < elements.size() ; i++){
        elements[i]->setRank(0);
    }
}