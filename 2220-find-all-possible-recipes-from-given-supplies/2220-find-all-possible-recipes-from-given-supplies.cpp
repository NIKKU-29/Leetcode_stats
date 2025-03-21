class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> Available;
        vector<bool> done(recipes.size(), false);  // Track which recipes are already made
        
        // Mark all initial supplies as available
        for (auto& elem : supplies) Available[elem]++;
        
        int count = recipes.size();  // Number of recipes to process
        while (count--) {
            bool madeRecipe = false;  // Track if at least one recipe is made in this iteration

            for (int i = 0; i < recipes.size(); i++) {
                if (done[i]) continue;  // Skip recipes that are already made

                int n = ingredients[i].size();
                bool outlier = false;
                
                // Check if all ingredients are available
                for (int j = 0; j < n; j++) {
                    if (Available.find(ingredients[i][j]) == Available.end()) {
                        outlier = true;
                        break;
                    }
                }

                // If all ingredients are available, mark recipe as done
                if (!outlier) {
                    Available[recipes[i]]++;
                    done[i] = true;  // Mark this recipe as made
                    madeRecipe = true;
                }
            }

            // If no new recipe was made in this iteration, break early
            if (!madeRecipe) break;
        }

        // Collect all successfully made recipes
        vector<string> ans;
        for (int i = 0; i < recipes.size(); i++) {
            if (done[i]) ans.push_back(recipes[i]);
        }

        return ans;
    }
};
