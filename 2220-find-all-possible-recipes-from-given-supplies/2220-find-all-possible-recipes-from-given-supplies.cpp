class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

            unordered_map<string,int>Available;

            for(auto elem : supplies) Available[elem]++;

            int count = recipes.size();

            while(count--)
            {

                for(int i =0 ;i < ingredients.size() ;i++)
                {

                    int n = ingredients[i].size();
                    bool outlier = false;
                    for(int j=0 ; j< n ; j++)
                    {
                        if(Available.find(ingredients[i][j]) == Available.end())
                        {
                            outlier = true;
                            break;
                        }   
                    }

                    if(outlier == false)
                    {
                        Available[recipes[i]]++;
                    }

                }
            }



            vector<string>ans;

            for(int i =0 ;i< recipes.size() ; i++)
            {
                int n = ingredients[i].size();
                bool outlier = false;
                for(int j=0 ; j< n ; j++)
                {
                    if(Available.find(ingredients[i][j]) == Available.end())
                    {
                        outlier = true;
                        break;
                    }   
                }

                if(!outlier) ans.push_back(recipes[i]);
            }

        return ans;
    }
};