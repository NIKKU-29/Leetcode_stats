class Solution {
public:

    // void helper(priority_queue<pair<char,int>>&pq,string &ans,pair<char, int> elem,char &prevElem,int repeatLimit)
    // {
       
    // }

    string repeatLimitedString(string s, int repeatLimit) {

        priority_queue<pair<char,int>>pq;
        unordered_map<char,int>mp;


        for(auto elem : s)
        {
            mp[elem]++;
        }

        for(auto elem : mp)
        {
            pq.push({elem.first,elem.second});
        }

        string ans="";
        char prevElem='!';

        while(!pq.empty())
        {
            auto elem = pq.top(); 
            pq.pop();

            if(elem.first!=prevElem) 
            {
                // helper(pq,ans,elem,prevElem,repeatLimit);
                 if(elem.second <= repeatLimit)
            {
                ans.append(elem.second, elem.first);
                prevElem=elem.first;
            }

            else
            {
                    ans.append(repeatLimit,elem.first);
                    if(elem.second-repeatLimit!=0)
                    {
                        pq.push({elem.first,elem.second-repeatLimit});
                    }    
                    prevElem=elem.first; 
                 

            }
            }

            //if elemnt on top is same as previous then add the next to the top to the string
            else {
                    if(pq.empty())
                    {
                        return ans;   
                    }

            auto Nelem = pq.top();
            pq.pop();
            
                ans.append(1,Nelem.first);
                prevElem=Nelem.first;

                if (Nelem.second - 1 > 0) {
                    pq.push({Nelem.first, Nelem.second - 1});
                }

                pq.push(elem);
                    
            }
        }

        return ans;
        
    }
};