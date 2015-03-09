#include <stdlib.h>
#include "stack.h"

stack_t* stack_new(unsigned int i_len)
{
    if (i_len == 0) return NULL;
    
    stack_t* stck = malloc(sizeof(stack_t));
    stck->n_items = 0;
    stck->item_size = i_len;
    stck->stack_max = -1;
    stck->data = malloc(i_len);
    
    return stck;
}

stack_t* stack_new_max(unsigned int i_len, long max_len)
{
    stack_t* stck = stack_new(i_len);
    stck->stack_max = max_len;

    return stck;
}

void stack_destroy(stack_t* stck)
{
    free(stck->data);
    free(stck);
    stck = NULL;
}

bool stack_push(stack_t* stck, void* data)
{
    if (stck->n_items + 1 >= stck->stack_max && stck->stack_max != -1) return false;

    stck->data = realloc(stck->data, ++(stck->n_items) * stck->item_size);
    stck->data[(stck->n_items) * stck->item_size] = data;

    return true;
}

void* stack_pop(stack_t* stck)
{
    if (stck->n_items == 0) return NULL;

    void* ret = stck->data[stck->n_items-- * stck->item_size];
    stck->data = realloc(stck->data, stck->n_items * stck->item_size);

    return ret;
}

void stack_clear(stack_t* stck)
{
    if (stck->n_items == 0) return;
    
    stck->data = realloc(stck->data, stck->item_size);
    stck->n_items = 0;
}
