class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int ans = INT_MAX;
        int n = blocks.size();
        int i=0,j=0,B=0,W=0;
        
        if(n == 1) return blocks[0] == 'W' ? 1 : 0;

        while(j <= n)
        {
            while(j-i+1 <= k)
                {
                    if(blocks[j] == 'W') W++;
                    else B++;
                    j++;
                    
                }

            ans=min(ans,W);

            
            if( j < n && blocks[j] != blocks[i])
            {
                if(blocks[i] == 'W') 
                {
                    W--;
                    B++;
                }

                else
                {
                    B--;
                    W++;    
                }
                
                ans=min(ans,W);

            }

            i++;
            j++;

        }

        return ans;        

    }
};