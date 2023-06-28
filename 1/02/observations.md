Experiment
==========
The character will be inserted after the hello and before the comma, I will use
"all" the ascii characters.

General observations
====================
The warnings are in the warnings.txt file and the output is on the output.txt
file.

Many, many are unknown and the result is just the character is printed (and the
compiler give us a warning). The \u, \U and \x I had to investigate to use them
properly. Next will be a table of all the known ones

| Char | Comment |
| ---- | ------- |
| a    | My editor shows me "^G" in that place. After googling it shows that is
a "beep" and then I saw that my terminal actually beeps!!!!! That does not
happens when printing only hello world. So I print a char and the OS beeps
because that is the beep char????? I love this, lets put printf("\a") in an
infinite loop and party like its 1988 |
| b    | My editors shows me "^H", when printing it removes last char and print
"hell, world", same|
| e    | It has a non-standard warning. My editor shows me "^[" and when
printing it removes the next char "hello world"|
| E    | Same as e|
| f    | "^L" Prints a new line but the next line is alligned with the end of
the first line. After googling: wtf is a formfeed page break?|
| n    | Ye olde new line|
| r    | "^M" removes last word (just the word or to begining?) prints ", world". After googling is a carriage return so beginning of line it is. Carriage? How old is this thing|
| t    | Ye olde tab |
| u    | Ye olde unicode |
| U    | Higher unicode points? never seen one, it is cool |
| v    | "^K" Seems to be doing the same as "\f" but it is different "^L" vs "^K". After googling is a vertical tab, just it happens that hello is 4 chars|
| x    | when googling: "The byte whose numerical value is given by hh… interpreted as a hexadecimal number"|
| 0-???| https://en.wikipedia.org/wiki/Escape_sequences_in_C#endnote_Note2|
| "    | Escape the quotes |
| %    | Conversion specifier? ahhhhh yeah, format strings. Ye olde format strings |
| '    | Escape the quote |
| (    | non-etandard |
| ?    | "Question mark (used to avoid trigraphs)". WTF is a trigraph |
| [    | non-standard |
| {    | non-standard |

Questions
=========
- What is a trigraph?
