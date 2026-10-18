class Node(object):
    def __init__(self, val=0, next=None):
        self.val: int = val
        self.next: Node = next
def insert(head: Node, node: Node, p: int):
    if p == 0:
        node.next = head
        return node
    curr = head
    for _ in range(p - 1):
        curr = curr.next
    node.next = curr.next
    curr.next = node
    return head

def remove(head: Node, p: int):
    if head is None:
        return None
    if p == 0:
        return head.next
    curr = head
    for _ in range(p - 1):
        curr = curr.next
    if curr.next:
        curr.next = curr.next.next
    return head

def printAll(head: Node):
    if head is None:
        print("-1")
        return
    curr = head
    res = []
    while curr:
        res.append(str(curr.val))
        curr = curr.next
    print(" ".join(res))

def replace(head: Node, p1: int, p2: int):
    if p1 == p2:
        return head
    if p1 == 0:
        extracted = head
        head = head.next
    else:
        curr = head
        for _ in range(p1 - 1):
            curr = curr.next
        extracted = curr.next
        curr.next = extracted.next
    extracted.next = None

    if p2 == 0:
        extracted.next = head
        return extracted
    
    curr = head
    for _ in range(p2 - 1):
        curr = curr.next
    extracted.next = curr.next
    curr.next = extracted
    return head

def reverse(head: Node):
    prev = None
    curr = head
    while curr:
        nxt = curr.next
        curr.next = prev
        prev = curr
        curr = nxt
    return prev

def cyclic_left(head: Node, x: int):
    if head is None or x == 0:
        return head

    tail = head
    length = 1
    while tail.next:
        tail = tail.next
        length += 1
    
    x %= length
    if x == 0:
        return head
    
    curr = head
    for _ in range(x - 1):
        curr = curr.next
    
    new_head = curr.next
    curr.next = None
    tail.next = head
    return new_head

def cyclic_right(head: Node, x: int):
    if head is None or x == 0:
        return head
    
    tail = head
    length = 1
    while tail.next:
        tail = tail.next
        length += 1
    
    x %= length
    if x == 0:
        return head
    
    curr = head
    for _ in range(length - x - 1):
        curr = curr.next
    
    new_head = curr.next
    curr.next = None
    tail.next = head
    return new_head

head = None

while True:
    try:
        vals = [int(i) for i in input().split()]
        if not vals:
            continue
        
        if vals[0] == 0:
            break
        elif vals[0] == 1:
            head = insert(head, Node(vals[1]), vals[2])
        elif vals[0] == 2:
            head = remove(head, vals[1])
        elif vals[0] == 3:
            printAll(head)
        elif vals[0] == 4:
            head = replace(head, vals[1], vals[2])
        elif vals[0] == 5:
            head = reverse(head)
        elif vals[0] == 6:
            head = cyclic_left(head, vals[1])
        elif vals[0] == 7:
            head = cyclic_right(head, vals[1])
    except EOFError:
        break