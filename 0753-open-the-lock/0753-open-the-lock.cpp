class Solution 
{
public:
    int openLock(vector<string>& deadends, string target) 
    {
        int level = 0;
        unordered_set<string> dead, vis;

        for(auto &deadend : deadends) dead.insert(deadend);
        if(dead.count("0000")) return -1;
        

        queue<string> q;
        q.push("0000");
        vis.insert("0000");

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                string cur_state = q.front();q.pop();
                if(cur_state == target) return level;
                for(int i = 0; i < 4; i++)
                {
                    string temp = cur_state;
                    temp[i] == '9' ? temp[i] = '0' : temp[i]++;
                    if(!vis.count(temp) && !dead.count(temp)) 
                        q.push(temp), vis.insert(temp);

                    temp = cur_state;
                    temp[i] == '0' ? temp[i] = '9' : temp[i]--;
                    if(!vis.count(temp) && !dead.count(temp)) 
                        q.push(temp), vis.insert(temp);
                }
            }
            ++level;
        }
        return -1;
    }
};