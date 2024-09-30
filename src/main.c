#include "main.h"

void cli() {
    puts("cli");
    return;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    cli();

    fp = create_data_file("../public/data.ct");
    if (fp == NULL) {
        fprintf(stderr, "Failed to create data file\n");
        return 1;
    }

    fclose(fp);

    fp = NULL;
    load_file(fp, "../public/data.ct");  

    return 0;
}
