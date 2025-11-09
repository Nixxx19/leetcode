class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() - 2;
        long long S = 1LL * n * (n - 1) / 2;
        long long P = 1LL * (n - 1) * n * (2LL * n - 1) / 6;

        long long sumNums = 0, sumSqNums = 0;
        for (int x : nums) {
            sumNums += x;
            sumSqNums += 1LL * x * x;
        }

        long long sumDiff = sumNums - S;      
        long long sqDiff = sumSqNums - P;    
        long long prod = ((sumDiff * sumDiff) - sqDiff) / 2; 

        long long D = sqrt(sumDiff * sumDiff - 4 * prod);
        long long x = (sumDiff + D) / 2;
        long long y = (sumDiff - D) / 2;

        return {(int)x, (int)y};
    }
};
