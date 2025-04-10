// class Solution {
// public:

    // bool valid(unordered_map<char,int>&mp)
    // {
    //     if()
    // }

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
    int helper(string& word, int i, int n) {
        if (i >= n) return 0;

        if (word[i] != 'a') {
            return helper(word, i + 1, n);
        }

        int vowelCount = 1; // 'a' is first
        int end = i;

        while (end + 1 < n && word[end] <= word[end + 1]) {
            if (word[end] < word[end + 1]) {
                vowelCount++;
            }
            end++;
        }

        int currLen = (vowelCount == 5) ? end - i + 1 : 0;

        // Start next recursion from character after this block
        return max(currLen, helper(word, end + 1, n));
    }

    int longestBeautifulSubstring(string word) {
        return helper(word, 0, word.size());
    }
};
