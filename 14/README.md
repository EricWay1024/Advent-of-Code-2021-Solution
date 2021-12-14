# Problem 14

It suffices to use brtual force to solve part 1.

In part 2, `mem[p][q][k][i]` denotes the occurrences of letter `i + 'A'` given string `ab` (where `a = p + 'A'` and `b = q + 'A'`) has run `k` insertion steps, excluding the first letter in the resultant string. Thus 
- when `ab` does not appear in the dictionary, `mem[p][q][k][q] = 1` and all `i != q` has `mem[p][q][k][i] = 0`;
- when `ab` appears in the dictionary, say `ab -> x` and `x = r + 'A'`, then we first apply one insertion and leave the remaining `k-1` insertions to recurrsion. Thus for all `i`, `mem[p][q][k][i] = mem[p][r][k-1][i] +  mem[r][q][k-1][i]`.

The initial cases are when `k = 1` which are trivial to handle. 

For example, when `NNCB` has run 2 insertion steps, we have `NBCCNBBBCBHCB`. That is, between the original `NN` we now have `NBCCN` and thus `mem['N']['N'][2]['B'] = 1, mem['N']['N'][2]['C'] = 2, mem['N']['N'][2]['N'] = 1` (`-'A'` ommited here). Notice we only count `N` once because we exclude the first letter.

Hence the occurences of letter `i + 'A'` in string `s` after `k` steps is

`sum(mem[s[j]-'A'][s[j+1]-'A'][k][i] for j in [0, 1, ..., s.size() - 2]) + (s[0] == i)`. The first letter of the entire string is counted separately.

`long long` must be used for part 2.