#include "b-tree.h"

page *create_new_tree(page *page) {
    return new_page(0, 0, 0);
}

bool delete_page(page);
