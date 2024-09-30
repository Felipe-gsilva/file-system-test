#ifndef FILE_H
#define FILE_H

#include "defines.h"
#define SOHR "-------HEADER-------"
#define EOHR "--------------------"


// Define a structure for header records
typedef struct {
    u8 record_size;
    u8 id_size;
    u8 name_size;
} header_record;

// Function declarations

/**
 * Reads a header record from the given file pointer.
 * @param fp File pointer to the file to read from.
 * @param hp Pointer to a header_record structure to populate.
 * @return true if the header was successfully read, false otherwise.
 */
bool read_header(FILE *fp, header_record *hp);

/**
 * Writes the header record to the given file pointer.
 * @param fp File pointer to write to.
 * @param hp Pointer to the header_record structure to write.
 */
void write_header(FILE *fp, header_record *hp);

/**
 * Populates a header_record structure with default values.
 * @param hp Pointer to the header_record structure to populate.
 */
void populate_header(header_record *hp);

/**
 * Writes data to the file (function implementation not provided).
 */
void write_data();

/**
 * Loads a file and reads its header.
 * @param fp File pointer (will be set by fopen).
 * @param fp_name Name of the file to open and load.
 */
void load_file(FILE *fp, char *fp_name);

/**
 * Creates a data file with a header and returns the file pointer.
 * @param address File path to create the new file.
 * @return File pointer to the created file.
 */
FILE *create_data_file(char *address);

/**
 * Function to insert data into the file (function implementation not provided).
 */
void insert_data();

#endif // FILE_H
