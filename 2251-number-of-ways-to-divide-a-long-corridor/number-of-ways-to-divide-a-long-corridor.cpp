class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1000000007;
        vector<int> seats;
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') seats.push_back(i);
        }
        int totalSeats = seats.size();
        if (totalSeats == 0 || totalSeats % 2 != 0) return 0;

        long long ans = 1;
        for (int i = 2; i < totalSeats; i += 2) {
            ans = (ans * (seats[i] - seats[i - 1])) % MOD;
        }
        return ans;
    }
};
