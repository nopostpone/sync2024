MOD = 998244353

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    k = int(data[1])
    a = list(map(int, data[2:]))
    s = [0] * (n + 1)
    for i in range(1, n + 1):
        s[i] = (s[i - 1] + a[i - 1]) % MOD
    max_t = k + 1
    binom = [[0] * max_t for _ in range(max_t)]
    binom[0][0] = 1
    for i in range(1, max_t - 1):
        for j in range(0, i + 1):
            if j == 0:
                binom[i][j] = 1
            elif j == i:
                binom[i][j] = 1
            else:
                binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD
    plt = [[0] * (n + 1) for _ in range(max_t)]
    for t in range(max_t - 1):
        acc = 0
        prev = s[0]
        for r in range(1, n + 1):
            val = prev ** t % MOD
            plt[t][r] = (acc + val) % MOD
            acc = (acc + prev ** t) % MOD
            prev = s[r] % MOD
    total = 0
    for r in range(1, n + 1):
        current = s[r]
        for t in range(max_t - 1):
            coeff = binom[k][t] * pow(-1, t, MOD) % MOD
            power = pow(current, k - t, MOD)
            contribution = (coeff * power * plt[t][r]) % MOD
            total = (total + contribution) % MOD
    print(total)

if __name__ == "__main__":
    main()