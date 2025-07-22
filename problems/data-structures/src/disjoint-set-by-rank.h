#include <stdio.h>
#include <stdlib.h>

typedef struct set Set;
Set *constructSet(int n);
void printSet(Set *set);
int findSet(Set *set, int x);
int mergeSet(Set *set, int x, int y);

struct set
{
    int r;
    int *v;
};

Set *constructSet(int r)
{
    Set *set = (Set*) malloc(sizeof(Set));
    set->r = r;
    set->v = (int*) malloc(sizeof(int)*r);
    for(int i=0; i<r; i++) set->v[i] = -1;
        
    return set;   
}

void printSet(Set *set)
{
    for(int i=0; i<set->r; i++) 
        printf("[%i]: %i\n", i, set->v[i]);
    printf("\n");
}

int findSet(Set *set, int x)
{
    if(set->v[x] < 0)
        return set->v[x];
    
    set->v[x] = findSet(set, set->v[x]);
    return set->v[x];
}

int mergeSet(Set *set, int x, int y)
{
    printf("Merge %i e %i\n", x,y);
    x = findSet(set, x);
    y = findSet(set, y);
    
    if(x==y)
    {
        return x;
    }
    else
    {
        if(set->v[x] <= set->v[y])
        {
            set->v[x] += set->v[y];
            set->v[y] = x;
            return set->v[x];
        }
        else
        {
            set->v[y] += set->v[x];
            set->v[x] = y;
            return set->v[y];
        }
    }
}
