n, k = map(int, input().split())
words = input().split()

shifted = words[k:] + words[:k]
print(*shifted)