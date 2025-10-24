#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fastq_file_reader.h>

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

}