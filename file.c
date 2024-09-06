#include "file.h"

header_record *read_header(FILE *fp) {
  i8 id;
  char test[100]; 
  header_record *hp;
  hp = malloc(sizeof(header_record));

  while (fscanf(fp, "%s %hhd", test, &id) != EOF || strcmp(test, "---") != 0) {
    hp->rrn = id;
    if(strcmp(test, "---") == 0)
      printf("header file ended %d", fp);
  }
  return hp;
}

int main(int argc, char *argv[]) {
  char fp_name[100];
  FILE *fp;

  if (argc > 1) {
    strcpy(fp_name, argv[1]); 
  } else {
    strcpy(fp_name, "index-file.fel"); 
  }

  printf("index-file: %s\n", fp_name);

  fp = fopen(fp_name, "r");
  if (fp == NULL) {
    printf("Error opening file: %s\n", fp_name);
    exit(1);
  }

  signed char id;
  char test[100]; 

  header_record *hr = read_header(fp);
  printf("%hhd", hr->rrn);

  free(hr);
  fclose(fp);
  return 0;
}
