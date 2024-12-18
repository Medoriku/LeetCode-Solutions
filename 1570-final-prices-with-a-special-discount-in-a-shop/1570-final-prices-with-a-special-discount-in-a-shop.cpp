class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> answer(n);

        for (int i = 0; i < n; i++) {
            // Start with no discount
            answer[i] = prices[i];
            // Look for the first item giving a discount
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    answer[i] = prices[i] - prices[j];
                    break;
                }
            }
        }

        return answer;
    }
};
