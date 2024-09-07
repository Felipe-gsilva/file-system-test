#include "file.h"

header_record *read_header(FILE *fp, header_record *hp) {
  char hp_keyword[100]; 
  i8 hp_value;
  fscanf(fp, "%s %hhd", hp_keyword, &hp_value);
  hp->record_size = hp_value;
  fscanf(fp, "%s %hhd", hp_keyword, &hp_value);
  hp->id_size = hp_value;
  fscanf(fp, "%s %hhd", hp_keyword, &hp_value);
  hp->name_size = hp_value;
  fscanf(fp, "%s", hp_keyword);
  printf("@Header Record Ended at: %p\n", fp);
  return hp;
}

void write_header(FILE *fp, header_record *hp){
  if(!fp){
    printf("!\n");
    exit(-1);
  }
  fprintf(fp, "---\nrec_sz %hhd\nid_sz %hhd\nnm_sz %hhd\n%s", hp->record_size, hp->id_size, hp->name_size, EOHR);
}

void populate_header(header_record *hp) {
  if(hp == NULL)
    hp = malloc(sizeof(header_record));
  hp->record_size = 8 *(i8)sizeof(header_record);
  hp->id_size = 8 * (i8)sizeof(i8);
  hp->name_size = (i8)sizeof(char)*50;
}

void write_data(){}

void load_file(FILE *fp, char *fp_name) {
  printf("file: %s\n", fp_name);

  fp = fopen(fp_name, "r");

  if (fp == NULL) {
    printf("Error opening file: %s\n", fp_name);
    exit(1);
  }

  char *hn;
  header_record *hp;

  read_header(fp, hp);
  
  
  fseek(fp, 0, SEEK_SET);
}

FILE *create_data_file(char *hn, char *address) {
  FILE *fp;
  header_record *hp;
  hp = malloc(sizeof(header_record));
  fp = fopen(address, "w+");
  fseek(fp, 0, SEEK_CUR);
  populate_header(hp);
  write_header(fp, hp);
  free(hp);
  return fp;
}

void insert_index () {
}

int main(int argc, char *argv[]) {
  char fp_name[100];
  FILE *fp;

  printf(".");
  fp = create_data_file("data.ct", "public/data.ct");
  fclose(fp);

  printf(".");
  strcpy(fp_name, "public/data.ct"); 
  load_file(fp, fp_name);
  printf(".");
  fclose(fp);

}
