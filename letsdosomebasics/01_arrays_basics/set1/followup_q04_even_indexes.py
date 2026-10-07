# Follow-up Q04b — EVEN INDEXES ONLY
#
# Given a list of numbers, return a NEW list containing only the
# elements at EVEN indexes (0, 2, 4, ...) in their original order.
# The original list must NOT be changed.
#
# Examples:
#   [10, 25, 7, 42, 19]  ->  [10, 7, 19]
#   [1, 2, 3]            ->  [1, 3]
#   [5]                  ->  [5]
#   []                   ->  []
#
# Write the function body below. Do NOT change the signature or tests.

def even_indexes(a):
    # YOUR CODE HERE
    # if a == []:
    #     return []

    res = []
    for i in range(0,len(a),2):
        res.append(a[i])

    return res  # replace this


if __name__ == "__main__":
    tests = [
        [10, 25, 7, 42, 19],
        [1, 2, 3],
        [5],
        [],
        [7, 7, 7],
    ]
    for t in tests:
        print(even_indexes(t))

    # Expected output:
    # [10, 7, 19]
    # [1, 3]
    # [5]
    # []
    # [7, 7]
