class Solution1:
    def isValid(self, s: str) -> bool:
        left_p = ["(", "[", "{"]
        right_p = [")", "]", "}"]

        stack = []
        for i in range(len(s)):
            c = s[i]
            if c in left_p:
                stack.append(c)
            else:
                if len(stack) == 0 or right_p.index(c) != left_p.index(stack.pop()):
                    return False

        return len(stack) == 0


class Solution2:
    def isValid(self, s: str) -> bool:
        stack = []
        hashmap = {")": "(", "}": "{", "]": "["}

        for char in s:
            if char in hashmap.values():
                stack.append(char)
            elif char in hashmap.keys():
                if not stack or hashmap[char] != stack.pop():
                    return False

        return not stack
