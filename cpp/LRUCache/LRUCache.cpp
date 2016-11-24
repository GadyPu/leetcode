#define DBG
#include <bits/stdc++.h>
class LRUCache {
public:
    LRUCache(int capacity) {
        idx = 0;
        size = capacity;
        A.clear(); B.clear();
    }
    int get(int key) {
        auto res = B.find(key);
        if(res == B.end()) return -1;
        A.erase(res->second.second);
        A.insert({ idx, key });
        res->second.second = idx++;
        return res->second.first;
    }
    void set(int key, int value) {
       auto res = B.find(key);
       if(res != B.end()) {
           res->second.first = value;
           A.erase(res->second.second);
           A.insert({ idx, key });
           res->second.second = idx++;
       } else if(B.size() != size) {
            A.insert({ idx, key });
            B.insert({ key, { value, idx++ } });  
       } else {
           auto tmp = A.begin();
           B.erase(tmp->second);
           A.erase(tmp);
           A.insert({ idx, key });
           B.insert({ key, { value, idx++ } });
       }
    }
private:
    size_t size, idx;
    std::map<int, int> A; // idx, key
    std::map<int, std::pair<int, int>> B; // key, value, idx
};
int main() {
#ifdef DBG
    freopen("in.txt", "r", stdin);
    freopen("SX.txt", "w+", stdout);
#endif
    int n, a, b;
    char buf[100];
    scanf("%d", &n);
    LRUCache d(n);
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
