
def bsl(arr, t):
    l, h = 0, len(arr)
    while l < h:
        m = (l + h) // 2
        if arr[m] < t:
            l = m + 1
        else:
            h = m
    return l

n, m = map(int, input().split())
a = list(map(int, input().split()))

pref = [0] * n
current_sum = 0
for i in range(n):
    current_sum += a[i]
    pref[i] = current_sum


for _ in range(m):
    line = int(input())
    print(bsl(pref, line) + 1)