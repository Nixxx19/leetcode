class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        if (n < k) return {};
        
        unordered_map<long long,int> cnt;
        cnt.reserve(k * 2);

        set<pair<int,long long>> top, rest;
        unordered_map<long long,bool> inTop;
        long long sumTop = 0;

        auto moveRestToTop = [&](set<pair<int,long long>>::iterator it) {
            auto p = *it;
            rest.erase(it);
            top.insert(p);
            inTop[p.second] = true;
            sumTop += 1LL * p.first * p.second;
        };

        auto moveTopToRest = [&](set<pair<int,long long>>::iterator it) {
            auto p = *it;
            top.erase(it);
            rest.insert(p);
            inTop[p.second] = false;
            sumTop -= 1LL * p.first * p.second;
        };

        auto rebalance = [&]() {
            // Ensure top has exactly x best elements
            while ((int)top.size() < x && !rest.empty()) {
                auto it = prev(rest.end());
                moveRestToTop(it);
            }
            while ((int)top.size() > x) {
                auto it = top.begin();
                moveTopToRest(it);
            }
            while (!rest.empty() && !top.empty()) {
                auto bestRestIt = prev(rest.end());
                auto worstTopIt = top.begin();
                if (*bestRestIt > *worstTopIt) {
                    auto bestRest = *bestRestIt;
                    auto worstTop = *worstTopIt;
                    rest.erase(bestRestIt);
                    top.erase(worstTopIt);
                    sumTop -= 1LL * worstTop.first * worstTop.second;
                    sumTop += 1LL * bestRest.first * bestRest.second;
                    top.insert(bestRest);
                    rest.insert(worstTop);
                    inTop[bestRest.second] = true;
                    inTop[worstTop.second] = false;
                } else break;
            }
        };

        auto applyChange = [&](long long val, int delta) {
            int oldc = 0;
            auto itCnt = cnt.find(val);
            if (itCnt != cnt.end()) oldc = itCnt->second;

            int newc = oldc + delta;

            if (oldc > 0) {
                if (inTop[val]) {
                    auto it = top.find({oldc, val});
                    if (it != top.end()) {
                        sumTop -= 1LL * oldc * val;
                        top.erase(it);
                    }
                } else {
                    auto it = rest.find({oldc, val});
                    if (it != rest.end()) rest.erase(it);
                }
            }

            if (newc > 0) {
                cnt[val] = newc;
                rest.insert({newc, val});
                inTop[val] = false;
            } else {
                cnt.erase(val);
                inTop.erase(val);
            }

            rebalance();
        };

        // initialize first window
        for (int i = 0; i < k; ++i) cnt[nums[i]]++;
        for (auto &p : cnt) {
            rest.insert({p.second, p.first});
            inTop[p.first] = false;
        }
        while ((int)top.size() < x && !rest.empty()) {
            auto it = prev(rest.end());
            moveRestToTop(it);
        }
        rebalance();

        vector<long long> ans;
        ans.reserve(n - k + 1);
        ans.push_back(sumTop);

        for (int i = 1; i <= n - k; ++i) {
            applyChange(nums[i - 1], -1);
            applyChange(nums[i + k - 1], +1);
            ans.push_back(sumTop);
        }

        return ans;
    }
};