class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1000000007;
        unordered_map<long long,long long> cnt;
        for (auto& p : points) cnt[p[1]]++;
        long long total = 0;
        long long sq = 0;
        for (auto& e : cnt) {
            long long k = e.second;
            long long c = k * (k - 1) / 2;
            c %= MOD;
            total = (total + c) % MOD;
            sq = (sq + (c * c) % MOD) % MOD;
        }
        long long ans = (total * total % MOD - sq + MOD) % MOD;
        ans = ans * ((MOD + 1) / 2) % MOD;
        return ans;
    }
};
