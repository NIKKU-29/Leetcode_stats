class Solution {
public:
    bool canChange(string start, string target) {
        
        //checking order
        // vector<pair<int,int>>starts;
        // int idx=0;
        // for(auto elem : start)
        // {   
        //     if(elem!='_') starts.push_back({elem,idx});
        //     idx++;
        // }

        // vector<pair<int,int>>targets;
        // int idx2=0;
        // for(auto elem : target)
        // {
        //     if(elem!='_') targets.emplace_back(elem,idx2);
        //     idx2++;
        // }

        // if(starts.size()!=targets.size()) return false;
        // int n=starts.size();
        // for(int i=0 ; i < n ;i++)
        // {
        //     if(targets[i].first !=starts[i].first || ( starts[i].first == 'L' && starts[i].second < targets[i].second) || ( starts[i].first == 'R' && starts[i].second > targets[i].second) )
        //     {
        //         return false;
        //     }
        // }

        // return true;


        int starts=0;
        int targets=0;
        int n=start.size();

        while(starts < n || targets < n)
        {
            while(starts < n && start[starts]=='_')
            {
                starts++;
            }

            while(targets < n && target[targets]=='_')
            {
                targets++;
            }

            if( (starts == n && targets!=n ) || (starts != n && targets==n) )
            {
                return false;
            }

            if(start[starts]!=target[targets] || ( start[starts]=='L' && starts < targets ) || ( start[starts]=='R' && starts > targets ))
            {
                return false;
            }

            starts++;
            targets++;
        }


        return true;
    }
};