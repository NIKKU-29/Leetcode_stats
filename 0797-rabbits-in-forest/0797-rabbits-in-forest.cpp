class Solution {
public:
    int numRabbits(vector<int>& answers) {

            map<int,int>mp;
            for(auto elem : answers)
            {
                mp[elem]++;
            }

            int sum = 0;

            for(auto elem : mp)
            {
                int num = elem.first;
                int count = elem.second;

                // if(num == 0) sum+=count;
                
                     double d = ceil((double)count / (num + 1));
                     sum += d * (num+1);
           
            }

        return sum;
    }
};