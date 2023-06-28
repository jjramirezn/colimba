When copying the example as is it does not work because there is already a
getline in stdio.
longline.c:5:5: error: conflicting types for 'getline'
int getline(char line[], int maxline);
    ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h:348:9: note: previous declaration is here
ssize_t getline(char ** __restrict __linep, size_t * __restrict __linecapp, FILE * __restrict __stream) __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_3);
        ^
longline.c:17:43: error: too few arguments to function call, expected 3, have 2
        while ((len= getline(line, MAXLINE)) > 0)
                     ~~~~~~~              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h:348:9: note: 'getline' declared here
ssize_t getline(char ** __restrict __linep, size_t * __restrict __linecapp, FILE * __restrict __stream) __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_3);
        ^
longline.c:28:5: error: conflicting types for 'getline'
int getline(char s[], int lim)
    ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h:348:9: note: previous declaration is here
ssize_t getline(char ** __restrict __linep, size_t * __restrict __linecapp, FILE * __restrict __stream) __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_4_3);
        ^
