class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char,int> freq;
        for (char c : s) freq[c]++;

        string temp = "", ans = "";
        char mini = 'a';

        for (char c : s) {
            temp.push_back(c);
            freq[c]--;

            while (mini <= 'z' && freq[mini] == 0)
                mini++;

            while (!temp.empty() && temp.back() <= mini) {
                ans.push_back(temp.back());
                temp.pop_back();
            }
        }

        return ans;
    }
};
