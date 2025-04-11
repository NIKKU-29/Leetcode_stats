class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        
        int count = 0;
        // low = 1203;
        // high = 1212;
        for(int i = low ; i <= high ; i++)
        {
           string num = to_string(i);
           if(num.size() % 2 == 0)
           {
                int first =0;
                int second = 0;
                for(int j = 0 ; j<num.size() ; j++)
                { 
                    if(j < num.size()/2)
                    {
                        first+= num[j] - '0';
                    }

                    else
                    {
                        second+= num[j] - '0';
                    }
                }
                
                // cout<<first<<"()"<<second;
              
                if(first == second) count++;
           }
        }

        return count;
    }
};