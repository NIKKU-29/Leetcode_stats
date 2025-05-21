// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {

//             int n = matrix.size();
//             int m = matrix[0].size();

//             set<pair<int,int>>mp;

//             for(int i = 0 ; i < n ; i++)
//             {
//                 for(int j = 0 ; j < m ; j++)
//                 {
//                     if(matrix[i][j] == 0)
//                     {
//                         mp.insert({i,j});
//                     }
//                 }
//             }


//             for(auto elem : mp)
//             {
//                 int x = elem.first;
//                 int y = elem.second;

//                 for(int i = 0 ; i < n ; i++)
//                 {
//                     matrix[i][y] = 0;
//                 }

//                 for(int j = 0 ; j < m ; j++)
//                 {
//                     matrix[x][j] = 0;
//                 }
//             }

//     }
// };



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool firstRow = false, firstCol = false;

        // Check if first row has any 0
        for(int j = 0; j < m; j++) {
            if(matrix[0][j] == 0) firstRow = true;
        }

        // Check if first column has any 0
        for(int i = 0; i < n; i++) {
            if(matrix[i][0] == 0) firstCol = true;
        }

        // Use first row and column as markers
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set zeros based on markers
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        // Zero the first row if needed
        if(firstRow) {
            for(int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }

        // Zero the first column if needed
        if(firstCol) {
            for(int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
    }
};
