class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        
        for (char c : expression) {
            if (c == ')') {
                // Collect all the inner expressions between '(' and ')'
                vector<char> innerExpr;
                while (stk.top() != '(') {
                    innerExpr.push_back(stk.top());
                    stk.pop();
                }
                stk.pop(); // Pop the '('

                // Get the operator before '('
                char op = stk.top();
                stk.pop();

                // Evaluate the inner expression based on the operator
                bool result;
                if (op == '&') {
                    result = true;
                    for (char ch : innerExpr) {
                        result &= (ch == 't');
                    }
                } else if (op == '|') {
                    result = false;
                    for (char ch : innerExpr) {
                        result |= (ch == 't');
                    }
                } else if (op == '!') {
                    // There should be only one element for '!'
                    result = !(innerExpr[0] == 't');
                }

                // Push the result back as 't' or 'f'
                stk.push(result ? 't' : 'f');
            } 
            else if (c != ',') {
                // Push other valid characters onto the stack
                stk.push(c);
            }
        }

        // The final result should be the only element in the stack
        return stk.top() == 't';
    }
};
