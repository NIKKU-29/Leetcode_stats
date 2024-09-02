class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();
        int left=0,right=0,count=0;
        unordered_map<char,int>map;

    
            while(right<n)
            {
                map[s[right]]++;
                right++;

            while(map[s[right]]>1)
            {
                map[s[left]]--;
                left++;
                
            }

                count=max(count,right-left+1);
            
        }

        return count;
    }
};