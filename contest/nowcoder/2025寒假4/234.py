MOD = int(1e9 + 7)

def compute_queries(a, b, queries):
    n = len(a)
    prefix_a = [0] * (n + 1)
    prefix_b = [0] * (n + 1)
    
    # Precompute prefix sums for sequence a and b
    for i in range(1, n + 1):
        prefix_a[i] = prefix_a[i - 1] ^ a[i - 1]
        prefix_b[i] = prefix_b[i - 1] ^ b[i - 1]
    
    results = []
    # Process each query
    for l, r in queries:
        S = (prefix_a[r + 1] - prefix_a[l]) ^ (prefix_b[r + 1] - prefix_b[l])
        results.append((S + MOD) % MOD) # Ensure non-negative result after modulo operation
    return results

# Example usage:
a = [0, 1, 0]
b = [0, 0, 1]
queries = [(0, 2)] # List of queries (l_i, r_i)
answers = compute_queries(a, b, queries)
print(answers) # This will print the answers for each query after modulo operation
