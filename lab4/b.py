class Node:
    def __init__(self, val, left, right):
        self.val = val
        self.left = left
        self.right = right

n = int(input())
arr = list(map(int, input().split()))
x = int(input())

root = None

