n = int(input())

n = n * (n - 1) * (n - 2) * (n - 3) * (n - 4)
x = int(n / 120)
x = x * n

print(x)
