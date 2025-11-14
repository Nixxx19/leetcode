class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1, i = 0;
        while (i < digits.size() && carry) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
            i++;
        }
        if (carry) digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
