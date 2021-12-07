# Problem 7

In part 1, define `ll cal(vector<ll> &a, ll t)` as the sum of `abs(u - t)` for `u` in `a`, then answer is the minimum of `cal(a, u)` for all `u` in `a`.

In part 2, we further define `f(n) = 1 + 2 + ... + n = (n + 1) * n / 2`. Thus just change the definition of `cal` to the sum of `f(abs(u - t))` for `u` in `a`.
