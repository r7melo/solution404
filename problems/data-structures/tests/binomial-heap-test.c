#include <stdio.h>
#include <stdlib.h>

#include "../assets/utils.h"
#include "../src/binomial-heap.h"

int main()
{
    
    // Raiz principal do B4
    Heap *h = ConstructHeap(1);

    // Definindo os 4 filhos da raiz (raízes das sub-árvores B3, B2, B1, B0)
    h->child = ConstructHeap(2);
    h->child->sibling = ConstructHeap(3);
    h->child->sibling->sibling = ConstructHeap(4);
    h->child->sibling->sibling->sibling = ConstructHeap(5);

    // Agora definindo os filhos do nó '2' (que é a raiz da sub-árvore B3)
    h->child->child = ConstructHeap(6);
    h->child->child->sibling = ConstructHeap(7);
    h->child->child->sibling->sibling = ConstructHeap(8);

    // E os filhos do nó '3' (que é a raiz da sub-árvore B2)
    h->child->sibling->child = ConstructHeap(9);
    h->child->sibling->child->sibling = ConstructHeap(10);

    // E assim por diante...
    print_heap(h);
    

    Heap *h2 = ConstructHeap(65);

    merge(h, h2);
    
    return 0;
}