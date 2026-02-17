class Solution {
public:
    vector<string> res;
    
    void backtrack(int leds, int idx, int hours, int mins) {
        if (hours > 11 || mins > 59) return;
        if (leds == 0) {
            string time = to_string(hours) + ":";
            if (mins < 10) time += "0";
            time += to_string(mins);
            res.push_back(time);
            return;
        }
        
        for (int i = idx; i < 10; i++) {
            if (i < 4)
                backtrack(leds - 1, i + 1, hours + (1 << i), mins);
            else
                backtrack(leds - 1, i + 1, hours, mins + (1 << (i - 4)));
        }
    }
    
    vector<string> readBinaryWatch(int turnedOn) {
        backtrack(turnedOn, 0, 0, 0);
        return res;
    }
};
