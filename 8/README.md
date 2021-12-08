# Problem 8

```
  0:      1:      2:      3:      4:
 aaaa    ....    aaaa    aaaa    ....
b    c  .    c  .    c  .    c  b    c
b    c  .    c  .    c  .    c  b    c
 ....    ....    dddd    dddd    dddd
e    f  .    f  e    .  .    f  .    f
e    f  .    f  e    .  .    f  .    f
 gggg    ....    gggg    gggg    ....

  5:      6:      7:      8:      9:
 aaaa    aaaa    aaaa    aaaa    aaaa
b    .  b    .  .    c  b    c  b    c
b    .  b    .  .    c  b    c  b    c
 dddd    dddd    ....    dddd    dddd
.    f  e    f  .    f  e    f  .    f
.    f  e    f  .    f  e    f  .    f
 gggg    gggg    ....    gggg    gggg
```

Part 1 of the problem is straight-forward to solve since we only care about the four output digits. Increment the counter when the length of the string is either 2, 3, 4, or 7.

Part 2 is quite complicated and here I present one possible way to solve it. 

Our main goal is to find

```cpp
map<string, int> dict; // dict[s] is the number that pattern s represents
```

Inspired from part 1, we first define

```cpp
map<int, vector<string>> mp; // mp[k] is all signal patterns with length k
```
`mp` can be obtained quite easily. We know that `mp[2]` contains only the pattern for 1, so we can update `dict` with this piece of information. So it is with 4, 7, and 8.

Next we must try to figure out 

```cpp
map<char, char> ans; // ans[c] is the segment in the given pattern corresponding to segment c in the standard pattern
```

We first notice that `ans['a']` is the character which appears in the pattern for `7` but not in for `1`.

Then let us count the occurrences of each segment in the ten given patterns, as we find that in the ten standard patterns, each segment has the following occurrences:

```
a: 8
b: 6
c: 8
d: 7
e: 4
f: 9
g: 7
```

Thus we define 
```cpp
map<char, int> cnt; // cnt[c] is the number of occurrences of character c in the given signal patterns
```

and `ans['b']`, `ans['e']` and `ans['f']` can be deduced directly from `cnt`, because `cnt[c] == 6` implies `ans['b'] = c` and so on. Also since we have already figured out `ans['a']`, another `c` such that `cnt[c] == 8` must have `ans['c'] = c`. To distinguish between `d` and `g`, notice that `d` occurs in 4 while `g` does not.

So we are finished with `ans`. Using `mp` and `ans` we can fully deduce `dict`: any pattern with length 5 and with `ans['c']` and `ans['e']` in it must be that of 2, and so on.

Notice in order to have the four digit output value directly correspond to a key in `dict`, we must sort every string we get from input.

There is also a brutal way to solve part 2 (see `8-2-brutal.cpp`): traverse each possible `ans` (which has only 7!=5040 permutations) and check if using this permutation we can get the standard patterns.