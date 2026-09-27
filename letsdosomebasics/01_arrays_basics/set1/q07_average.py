# Q07 — AVERAGE OF ARRAY
#
# Given a list of numbers, return the average (mean) of all elements.
# Average = (sum of all elements) / (number of elements).
# The list will always have at least one element.
#
# Example:
#   [10, 25, 7]   ->  14.0   (42 / 3)
#   [1, 2, 3, 4]  ->  2.5    (10 / 4)
#   [5]           ->  5.0
#
# NOTE: In Python 3, dividing two ints with / already gives a float.

def average(a):
    # YOUR CODE HERE
    return 0.0  # replace this


if __name__ == "__main__":
    tests = [
        [10, 25, 7],
        [1, 2, 3, 4],
        [5],
        [0, 0, 0],
    ]
    for t in tests:
        print(average(t))

    # Expected output:
    # 14.0
    # 2.5
    # 5.0
    # 0.0
