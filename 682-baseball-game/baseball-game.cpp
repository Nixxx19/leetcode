class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> st;
        int sum = 0;

        for (string &op : ops) {
            if (op == "C") {
                sum -= st.back();
                st.pop_back();
            } 
            else if (op == "D") {
                int val = st.back() * 2;
                st.push_back(val);
                sum += val;
            } 
            else if (op == "+") {
                int val = st[st.size()-1] + st[st.size()-2];
                st.push_back(val);
                sum += val;
            } 
            else {
                int val = stoi(op);
                st.push_back(val);
                sum += val;
            }
        }
        return sum;
    }
};
