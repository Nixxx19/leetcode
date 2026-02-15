class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1, j = b.size() - 1;
        bool carry = false;
        while (i >= 0 || j >= 0 || carry) {
            int ones = carry;
            if (i >= 0) ones += a[i--] - '0';
            if (j >= 0) ones += b[j--] - '0';
            res.push_back((ones & 1) + '0');
            carry = ones > 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
