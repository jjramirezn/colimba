Ideas
=====
- I could split in half v outside of the loop and then go over each element. But
that would not be binary search wouldn't it?
- Somehow implement a check inside the while condition? Done, it is really
  outside of the loop thought? No its not.
- Look into the early return an see if there is something we can check after the
  while. I can check if v[mid] == x at the end and changle the while condition
  to low < high because if low == high it means that we reached the end and in
  that moment either v[mid] will be the correct one or x is not present on v.


Measuring run-time
==================

Before Fix
----------
Ok, I have to google this one, it appears I can use a function called clock() to
get a timestamp before and after running the function.

Running each function only one does not give any meaningful information and it
seems like the function that I run first always takes some more ticks than the
other one. I must run them several times each

Ok, running them 1000 times each seems to indicate that there is no meningful
difference between both. Which makes sense because I am still doing one extra
check per iteration.

After Fix
---------
Results did not change. I could try going even higher (1000 elements is not too
much). As I learned on the complexity class a bin search over 1000 elements will
take 10 iterations, so It does not matter much that we do one less check. I
wonder how big would n have to be in order to us to notice the difference. That
extra check is not the bottle neck here.
