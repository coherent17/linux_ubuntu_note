#include <stdio.h>
#include "min.h"

int main(){
    int array[5]={1,8,3,4,5};
    int min=findMin(array, 5);
    printf("min=%d\n", min);
    return 0;
}