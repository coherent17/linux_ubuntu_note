#include "max.h"

int findMax(int array[], int size){
    int max=array[0];
    for(int i=0;i<size;i++){
        if(array[i]>max) max=array[i];
    }
    return max;
}