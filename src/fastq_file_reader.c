#include <fastq_file_reader.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <zlib.h>

void read_file_line_by_line(const char *filename) {
  // Implementation here
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Error opening file");
    return; // Handle error appropriately
  }
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, file)) != -1) {
    // Process the line
  }

  free(line);
  fclose(file);
  printf("Finished reading file: %s\n", filename);
}

void read_gz_file_line_by_line(const char *filename) {
  gzFile file = gzopen(filename, "rb");
  if (file == NULL) {
    perror("Error opening gz file\n");
    return;
  }

  gzbuffer(file, 1024 * 128); // set internal buffer to 128KB
  char buffer[64 * 1024];     // 64KB buffer for reading lines

  while (gzgets(file, buffer, sizeof(buffer)) != NULL) {
    // Process the line
  }

  if (!gzeof(file)) {
    int errnum;
    const char *error_string = gzerror(file, &errnum);
    fprintf(stderr, "Error reading gz file: %s\n", error_string);
  }

  gzclose(file);
  printf("Finished reading gz file: %s\n", filename);
}
