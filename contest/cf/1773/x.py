# c2 = 0
# c5 = 0

# for i in range(1, 11):
#     if (i % 2 == 0):
#         c2 += 1
#     if (i % 5 == 0):
#         c5 += 1

# print(min(c2, c5))

ans = 1

for i in range(1, 101):
    ans *= i
    print(ans)
