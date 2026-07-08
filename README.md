# Competitive Programming (C++)

A collection of C++ solutions to competitive programming problems, solved on [Codeforces](https://codeforces.com/) and [VJudge](https://vjudge.net/).

## Codeforces profile

[ThMrCode](https://codeforces.com/profile/ThMrCode)

## Structure

Solutions are organized by platform, and within Codeforces, by division and round:

```
codeforces/
  div_2/
    round_<id>/
      problem_a.cpp
      problem_b.cpp
      ...
  div_3/
  div_4/
  global/
    round_<id>/
      ...
vjudge/
  <contest_name>/
    problem_a.cpp
    ...
```

Each file corresponds to a single problem, named after its letter in the contest (`problem_a.cpp`, `problem_b.cpp`, ...). Multi-part problems use a numeric suffix (e.g. `problem_c_1.cpp`, `problem_c_2.cpp`).

## Building and running

Each solution is a standalone, single-file program. Compile with g++:

```bash
g++ -o solution path/to/problem_a.cpp
./solution < input.txt
```

## License

MIT License — see [LICENSE](LICENSE).
