Ideas
=====
- I could split in half v outside of the loop and then go over each element. But
that would not be binary search wouldn't it?
- Somehow implement a check inside the while condition? Done, it is really
  outside of the loop thought?

Measuring run-time
==================
Ok, I have to google this one, it appears I can use a function called clock() to
get a timestamp before and after running the function.

Running each function only one does not give any meaningful information and it
seems like the function that I run first always takes some more ticks than the
other one. I must run them several times each

Ok, running them 1000 times each seems to indicate that there is no meningful
difference between both. Which makes sense because I am still doing one extra
check per iteration.
