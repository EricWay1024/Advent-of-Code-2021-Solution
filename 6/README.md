# Problem 6

Consider `b[i] (0 <= i <= 8)` is the number of fishes with timer `i` on the current day. Initially `b[i]` is obtained from counting the occurrences of each number in the input. Each day, we get a new `b` from the old one according to the rules given. After `n` days (`n` iterations of updating `b`), the sum of fishes is the sum of `b[i]`.

The only difference between part 1 and part 2 is the number of iterations applied and that in part 2 `long long` needs to be used for `b`.

P.S. The progression of `b` can be represented as a matrix multiplication. This can be useful in case `n` is extremely large.