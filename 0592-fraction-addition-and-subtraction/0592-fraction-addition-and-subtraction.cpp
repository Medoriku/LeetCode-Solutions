class Solution {
public:
    string fractionAddition(string expression) {
        // Initialize the result numerator and denominator as 0/1.
        int numerator = 0, denominator = 1;
        
        // Use a stringstream to parse the expression.
        istringstream ss(expression);
        int num, denom;
        char slash;

        while (ss >> num >> slash >> denom) {
            // Update numerator and denominator by adding/subtracting the current fraction.
            numerator = numerator * denom + num * denominator;
            denominator *= denom;

            // Reduce the fraction by dividing with the GCD of the numerator and denominator.
            int gcdVal = gcd(abs(numerator), abs(denominator));
            numerator /= gcdVal;
            denominator /= gcdVal;
        }

        // Handle cases where the denominator is negative.
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        // Return the result in string format.
        return to_string(numerator) + "/" + to_string(denominator);
    }
};
