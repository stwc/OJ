class Solution1:
    def maxSubArray(self, nums: List[int]) -> int:
        length = len(nums)
        dp = [0] * length
        dp[0] = nums[0]
        max_sum = nums[0]

        for i in range(1, length):
            if dp[i - 1] < 0:
                dp[i] = nums[i]
            else:
                dp[i] = dp[i - 1] + nums[i]

            if dp[i] > max_sum:
                max_sum = dp[i]

        return max_sum


class Solution2:
    def maxSubArray(self, nums: List[int]) -> int:
        length = len(nums)
        cur_sum = nums[0]
        max_sum = nums[0]

        for i in range(1, length):
            if cur_sum < 0:
                cur_sum = nums[i]
            else:
                cur_sum += nums[i]

            if cur_sum > max_sum:
                max_sum = cur_sum

        return max_sum
