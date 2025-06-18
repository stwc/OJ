class MyQueue:
    def __init__(self):
        self.stack = deque()
        self.size = 0

    def push(self, x: int) -> None:
        tmp_stack = deque()
        while len(self.stack) != 0:
            element = self.stack.pop()
            tmp_stack.append(element)

        tmp_stack.append(x)
        self.size += 1

        while len(tmp_stack) != 0:
            element = tmp_stack.pop()
            self.stack.append(element)

    def pop(self) -> int:
        self.size -= 1
        return self.stack.pop()

    def peek(self) -> int:
        return self.stack[-1]

    def empty(self) -> bool:
        return self.size == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
