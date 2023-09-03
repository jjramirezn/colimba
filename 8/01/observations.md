I tried both ways reading char by char and by chunks of BUFSIZ size. In my
computer BUFSIZ is 1024.
File tested: main.c
Number of times: 7 and discarded max and min

Lowlevel + char by char:    4932 ticks
FILE + char by char:        437 ticks
Lowlevel + chunks:          149 ticks
FILE + chunks:              193 ticks

The biggest difference is that by chunks is faster than by char.
If we do it by char lowlevel is 22% faster than using the FILE struct

-------------------------------------------------------------------------

Second test is using a 9.5MB file, I only tested this by chunks and the results
where surprising

FILE:       96395 ticks
Lowlevel:   109935 ticks

FILE seems to be 12% faster
