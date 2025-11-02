#include <fastq_file_reader.h>
#include <stdio.h>

void read_file_line_by_line(const char *filename);
void read_gz_file_line_by_line(const char *filename);

int main(int argc, char *argv[]) {
  printf("Hello, World!\n");
  if (argc > 1) {
    // read_file_line_by_line(argv[1]);
    read_gz_file_line_by_line(argv[1]);
    return 0;
  }

  else {
    printf("Please provide a filename as an argument.\n");
  }
  return 0;
}
