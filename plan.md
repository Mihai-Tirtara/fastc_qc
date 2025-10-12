Fast QC (Quality Control values for sequence data)

# 1.FASTQ File Parsing

Write a robust C function to read a FASTQ file line-by-line or read-by-read, handling both uncompressed and GZIP-compressed files (you'll need to link a library like zlib for this). 

There are 3 different ways to read a file 
- Load a the whole file in memory and then read it bit by bit 
- Load the file in chunks and read each bit in the chunk and then realocate a new chunk 
- Load the file line by line and read it line by line 

Let's try each method and see which one is the fastest




