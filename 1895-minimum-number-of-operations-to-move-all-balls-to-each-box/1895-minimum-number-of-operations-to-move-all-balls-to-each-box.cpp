class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        // vector<int>ans;
        // vector<int>relative;
        // for(int i=0 ; i<boxes.size();i++)
        // {
        //     if(boxes[i]=='1')
        //     {
        //         relative.push_back(i);
        //     }
        // }

        // for(int i=0 ; i< boxes.size() ; i++)
        // {
        //     int sum=0;
        //     for(auto elem : relative)
        //     {
        //         sum+=abs(i-elem);
        //     }
            
        //     ans.push_back(sum);
        // }

        // return ans;

        int n=boxes.size();
        vector<int>ans(n,0);
        int ballsonleft=0,movesfromleft=0;
        int ballsonright=0,movesfromright=0;

        for(int i=0 ; i< n ; i++)
        {
            ans[i]+=movesfromleft;
            ballsonleft+=boxes[i]-'0';
            movesfromleft+=ballsonleft;

            int j=n-i-1;
            ans[j]+=movesfromright;
            ballsonright+=boxes[j]-'0';
            movesfromright+=ballsonright;


        }

        return ans;
    }
};