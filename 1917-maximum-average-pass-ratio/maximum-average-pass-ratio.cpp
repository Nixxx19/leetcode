class Solution {
    double getGain(int passed, int total) {
        double before = (double)passed / total;
        double after = (double)(passed + 1) / (total + 1);
        return after - before;
    }

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> maxHeap;

        for (const auto& cls : classes) {
            int passed = cls[0], total = cls[1];
            maxHeap.push({getGain(passed, total), {passed, total}});
        }

        for (int i = 0; i < extraStudents; i++) {
            auto top = maxHeap.top();
            maxHeap.pop();

            int passed = top.second.first + 1;
            int total = top.second.second + 1;

            maxHeap.push({getGain(passed, total), {passed, total}});
        }

        double totalRatio = 0;
        while (!maxHeap.empty()) {
            auto [_, pair] = maxHeap.top();
            maxHeap.pop();
            totalRatio += (double)pair.first / pair.second;
        }

        return totalRatio / classes.size();
    }
};