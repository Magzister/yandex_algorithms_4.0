n, m = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

dp_min = [[-1] * n for _ in range(n)]
dp_max = [[-1] * n for _ in range(n)]

for i in range(n):
    dp_min[i][i] = dp_max[i][i] = a[i]

for i in range(n):
    for j in range(i + 1, n):
        dp_min[i][j] = min(a[j], dp_min[i][j - 1])
        dp_max[i][j] = max(a[j], dp_max[i][j - 1])

for _ in range(m):
    l, r = [int(x) for x in input().split()]
    if dp_min[l][r] == dp_max[l][r]:
        print("NOT FOUND")
    else:
        print(dp_max[l][r])
