class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
        backtrack(candidates, target, 0, combination, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& combination, vector<vector<int>>& result) {
        if (target == 0) {  // If we hit the target sum
            result.push_back(combination);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;  // Skip duplicates

            if (candidates[i] > target) break;  // No point in continuing if the current candidate is greater than the target
            
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, combination, result);  // Recur with reduced target and next start index
            combination.pop_back();  // Backtrack and try the next candidate
        }
    }
};
