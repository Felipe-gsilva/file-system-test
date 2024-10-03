#include "page.h"

page *alloc_page() {
    page* newpage = malloc(sizeof(page));
    if(newpage)
        return newpage;
    return NULL;

}

page *new_page(u16 rrn, key keys[], u16 children[]) {
    page *page = alloc_page();
    page->rrn = rrn;   
    if(keys && children) {
        for(int i = 0; i < ORDER; i++) {
            page->keys[i] = keys[i];
            page->children[i] = children[i];
        }
        page->children[ORDER-1] = children[ORDER-1];
    }
    if(page)
        return page;
    return NULL;
}


void clear_page(page *page) {
    if(page) {
        free(page);
        printf("successfully freed page");
        return;
    }
    printf("error while freeing page");
}
