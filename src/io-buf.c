#include "io-buf.h"

io_buf *alloc_io_buf(){
    io_buf *io = malloc(sizeof(io_buf));
    io->hr = malloc(sizeof(header_record));
    if(io) {
        puts("@Allocated IO_BUFFER");
        return io;
    }
    puts("!!Could not allocate IO_BUFFER");
    return NULL;
}

void read_data_header(io_buf *io){
    char hp_keyword[100]; 
    u16 hp_value;
    if (!io->fp){
        puts("!!Could not read data header");
        return;
    }

    fscanf(io->fp, "%s", hp_keyword);
    fscanf(io->fp, "%s %hu", hp_keyword, &hp_value);
    io->hr->record_size = hp_value;
    fscanf(io->fp, "%s %hu", hp_keyword, &hp_value);
    io->hr->id_size = hp_value;
    fscanf(io->fp, "%s %hu", hp_keyword, &hp_value);
    io->hr->name_size = hp_value;
    fscanf(io->fp, "%s", hp_keyword);
    puts("@Header Record Loaded\n");
}

void write_data_header(FILE *fp, header_record *hr){
    if(!fp){
        printf("!NULL file\n");
        exit(-1);
    }
    fprintf(fp, "%s\nrecord_size %hu\nid_size %hu\nname_size %hu\n%s", SOHR, hr->record_size, hr->id_size, hr->name_size, EOHR);
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

void load_file(io_buf *io, char *file_name) {
    if(io->fp != NULL) {
        puts("--> buffer already filled\n--> closing logical link\n");
        fclose(io->fp);
    }

    strcpy(io->name, file_name);
    printf("@Loading file: %s\n", file_name);

    if(!file_name) {
        puts("!!ERROR: no file");
        return;
    }

    io->fp = fopen(io->name, "r");

    if (io->fp == NULL) {
        printf("Error opening file %s ERROR: %d",io->name, -10);
        exit(1);
    }
    
    read_data_header(io);
    puts("@File loaded");
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
    if (io) {
        if (io->fp) {
            fclose(io->fp);
            io->fp = NULL;  
        }

        if (io->hr) {
            free(io->hr);
            io->hr = NULL; 
        }

        free(io);
        io = NULL;
    }

    puts("@Buffer cleared\n");
}
