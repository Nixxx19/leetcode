class MyHashSet {
    static const int B = 1000;
    vector<vector<int>> h;
public:
    MyHashSet() : h(B) {}

    void add(int key) {
        int i = key % B;
        for (int x : h[i]) if (x == key) return;
        h[i].push_back(key);
    }

    void remove(int key) {
        int i = key % B;
        auto &b = h[i];
        for (int j = 0; j < b.size(); j++) {
            if (b[j] == key) {
                b[j] = b.back();
                b.pop_back();
                return;
            }
        }
    }

    bool contains(int key) {
        int i = key % B;
        for (int x : h[i]) if (x == key) return true;
        return false;
    }
};
