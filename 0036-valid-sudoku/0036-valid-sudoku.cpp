class Solution {
public:

    bool checker(int i,int j , char val , vector<vector<char>>& board)
    {
        int n=board.size();

        for(int x=0 ; x< n;x++)
        {
            if(x!=j && board[i][x] == val) return false;
            if(x!=i && board[x][j] == val) return false;
            int subRow = 3 * (i / 3) + x / 3, subCol = 3 * (j / 3) + x % 3;
            if ((subRow != i || subCol != j) && board[subRow][subCol] == val) return false;
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        int n=board.size();
        for(int i=0 ;i< n;i++)
        {
            for(int j=0 ;j< n ;j++)
            {
                if(board[i][j]!='.')
                {
                    char val=board[i][j];
                    if(checker(i,j,val,board)==false)
                    {
                        cout<<i<<j;
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};