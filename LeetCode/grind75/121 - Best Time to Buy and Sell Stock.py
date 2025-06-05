class Solution1:
    def maxProfit(self, prices: List[int]) -> int:
        length = len(prices)
        if length == 1:
            return 0

        dp = [0] * (length + 1)
        min_price = min(prices[0], prices[1])

        for i in range(1, length):
            dp[i + 1] = max(dp[i], prices[i] - min_price)
            min_price = min(prices[i], min_price)

        return dp[length]


class Solution2:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = prices[0]
        max_profit = 0

        for price in prices[1:]:
            profit = price - min_price
            if max_profit < profit:
                max_profit = profit

            if min_price > price:
                min_price = price

        return max_profit
