Ideas
=====
1. Very large input. The counters are int, so maybe a very big input will
  overflow them
2. Several lines with only blanks
3. Only one word
4. Word inmediatly followed by EOF

Results
=======
1. Tested with files of 2MB, 20MB and 5GB. The first two were handled ok, the
   third one I let run for a long time and it never returned anything, so I
   think it did not work. I tested with my system wc and it handled the 5GB file
   just fine. After testing a litle and printing my INT\_MAX, I realize that
   there is no overflow happening, so it may just be that the program is not
   as efficient as gnu wc. But still, an input can overflow this program.
2. Works correctly
3. It works! After reading carefully the line again, it works because the
   initial state is OUT, nice!
4. Same as 3.

