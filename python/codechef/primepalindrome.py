import math

def main():
    n = int(raw_input())

    #because 2 shouldn't be caught in
    #next if condition.
    if n == 2:
        print '2'
        return
    #to ensure to check only odd
    #numbers
    elif n % 2 == 0:
        n += 1

    while True:
        if is_prime(n) and is_palindrome(n):
            print n
            break
        else:
            #since every n entered here
            #is odd, they should remain odd
            n += 2

def is_prime(n):
    # 1 is neither prime nor
    # nor composite
    if n == 1:
        return False
    elif n == 2:
        return True

    for i in range(2, int(math.sqrt(n))):
        if n % i == 0:
            return False

    return True

def is_palindrome(n):
    l = list(str(n))
    for i in range(int(len(l)// 2)):
        if l[i] != l[-1 - i]:
            return False
    return True

if __name__ == '__main__':
    main()
