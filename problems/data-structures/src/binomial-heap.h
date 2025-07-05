typedef struct heap Heap;
Heap *ConstructHeap(int value);


struct heap
{
    int value;
    int degree;

    struct heap *parent;
    struct heap *next;
    struct heap *child;

};

Heap *ConstructHeap(int value)
{
    Heap *heap = malloc(sizeof(Heap));

    heap->value = value;
    heap->degree = 0;
    heap->parent = NULL;
    heap->next = NULL;
    heap->child = NULL;

    return heap;
}


