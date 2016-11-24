#define DBG
#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
class LRUCache {
private:
    const int INF = ~0u >> 1;
public:
    LRUCache() = default;
    LRUCache(int capacity) {
        idx = 0, size = capacity;
        null = new Node(INF, INF, -1, 0, NULL);
        root = null;
    }
    ~LRUCache() { clear(root); root = NULL; }
    int get(int key) {
        Node *x = find(key);
        if (x->s) {
            MP.erase(MP.find(x->idx));
            MP[idx] = x->key;
            x->idx = idx++;
        }
        return !x->s ? -1 : x->val;
    }
    void set(int key, int value) {
        Node *x = find(key);
        if (!x->s && root->s != this->size) {
            insert(root, key, value, idx);
            MP[idx++] = key;
        } else {
            if (key == x->key) {
                x->val = value;
                MP.erase(MP.find(x->idx));
                MP[idx] = x->key;
                x->idx = idx++;
            } else {
                auto ret = MP.begin();
                erase(root, ret->second);
                MP.erase(ret);
                insert(root, key, value, idx);
                MP[idx++] = key;
            }
        }
    }
private:
    int idx, size;
private:
    map<int, int> MP;
    struct Node {
        int key, val, idx, s;
        Node *ch[2];
        Node(int i, int j, int k, int l, Node *p) {
            key = i, val = j, idx = k, s = l;
            ch[0] = ch[1] = p;
        }
        inline bool cmp(int v) const {
            return v > key;
        }
        inline void push_up() {
            s = ch[0]->s + ch[1]->s + 1;
        }
    }*root, *null;
    inline void rotate(Node *&x, bool d) {
        Node *k = x->ch[!d]; x->ch[!d] = k->ch[d]; k->ch[d] = x;
        k->s = x->s, x->push_up(), x = k;
    }
    inline void Maintain(Node *&x, bool d) {
        if (!x->ch[d]->s) return;
        if (x->ch[d]->ch[d]->s > x->ch[!d]->s) rotate(x, !d);
        else if (x->ch[d]->ch[!d]->s > x->ch[!d]->s) rotate(x->ch[d], d), rotate(x, !d);
        else return;
        Maintain(x, 0), Maintain(x, 1);
    }
    inline void insert(Node *&x, int key, int val, int idx) {
        if (!x->s) { x = new Node(key, val, idx, 1, null); return; }
        x->s++;
        bool d = x->cmp(key);
        insert(x->ch[d], key, val, idx);
        x->push_up();
        Maintain(x, d);
    }
    inline void erase(Node *&x, int key) {
        if (!x->s) return;
        x->s--;
        bool d = x->cmp(key);
        if (x->key == key) {
            Node *ret = NULL;
            if (!x->ch[0]->s || !x->ch[1]->s) {
                ret = x;
                x = ret->ch[0]->s ? ret->ch[0] : x->ch[1];
                delete ret;
            } else {
                ret = x->ch[1];
                for (; ret->ch[0]->s; ret = ret->ch[0]);
                x->key = ret->key, x->val = ret->val, x->idx = ret->idx;
                erase(x->ch[1], x->key);
            }
        } else {
            erase(x->ch[d], key);
        }
        if (x->s) x->push_up();
    }
    inline Node* find(int key) {
        Node *x = root;
        while (x->s && x->key != key) x = x->ch[key > x->key];
        return x;
    }
    inline void clear(Node *x) {
        if (!x->s) return;
        clear(x->ch[0]);
        delete x;
        clear(x->ch[1]);
    }
};
int main() {
#ifdef DBG
    freopen("in.txt", "r", stdin);
    freopen("SB.txt", "w+", stdout);
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
