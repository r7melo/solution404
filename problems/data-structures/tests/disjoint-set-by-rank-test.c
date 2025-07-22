#include <stdio.h>
#include <stdlib.h>

#include "../assets/utils.h"
#include "../src/disjoint-set-by-rank.h"



int main()
{
    Set *set = constructSet(10);
    printSet(set);
    
    mergeSet(set, 5,4);
    printSet(set);
    
    mergeSet(set, 2,1);
    printSet(set);
    
    mergeSet(set, 4,1);
    printSet(set);
    
    return 0;
}