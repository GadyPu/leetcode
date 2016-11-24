#define DBG
#include <bits/stdc++.h>
struct Node {
    size_t idx, freq;
    int key, val;
    Node() = default;
    Node(size_t i, size_t j, int k, int l) :idx(i), freq(j), key(k), val(l) {}
    inline bool operator<(const Node &rhs) const {
        return freq == rhs.freq ? idx < rhs.idx : freq < rhs.freq;
    }
};
class LFUCache {
public:
    LFUCache(int capacity) {
       idx = 0, size = capacity; 
    }
    int get(int key) {
        auto res = A.find(key);
        if(res == A.end()) return -1;
        B.erase(res->second);
        res->second.freq++, res->second.idx = idx++;
        B.insert(res->second);
        return res->second.val;
    }
    void set(int key, int value) {
        auto res = A.find(key);
        if(res != A.end()) {
            B.erase(res->second);
            res->second.freq++, res->second.idx = idx++;
            res->second.val = value;
            B.insert(res->second);
        } else if(B.size() != size) {
            A.insert({ key, { idx++, 0, key, value } });
            B.insert(A[key]);
        } else if(B.size()) {
            auto tmp = B.begin();
            A.erase(tmp->key);
            B.erase(tmp);
            A.insert({ key, { idx++, 0, key, value } });
            B.insert(A[key]);
        }
    }
private:
    size_t idx, size;
    std::map<int, Node> A; // key Node
    std::set<Node> B; 
};
int main() {
#ifdef DBG
    freopen("in.txt", "r", stdin);
    freopen("SX.txt", "w+", stdout);
#endif
    int n, a, b;
    char buf[100];
    scanf("%d", &n);
    LFUCache d(n);
    while(fgets(buf, sizeof(buf), stdin)) {
        if(buf[0] == 'g') {
            sscanf(buf, "%*s %d", &a);
            printf("%d\n", d.get(a));
        } else if(buf[0] == 's') {
            sscanf(buf, "%*s %d %d", &a, &b);
            d.set(a, b);
        }
    }
    return 0;
}
