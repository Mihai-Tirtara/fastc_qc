# FastQC in C

This project will be a clone of FastQC written in C.  
FastQC it's a tool for generating quality control values for DNA or RNA sequence data.

# For the MVP what we want to achieve is this:

- [x] ~~Parse 1 FastQ file~~  
- [ ] Parse Zipped FastQ file   
- [ ] Create data structure to hold the reads   
- [ ] Generate text output with basic statistics including file name,  Encoding of quality values type, total number of sequences, sequence length, %GC content   
- [ ]  Generate plot with Per Base Sequence Quality(you need to convert the quality values from asci to numerical )

# File structure 

- Parser   
- Basic Statistics   
- Base Sequence Quality   
- HTML Report 

## Parser

This file will have the following methods:

- ReadFile ( method who will read a fastQ file line by line) and will also read in case the file is gzip  
- Struct to hold a sequence (id, char\[\] sequence, union of char and char\[\], char\[\])

## Basic Statistics 

This file will have the following methods:

- GenerateBasicStatistics (will return a text output with all the information)  
- GetEncodingQualityType (will return which ASCII encoding of quality values was found in this file)  
- GetTotalNumberSequences (will return the total number of sequences found in the file)   
- GetSequenceLength (will return length of the shortest and longest sequence in the  
- set. If all sequences are the same length only one value is reported.\\  
- GetGCPercent (will return the overall %GC of all bases in all sequences)

Base Sequence Quality

- CalculateBaseSequenceQuality (will calculate the range of quality values across all bases at each position in the FastQ file)  
- GenerateReport(Return an HTML report that shows an overview of the range of quality values across all bases)

## HTML Report

##  This file will create a html report based on the analysis 

# Later to implement analysis modules 

Focus on implementing the logic for a few key reports:

| FastQC Module | What You'll Learn/Do in C |
| :---- | :---- |
| **Per Sequence Quality Scores** | Calculate the average quality score for **each entire read** and generate a histogram of these averages. |
| **Per Base Sequence Content** | Count the frequency of A, C, G, T at **each position** of the read to spot sequence bias. |
| **Adapter Content** | Implement a simple string-matching algorithm (**strstr** or KMP if you're ambitious) to search for common Illumina adapter sequences. |

### 

