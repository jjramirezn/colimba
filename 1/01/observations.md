Experiment table
================

| Code | Experiment | Compiles | Runs | Warning/Error | Comment |
| ---- | ---------- | -------- | ---- | ------------- | ------- |
| 001  | Remove include | No   | No   | 001.c:3:9: error: implicitly declaring library function 'printf' with type 'int (const char \*, ...)' | Fix: agregate the include that defines the function (or defining the function) |
| 002  | Remove main | No      | No   | 002.c:3:1: error: expected identifier or '(' | The compiler seems confused that it found the opening brace before an 'identifier' |
| 003  | Remove opening brace | No | No | 003.c:4:9: error: expected function body after function declarator // 003.c:5:1: error: extraneous closing brace ('}') | The first error seems to indicate that the body is defined by the braces and it is needed after a function declaration. The second error indicates that there is no matching opening brace |
| 004  | Remove the printf line | Yes | Yes |         | Doesn't do much, still weights 16Kb |
| 005  | Remove closing brace | No | No | 005.c:5:34: error: expected '}' // 005.c:4:1: note: to match this '{' | Indicates that the closing brace is needed. Produces a helpful indication of which brace needs closing (in more complex programs this may not be the one), the compiler is not so bad after all... |
| 006  | Remove hash before include | No | No | 006.c:1:1: error: unknown type name 'include' // 006.c:1:9: error: expected identifier or '(' | Without the hash include does not works. include is not a special word. First error seems to indicate that it tried to read it as a variable (?). Second error, maybe the compiler hoped that included was a function (?). The compiler tries to make sense of what we feed it. I am starting to feel a little bad for feeding it nonsense on purpose. |
| 007  | Remove parentheses after main | No | No | 007.c:3:1: warning: declaration specifier missing, defaulting to 'int' // 007.c:3:1: warning: variable named 'main' with external linkage has undefined behavior [-Wmain] // 007.c:3:5: error: expected ';' after top level declarator | Ok, it understood main as a variable. If I don't specify the type of a variable it will default to int, it seems to be allowed but discorauged (warning, no error). WTF is external linkage? WTF is undefined behavior? Semicolons are important |
| 008  | Remove parentheses of printf | No | No | 008.c:5:15: error: expected ';' after expression // 008.c:5:9: warning: expression result unused [-Wunused-value] // 008.c:5:16: warning: expression result unused [-Wunused-value] | The compiler is a little dumb, it does not see the things the way we do. Is clear that that is a function without parentheses, but it doesnt know. Really obsessed with semicolons |
| 009  | Sames as 008 but adding semicolon after printf | Yes | Yes | 009.c:5:9: warning: expression result unused [-Wunused-value] // 009.c:5:17: warning: expression result unused [-Wunused-value] | Ok, a valid C program that does not do anything. What is an expression?. The generated executable is very similar to the 004 one, both are 16Kb in size opossed to 48Kb of the hello executable. And a quick diff with xxd reveals very little differences (which I dont understand). I imagine that the printf function is not even included on the executable |
| 010  | Remove double quotes | No | No | 010.c:5:16: error: use of undeclared identifier 'hello'; did you mean 'ftello'? // /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h:321:8: note: 'ftello' declared here // 010.c:5:23: error: use of undeclared identifier 'world' | Quotes make strings (are they strings or char arrays or something else?). Look, the compiler is suggesting another name that it knows, maybe there is hope for some typos? ||
| 011  | Remove newline | Yes  | Yes  |               | Doesn't print the new line. My shell is a little smarter than others and just indicates that to me with the "%" character and puts me in a new line (god bless zsh). Testing with unconfigured bash, the result is: hello, worldbash-3.2$ |
| 012  | Change printf to print | No | No | 012.c:5:9: error: implicit declaration of function 'print' [-Werror,-Wimplicit-function-declaration] // 012.c:5:9: note: did you mean 'printf'? //  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h:170:6: note: 'printf' declared here | Niceee, it suggested the actual function I meant. There is hope!

General observations
====================

Some other testing that I did reliying on my IDE messages instead of compiling.
Seems that the hash character is to indicate something called preprocessing
directive (with the message pp\_invalid\_directive). If there is something inside
of the function argument values it tries to use it as a type first (makes sense)

Questions
=========
- What is external linkage?
- What is undefined behavior?
- What is an expression?
- What is that thing in between the double quoutes?
