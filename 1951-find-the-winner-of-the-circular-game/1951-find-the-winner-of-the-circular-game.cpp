class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0;  // Base case for one person (0 in zero-based index)
        for (int i = 2; i <= n; ++i) {
            winner = (winner + k) % i;
        }
        return winner + 1;  // Convert from zero-based index to one-based
    }
};
