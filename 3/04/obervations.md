When using the example I try to convert the int -2147483648 into string, I
print the following string "-(" instead of the correct one. If I try to convert
the int -2147483647 it correctly prints "-2147483647".

Ok, I understood why. The operation statement "n = -n;" is the same as
"n = 0 - n;" which is a two's complement means "move n times to the left" if
from 0 we move -2147483648 to the left, that is 2147483648 to the right we end
in -214748648 again! Don't believe me? Ok, imagine a 4 bit number in a two's
complement representation that would look like this:

    0 1 2 3 4 5 6 7 -8 -7 -6 -5 -4 -3 -2 -1

So if n = 2, then -n would be moving from 0 two positions to the left that would
put us in -2. Imagine that n = -2, then -n would be moving from 0 two positions
to the right, that would put us in 2. Now imagine that n = -8, then -n would be
moving from 0 eight positions to the right. Where would that put us.... that is
correct in -8 again!!!!

Going back to the example then -n is -2147483648 so when we do "n % 10 + '0'"
that would be "-2147483648 % 10 + 48" which would be "-8 + 48" wich give us 40,
and in the ascii table the char that is at position 40 is '(' so we do
"s[0] = '('" then the evaluation we do in the while is "(-2147483648 / 10) > 0"
that would be "-214748364 > 0" which is 0 (false) and we dont go over the body
again, sign at this time is -2147483648 so the if is 1 (true) and we do "s[1] =
'-' " this far s = ")-" then we reverse it and we get the output we found: "-("
