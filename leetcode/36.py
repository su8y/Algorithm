""" 36. Valid Sudoku
bruteforce: O(1)
3가지 조건을 확인한다.
1. 3x3 distinct
2. row distinct
3. column distinct
"""
class Solution:
    def isUnique3x3(self, y, x, board) -> bool:
        cnt = [0] * 10
        for i in range(0, 3):
            for j in range(0, 3):
                ny = y + i
                nx = x + j
                ch = board[ny][nx]

                if ch == '.': 
                    continue

                cnt[int(ch)] += 1
                if cnt[int(ch)] >= 2:
                    return False
        return True

    def isUniqueRow(self, y, board) -> bool:
        cnt = [0] * 10
        for ch in board[y]:
            if ch == '.': continue
            cnt[int(ch)] += 1
            if cnt[int(ch)] >= 2:
                return False
        return True
            
    def isUniqueCol(self, x, board) -> bool:
        cnt = [0] * 10
        for i in range(0,9):
            ch = board[i][x]
            if ch == '.': continue
            cnt[int(ch)] += 1
            if cnt[int(ch)] >= 2:
                return False
        return True

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(3):
            for j in range(3):
                if not self.isUnique3x3(i*3, j*3, board):
                    return False
        
        for i in range(9):
            if not self.isUniqueRow(i, board) or not self.isUniqueCol(i, board):
                return False

        return True
