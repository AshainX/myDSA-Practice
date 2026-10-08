# Q10 — FIND THE SECOND LARGEST
#
# Given a list of numbers (with at least 2 elements), return the
# SECOND LARGEST value. It does NOT have to be strictly smaller —
# if the largest appears twice, the second largest can equal it.
#
# Examples:
#   [10, 25, 7]   ->  10      (largest is 25, second is 10)
#   [5, 1, 5]     ->  5       (largest 5, second 5)
#   [3, 3, 3]     ->  3
#   [1, 2, 3, 4]  ->  3
#   [100, 50]     ->  50
#
# THINK: keep track of two things — the largest so far, and the
# second largest so far. Walk through and update both.

def second_largest(a):
    # YOUR CODE HERE
    large = float('-inf')
    slarge = float('-inf')
    for i in range(len(a)):
        if a[i] > large:
            slarge = large
            large = a[i]
        else:
            if a[i] >= slarge:
                slarge = a[i]

    return slarge  # replace this


if __name__ == "__main__":
    tests = [
        [10, 25, 7],
        [5, 1, 5],
        [3, 3, 3],
        [1, 2, 3, 4],
        [100, 50],
    ]
    for t in tests:
        print(second_largest(t))

    # Expected output:
    # 10
    # 5
    # 3
    # 3
    # 50
