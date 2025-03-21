class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> inDegree;
        unordered_map<string, vector<string>> graph;
        unordered_set<string> available(supplies.begin(), supplies.end());
        queue<string> q;

        // Initialize graph and in-degree for recipes
        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = ingredients[i].size(); // Count required ingredients
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]); // Ingredient -> Recipe dependency
            }
        }

        // Add initial supplies to the queue
        for (const string& s : supplies) {
            q.push(s);
        }

        vector<string> result;

        // Process the queue
        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            // If curr is a recipe and in-degree becomes 0, it can be made
            if (inDegree.find(curr) != inDegree.end() && inDegree[curr] == 0) {
                result.push_back(curr);
            }

            // Reduce in-degree of dependent recipes
            for (const string& r : graph[curr]) {
                if (--inDegree[r] == 0) {
                    q.push(r); // All ingredients for r are available now
                }
            }
        }

        return result;
    }
};