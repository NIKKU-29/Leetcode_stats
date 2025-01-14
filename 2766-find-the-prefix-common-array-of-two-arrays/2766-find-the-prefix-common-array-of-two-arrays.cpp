class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
            int n=A.size();
            vector<int>freq(1e5,0);
            int count=0;
            vector<int>ans;

            for(int i=0 ; i< n ;i++)
            {
                freq[A[i]]++;
                freq[B[i]]++;

                if(A[i]==B[i])
                {
                    count++;
                }

                else{

                if(freq[A[i]] >= 2)
                {
                    count++;
                }

                if(freq[B[i]] >= 2)
                {
                    count++;
                }
            }


                ans.push_back(count);
            }

            return ans;
    }
};