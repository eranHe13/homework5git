#include <iostream>
#include "FileReader.h"

int main(int argc, char** argv) {
    if(argc!=3){
        cerr << "ERROR: Invalid input.";
        exit(1);
    }
    char* file=argv[1];
    FileReader fileReader(file);
    double ** matrix=fileReader.getMatrix();
    int * arguments=fileReader.getArguments();

// test update
int a;
int b;
    return 0;



     /// to add for genericSort class- >>
     /// sort of container using bubble sort
     /*
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
                if (container[j].getRack > container[j + 1].getRank)
                    swap(&container[j], &container[j + 1]);
            }
        }
        return *container;
    }
   */


}
