class Solution {
public:

    int N;

    void solver(string& curr, string& ans, vector<int>&visited, int idx,
                string pattern) {

        if (curr.size() == N + 1) {
            
          
             if (ans.empty() || curr < ans) {  
                ans = curr;
            }
                return;
        }

        if(pattern[idx] == 'I')
        {
            for(int i= (curr.back()-'0') ;i <= N + 1 ; i++)
            {
                if(visited[i]==0)
                {
                    curr+=to_string(i);
                    visited[i]=1;
                    solver(curr,ans,visited,idx+1,pattern);
                    visited[i]=0;
                    curr.pop_back();
                }
            }
        }


        else{

         for(int i= (curr.back()-'0') ;i >= 1 ; i--)
            {
                if(visited[i]==0)
                {
                    curr+=to_string(i);
                    visited[i]=1;
                    solver(curr,ans,visited,idx+1,pattern);
                    visited[i]=0;
                    curr.pop_back();
                }
            }
        }


       return ;
    }

    string smallestNumber(string pattern) {

        N = pattern.size();
        string ans = ""; 
        vector<int> visited(10, 0);

        for (int i = 1; i <= N + 1; i++) {
            string curr = to_string(i);
            visited[i] = 1;
            solver(curr, ans, visited, 0, pattern);
            visited[i] = 0;
        }

        return ans;
    }
};