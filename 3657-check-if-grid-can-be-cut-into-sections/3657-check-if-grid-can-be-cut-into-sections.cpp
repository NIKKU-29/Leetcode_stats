class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return canCut(rectangles, 0) || canCut(rectangles, 1);
    }
    

    bool canCut(vector<vector<int>>& rectangles, int axis) {
        vector<pair<int,int>>intervals;

        for (const auto& rect : rectangles) {
            int xy1 = rect[axis];    
            int xy2 = rect[axis + 2]; 
            intervals.push_back({xy1,xy2});
        }

       sort(intervals.begin(),intervals.end());
       vector<pair<int,int>>vec;
       
       for(auto elem : intervals)
       {
            if(vec.empty())
            {
                vec.push_back(elem);
            }

            else{
                    int x = elem.first;
                    int y = elem.second;

                    if(vec.back().second > x)
                    {
                        int newx = min(vec.back().first,x);
                        int newy = max(vec.back().second,y);
                        vec.pop_back();
                        vec.push_back({newx,newy});
                    }

                    else{
                        vec.push_back({x,y});
                    }

            }
       }
        
        if(vec.size() >= 3) return true; 
        
        return false;
    }
};
