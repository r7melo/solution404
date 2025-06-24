#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <time.h>

#define MAX_BYTES_MEMORI 1000
const char *data = "[Technology-Computer-Programming-Algorithm-Internet-Software[Nature-Forest-River-Mountain-Animal-Plant[Colors-Red-Blue-Green-Yellow-Purple[Food-Pizza-Rice-Apple-Chocolate-Salad[Human Body-Heart-Lung-Brain-Hand-Eye[Transport-Car-Airplane-Bicycle-Train-Boat]";
const size_t data_size = 256;

void construct_memori(uint8_t **memori)
{
    *memori = malloc(sizeof(char) * MAX_BYTES_MEMORI);

    if(*memori == NULL)
    {
        perror("malloc failed in memori");
        exit(EXIT_FAILURE);
    }

}

void init_memori(uint8_t **memori)
{
    for(size_t i=0; i < data_size; i++)
    {
        (*memori)[i] = data[i];
    }
}

void raffle(uint8_t **memori, uint8_t **theme, uint8_t **word)
{
    size_t iv = rand() % data_size;
    int8_t d = 1;

    for(size_t i=iv; i<data_size; i=i+d)
    {
        printf("%c", (*memori)[i]);

        if(((*memori)[i]=='-') && (d>0))
        {
            *word = &(*memori)[i];
            d = -1;
            printf(" <-> ");
        }

        else if(((*memori)[i]=='[') && (d<0))   
        {
            *theme = &(*memori)[i];
            break;
        }
        
        else if((*memori)[i]==']') i=0;
    }

}

void iprint(uint8_t **imemori)
{
    for(uint8_t *i=*imemori+1; (*i!='-')&&(*i!='['); i++)
    {
        if(*i == ']') break;
        printf("%c", *i);
    } 
}

int main()
{
    srand(time(NULL));

    uint8_t *memori;
    construct_memori(&memori);
    init_memori(&memori);

    uint8_t *theme = NULL;
    uint8_t *word = NULL;

    raffle(&memori, &theme, &word);

    printf("\n\nTEMA="); iprint(&theme); printf("\n");
    printf("PALAVRA="); iprint(&word); printf("\n");


    free(memori);
    return 0;
}