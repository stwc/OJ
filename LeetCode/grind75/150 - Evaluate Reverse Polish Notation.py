class Solution1:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for token in tokens:
            if self.isOperand(token):
                stack.append(token)
                continue

            y = int(stack.pop())
            x = int(stack.pop())
            if token == "+":
                stack.append(x + y)
            elif token == "-":
                stack.append(x - y)
            elif token == "*":
                stack.append(x * y)
            elif token == "/":
                res = x / y
                if res < 0:
                    stack.append(math.ceil(res))
                else:
                    stack.append(res)

        return int(stack.pop())

    def isOperand(self, token: str) -> bool:
        if token == "+" or token == "-" or token == "*" or token == "/":
            return False
        else:
            return True


class Solution2:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        operators = {"+", "-", "*", "/"}

        for token in tokens:
            if token not in operators:
                stack.append(int(token))
                continue

            y = stack.pop()
            x = stack.pop()
            if token == "+":
                stack.append(x + y)
            elif token == "-":
                stack.append(x - y)
            elif token == "*":
                stack.append(x * y)
            elif token == "/":
                stack.append(int(x / y))

        return stack.pop()
