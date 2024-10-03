#include "b-tree.h"

page *create_new_tree(page *page) {
    return new_node(0, "page");
}

bool delete_page(page);
