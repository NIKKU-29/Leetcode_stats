class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
            int moves=0;
            unordered_set<string>st,vis;

            for(auto elem : deadends) st.insert(elem);
            queue<string>q;
            q.push("0000");
            vis.insert("0000");

            if(st.count("0000")) return -1;
            int counter=0;

            while(!q.empty())
            {
                int sz=q.size();

                while(sz--)
                {
                    string curr=q.front();
                    q.pop();

                    if(curr==target) return moves;

                    for(int i=0 ; i < 4; i++)
                    {
                        
                        

                        string temp=curr;
                        temp[i]=='9' ? temp[i]= '0' : temp[i]++;
                        if(!st.count(temp) && !vis.count(temp))
                        {
                            q.push(temp);
                            vis.insert(temp);
                        }
                        
                        temp=curr;
                        temp[i]=='0' ? temp[i] = '9' : temp[i]--;
                        if(!st.count(temp) && !vis.count(temp))
                        {
                            q.push(temp);
                            vis.insert(temp);
                        }   
                    }

                }
                    ++moves;
                
            }

            return -1;

    }
};