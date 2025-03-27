// class Solution {
// public:
//     int minimumIndex(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int>Main;

//         for(auto elem : nums) Main[elem]++;

//         unordered_map<int,int>checker;
//         for(int i = 0 ;i< n-1 ;i++)
//         {
//             int elem = nums[i];
//             checker[elem]++;
//             int leftpartLen = i+1,rightpartLen = n - leftpartLen;
//             int freqdiff = Main[elem] - checker[elem];

//             if(leftpartLen < (checker[elem] * 2) && rightpartLen < (freqdiff * 2))
//             {
//                 return i;
//             } 
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int minimumIndex(vector<int>& nums) {

            int elem = 0,count = 0;

            for(auto ele : nums)
            {
                if(count == 0) elem = ele;
                count+= (elem == ele) ? +1 : -1;
            }

            int n =nums.size();

            int total = 0;
            for (int x : nums) {
                if (x == elem) total++;
            }
            if (total * 2 <= n) return -1;
            int cnt =0;

            for(int i = 0 ;i< n-1 ;i++)
            {
                if(nums[i] == elem)
                {

                    cnt++;
                    int freqdiff = total - cnt;
                    int leftpartLen = i+1,rightpartLen = n - leftpartLen;
                    if(leftpartLen < (cnt * 2) && rightpartLen < (freqdiff * 2))
                    {
                        return i;
                    } 
                }
            }

        return -1;
    }
};