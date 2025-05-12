class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        
        unordered_map<int,int>mp;

        for(auto elem : digits)
        {
            mp[elem]++;
        }

        

        vector<int>ans;

        for(int i = 100 ; i < 1000 ; i++)
        {

            unordered_map<int,int>proxy = mp;

            if(i % 2 == 0)
            {   
               
                string num = to_string(i);
                
                bool valid = true;

                    for(auto elem : num)
                    {
                        int digit = elem - '0';

                         if(proxy.find(digit) == proxy.end())
                         {
                            
                            valid = false;
                            break;
                         }

                        else{

                                proxy[digit]--;
                                if(proxy[digit] == 0) proxy.erase(digit);
                        }
                    }

                   
                if(valid) ans.push_back(i);
                    
            }
        }


        return ans;

    }
};