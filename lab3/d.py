def binary_search_right(arr, val):
    low, high = 0, len(arr)
    while low < high:
        mid = (low + high) // 2
        if arr[mid] <= val:
            low = mid + 1
        else:
            high = mid
    return low

n = int(input())
a = sorted(map(int, input().split()))

pref = [0] * (n + 1)
for i in range(n):
    pref[i + 1] = pref[i] + a[i]

q = int(input())
for _ in range(q):
    x = int(input())
    # Находим количество соперников с силой <= x
    count = binary_search_right(a, x)
    total_power = pref[count]
    print(count, total_power)