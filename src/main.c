#include <stdio.h>
#include <fastq_file_reader.h>


void read_file_line_by_line(const char *filename);

int main() {
    printf("Hello, World!\n");
    read_file_line_by_line("/home/mihai/fastq_data/SRR062634_1.fastq");
    return 0;
}


