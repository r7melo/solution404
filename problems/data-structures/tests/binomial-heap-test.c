#include <stdio.h>
#include <stdlib.h>

#include "../assets/utils.h"
#include "../src/binomial-heap.h"

int main()
{
    Heap *h = ConstructHeap(10);

    printf("value=%i",h->value);

    
    return 0;
}