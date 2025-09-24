class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string result = (numerator < 0) ^ (denominator < 0) ? "-" : "";
        long long num = abs((long long)numerator);
        long long denom = abs((long long)denominator);
        
        result += to_string(num / denom);
        long long remainder = num % denom;
        if (remainder == 0) return result;
        
        result += ".";
        unordered_map<long long, int> seen_remainders;
        
        while (remainder != 0) {
            if (seen_remainders.find(remainder) != seen_remainders.end()) {
                int pos = seen_remainders[remainder];
                result.insert(result.begin() + pos, '(');
                result += ')';
                return result;
            }
            
            seen_remainders[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / denom);
            remainder %= denom;
        }
        
        return result;
    }
};
// finished