#include "app.h"

void cli() {
    puts("cli");
    return;
}

app* alloc_app() {
    app* appl = malloc(sizeof(app));
    appl->in = alloc_io_buf();
    appl->out = alloc_io_buf();
    if (appl && appl->in && appl->out){
        puts("@Allocated App Buffer\n");
        return appl;
    }
        
    puts("!!Error while allocating App Buffer\n");
    return NULL;
}

void clear_app(app* app) {
    if(app->in) {
        clear_io_buf(app->in);   
        app->in = NULL;
    }
    if(app->out) {
        clear_io_buf(app->out);
        app->out = NULL;
    }
    if(app) {
        free(app);
        app = NULL;
    }
    if(app)
        puts("!! Error while clearing app");
}

int main(int argc, char **argv) {
    app *app;
    app = alloc_app();

    cli();
    app->in->fp = create_data_file("public/data.ct");
    if (app->in->fp == NULL) {
        printf("Failed to create data file\n");
        exit(0);
    }

    load_file(app->in, "public/data.ct");
    
    clear_app(app);
    return 0;
}
