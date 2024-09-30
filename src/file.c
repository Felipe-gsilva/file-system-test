#include "file.h"

bool read_header(FILE *fp, header_record *hp) {
    char hp_keyword[100]; 
    u8 hp_value;
    if (fp != NULL){
        fscanf(fp, "%s", hp_keyword);
        fscanf(fp, "%s %hhd", hp_keyword, &hp_value);
        hp->record_size = hp_value;
        fscanf(fp, "%s %hhd", hp_keyword, &hp_value);
        hp->id_size = hp_value;
        fscanf(fp, "%s %hhd", hp_keyword, &hp_value);
        hp->name_size = hp_value;
        fscanf(fp, "%s", hp_keyword);
        printf("@Header Record Loaded");
        return true;
    }
    return false;
}

void write_header(FILE *fp, header_record *hp){
    if(!fp){
        printf("!\n");
        exit(-1);
    }
    fprintf(fp, "%s\nrecord_size %hhd\nid_size %hhd\nname_size %hhd\n%s", SOHR, hp->record_size, hp->id_size, hp->name_size, EOHR);

}

void populate_header(header_record *hp) {
    if (hp == NULL) {
        hp = malloc(sizeof(header_record));
        if (hp == NULL) {
            return; 
        }
    }

    hp->record_size = 8 * (int)sizeof(header_record); 
    hp->id_size = 8 * (int)sizeof(u8); 
    hp->name_size = (int)sizeof(char) * 50; 
}

void write_data(){}

void load_file(FILE *fp, char *fp_name) {
    printf("@Loading file: %s\n", fp_name);

    fp = fopen(fp_name, "r");

    if (fp == NULL) {
        fprintf(stderr,"Error opening file %s ERROR: %d",fp_name, -10);
        exit(1);
    }

    header_record *hp;
    hp = malloc(sizeof(header_record));

    read_header(fp, hp);
    fseek(fp, 0, SEEK_SET);
}

FILE *create_data_file(char *address) {
    FILE *fp;
    header_record *hp;

    hp = malloc(sizeof(header_record));
    if (hp == NULL) {
        fprintf(stderr, "Memory allocation failed for header_record\n");
        return NULL;  
    }

    fp = fopen(address, "w+");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", address);
        free(hp); 
        return NULL; 
    }

    populate_header(hp);
    write_header(fp, hp);

    free(hp);  
    return fp;
}

void insert_data () {

}

