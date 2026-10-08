# Q08 — COUNT NUMBERS GREATER THAN A VALUE
#
# Given a list of numbers and a value `threshold`, return how many
# elements are STRICTLY GREATER than `threshold`.
#
# Example:
#   a = [10, 25, 7], threshold = 9   ->  2   (10 and 25)
#   a = [5, 5, 5],   threshold = 5   ->  0   (equal is NOT greater)
#   a = [1, 2, 3],   threshold = 0   ->  3
#   a = [8],         threshold = 100 ->  0

def count_greater(a, threshold):
    # YOUR CODE HERE
    count = 0
    # for i in range(len(a)):
        # if a[i]>threshold:
            # count+=1
    for x in a:
        if x>threshold:
            count+=1
    return count  # replace this


if __name__ == "__main__":
    tests = [
        ([10, 25, 7], 9),
        ([5, 5, 5], 5),
        ([1, 2, 3], 0),
        ([8], 100),
    ]
    for t, threshold in tests:
        print(count_greater(t, threshold))

    # Expected output:
    # 2
    # 0
    # 3
    # 0
