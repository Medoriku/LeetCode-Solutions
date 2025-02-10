class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for (char c : s) {
            if (isdigit(c)) {
                if (!st.empty()) {
                    st.pop(); // Remove the closest non-digit character
                }
            } else {
                st.push(c); // Push letters onto the stack
            }
        }

        // Convert stack to string
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        // Reverse the result since stack stores in LIFO order
        reverse(result.begin(), result.end());
        return result;
    }
};
