class Solution {
public:

    typedef pair<int,int> pp;
    int n =0;

    pp helper(int num)
    {
        int row = n - 1 - (num - 1) / n;
        int col = (num - 1) % n;
        
        if ((n - 1 - row) % 2 == 1) col = n - 1 - col;

        return {row , col};
        
    } 

    int snakesAndLadders(vector<vector<int>>& board) {

        n = board.size();
        vector<bool>visited( n * n + 1 , 0);
        queue<pp>q;

        q.push({1,0});
        visited[1] = true;

        while(!q.empty())
        {
            pp elem = q.front();
            q.pop();

            int num = elem.first;
            int step = elem.second;

            if(num == n * n) return step;

            for(int i = 1 ; i <= 6 ; i++)
            {
                int next = num + i;
                if(next > n * n) break;

                pp converted = helper(next);
                int r = converted.first;
                int c = converted.second;
                if(board[r][c] != -1)
                {
                    next = board[r][c];
                }

                if(!visited[next])
                {
                    visited[next] = true;
                    q.push({next,step+1});
                }

            }
        }
        
        return -1;
    }
};