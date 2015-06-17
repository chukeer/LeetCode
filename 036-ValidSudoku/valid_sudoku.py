class Solution:
    # @param {character[][]} board
    # @return {boolean}
    def isValidSudoku(self, board):
        row_dict = {}
        col_dict = {}
        cell_dict = {}
        for i in range(9):
            for j in range(9):
                char = board[i][j]
                if char == '.':
                    continue
                cell_index = i / 3 * 3 + j / 3
                cell_set = cell_dict.get(cell_index, None)
                if cell_set:
                    if char in cell_set:
                        return False
                    else:
                        cell_set.add(char)
                        cell_dict[cell_index] = cell_set
                else:
                    tmp_set = set((char,))
                    cell_dict[cell_index] = tmp_set

                row_index = i
                row_set = row_dict.get(row_index, None)
                if row_set:
                    if char in row_set:
                        return False
                    else:
                        row_set.add(char)
                        row_dict[row_index] = row_set
                else:
                    tmp_set = set((char,))
                    row_dict[row_index] = tmp_set

                col_index = j
                col_set = col_dict.get(col_index, None)
                if col_set:
                    if char in col_set:
                        return False
                    else:
                        col_set.add(char)
                        col_dict[col_index] = col_set
                else:
                    tmp_set = set((char,))
                    col_dict[col_index] = tmp_set

        return True

def print_board(board):
    for i in range(9):
        for j in range(9):
            print board[i][j],
        print '\n'

s = Solution()
board = ["..4...63.",".........","5......9.","...56....","4.3.....1","...7.....","...5.....",".........","........."]
print_board(board)
print s.isValidSudoku(board)
