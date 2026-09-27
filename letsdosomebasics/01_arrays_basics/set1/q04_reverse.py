# Q04 — REVERSE THE ARRAY
#
# Given a list of numbers, return a NEW list with the elements in
# reverse order. The original list must NOT be changed.
#
# Example:
#   [10, 25, 7]   ->  [7, 25, 10]
#   [1, 2, 3, 4]  ->  [4, 3, 2, 1]
#   [5]           ->  [5]
#
# In Python, build a new list and return it (don't modify `a`).

def reverse_array(a):
    # YOUR CODE HERE
    if len(a)==1: return a
    result = []
    for i in range(len(a)-1, -1, -1):  # range(start, stop, step).
        result.append(a[i])
    return result  # replace this


if __name__ == "__main__":
    tests = [
        [10, 25, 7],
        [1, 2, 3, 4],
        [5],
        [7, 7, 7],
    ]
    for t in tests:
        print(reverse_array(t))

    # Expected output:
    # [7, 25, 10]
    # [4, 3, 2, 1]
    # [5]
    # [7, 7, 7]
