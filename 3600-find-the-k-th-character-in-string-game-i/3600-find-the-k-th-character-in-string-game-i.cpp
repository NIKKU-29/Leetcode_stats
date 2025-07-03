class Solution {
public:
    char kthCharacter(int k) {

        string word = "a";

        while(word.size() < k)
        {
            string add = "";

            for(int i = 0 ; i < word.size() ; i++)
            {
                char elem = word[i];
                if(elem == 'z') add+='a';
                else add+= (elem + 1);
            }

            word+=add;
        }
        
        cout<<word;
        return word[k-1]; 
    }
};