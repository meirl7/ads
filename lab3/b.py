def bl(arr, val):
    l, r = 0, len(arr)
    while l < r:
        mid = (l + r) // 2
        if arr[mid] < val:
            l = mid + 1
        else:
            r = mid
    return l

def br(arr, val):
    l, r = 0, len(arr)
    while l < r:
        mid = (l + r) // 2
        if arr[mid] <= val:
            l = mid + 1
        else:
            r = mid
    return l

def cnt(arr, l, r):
    if l > r:
        return 0
    return br(arr, r) - bl(arr, l)

n, q = map(int, input().split())
a = sorted(map(int, input().split()))

for _ in range(q):
    l1, r1, l2, r2 = map(int, input().split())
    c1 = cnt(a, l1, r1)
    c2 = cnt(a, l2, r2)
    
    overlap_l = max(l1, l2)
    overlap_r = min(r1, r2)
    c_overlap = cnt(a, overlap_l, overlap_r)
    
    print(c1 + c2 - c_overlap)