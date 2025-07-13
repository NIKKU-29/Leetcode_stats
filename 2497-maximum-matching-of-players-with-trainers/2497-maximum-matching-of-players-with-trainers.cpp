class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n=players.size(),m=trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());  

        int count = 0;
        int i =0,j=0;
        while(i < n && j < m)
        {
            if(players[i] > trainers[j])
            {
                j++;
            }

            else if(players[i] <= trainers[j])
            {
                i++;
                j++;
                count++;
            }
        }  

        return count;
    }
};