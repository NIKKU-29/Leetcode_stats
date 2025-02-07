
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> result;
        unordered_map<int, int> ballColors; 
        unordered_map<int, int> colorCount; 

        for (const vector<int>& query : queries) {
            int ball = query[0];
            int color = query[1];

            
            if (ballColors.find(ball) != ballColors.end()) {
                int oldColor = ballColors[ball];
                colorCount[oldColor]--;
                if (colorCount[oldColor] == 0) {
                    colorCount.erase(oldColor);
                }
            }

            
            ballColors[ball] = color;
            colorCount[color]++;

            
            result.push_back(colorCount.size());
        }

        return result;
    }
};