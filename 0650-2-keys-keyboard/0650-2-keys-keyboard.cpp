class Solution {
public:
    int minSteps(int n) {
        int steps = 0;
        for (int factor = 2; factor <= n; ++factor) {
            while (n % factor == 0) {
                steps += factor;
                n /= factor;
            }
        }
        return steps;
    }
};
