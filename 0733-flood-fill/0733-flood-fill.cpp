class Solution {
public:

    void solver(vector<vector<int>>& image, int start, int end, int color,int n,int m,int value)
    {
            if(start < 0 || end < 0 || start >= n || end >=m || image[start][end]!=value) return ;

            image[start][end]=color;

            solver(image,start+1,end,color,n,m,value);
            solver(image,start-1,end,color,n,m,value);
            solver(image,start,end+1,color,n,m,value);
            solver(image,start,end-1,color,n,m,value);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int n=image.size();
            int m=image[0].size();
            int value=image[sr][sc];

            if (value == color) 
            {
            return image;
            }



            solver(image,sr,sc,color,n,m,value);

            return image;
           
    }
};