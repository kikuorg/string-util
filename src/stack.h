#ifndef STACK_H
#define STACK_H

#include "type.h"

typedef struct
{
    unsigned int n_items;
    unsigned char item_size;
    long stack_max;
    void** data;
} stack_t;

stack_t* stack_new(unsigned int i_len);
stack_t* stack_new_max(unsigned int i_len, long max_len);
void     stack_destroy(stack_t* stck);
bool	 stack_push(stack_t* stck, void* data);
void*    stack_pop(stack_t* stck);
void	 stack_clear(stack_t* stck);

#endif
