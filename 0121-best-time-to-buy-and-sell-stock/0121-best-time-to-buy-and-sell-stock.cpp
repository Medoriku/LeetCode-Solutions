class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        // Loop through all the prices in the vector
        for (int price : prices){
            // If the price is less than minPrice (which will be true for most cases), set minPrice equal to the current price 
            if (price < minPrice){
                minPrice = price;
            }

            // Set profit equal to the difference between current price and the minPrice
            int profit = price - minPrice;
            if (profit > maxProfit){
                maxProfit = profit;
            }
        }
        return maxProfit;
    }
};