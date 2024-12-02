class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {


        stringstream ss(sentence);
        string word;
        int count=0;
        while(ss >> word)
        {
            count++;
            if(word.size() < searchWord.size()) continue;

            else{

                string match=word.substr(0,searchWord.size());
                if(match==searchWord) return count;
            }
        }
        

        return -1;
    }
};