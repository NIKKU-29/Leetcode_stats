class Solution {
public:

    int binarySearch(int height,vector<pair<int,int>>&st)
    {
        int l=0; 
        int r=st.size()-1;
        int idx=-1;

        while(l <=r)
        {
            int mid=l+(r-l)/2;

            if(st[mid].first > height)
            {
                idx=mid;
                l=mid+1;
            }

            else
            {
                r=mid-1;
            } 
        }

        return idx;
    }



    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {

        vector<pair<int,int>>st;
        vector<int>answer(queries.size());
        vector<vector<pair<int,int>>>Queries_left(heights.size());

        for(int i=0 ; i< queries.size() ; i++)
        {
            int a=queries[i][0],b=queries[i][1];
            if(a>b) swap(a,b);
            answer[i]=( heights[a] < heights[b] || a==b ) ? b : -1;
            if(answer[i]==-1) Queries_left[b].push_back({heights[a],i});

            //this line shows the condition when the height of a is more than
            // b and we have to find someone greter than both on the right
            //so we use Queries_left hcih shows which queries
            //are left and where not haldeled now have to find just large
            //number on the right side of each quries
            //so we store b after this index we have to find
            // height[a] a heighter beiiger than is height
            //i shoing and final answer where we have to push when we find
            // just greater 
        }

        for(int i=heights.size()-1 ; i>=0 ;i--)
        {
            for(auto & [h,idx] : Queries_left[i])
            {
                int nextgreateridx=binarySearch(h,st);
                if(nextgreateridx!=-1)
                {
                    answer[idx]=st[nextgreateridx].second;
                }
            }

            while(!st.empty() && st.back().first<=heights[i])
            {
                st.pop_back();
            }

            st.push_back({heights[i],i});
        }

        return answer;
        
    }
};