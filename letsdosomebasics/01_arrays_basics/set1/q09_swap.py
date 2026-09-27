# Q09 — SWAP TWO ELEMENTS
#
# Given a list of numbers and two indexes i and j, swap the elements
# at those positions (in the SAME list, modify it) and return it.
# Indexes are always valid (within bounds).
#
# Example:
#   a = [10, 25, 7], i = 0, j = 2  ->  [7, 25, 10]
#   a = [1, 2, 3],   i = 1, j = 1  ->  [1, 2, 3]   (same index, no change)
#   a = [5, 6],      i = 0, j = 1  ->  [6, 5]
#
# TIP: In Python you can swap with:  a[i], a[j] = a[j], a[i]

def swap_elements(a, i, j):
    # YOUR CODE HERE
    return a  # leave this


if __name__ == "__main__":
    tests = [
        ([10, 25, 7], 0, 2),
        ([1, 2, 3], 1, 1),
        ([5, 6], 0, 1),
    ]
    for t, i, j in tests:
        print(swap_elements(t, i, j))

    # Expected output:
    # [7, 25, 10]
    # [1, 2, 3]
    # [6, 5]
