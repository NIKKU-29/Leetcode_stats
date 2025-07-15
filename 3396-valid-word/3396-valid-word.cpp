class Solution {
public:
    bool isValid(string word) {
        bool char3 = false;
        bool vow = false;
        bool cons = false;
        int chr = 0;

        for(auto elem : word)
        {
            if(!isalpha(elem) && !isdigit(elem)) return false;
            if(isalpha(elem))
            {
                elem = toupper(elem);
                if(elem == 'A' || elem == 'E' || elem == 'I' || elem == 'O' || elem == 'U')
                {
                    vow = true;
                    chr++;
                }

                else{

                    cons = true;
                    chr++;

                }
            }

            if(isdigit(elem)) chr++;
        }

        if(chr >= 3) char3 = true;

       
        return char3 && cons && vow ;
    }
};