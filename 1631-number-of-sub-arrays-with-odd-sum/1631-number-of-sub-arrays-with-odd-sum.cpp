class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int odd_count = 0,
            even_count = 1; // Start with even_count as 1 to account for the sum
                            // 0 which is even
        int current_sum = 0;
        int result = 0;

        for (int num : arr) {
            current_sum += num;

            if (current_sum % 2 == 0) {
                result =
                    (result + odd_count) % MOD; // add count of odd prefix sums
                even_count++;
            } else {
                result = (result + even_count) %
                         MOD; // add count of even prefix sums
                odd_count++;
            }
        }

        return result;
    }
};
