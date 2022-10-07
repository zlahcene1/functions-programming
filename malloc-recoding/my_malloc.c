#ifndef MALLOC_H_
#define MALLOC_H_

#include <stdbool.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct block_s
{
    bool is_free;
    size_t size;
    void *adress;
    struct block_s *next;
    struct block_s *prev;
} block_t;


#endif

#include <unistd.h>
#include <stddef.h>

#define OFFSET sizeof(block_t);

size_t _papesize = 0;

block_t *fi = NULL;




block_t *add_memory_fi(size_t size) 
{
    void *adress = sbrk(size + sizeof(block_t)) + size;

    block_t *newBlock;




//    size_t papesize = (size + sizeof(block_t)) / getpagesize() * getpagesize() + getpagesize();

    if (adress == (void *) -1)
        return NULL;
    newBlock = adress;
    newBlock->adress = adress + OFFSET;
    newBlock->size = size;
    newBlock->next = NULL;
    newBlock->prev = NULL;
    newBlock->is_free = false;
    return newBlock;
}

block_t *add_memory_in(block_t *B, size_t size)
{
    block_t *newBlock;
    void *tmp = sbrk(size + sizeof(block_t));

    if (tmp == (void *) -1)
        return NULL;
    for (; B->next != NULL; B = B->next);

    B->next = tmp;
    B->next->next = NULL;
    B->next->prev = B;
    B->next->is_free = false;
    B->next->size = size;
    B->next->adress = tmp + OFFSET;
    return B->next;
}

bool head_fi(size_t size)
{
    if (!fi) {
        _papesize = getpagesize();
        fi = add_memory_fi(size);
        return true;
    } return false;
}


//void *mmalloc(size_t size)
void *malloc(size_t size)
{
    block_t *B;

    if (size <= 0)
        return NULL;
    if (fi == NULL) {
    
        fi = add_memory_fi(size);
        return fi == NULL ? NULL : fi->adress; 
    }
    if (B != NULL) {
        for ( ;B->next; B = B->next)
            if (B->is_free && size <= B->size) {
                B->is_free = false;
                return B->adress;
            }
    } else {
        B = add_memory_in(fi, size);
        return B ? B->adress : NULL;
    }
    return NULL;
}


void *calloc(size_t nb, size_t size)
{
	int *tmp = malloc(size * nb);

	if (tmp && size > 0) {
		for (int i = 0; i < size; i++)
			tmp[i] = 0;
		return tmp;
	} else return NULL;
}

void free(void *ptr) //BTTF OBLIGATOIRE
{}

block_t *grep_for_realloc(void *_st, block_t *_fi)
{
    if (!_st)
        return NULL;
    for (; _fi; _fi = _fi->next)
        if (_st == _fi->adress)
            return _fi;
    return NULL;
}

void *realloc(void *ptr, size_t size)
{
    void *_ptr = malloc(size);
    block_t *_fi, *_st;

    _fi = grep_for_realloc(fi, ptr);
    _st = grep_for_realloc(fi, _ptr);
    memcpy(_st, _fi, size);
    return _ptr;
;}

// void		show_alloc_mem()
// {
//   block_t	*tmp;

//   printf("break : %p\n", sbrk(0));
//   tmp = fi;
//   while (tmp != NULL)
//     {
//       if (tmp->is_free == false)
// 	printf("%p - %p : %u bytes\n", tmp->adress,
// 		  tmp->adress + tmp->size, tmp->size);
//       tmp = tmp->next;
//     }
// }

// int main(int ac, char **av)
// {
//     void *S = mmalloc(sizeof(char)*5);
//     show_alloc_mem();
// }