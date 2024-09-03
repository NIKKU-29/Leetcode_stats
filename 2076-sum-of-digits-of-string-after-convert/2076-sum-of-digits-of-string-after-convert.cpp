class Solution {
public:
    int getLucky(string s, int k) {

        string number;

        for(char elem : s)
        {
            number+= to_string(elem - 'a' + 1);
        }
        
        while(k!=0)
        {
            int no=0;

            for(char elem : number)
            {
                no+=(elem - '0'); 
            }

            number=to_string(no);
            k--;
        }

        return stoi(number);
    }
};