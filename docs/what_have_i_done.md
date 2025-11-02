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
We are able now to read a zipped FastQ file using zlib library
Although at the moment the performance is not as good as reading the uncompressed file
We need to do some more research on how to improve the performance when reading a zipped file
Also one decision I took was to use the buffer on the stack instead of the heap this will improve performance as we don't need to allocate and free memory each time we read a line
