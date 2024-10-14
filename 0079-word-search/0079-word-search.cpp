class Solution {
public:

    int m,n;

    vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};

    bool solver(int idx,int i,int j,vector<vector<char>>& board,string word)
    {

        if(idx==word.size()) return true;

        if(i < 0 || j < 0 || i >=m || j >=n || board[i][j]=='$' || board[i][j]!=word[idx] )
        {
            return false;
        }
        
        
        char temp=board[i][j];
        board[i][j]='$';

        for(auto& elem : directions)
        {
            int newX=i+elem.first;
            int newY=j+elem.second;

            if(solver(idx+1,newX,newY,board,word))
            {
                return true;
            }

        }

        board[i][j]=temp;


        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        m=board.size();
        n=board[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0] && solver(0,i,j,board,word))
                {
                    return true;
                }
            }
        }


        return false;
        
    }
};