class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        vector<int>ans;
        vector<int>relative;
        for(int i=0 ; i<boxes.size();i++)
        {
            if(boxes[i]=='1')
            {
                relative.push_back(i);
            }
        }

        for(int i=0 ; i< boxes.size() ; i++)
        {
            int sum=0;
            for(auto elem : relative)
            {
                sum+=abs(i-elem);
            }
            
            ans.push_back(sum);
        }

        return ans;
    }
};