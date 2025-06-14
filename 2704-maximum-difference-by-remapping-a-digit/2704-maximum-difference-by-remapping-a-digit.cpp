class Solution {
public:
    int minMaxDifference(int num) {

        string maxi,mini;
        string number = to_string(num);
        char selected;

        for(auto elem : number)
        {
            if(elem != '9')
            {
                selected = elem;
                break;
            }
        }

        // cout<<"SELCTED IS ->"<<selected<<endl;

        for(auto elem : number)
        {
           if(elem == selected) 
           {
                maxi+='9';
           }

           if(elem == number[0])
           {
                mini+='0';
           }
        
           if(elem != selected)
           {
                
                maxi+=elem;
               
           }

           if(elem != number[0])
           {
                 mini+=elem;
           }
        }

        cout<<maxi<<"<>"<<mini;

        return stoi(maxi) - stoi(mini);

    }
};