#ifndef _PAGE_H
#define _PAGE_H

#include "io-buf.h"

#define ORDER 4

typedef struct key key;

typedef struct page page;

struct key {
    u16 key;
    char file_name[128];
    u16 data_file_key;
};

struct page{
    u16 rrn;
    key keys[ORDER-1];            
    u16 children[ORDER];
};

page *alloc_page();

page *new_page(u16 rrn, key keys[], u16 children[]);

void clear_page(page *page);

#endif 
