# Problem 7

In part 1, define `ll cal(vector<ll> &a, ll t)` as 

$$
\sum_{i=1}^n |a_i-t|,
$$

then answer is the minimum of `cal(a, u)` for all `u` in `a`.

In part 2, we further define `f(n) = 1 + 2 + ... + n = (n + 1) * n / 2`. Thus just change the definition of `cal` to

$$
\sum_{i=1}^n f(|a_i-t|),
$$
