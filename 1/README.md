# Problem 1

A function `int cal(vector<int> &a)` is defined in both parts to find the number of `i` such that `a[i - 1] < a[i]`. In part 1 we simply apply `cal` to `a`; in part 2 we first find `b` which is the sliding window sum of `a`, then apply `cal` to `b`.