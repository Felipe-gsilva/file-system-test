#include "main.h"

void cli() {
    return;
}

int main(int argc, char *argv[]) {
    printf(".");
    char fp_name[100];
    FILE *fp;

    cli();

    fp = create_data_file("data.ct", "public/data.ct");
    if (fp == NULL) {
        fprintf(stderr, "Failed to create data file\n");
        return 1;
    }
    fclose(fp);

    printf(".");
    strcpy(fp_name, "public/data.ct");

    fp = NULL;
    load_file(fp, fp_name);  

    printf(".");

    return 0;
}
