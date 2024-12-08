class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<pair<int,pair<bool,int>>>plots;
        int maxsum=0;
        int maxend=0;

        for(auto event : events)
        {
            int start=event[0],end=event[1],value=event[2];
            plots.push_back({start,{true,value}}); //inclusive
            plots.push_back({end+1,{false,value}}); //exclusive
        }

        sort(plots.begin(),plots.end());

        for(auto plot : plots)
        {
            int time=plot.first;
            bool starting=plot.second.first;
            int value=plot.second.second;

            if(starting==true)
            {
                maxsum=max(maxsum,maxend+value);
            }
            else{
                maxend=max(maxend,value);
            }
        }
        
        return maxsum;
    }
};