# 2021 Advent of Code C++ Solution

My C++ solutions to 2021 Advent of Code, along with a simple Python script to fetch the current day's input file.

```bash
pip install requests
export AOC_SESSION=# your cookies session
python main.py
cd 1 # current date
code 1.cpp # or any other editor/IDE you like to use
g++ 1.cpp -o a -g -O2 -std=gnu++20 && ./a && rm ./a # some features of C++20 are used
```

Notice:

1. A code template is used throughout the project where some handy but terse macros are defined as shortcuts for various frequently used facilities (see `everything.hpp`).

2. Despite the potential similarity between the solutions of two parts of the problem, all the code is provided on a copy-and-paste basis even if only slightest edition is required to transform a part 1 solution to a part 2 one. I choose to do so in order to keep a uniform format across different solutions.

3. Though I should have passed my puzzles when I push my code to the repo and I attempt to cover a wider range of inputs, I do not claim the correctness of my code in general. Some values used in the code are directly from observation of the input data (e.g. the range of the inputs) and could be falsified given another input. Utmost efficiency is not promised as well: I do make attempts to improve the algorithms used, but I do not insist on seeking an optimized solution as long as my current solution suffices to produce an answer within a reasonable time limit (1 second, usually). Nevertheless, an issue is always welcome if you find anything that can be refined.

4. Do not cheat! That is not fun.

