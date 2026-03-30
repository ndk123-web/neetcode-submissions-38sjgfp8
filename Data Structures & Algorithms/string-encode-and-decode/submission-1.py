class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded = ''

        for i in range(len(strs)):
            encoded += str(len(strs[i])) + '#' + strs[i]
        
        return encoded 
        
        # -> 4 # n e e t 3 # y o  u   
        # -> 0 1 2 3 4 5 6 7 8 9  10
 
    def decode(self, s: str) -> List[str]:
        ans = []
        i = 0

        while i < len(s):
            j = i 
            
            while s[j] != '#':
                j+=1
                
            curr_len = int(s[i:j])
            i = j + 1
            
            ans.append(s[i:i+curr_len])
            i = i + curr_len 

        return ans 