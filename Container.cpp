#include "Container.h"
#include <typeinfo>



Container::Container(double** matrix , int n_elems , int n_values , int n_after_func):
        n_of_elements(n_elems), n_values(n_values) , n_values_after_func(n_after_func)
{/* constructor set data members of containers initializing the elements
   param matrix  - elements values
   param n_elems  - number of elements
   param n_values - number of values in each element
   param n_after_func - number of values after func in each element
*/
    srand( (unsigned)time( NULL ) );
    randomVector = new double[n_values];
    for(int i = 0 ; i < n_of_elements ; i++) {
        Element *curr = new Element(n_values, matrix[i], n_after_func);
        elements.push_back(curr);
    }
}
Container::~Container(){
    delete[] randomVector;
    elements.clear();
}

void Container::simulates(int n_simulate)
{/* simulate - control func on the simulations
    param n_simulate -  number of simulation from the user
*/  int x = 0;
    for(int i = 0 ; i < n_simulate ; i++)
    {
        resize_elements(); // crate more n_elems
        setElementFunc();
        genericSort< vector<Element* > , Element > G(elements );
        elements =  G.ParetoSorting(2*n_of_elements);
        //elements.erase(elements.begin() , elements.begin()+(n_of_elements) );
        elements.erase(elements.begin()+(n_of_elements) , elements.end() );
        clearRank();
    }
}

void Container:: setElementFunc(){
    for(int i = 0 ; i< elements.size() ; i++){
        elements[i]->func();
    }
}



/*void Container::sliceContainer(){
    for (int curr = 0 ; curr < n_of_elements ; curr++){
        int rank = elements[curr]->getRank();
        for (int other = 0; other < n_of_elements; other++) {
            if(rank == elements[other]->getRank()){

            }
        }
    }
}*/

void Container:: resize_elements()
{   int curr_elem ; // index for the exists elements
    double res[n_values]; // the new value of this new element
    for(int i =n_of_elements;i < 2*n_of_elements ; i++)// loop for n_elements times
    {
        get_random_vector(); // set randomVector
        for(int curr_index = 0;curr_index <n_values ; curr_index++){
            res[curr_index] = add_vectors(curr_elem, curr_index); // crate new value -  adding element[j] value with randomVector
        }
        curr_elem++;
        Element* e = new Element(n_values , res , n_values_after_func);// crate new element
        elements.push_back(e);// adding to the container
    }

}

double Container:: add_vectors(int curr_elem , int curr_index)
{/* add_vectors - return new value by add 2 values
    param curr_elem - elem[curr_elem].value[i]
    param curr_index - index for the randomVector
    */
    double res;
    res = randomVector[curr_index] + elements[curr_elem]->getvalue(curr_index); // un finish
    return res;
}

void Container::get_random_vector()
{/* get_random_vector - get random number [0,1]
  */
    double val;
    for(int i = 0;i < n_values;i++){
        randomVector[i] = (double ) rand()/RAND_MAX;
    }
}

void Container::writeToFile(char* filename) const {
    /*writeToFile - print the data of each func result of element
    */
    ofstream resultFile(filename,ios::out);
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
    /*return pointer of the wanted element
     * */
    return this->elements[x];
}

/*Container::Container():n_of_elements(NULL),n_values(NULL),n_values_after_func(NULL),elements(NULL),randomVector(NULL){
    cout<<"container"<<endl;
}

Container::Container(const Container *p1){
    cout<<"copy container"<<endl;
    this->n_of_elements = p1->n_of_elements;
    this->n_values = p1->n_values;
    this->n_values_after_func = n_values_after_func;
    this->elements = p1->elements;
    this->randomVector = p1->randomVector;
}*/

void Container:: clearRank(){
    /* reset the elements ranks to 0
     */
    for(int i =0 ; i < elements.size() ; i++){
        elements[i]->setRank(0);
    }
}