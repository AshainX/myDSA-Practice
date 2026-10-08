# PROGRESS — your learning log

## 🎉 SET 1 COMPLETE — ALL 10 CLEAN (both languages, 0 hints on q06–q10)

## Ladder (unlock order)

| # | Module | Status |
|---|--------|--------|
| 01 | Arrays Basics | ✅ Set 1 DONE — Set 2 (harder) ready to build |
| 02 | Strings | 🔒 locked |
| 03 | Two Pointers | 🔒 locked |
| 04 | Sliding Window / Prefix Sum | 🔒 locked |
| 05 | Hashing / Maps | 🔒 locked |
| 06 | Recursion Basics | 🔒 locked |
| 07 | Sorting & Binary Search | 🔒 locked |
| 08 | Stacks & Queues | 🔒 locked |
| 09 | Linked Lists | 🔒 locked |
| 10 | Trees | 🔒 locked |
| 11 | Graphs | 🔒 locked |
| 12 | Dynamic Programming | 🔒 locked |

## Current set

**Module 01 — Arrays Basics · Set 1** (easy, entry level)

| Q | Problem | Hints used | Result |
|---|---------|-----------|--------|
| 01 | Sum of array elements | 0 | ✅ Clean (cpp + py) |
| 02 | Find the maximum element | 0 | ✅ Clean (cpp + py) |
| 03 | Count even numbers | 0 | ✅ Clean (cpp + py) |
| 04 | Reverse the array | py: 2 | ✅ Clean (cpp + py, followup done) |
| 05 | Search for a value | 0 (syntax help: missing brace) | ✅ Clean (cpp + py) |
| 06 | Count occurrences of a value | 0 | ✅ Clean (cpp + py) |
| 07 | Average of array | 0 | ✅ Clean (cpp + py) |
| 08 | Count numbers greater than a given value | 0 | ✅ Clean (cpp + py) |
| 09 | Swap two elements | 0 | ✅ Clean (cpp + py) |
| 10 | Find the second largest | 0 | ✅ Clean (cpp + py, stress-tested) |

**Pending:** none — SET 1 COMPLETE. Next: Set 2 (harder arrays) or your call.

## Notes / patterns observed

- **Off-by-one errors** — q04 python: started reverse loop at `len(a)` instead of `len(a)-1`. This is a recurring trap for the user. Watch for it in future problems (loops over indexes, especially backwards).
- Uses `int i` vs `a.size()` (size_t) in C++ — cosmetic warning, not an error.
- Good defensive instinct: proactively checks empty-list / single-element edge cases.
- Understands loop-over-index pattern well; both index-based and value-based loops used correctly.
- Python: previously used mutating approach (pop) in q01; corrected to non-mutating for-loop on feedback.
- Stronger/more comfortable in C++ than Python at the moment.

## Session log
- Set 1 created (10 problems × cpp/py), skeletons verified (all compile + run).
- q01 ✅ both, q02 ✅ both, q03 ✅ both, q04 cpp ✅ / py 🤝 (2 hints: negative-step idea + off-by-one).
- q05 ✅ both (syntax fix: missing brace — free). followup_q04 ✅ done → q04 fully Clean.
- q06 ✅ both.
- Oct 9: q09 ✅ both (std::swap / temp-var swap), q10 ✅ both (two-variable tracking, passed all hidden edges incl. duplicates, negatives, INT_MAX). SET 1 COMPLETE — 10/10 Clean.
