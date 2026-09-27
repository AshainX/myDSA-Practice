# Q01 — SUM OF ARRAY ELEMENTS
#
# Given a list of numbers, return the sum (total) of all elements.
#
# Example:
#   [10, 25, 7]  ->  42   (because 10 + 25 + 7 = 42)
#   [1, 2, 3, 4] ->  10
#   [5]          ->  5
#
# Write the function body below. Do NOT change the function signature
# or the test code.

def sum_array(a):
    # YOUR CODE HERE
    # len(a) gives the number of elements
    sum = 0 
    # while len(a):
    #     sum += a.pop()
    for  i in range(len(a)):
        sum += a[i]
    return sum  # replace this


if __name__ == "__main__":
    tests = [
        [10, 25, 7],
        [1, 2, 3, 4],
        [5],
        [100, 200, 300],
    ]
    for t in tests:
        print(sum_array(t))

    # Expected output:
    # 42
    # 10
    # 5
    # 600
