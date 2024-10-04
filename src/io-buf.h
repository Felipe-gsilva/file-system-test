#ifndef FILE_H
#define FILE_H

#include "defines.h"
#define SOHR "-------HEADER-------"
#define EOHR "--------------------"

typedef struct header_record header_record;
typedef struct io_buf io_buf;


struct header_record {
    u16 record_size;
    u16 id_size;
    u16 name_size;
};

struct io_buf {
    char name[4096];
    FILE *fp;
    header_record *hr;
};


io_buf *alloc_io_buf();

void load_file(io_buf *io, char *file_name);

FILE *create_data_file(char *address);

void read_data_header(io_buf *io);

void populate_header(header_record *hp);

void write_data_header(FILE *fp, header_record *hp);

void write_data(io_buf *io, int count, ...);

void clear_io_buf(io_buf *io_buf);

#endif 
