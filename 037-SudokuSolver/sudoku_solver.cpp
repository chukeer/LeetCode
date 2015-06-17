#include <vector>
#include <stdio.h>
using std::vector;

void PrintBoard(const vector<vector<char> >& board)
{
    for (vector<vector<char> >::const_iterator it = board.begin(); it != board.end(); ++it)
    {
        for (vector<char>::const_iterator it_it = it->begin(); it_it != it->end(); ++it_it)
        {
            printf("%c ", *it_it);
        }
        printf("\n");
    }
    printf("==============================\n");
}

class Solution {
public:
    int rows_;
    int cols_;
    bool find_;
    int blank_cells_;

    void solveSudoku(vector<vector<char> >& board) 
    {
        rows_ = board.size();
        cols_ = board[0].size();
        find_ = false;
        blank_cells_ = 0;
        for (int i = 0; i < rows_; ++i)
        {
            for (int j = 0; j < cols_; ++j)
            {
                if (board[i][j] == '.')
                {
                    ++blank_cells_;
                }
            }
        }
        return Search(board, 0);
    }

    void Search(vector<vector<char> >& board, int iter_num)
    {
        //PrintBoard(board);
        if (iter_num >=  blank_cells_)
        {
            find_ = true;
            return;
        }
        int index = GetNextCellIndex(board);
        int next_row = index / 9;
        int next_col = index % 9;

        //printf("next_row:%d next_col:%d\n", next_row, next_col);
                
        vector<char> candidates = GetCandidates(board, next_row, next_col);
        for (vector<char>::iterator c = candidates.begin(); c != candidates.end(); ++c)
        {
            board[next_row][next_col] = *c;
            //AddCell(board, next_row, next_col);
            Search(board, iter_num + 1);
            if (find_)
            {
                return ;
            }
            board[next_row][next_col] = '.';
            //DelCell(board, next_row, next_col);
        }
    }

    int GetNextCellIndex(vector<vector<char> >& board)
    {
        int min_candidate_num = 9;
        int index = -1;
        for (int i = 0; i < rows_; ++i)
        {
            for (int j = 0; j < cols_; ++j)
            {
                if (board[i][j] != '.')
                {
                    continue;
                }
                vector<char> candidates = GetCandidates(board, i, j);
                if (candidates.size() < min_candidate_num)
                {
                    min_candidate_num = candidates.size();
                    index = i * cols_ + j;
                }
            }
        }
        return index;
    }


    vector<char> GetCandidates(vector<vector<char> >& board, int row, int col)
    {
        // 行占选字符
        vector<int> chars(10);
        for (int i = 0; i < cols_; ++i)
        {
            if (board[row][i] != '.')
            {
                chars[board[row][i] - '0'] = 1;
            }
        }

        // 列占用字符
        for(int i = 0; i < rows_; ++i)
        {
            if (board[i][col] != '.')
            {
                chars[board[i][col] - '0'] = 1;
            }
        }

        // 块占用字符
        int block_row = row / 3 * 3;
        int block_col = col / 3 * 3;
        for (int i = block_row; i < block_row + 3; ++i)
        {
            for (int j = block_col; j < block_col + 3; ++j)
            {
                if (board[i][j] != '.')
                {
                    chars[board[i][j] - '0'] = 1;
                }
            }
        }
        vector<char> candidates;
        for (int i = 1; i < 10; ++i)
        {
            if (chars[i] == 0)
            {
                candidates.push_back(i + '0');
            }
        }
        return candidates;
    }
};



void PushBoard(vector<vector<char> >& board, const char line[10])
{
    vector<char> vec(&line[0], &line[9]);
    board.push_back(vec);
}

int main()
{
    vector<vector<char> > board;
    //PushBoard(board, "...678912");
    //PushBoard(board, "...195348");
    //PushBoard(board, "...342567");
    //PushBoard(board, ".59761423");
    //PushBoard(board, ".26853791");
    //PushBoard(board, ".13924856");
    //PushBoard(board, ".61537284");
    //PushBoard(board, ".87419635");
    //PushBoard(board, ".45286179");

    //PushBoard(board, "534678912");
    //PushBoard(board, "672195348");
    //PushBoard(board, "198342567");
    //PushBoard(board, "859761423");
    //PushBoard(board, "426853791");
    //PushBoard(board, "713924856");
    //PushBoard(board, "961537284");
    //PushBoard(board, "287419635");
    //PushBoard(board, "345286179");

    PushBoard(board, "53..7....");
    PushBoard(board, "6..195...");
    PushBoard(board, ".98....6.");
    PushBoard(board, "8...6...3");
    PushBoard(board, "4..8.3..1");
    PushBoard(board, "7...2...6");
    PushBoard(board, ".6....28.");
    PushBoard(board, "...419..5");
    PushBoard(board, "....8..79");

    printf("before:\n");
    PrintBoard(board);

    Solution s;
    s.solveSudoku(board); 
    printf("after:\n");
    PrintBoard(board);

    return 0;
}
