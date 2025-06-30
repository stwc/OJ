class Solution1:
    def containsDuplicate(self, nums: List[int]) -> bool:
        s = set(nums)
        if len(s) == len(nums):
            return False
        else:
            return True


class Solution2:
    def containsDuplicate(self, nums: List[int]) -> bool:
        num_set = set()

        for n in nums:
            if n in num_set:
                return True
            num_set.add(n)

        return False
