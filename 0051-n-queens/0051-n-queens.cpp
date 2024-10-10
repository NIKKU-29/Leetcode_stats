class Solution {
public:

    int size;
    vector<vector<string>>ans;

    bool isvalid(vector<string>& board , int row ,int column)
    {
        for(int i=0;i< row; i++)
        {
            if(board[i][column]=='Q')
            {
                return false;
            }
        }

        for(int i=row,j=column ; i >= 0 && j < size; i--,j++) //right digonal
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }  

        for(int i=row,j=column ; i>=0 && j>=0; i--,j--) //left digonal
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }

        return true;
    }

    void solver(vector<string>& board,int row)
    {
       if(row >= size)
       {
            ans.push_back(board);
            return;
       }

       for(int column=0 ; column < size ; column++)
       {
            if(isvalid(board,row,column))
            {
                board[row][column]='Q';
                solver(board,row+1);
                board[row][column]='.';
            }
       }
    }

    vector<vector<string>> solveNQueens(int n) {

        size=n;
        vector<string>board(n,string(n,'.'));

        solver(board,0);

        return ans;
        
    }
};