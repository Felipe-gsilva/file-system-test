#ifndef _app
#define _app

#include "io-buf.h"

typedef struct app app;

struct app {
    io_buf *in;
    io_buf *out;

};

void cli();

app *alloc_app();

int main(int argc, char **argv);

#endif
