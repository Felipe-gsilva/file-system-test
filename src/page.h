#ifndef _PAGE_H
#define _PAGE_H

#define ORDER 4
#include "file.h"

typedef struct key {
    u8 key;
    char *file_name;
    u8 data_file_key;
} key;

typedef struct page {
    u8 RRN;
    struct page *children; 
    key *keys;            
} page;

/**
 * Creates a new tree with the specified key.
 * @param key The initial key for the new tree.
 * @return Pointer to the newly created tree root page.
 */
page *create_new_tree(u8 key);

#endif // _PAGE_H
