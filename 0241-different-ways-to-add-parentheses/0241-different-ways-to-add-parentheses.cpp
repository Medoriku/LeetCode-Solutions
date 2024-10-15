class Solution {
public:
    // Memoization map to store results of sub-expressions
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        // If result already computed for this expression, return it
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }
        
        vector<int> result;

        // Traverse the expression to find operators
        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                // Recursively compute left and right parts
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // Combine results from left and right based on the operator
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') {
                            result.push_back(l + r);
                        } else if (c == '-') {
                            result.push_back(l - r);
                        } else if (c == '*') {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }

        // If no operators were found, the expression is a single number
        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        // Store the computed result in memo
        memo[expression] = result;
        return result;
    }
};
