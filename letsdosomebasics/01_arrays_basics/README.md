# 01 — Arrays Basics

The single most important data structure. An **array** (C++) / **list** (Python) is just a
**collection of values stored in order**, each reachable by an **index** starting at 0.

```
Index:   0    1    2    3    4
Value: [ 10,  25,   7,  42,  19 ]
```

- First element = index `0`
- Last element = index `size - 1`
- You can read/write any element in one step: `arr[i]`

---

## C++ cheatsheet (vector)

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {10, 25, 7, 42, 19};  // a list of ints
    int n = a.size();                     // how many elements (5)

    // read
    cout << a[0];      // 10
    cout << a[n - 1];  // 19 (last one)

    // write
    a[2] = 99;         // now {10, 25, 99, 42, 19}

    // loop over all elements
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    // add to the end
    a.push_back(100);  // now has 6 elements
    return 0;
}
```

### C++ loop patterns you'll use constantly

```cpp
// SUM of all elements
int sum = 0;
for (int i = 0; i < n; i++) {
    sum += a[i];
}

// MAX (start with the first element, not 0!)
int mx = a[0];
for (int i = 1; i < n; i++) {
    if (a[i] > mx) mx = a[i];
}

// COUNT how many satisfy a condition
int count = 0;
for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0) count++;   // even numbers
}
```

---

## Python cheatsheet (list)

```python
a = [10, 25, 7, 42, 19]   # a list of ints
n = len(a)                # how many elements (5)

# read
print(a[0])               # 10
print(a[-1])              # 19 (last one, -1 = last index)

# write
a[2] = 99                 # now [10, 25, 99, 42, 19]

# loop over all elements
for i in range(n):
    print(a[i])

# loop over values directly (only when you don't need the index)
for val in a:
    print(val)

# add to the end
a.append(100)             # now has 6 elements
```

### Python loop patterns

```python
# SUM
total = 0
for i in range(n):
    total += a[i]

# MAX
mx = a[0]
for i in range(1, n):
    if a[i] > mx:
        mx = a[i]

# COUNT
count = 0
for i in range(n):
    if a[i] % 2 == 0:
        count += 1
```

---

## The 4 steps for EVERY problem (do this, don't skip)

1. **Read** the question. Write in your own words what it asks.
2. **Dry-run** on paper: small array like `[10, 25, 7]`, walk your planned logic step by step.
3. **Code** it in the skeleton (there's a `// YOUR CODE HERE` / `# YOUR CODE HERE` spot).
4. **Run** the visible tests. Only when they pass, come to chat.

## Common beginner traps

- Starting max/min at `0` → always start at `a[0]`.
- Forgetting array indexes start at `0`.
- `a[n]` is out of bounds — valid indexes are `0` to `n-1`.
- Not reading the problem fully before coding.

---

Now open `set1/q01_sum...` and solve q01 → q10 in order. Do them one at a time; come to chat after each (or after a few) so I can verify.
