class Solution1:
    """
    Hash table

    Space: O(n)
    """

    def majorityElement(self, nums: List[int]) -> int:
        freq = {}
        threshold = len(nums) // 2

        for n in nums:
            freq[n] = freq.get(n, 0) + 1
            if freq[n] > threshold:
                return n


class Solution2:
    """
    Boyer–Moore majority vote algorithm

    Space: O(1)
    """

    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        candidate = 0

        for num in nums:
            if count == 0:
                candidate = num

            if num == candidate:
                count += 1
            else:
                count -= 1

        return candidate
