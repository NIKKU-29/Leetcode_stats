class Solution {
public:
    int maxDiff(int num) {

        string number = to_string(num);
        char selecteda = '\0';
        char selectedb = '\0';

        for(auto elem : number)
        {
            if(elem != '9')
            {
                selecteda = elem;
                break;
            }
        }

        for(auto elem : number)
        {
            if(elem != '1' && elem > '1')
            {
                selectedb = elem;
                break;
            }
        }

        string maxi,mini;

        for(auto elem : number)
        {
            if(elem == selecteda) maxi+='9';
            if(elem != selecteda) maxi+=elem;
            if(elem == selectedb && number[0] != '1') mini+='1';
            if(elem == selectedb && number[0] == '1') mini+='0';
            if(elem != selectedb) mini+=elem;
        }

        if(selectedb == '\0') mini = number;

        return stoi(maxi) - stoi(mini);

    }
};