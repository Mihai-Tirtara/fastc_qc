Fast QC (Quality Control values for sequence data)

# 1.FASTQ File Parsing

Write a C function to read FastQ files 

There are 3 different ways to read a file 
- Load a the whole file in memory and then read it bit by bit 
- Load the file in chunks and read one chunk at the time 
- Load the file line by line and read it line by line 

With each method tested I have reached the following results:

Reading in chunks is the most efficient method:  
Avg time: Around 1.4 seconds 
Chunk size: 1024 



