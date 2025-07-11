typedef struct heap Heap;
Heap *ConstructHeap(int value);
Heap *merge(Heap *h1, Heap *h2);
Heap *combine_heaps(Heap *h1, Heap *h2);
void print_heap(Heap *heap);


struct heap
{
    int value;
    int degree;

    struct heap *parent;
    struct heap *sibling;
    struct heap *child;

};

Heap *ConstructHeap(int value)
{
    Heap *heap = malloc(sizeof(Heap));

    heap->value = value;
    heap->degree = 0;
    heap->parent = NULL;
    heap->sibling = NULL;
    heap->child = NULL;

    return heap;
}

void print_heap(Heap *heap)
{
    if(heap != NULL)
        printf("(%i) ",heap->value);

    if(heap->parent != NULL)
        printf("parent=%i ",heap->parent->value);

    if(heap->sibling  != NULL)
        printf("sibling=%i ",heap->sibling ->value);

    if(heap->child != NULL)
        printf("child=%i ",heap->child->value);
    
    printf("\n");

    if(heap->child != NULL)
        print_heap(heap->child);

    if(heap->sibling  != NULL)
        print_heap(heap->sibling );
}

Heap *merge(Heap *h1, Heap *h2)
{
    Heap *back, *x, *next;
    Heap *h = combine_heaps(h1, h2);

    x = h;

    if(h == NULL) return h;

    next = x->sibling;

    while(next != NULL)
    {
        if((x->degree != next->degree) || ((next->sibling != NULL) && (next->sibling->degree == x->degree)))
        {
            back = x;
            x = next;
        }
    }


    return h;
}

Heap *combine_heaps(Heap *h1, Heap *h2)
{
    Heap *h, *a, *b, *y, *z;
    y = h1;
    z = h2;

    if(y != NULL)
    {
        if((z != NULL) && (y->degree <= z->degree))
            h = y;
        else if((y != NULL) && (y->degree > h2->degree))
            h = h2;
    }
    else
    {
        h = h2;
    }

    while((y != NULL) && (z != NULL))
    {
        if(y->degree <z->degree)
        {
            y = z->sibling;
        }
        else
        {
            if(y->degree == z->degree)
            {
                a = y->sibling;
                y->sibling = z;
                y = a;
            }
            else
            {
                b = z->sibling;
                z->sibling = y;
                z = b;
            }
        }
    }

    return h;
}
