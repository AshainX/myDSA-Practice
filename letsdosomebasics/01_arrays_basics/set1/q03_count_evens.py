# Q03 — COUNT EVEN NUMBERS
#
# Given a list of numbers, return how many of them are EVEN.
# (An even number is divisible by 2, i.e. number % 2 == 0.)
#
# Example:
#   [10, 25, 7]   ->  1   (only 10 is even)
#   [2, 4, 6]     ->  3
#   [1, 3, 5]     ->  0
#   [0, 8, 3]     ->  2

def count_evens(a):
    # YOUR CODE HERE
    count = 0
    if len(a) == 0:
        return 0
    for  i in range(len(a)):
        if a[i] % 2 == 0:
            count +=1 

    return count  # replace this


if __name__ == "__main__":
    tests = [
        [10, 25, 7],
        [2, 4, 6],
        [1, 3, 5],
        [0, 8, 3],
    ]
    for t in tests:
        print(count_evens(t))

    # Expected output:
    # 1
    # 3
    # 0
    # 2
