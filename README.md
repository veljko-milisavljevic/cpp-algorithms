# C++ Algorithms

Classic algorithms and competitive-programming solutions I wrote in C++ while preparing for programming competitions in high school (2021–2022).

The repository has two parts:

- **`algorithms/`**: core algorithms, cleaned up, commented in English and covered by sample tests.
- **`competitive/`**: my solutions to competition and training problems, kept close to how I originally wrote them.

## Algorithms

| Topic | Algorithm | Time | Memory | File |
|---|---|---|---|---|
| Strings | Knuth–Morris–Pratt search (LPS table) | O(n + m) | O(m) | [`strings/kmp.cpp`](algorithms/strings/kmp.cpp) |
| Strings | Boyer–Moore search, bad-character rule | O(n·m) worst, sub-linear typical | O(σ) | [`strings/boyer_moore.cpp`](algorithms/strings/boyer_moore.cpp) |
| Graphs | Reachability with recursive DFS | O(V + E) per query | O(V + E) | [`graphs/dfs_reachability.cpp`](algorithms/graphs/dfs_reachability.cpp) |
| Searching | Recursive binary search | O(log n) | O(log n) | [`searching/binary_search.cpp`](algorithms/searching/binary_search.cpp) |
| Bits | Binary print, clear/toggle by mask, 8-bit rotation | O(1) | O(1) | [`bits/bit_operations.cpp`](algorithms/bits/bit_operations.cpp) |

*n* = text length, *m* = pattern length, *σ* = alphabet size (256). The input format is described at the top of each file.

### Build and test

Requires a C++17 compiler (GCC or Clang).

```bash
g++ -std=c++17 -O2 -o kmp algorithms/strings/kmp.cpp
echo "ababcabcabababd ababd" | ./kmp      # prints 10

tests/run_tests.sh                       # builds every algorithm and checks tests/<name>/*.in against *.out
```

KMP and Boyer–Moore were also cross-checked against `std::string::find` on 3,000 random inputs.

## Competitive programming

**`competitive/qualifications-2021-22/`**: qualification round of a 2021/22 high-school programming competition in Serbia.

| Problem | Main idea |
|---|---|
| `cenzura` (Censorship) | Character counting in a substring range |
| `ekskurzija` (School trip) | Closed-form formula for an even split into groups |
| `madjionicar` (Magician) | Position lookup array |
| `nesusedni` (Non-adjacent) | Constructive: alternate two characters |
| `nocna-voznja` (Night drive) | Shortest distances on a tree (Dijkstra-style), cached per source |
| `palindrom-safl` (Palindrome shuffle) | Two pointers + KMP |
| `prepisivaci` (Copycats) | Geometry: segments grouped by slope and length in a map |
| `transfuzija-krvi` (Blood transfusion) | Greedy allocation of blood types |

**`competitive/training/`**: problems from training cycles with my competition coach (`cycle-2` … `cycle-4`, `problems/`, `other/`). Many of them are from Codeforces, and the original problem names are kept so they can be looked up.

Notes on this part:
- The code is shown as I wrote it at the time: Serbian identifiers and comments, `bits/stdc++.h`, variable-length arrays (a GCC extension).
- The only changes are small fixes so that every file compiles with `g++ -std=c++17`:
  - removed stray `;` after `#include`;
  - one invalid variable name in `tower.cpp`;
  - a missing `<climits>` in `two-tables.cpp`;
  - leftover debug output in `palindrom-safl.cpp`.
- The solutions were not re-checked against the official tests, so some may be partial.

## Repository structure

```
algorithms/       cleaned-up core algorithms (strings, graphs, searching, bits)
tests/            sample inputs/outputs and run_tests.sh
competitive/
  qualifications-2021-22/
  training/       cycle-2, cycle-3, cycle-4, problems, other
```

## About the cleanup

The files in `algorithms/` are based on my original solutions and were refactored in 2026:
- English names and comments;
- `std::vector` instead of variable-length arrays;
- input from stdin.

Two bugs were fixed during the cleanup:
- the original DFS returned the result of the first unvisited neighbour instead of trying all of them;
- the original Boyer–Moore used an incorrect shift and worked only for the uppercase letters A–Z.

## License

[MIT](LICENSE)

## Author

**Veljko Milisavljević** · [GitHub](https://github.com/veljko-milisavljevic)
