class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        # row checking 
        for i in range(len(board)):
            seen = set()
            for j in range(len(board[0])):
                if board[i][j] == '.':
                    continue  
                if board[i][j] in seen:
                    return False
                seen.add(board[i][j])
        
        # col checking 
        for i in range(len(board)):
            seen  = set()
            for j in range(len(board[0])):
                if board[j][i] == '.':
                    continue 
                if board[j][i] in seen:
                    return False
                seen.add(board[j][i])
        
        # box checking 
        for box in range(9):
            seen = set()
            for i in range(3):
                for j in range(3):
                    row = (box // 3) * 3 + i
                    col = (box % 3) * 3 + j 
                    if board[row][col] == '.':
                        continue 
                    if board[row][col] in seen:
                        return False
                    seen.add(board[row][col])
        
        return True  
