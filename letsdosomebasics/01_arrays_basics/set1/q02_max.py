# Q02 — FIND THE MAXIMUM ELEMENT
#
# Given a list of numbers, return the largest value in the list.
# The list will always have at least one element.
#
# Example:
#   [10, 25, 7]   ->  25
#   [1, 2, 3, 4]  ->  4
#   [5]           ->  5
#   [9, 9, 9]     ->  9
#
# Hint: start your "max" with the FIRST element, not 0.

def max_element(a):
    # YOUR CODE HERE
    val = float('-inf')
    for i in range(len(a)):
        if a[i] > val:
            val = a[i]
    return val  # replace this


if __name__ == "__main__":
    tests = [
        [10, 25, 7],
        [1, 2, 3, 4],
        [5],
        [9, 9, 9],
        [-3, -1, -7],
    ]
    for t in tests:
        print(max_element(t))

    # Expected output:
    # 25
    # 4
    # 5
    # 9
    # -1
