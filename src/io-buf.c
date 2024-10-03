#include "io-buf.h"

io_buf *alloc_io_buf(){
    io_buf *io = malloc(sizeof(io_buf));
    io->name = NULL;
    io->fp = NULL;
    io->hr = NULL;
    if(io)
        return io;
    puts("!!Could not allocate IO_BUFFER");
    return NULL;
}

void read_data_header(io_buf *io){
    char hp_keyword[100]; 
    u16 hp_value;
    if (!io->fp ){
        puts("!!Could not read data header");
        return;
    }
    fscanf(io->fp, "%s", hp_keyword);
    fscanf(io->fp, "%s %hd", hp_keyword, &hp_value);
    io->hr->record_size = hp_value;
    fscanf(io->fp, "%s %hd", hp_keyword, &hp_value);
    io->hr->id_size = hp_value;
    fscanf(io->fp, "%s %hd", hp_keyword, &hp_value);
    io->hr->name_size = hp_value;
    fscanf(io->fp, "%s", hp_keyword);
    printf("@Header Record Loaded");
}

void write_data_header(FILE *fp, header_record *hr){
    if(!fp){
        printf("!NULL file\n");
        exit(-1);
    }
    fprintf(fp, "%s\nrecord_size %hd\nid_size %hd\nname_size %hd\n%s", SOHR, hr->record_size, hr->id_size, hr->name_size, EOHR);
}

void populate_header(header_record *hp) {
    if (hp == NULL) {
        hp = malloc(sizeof(header_record));
        if (hp == NULL) {
            return; 
        }
    }

    hp->record_size = 8 * (int)sizeof(header_record); 
    hp->id_size = 8 * (int)sizeof(u16); 
    hp->name_size = (int)sizeof(char) * 50; 
}

void write_data(io_buf *io, int count, ...){
    if(!io || !io->fp || !io->hr) {
        printf("!!NULL io_buf\n");
    }
    va_list args;
    va_start(args, count);
    for (int i = count; i >= 0; i = va_arg(args, int))
        printf("%d ", i);
    va_end(args);
    // TODO add the string writing
}

void load_file(io_buf *io) {
    printf("@Loading file: %s\n", io->name);

    io->fp = fopen(io->name, "r");

    if (io->fp == NULL) {
        fprintf(stderr,"Error opening file %s ERROR: %d",io->name, -10);
        exit(1);
    }

    read_data_header(io);
    fseek(io->fp, 0, SEEK_SET);
}

FILE *create_data_file(char *address) {
    FILE *fp;
    header_record *hp;

    hp = malloc(sizeof(header_record));
    if (hp == NULL) {
        fprintf(stderr, "!!Memory allocation failed for header_record\n");
        return NULL;  
    }

    fp = fopen(address, "w+");
    if (fp == NULL) {
        fprintf(stderr, "!!Error opening file: %s\n", address);
        free(hp); 
        return NULL; 
    }

    populate_header(hp);
    write_data_header(fp, hp);

    free(hp);  
    return fp;
}

void clear_io_buf(io_buf *io) {
    free(io->name);
    free(io->hr);
    fclose(io->fp);
}
