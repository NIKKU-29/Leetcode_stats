// class Solution {
// public:

       

//     long long maxKelements(vector<int>& nums, int k) {

//         priority_queue<int>pq(nums.begin(),nums.end());
//         long long ans=0;

//         for(int i=0;i<k;i++)
//         {
//             int elem=pq.top();
//             ans+=elem;

//             if(elem==1)
//             {
//                 ans+=(k-elem-1);
//                 break;
//             }

//             pq.pop();
//             pq.push((elem+2)/3);
           
//         }


//         return ans;
        
//     }
// };


class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long score=0;
        for(int i=0; i<k; i++){
            int x=pq.top();
            score+=x;
            if (x==1){
                score+=(k-1-i);
                break;
            }
            pq.pop();
            pq.push((x+2)/3);
        }
        return score;
    }
};