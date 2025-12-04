class Solution {
public:
    int countCollisions(string d) {
        int n = d.size();
        int l = 0, r = n - 1;
        
        while (l < n && d[l] == 'L') l++;
        while (r >= 0 && d[r] == 'R') r--;
        
        int ans = 0;
        for (int i = l; i <= r; i++) {
            if (d[i] == 'L' || d[i] == 'R')
                ans++;
        }
        return ans;
    }
};
