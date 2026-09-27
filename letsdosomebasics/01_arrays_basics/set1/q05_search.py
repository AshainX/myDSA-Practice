# Q05 — SEARCH FOR A VALUE
#
# Given a list of numbers and a target value, return True if the
# target appears in the list, False otherwise.
#
# Example:
#   a = [10, 25, 7], target = 25  ->  True
#   a = [10, 25, 7], target = 99  ->  False
#   a = [5],          target = 5   ->  True
#   a = [1, 2, 3],    target = 3   ->  True

def contains(a, target):
    # YOUR CODE HERE
    return False  # replace this


if __name__ == "__main__":
    tests = [
        ([10, 25, 7], 25),
        ([10, 25, 7], 99),
        ([5], 5),
        ([1, 2, 3], 3),
    ]
    for t, target in tests:
        print(contains(t, target))

    # Expected output:
    # True
    # False
    # True
    # True
