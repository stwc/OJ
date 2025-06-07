class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i in range(len(nums)):
            x = nums[i]
            y = target - x
            if y in hashmap:
                return [i, hashmap[y]]
            hashmap[x] = i
        return []
