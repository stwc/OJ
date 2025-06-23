class Solution1:
    def climbStairs(self, n: int) -> int:
        # dp[i] = dp[i - 1] + dp[i - 2]
        # dp[0] = dp[1] = 1

        if n <= 1:
            return 1

        x, y = 1, 1
        result = 0
        for _ in range(1, n):
            result = x + y
            x, y = result, x

        return result


class Solution2:
    def climbStairs(self, n: int) -> int:
        if n == 1 or n == 2:
            return n
        a, b = 1, 2
        for _ in range(3, n + 1):
            a, b = b, a + b
        return b
