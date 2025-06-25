class Solution1:
    def addBinary(self, a: str, b: str) -> str:
        len_a = len(a)
        len_b = len(b)
        if len_a > len_b:
            max_len = len_a
        else:
            max_len = len_b

        rev_a = [0] * max_len
        rev_b = [0] * max_len
        for i in range(len_a):
            rev_a[i] = int(a[-(i + 1)])

        for i in range(len_b):
            rev_b[i] = int(b[-(i + 1)])

        result = ""
        carry = 0
        for i in range(max_len):
            digit_sum = rev_a[i] + rev_b[i] + carry
            if digit_sum >= 2:
                carry = 1
                result += str(digit_sum - 2)
            else:
                carry = 0
                result += str(digit_sum)

        if carry == 1:
            result += "1"

        return result[::-1]


class Solution2:
    def addBinary(self, a: str, b: str) -> str:
        res = ""
        carry = 0
        i = len(a) - 1
        j = len(b) - 1

        while i >= 0 or j >= 0 or carry:
            if i >= 0:
                carry += int(a[i])
                i -= 1
            if j >= 0:
                carry += int(b[j])
                j -= 1
            res += str(carry % 2)
            carry //= 2

        return res[::-1]


class Solution3:
    def addBinary(self, a: str, b: str) -> str:
        s = []
        carry = 0
        i = len(a) - 1
        j = len(b) - 1

        while i >= 0 or j >= 0 or carry:
            if i >= 0:
                carry += int(a[i])
                i -= 1
            if j >= 0:
                carry += int(b[j])
                j -= 1
            s.append(str(carry % 2))
            carry //= 2

        return "".join(reversed(s))
