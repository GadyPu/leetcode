#include <bits/stdc++.h>
using namespace std;
class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        idx = 1;
    }
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
		if(C.find(key) == C.end()) {
			C.insert({ key, { idx, 1 }});
			A.insert({ idx, key });
			B.insert({ 1, idx++ });
		} else {
			auto r = C.find(key);
			int x = (*r).second.second, y = (*r).second.first;
			auto d = B.find({ x, y });
			C[key].second = x + 1;
			B.erase(d);
			B.insert({ x + 1, y });
		}
    }
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
       if(C.find(key) == C.end()) return;
		auto r = C.find(key);	
		int x = (*r).second.second, y = (*r).second.first;
		auto d = B.find({ x, y });
		if(x == 1) {
			C.erase(r);
			A.erase(y);
			B.erase(d);
		} else {
			C[key].second = x - 1;
			B.erase(d);
			B.insert({ x - 1, y });
		}
    }
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
		if(B.empty()) return "";
		auto r = *B.rbegin();
       	return A[r.second]; 
    }
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
		if(B.empty()) return  "";
		auto r = *(B.begin());
	  	return A[r.second];
    }
private:
	int idx;
	map<int, string> A; // idx key
	set<pair<int, int>> B; // val idx
	map<string, pair<int,int>> C; // key idx val

};
/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
int main() {
	AllOne d;
	d.inc("Bob");
	d.inc("Bob");
/*
	d.inc("Alice");
	d.inc("Tom");
	for(int i = 0; i < 3; i++) d.inc("GadyPu");
*/	
	cout << d.getMaxKey() << '\n';
	cout << d.getMinKey() << '\n';
	d.inc("leetcode");
	cout << d.getMaxKey() << '\n';
	cout << d.getMinKey() << '\n';
	return 0;
}
