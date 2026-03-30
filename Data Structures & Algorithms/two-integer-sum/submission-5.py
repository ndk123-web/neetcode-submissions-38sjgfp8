class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # 3 4 5 6 , t = 7 
        # let say 
        # 1-> 7 - 3 = 4 it means we want 4 
        # 2-> 4 and 4 is in the table then return indicea and that 

        diff_map = {}
        c = 0 

        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in diff_map:
                return [diff_map[diff],c]
            diff_map[nums[i]] = i
            c+=1

        return []
