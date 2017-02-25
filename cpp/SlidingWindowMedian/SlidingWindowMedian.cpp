#define LOCAL
#include <iostream>
#include <memory>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;
template<typename T>
class Tree {
private:
	struct Node {
		T data;
        int size, cnt;
		Node *ch[2];
		Node(T ref) :data(ref) {
            size = cnt = 1;
			ch[0] = ch[1] = nullptr;
		}
        void push_up() {
            int v1 = !ch[0] ? 0 : ch[0]->size;
            int v2 = !ch[1] ? 0 : ch[1]->size;
            size = v1 + v2 + cnt;
        }
        int cmp(T d) const {
            return data == d ? -1: d > data;
        }
	};
public:
	Tree() :root(nullptr) {}
	~Tree() { clear(root), root = nullptr; }
	void insert(T d) {
		insert(d, root);
	}
    void erase(T d) {
        erase(d, root);
    }
    T operator[](int k) const {
        return kth(root, k);
    }
private:
	void insert(T d, Node *&x) {
		if (!x) { x = new Node(d); return; }
        x->size++;
        int c = x->cmp(d);
        if (-1 == c) { x->cnt++; return; }
        insert(d, x->ch[c]);
        x->push_up();
	}
    void erase(T d, Node *&x) {
        if (!x) return;
        x->size--;
        int c = x->cmp(d);
        if (-1 == c) {
            if (x->cnt > 1) {
                x->cnt--;
            } else {
                Node *temp = x;
                if (!x->ch[0] || !x->ch[1]) {
                    x = x->ch[0] ? x->ch[0] : x->ch[1];
                    delete temp;
                } else {
                    for (temp = x->ch[1]; temp->ch[0]; temp = temp->ch[0]);
                    x->data = temp->data;
                    erase(x->data, x->ch[1]);
                }
            }
        } else {
            erase(d, x->ch[c]);
        }
        if (x) x->push_up();
    }
    T kth(Node *x, int k) const {
        int t = 0;
        for ( ; x ; ) {
            t = x->ch[0] ? x->ch[0]->size : 0;
            if (t + 1 <= k && k <= t + x->cnt) break;
            else if (k < t + 1) x = x->ch[0];
            else k -= t + x->cnt, x = x->ch[1];
        }
        return x->data;
    }
	void clear(Node *x) {
		if (!x) return;
		clear(x->ch[0]);
		clear(x->ch[1]);
		delete x;
	}
private:
	Node *root;
};
class Solution {
    using ll = long long int;
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
       if (nums.empty()) return res;
       bool f = k & 1;
       int n = nums.size();
       go = std::make_shared<Tree<ll>>();
       for (int l = 0, r = k - 1; r < n; l++, r++) {
           if (!l) {
               for (int i = l; i <= r; i++) {
                   go->insert(nums[i]);
               }
           } else {
               go->insert(nums[r]);
           }
           if (f) {
               res.push_back(static_cast<double>((*go)[k / 2 + 1]));
           } else {
               ll v1 = (*go)[k / 2];
               v1 += (*go)[k / 2 + 1];
               res.push_back(static_cast<double>(v1 / 2.0));
           }
           go->erase(nums[l]);
       }
       return res;
    }
private:
    vector<double> res;
    std::shared_ptr<Tree<ll>> go;
};
int main() {
    vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    Solution d;
    auto res = d.medianSlidingWindow(nums, 3);
    for (auto &r: res) {
        std::cout << r << ' ';
    }
    std::cout << '\n';
    return 0;
}
