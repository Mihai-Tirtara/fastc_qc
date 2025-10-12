#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // For ssize_t on POSIX systems


#define TICK(X) clock_t X = clock()
#define TOCK(X) printf("time %s: %g sec.\n", (#X), (double)(clock() - (X)) / CLOCKS_PER_SEC)
#define CHUNK_SIZE 1024 * 1024  

void read_whole_file(const char *filename);
void read_file_in_chunks(const char *filename);
void read_file_line_by_line(const char *filename);

int main() {
    printf("Hello, World!\n");
    TICK(t1);
    read_whole_file("/home/mihai/fastq_data/SRR062634_1.fastq");
    TOCK(t1);
    TICK(t2);
    read_file_in_chunks("/home/mihai/fastq_data/SRR062634_1.fastq");
    TOCK(t2);   
    TICK(t3);
    read_file_line_by_line("/home/mihai/fastq_data/SRR062634_1.fastq");
    TOCK(t3); 
    return 0;
}

// TODO: Implement the three different file reading methods as per plan.md
// 1. Load the whole file in memory and then read it bit by bit
void read_whole_file(const char *filename) {

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return; // Handle error appropriately       
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(file_size + 1);

    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0'; // Null-terminate the buffer
    fclose(file);
    free(buffer);

    
}   
// 2. Load the file in chunks and read each bit in the chunk and then reallocate a new chunk
void read_file_in_chunks(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return; // Handle error appropriately   
    }

    size_t bytes_read = 0;
    char *buffer = (char *)malloc(CHUNK_SIZE);

    while ((bytes_read = fread(buffer, 1, CHUNK_SIZE , file)) > 0) {
    }

    free(buffer);
    fclose(file);
    
}
// 3. Load the file line by line and read it line by line
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

