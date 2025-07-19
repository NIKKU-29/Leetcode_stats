class Solution {
public:
    bool fun(string check, unordered_set<string>& st) {
        if (st.count(check)) return false; // It's a subfolder
        if (check.empty()) return true;

        int n = check.size();
        while (n > 0 && check[n - 1] != '/') n--;
        return fun(check.substr(0, n - 1), st);
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(folder.begin(), folder.end());
        vector<string> ans;

        for (auto& elem : folder) {
            int n = elem.size();
            while (n > 0 && elem[n - 1] != '/') n--;

            string need = elem.substr(0, n - 1);

            if (fun(need, st)) {
                ans.push_back(elem);
            }
        }

        return ans;
    }
};
