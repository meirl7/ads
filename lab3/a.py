l = 0
r = int(input()) - 1
a = list(map(int, input().split()))
t = int(input())


def bs(l, r, a, t):
    while l <= r:
        m = (l + r) // 2
        if a[m] > t:
            r = m - 1
        elif a[m] < t:
            l = m + 1
        else:
            return "Yes"
    return "No"
print(bs(l, r, a, t))