# C Exercies

### Sam Schulman

## Ex 1

I interpreted the instructions here as requiring taking in the name from stdin, so I tried to use `scanf` since it's quick and dirty and would get the job done.
I encountered a problem, though, when running it on my lab VM in an SSH session.
Something about how SSH handled/buffered newlines made it completely skip waiting for my input and immediately output with an empty name, then exit.
So I switched to using `fgets(stdin)` which worked, although I had to remove an extra newline from the end of the string with some clever array indexing.

Speaking of arrays, I did use static strings for this.

![1770672434011](img/1770672434011.png)

## Ex 2

I tried two different ways of timing this program: within the code and outside the code.

The first method did give me some trouble, because the ordinary c `time()` from `<time.h>` only gives you time in seconds.
After poking around online I wound up using `<sys/time.h>` and `gettimeofday` instead.
This function returns a struct which has fields for seconds and microseconds, so I could subtract a starting and ending time with adequate resolution.
The second method was with the `time` package on linux, which times the execution of a binary.

![1770673373372](img/1770673373372.png)

The output shows the stark contrast in the results.
Internal measurement registered only 181 microseconds and external measurement clocked 38 times that span.
I surmise this is because my internal timing does not count OS-level process initialization or teardown procedures, and that's what makes up the difference.
Further support for this can be found by looking at the CPU time breakdown, since most of the 6.87ms was from sys time, not usr time.

No issues with convergence per se, although in theory I would run up against the limits of the C `double` type, with only so much precision available.
C does have a `long double` type, but the standard library `sqrt` and `pow` functions don't use it, so I stuck with normal `double`.

## Ex 3

I assumed the text file needed to be loaded dynamically and couldn't just be statically programmed into the code, so I wrote a routine using `fgets` and `sscanf` to do that work.

My matrix is a dynamically-allocated integer buffer, storing the matrix in one-dimensional memory in row-major order.

I had to figure out how to read lines from the file with a dynamic number of numbers per line.
I landed on a strategy that involved `sscanf` to load one value at a time, advancing my string pointer to the start of the next value by using `strchr` to find the next space.
I didn't want to spend more time on my I/O than my actual multiplication routine so as a result I'm trusting that the row/column values will not lie to me.
If they did, this would end with garbage data and almost certainly a segfault.

The actual computation was surprisingly simple.
Honestly, it was very satisfying having the real computation be only five lines with the real meat of it being only one.

```c
for (int i=0; i < rows; i++){
    for (int j=0; j < cols; j++){
        out[i] += matrix[i*cols+j]*vector[j];
    }
}
```

I wanted to exclude the I/O time from the equation and time only the matrix multiplication part, since that feels like the real core of the task here.
As a result, I decided to stick with my code-internal timing strategy from exercise 2.