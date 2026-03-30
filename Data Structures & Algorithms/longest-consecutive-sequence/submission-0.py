class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        final_max = 0 
        seen = set(nums)

        for num in seen:
            if (num-1) not in seen:
                curr_num = num 
                curr_max = 1

                while curr_num + 1 in seen:
                    curr_num+=1
                    curr_max+=1
                
                final_max = max(final_max,curr_max)
        
        return final_max

