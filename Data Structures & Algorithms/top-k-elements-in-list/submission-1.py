from collections import Counter 

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_items = Counter(nums)

        sorted_items = sorted(freq_items.items() , key = lambda x : x[1] , reverse = True)
        res = []

        for i in range(k):
            res.append(sorted_items[i][0])
        
        return res