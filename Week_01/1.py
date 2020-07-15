class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        length = len(nums)
        for cnt in range(length):
            for cnt2 in range(cnt+1, length):
                if nums[cnt] + nums[cnt2] == target:
                    return [cnt, cnt2]