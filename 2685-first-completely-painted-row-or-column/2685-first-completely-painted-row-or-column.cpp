class Solution {
public:

    // bool checker(int&idx,int&idy,vector<bool>&visited,vector<vector<int>>& mat)
    // {
       
    //     int a=mat.size();
    //     int b=mat[0].size();

    //     int x=0;
    //     int y=0;
        
    //     // cout<<idx<<","<<idy<<endl;

    //     bool RL=true;
    //     bool UD=true;
   
    //     //explore right-left
    //     while(y<b)
    //     {
    //         int elem=mat[idx][y];
    //         if(visited[elem]==false)
    //         {
    //             RL=false;
    //             break;
    //         }
    //         y++;
    //     }

        

    //     //explore top to bottom
    //     while(x<a)
    //     {
    //         int elem=mat[x][idy];
    //         if(visited[elem]==false)
    //         {
    //             UD=false;
    //         }

    //         x++;
    //     }

    //     return RL | UD;
    // }

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int a=mat.size();
        int b=mat[0].size();
        int n=arr.size();
        vector<int>rows(a,0);
        vector<int>colm(b,0);

        vector<pair<int,int>>vec(n+1);

        for(int i=0 ;i<a ;i++)
        {
            for(int j=0 ;j<b ;j++)
            {
                vec[mat[i][j]]={i,j};
            }
        }

        for(int i=0 ; i< n ;i++)
        {
            int elem=arr[i];
            pair<int,int>p=vec[elem];
            int x=p.first;
            int y=p.second;
            
            rows[x]++;
            colm[y]++;

            if(rows[x]==b || colm[y]==a)
            {
                return i;
            }
        
            // if(checker(x,y,visited,mat)) return i;
        }
        

        return 0;
    }
};