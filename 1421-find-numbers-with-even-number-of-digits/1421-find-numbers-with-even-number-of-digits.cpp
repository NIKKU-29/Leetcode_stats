class Solution {
public:
    int findNumbers(vector<int>& nums) {

        int count = 0;
        for(auto elem : nums)
        {
            string ele = to_string(elem);
            if(ele.size() % 2 ==0) count++;
        }

        return count;
        
    }
};