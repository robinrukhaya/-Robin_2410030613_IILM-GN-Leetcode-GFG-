class Solution {
public:

    void dfs(vector<vector<char>>& board, int row, int col)
    {
        int n = board.size();
        int m = board[0].size();

        
        if(row < 0 || row >= n || col < 0 || col >= m)
            return;

        if(board[row][col] != 'O')
            return;

        board[row][col] = '#';

        
        dfs(board, row-1, col); // up
        dfs(board, row+1, col); // down
        dfs(board, row, col-1); // left
        dfs(board, row, col+1); // right
    }


    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();


        
        for(int j = 0; j < m; j++)
        {
            if(board[0][j] == 'O')
            {
                dfs(board, 0, j);
            }
        }


        
        for(int j = 0; j < m; j++)
        {
            if(board[n-1][j] == 'O')
            {
                dfs(board, n-1, j);
            }
        }


        
        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 'O')
            {
                dfs(board, i, 0);
            }
        }


        
        for(int i = 0; i < n; i++)
        {
            if(board[i][m-1] == 'O')
            {
                dfs(board, i, m-1);
            }
        }


        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }

                if(board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};