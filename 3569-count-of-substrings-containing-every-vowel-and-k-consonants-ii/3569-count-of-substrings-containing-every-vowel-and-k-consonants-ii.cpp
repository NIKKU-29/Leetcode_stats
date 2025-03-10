class Solution {
public:

    bool isVowel(char c) { 
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    long long countOfSubstrings(string word, int k) {
        int n=word.size();
        int i=0,j=0;
        unordered_map<char,int>mp;
        int C=0;
        long long ans=0;

        vector<int>NextConsonant(n);
        int maxic = n;

        for(int i= n-1 ; i>=0 ; i--)
        {
            NextConsonant[i]=maxic;
            if(!isVowel(word[i])) maxic = i;
        }

        while(j < n)
        {
            if (isVowel(word[j])) mp[word[j]]++;
            else C++;

            while(C > k)
            {
                char ch = word[i];
                 if (isVowel(ch))
                {   
                    mp[ch]--;
                    if(mp[ch] == 0) mp.erase(ch);
                }

                else C--;  

                i++; 
            }

            while(i < n && mp.size() == 5 && C == k)
            {
                int nxtidx = NextConsonant[j];
                ans+= nxtidx - j;

                if (isVowel(word[i]))
                {   
                    mp[word[i]]--;
                    if(mp[word[i]] == 0) mp.erase(word[i]);
                }
                else C--;

                i++;
            }

            j++;
        }

        return ans;
    }
};