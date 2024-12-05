class Solution {
public:
    bool canChange(string start, string target) {
        
        //checking order
        vector<pair<int,int>>starts;
        int idx=0;
        for(auto elem : start)
        {   
            if(elem!='_') starts.emplace_back(elem,idx);
            idx++;
        }

        vector<pair<int,int>>targets;
        int idx2=0;
        for(auto elem : target)
        {
            if(elem!='_') targets.emplace_back(elem,idx2);
            idx2++;
        }

        if(starts.size()!=targets.size()) return false;
        int n=starts.size();
        for(int i=0 ; i < n ;i++)
        {
            if(targets[i].first !=starts[i].first || ( starts[i].first == 'L' && starts[i].second < targets[i].second) || ( starts[i].first == 'R' && starts[i].second > targets[i].second) )
            {
                return false;
            }
        }

        return true;
    }
};