class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        while (n >= 1) {
            if (n % 5 == 0 && n % 3 == 0) {
                answer.push_back("FizzBuzz");
                n -= 1;
                continue;
            } else if (n % 5 == 0 && n % 3 != 0) {
                answer.push_back("Buzz");
                n -= 1;
                continue;
            } else if (n % 3 == 0 && n % 5 != 0) {
                answer.push_back("Fizz");
                n -= 1;
                continue;
            }

            else {
                answer.push_back(to_string(n));
                n -= 1;
                continue;
            }
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};