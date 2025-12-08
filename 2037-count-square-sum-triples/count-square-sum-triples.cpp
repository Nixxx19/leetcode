class Solution {
public:
    int countTriples(int n) {
        int c = 0;
        for (int a = 1; a <= n; a++)
            for (int b = 1; b <= n; b++)
                for (int k = a*a + b*b, c2 = 1; c2 <= n; c2++)
                    if (c2*c2 == k) c++;
        return c;
    }
};
