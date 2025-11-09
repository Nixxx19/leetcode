class Solution {
public:
    int countOperations(int a, int b) {
        int ops = 0;
        for (; a && b; ops += a / b, a %= b, swap(a, b));
        return ops;
    }
};
