class Solution {
public:
    int countTriples(int n) {
        int c = 0;
        for (int a = 1; a <= n; a++)
            for (int b = 1; b <= n; b++) {
                int s = a*a + b*b;
                int c2 = sqrt(s);
                if (c2 <= n && c2*c2 == s) c++;
            }
        return c;
    }
};
