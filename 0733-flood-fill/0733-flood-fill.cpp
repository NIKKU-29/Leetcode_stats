class Solution {
public:

    vector<vector<int>>directions = {{0,-1},{0,1},{-1,0},{1,0}};
    int m,n;
    typedef pair<int,int> P;
    void solver(vector<vector<int>>& image, int x, int y, int color , int value)
    {

        queue<P>q;
        q.push({x,y});

        while(!q.empty())
        {
            int siz = q.size();

            while(siz--)
            {
                P tp = q.front();
                int x=tp.first;
                int y=tp.second;
                image[x][y] = color;
                q.pop();

               for(auto elem : directions)
               {
                    int newx = x + elem[0];
                    int newy = y + elem[1];

                    if(newx >= 0 && newx < m && newy >= 0 && newy < n && image[newx][newy]== value)
                    {
                        q.push({newx,newy});
                    }

               }

            }
        }

        




    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        

        m= image.size();
        n= image[0].size();
        if (image[sr][sc] == color) return image;
        int value = image[sr][sc];

        solver(image,sr,sc,color,value);
        return image;

    }
};