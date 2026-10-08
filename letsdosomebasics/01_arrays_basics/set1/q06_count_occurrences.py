# Q06 — COUNT OCCURRENCES OF A VALUE
#
# Given a list of numbers and a target value, return HOW MANY TIMES
# the target appears in the list.
#
# Example:
#   a = [10, 25, 7],  target = 25  ->  1
#   a = [3, 3, 3],    target = 3   ->  3
#   a = [1, 2, 3],    target = 9   ->  0
#   a = [7, 7, 1, 7], target = 7   ->  3

def count_occurrences(a, target):
    # YOUR CODE HERE
    count = 0
    #for i in range(0,len(a),1):
    for i in range(len(a)):
        if a[i] == target:

            count+=1
    return count  # replace this


if __name__ == "__main__":
    tests = [
        ([10, 25, 7], 25),
        ([3, 3, 3], 3),
        ([1, 2, 3], 9),
        ([7, 7, 1, 7], 7),
    ]
    for t, target in tests:
        print(count_occurrences(t, target))

    # Expected output:
    # 1
    # 3
    # 0
    # 3
