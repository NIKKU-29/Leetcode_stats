// class Solution {
// public:

//     // bool valid(unordered_map<char,int>&mp)
//     // {
//     //     if()
//     // }

//     int longestBeautifulSubstring(string word) {
//         int n = word.size();
//         int start = 0;
//         int maxlen = 0;
//         // unordered_map<char,int>mp;
//         int diff = 1;
//         // while(end > n)

//         for(int end = 0 ; end < n ; end ++)
//         {
//             if(end > 0 && word[end] < word[end -1])
//             {
//                 diff = 1;
//                 start = end;
//                 // mp.clear();
//             }

//             else if(end > 0 && word[end] > word[end -1]) diff++;

//             if(diff == 5)
//             {
//                 maxlen = max(maxlen,end - start + 1);
//             }
//         }
        
//         return maxlen;
//     }
// };



class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        int start = 0, end = 0;
        int maxlen = 0;

        while (start < n) {
            if (word[start] != 'a') {
                start++;
                continue;
            }

            end = start;
            int diff = 1; // We start from 'a', so 1 vowel found

            while (end + 1 < n && word[end] <= word[end + 1]) {
                if (word[end] < word[end + 1])
                    diff++; // New vowel in order
                end++;
            }

            if (diff == 5) {
                maxlen = max(maxlen, end - start + 1);
            }

            start = end + 1; // Move to the next possible segment
        }

        return maxlen;
    }
};
