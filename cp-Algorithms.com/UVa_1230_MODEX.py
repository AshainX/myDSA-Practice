'''
Problem Statement :

Input
The input consists of a line containing the number c of datasets, followed by c datasets, followed by a line containing the number ‘0’.
Each dataset consists of a single line containing three positive integers, x, y, and n, separated by blanks.
You can assume that 1 < x, n < 2^15 = 32768, and 0 < y < 2^31 = 2147483648.

Output
The output consists of one line for each dataset. The i-th line contains a single positive integer z such
that z = x y mod n for the numbers x, y, z given in the i-th input dataset.

Sample Input
2
2 3 5
2 2147483647 13
0

Sample Output
3
11

'''

def modular_exponentiation(x, y, n):
    # Compute (x^y) % n using modular exponentiation
    result = 1
    base = x % n  # Reduce x modulo n initially
    
    while y > 0:
        # If y is odd, multiply the result with the current base
        if y % 2 == 1:
            result = (result * base) % n
        
        # Square the base and reduce modulo n
        base = (base * base) % n
        # Halve y (integer division)
        y //= 2
    
    return result

def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split("\n")
    
    # First line contains the number of datasets
    c = int(data[0])
    
    # Process each dataset
    results = []
    for i in range(1, c + 1):
        x, y, n = map(int, data[i].split())
        z = modular_exponentiation(x, y, n)
        results.append(z)
    
    # Print results for each dataset
    for result in results:
        print(result)

# Example usage
if __name__ == "__main__":
    main()
