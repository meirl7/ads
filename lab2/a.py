t = int(input())

for i in range(t):
    n = int(input())
    l = input().split()
    
    c = {}
    s = []
    r = []

    for char in l:
        c[char] = c.get(char, 0) + 1
        s.append(char)

        while s and c[s[0]] > 1:
            s.pop(0)
        if s:
            r.append(s[0])
        else:
            r.append("-1")
    print(" ".join(r))
