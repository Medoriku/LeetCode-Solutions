class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for (int i = 0; i < bills.size(); ++i) {
            if (bills[i] == 5) {
                // Customer pays with $5, no change needed
                five++;
            } 
            else if (bills[i] == 10) {
                // Customer pays with $10, need to give back $5 as change
                if (five > 0) {
                    five--;
                    ten++;
                } else {
                    return false; // Not enough $5 bills for change
                }
            } 
            else if (bills[i] == 20) {
                // Customer pays with $20, need to give back $15 as change
                if (ten > 0 && five > 0) {
                    // Prefer to give one $10 and one $5
                    ten--;
                    five--;
                } else if (five >= 3) {
                    // Otherwise give three $5 bills
                    five -= 3;
                } else {
                    return false; // Not enough bills for change
                }
            }
        }

        return true; // Able to provide change for all customers
    }
};
