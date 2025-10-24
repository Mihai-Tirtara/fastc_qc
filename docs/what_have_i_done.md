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

The above ideas are wrong after careful research it turns out that reading the FastQ files line by line is the most efficient method.
Which is also how is done in the original FastQC implementation in Java using bufferedreader() which has similar performance with getline() in C.


Now we are able to read the filename from the command line:
At the moment we are just using the basic implementation of argc with argv later when add more options flags we will swithc to get_opt()


Now we need to be able to also read a zip file 





