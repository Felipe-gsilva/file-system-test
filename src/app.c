#include "app.h"

void cli() {
    puts("cli");
    return;
}

app* alloc_app() {
    app* appl = malloc(sizeof(app));
    appl->in = alloc_io_buf();
    appl->out = alloc_io_buf();
    if (appl)
        return appl;
    return NULL;
}

void clear_app(app* app) {
    clear_io_buf(app->in);   
    clear_io_buf(app->out);
    free(app);
}

int main(int argc, char **argv) {
    app *app;
    app = alloc_app();

    cli();

    app->in->fp = create_data_file("public/data.ct");
    if (app->in->fp == NULL) {
        printf("Failed to create data file\n");
        return 1;
    }

    clear_io_buf(app->in);

    strcpy(app->in->name, "public/data.ct");
    load_file(app->in);  

    clear_app(app);
    return 0;
}
