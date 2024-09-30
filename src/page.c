#include "page.h"

page *create_new_tree(u8 key) {
    page* newpage = malloc(sizeof(page));
    newpage->keys = malloc(sizeof(u8)*ORDER-1);
    newpage->children = malloc(sizeof(u8)*ORDER);
    newpage->keys[0].key = key;
    return newpage;
}
