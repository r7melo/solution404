#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#define MAX_BYTES_MEMORI 1000
const char *data = "[Technology|Computer-Programming-Algorithm-Internet-Software[Nature|Forest-River-Mountain-Animal-Plant[Colors|Red-Blue-Green-Yellow-Purple[Food|Pizza-Rice-Apple-Chocolate-Salad[Human Body|Heart-Lung-Brain-Hand-Eye[Transport|Car-Airplane-Bicycle-Train-Boat]";
const size_t data_size = 256;

void construct_memori(uint8_t **memori)
{
    *memori = malloc(sizeof(char) * MAX_BYTES_MEMORI);

    if(*memori == NULL)
    {
        perror("malloc failed in memori");
        exit(EXIT_FAILURE);
    }

    (*memori)[MAX_BYTES_MEMORI] = '\0';
}

void init_memori(uint8_t **memori)
{
    for(size_t i=0; i < data_size; i++)
    {
        (*memori)[i] = data[i];
    }
}

int main()
{
    
    uint8_t *memori;
    construct_memori(&memori);
    init_memori(&memori);

    for(size_t i=0; i < data_size; i++)
    {
        printf("%c", (memori)[i]);
    }

    free(memori);
    return 0;
}