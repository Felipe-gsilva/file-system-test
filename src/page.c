#include "page.h"

page *create_new_tree(i8 key) {
    page* newpage = malloc(sizeof(page));
    newpage->keys = malloc(sizeof(i8)*ORDER-1);
    newpage->children = malloc(sizeof(i8)*ORDER);
    newpage->keys[0].key = key;
    return newpage;
}
