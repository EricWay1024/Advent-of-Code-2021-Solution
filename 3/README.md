# Problem 3

In part 1, we maintain an array `cnt` to count the number of 0 and 1 for each position. Then we construct `a` ("`gamma`" in the problem description) and `b` ("`epsilon`") position by position. Notice that binary numbers are represented with strings here to easily get the bit of each position.

In part 2, a function `vector<string> filter(vector<string> &v, int k, int mode)` is defined, where `v` is the current list of binary numbers, `k` is the current bit position, and `mode` is either 0 or 1 representing whether we are using "oxygen generator rating" or "CO2 scrubber rating". The return value is a subset of `v` after considering current bit position. The function `int cal(vector<string> v, int mode)` returns the corresponding rating for `v` by repeatedly calling `filter` until there is only one element in `v` left.

