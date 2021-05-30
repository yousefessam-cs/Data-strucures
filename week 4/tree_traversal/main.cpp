#include<bits/stdc++.h>
using namespace std;
template <class T> void display(const vector<T> vec) {
    for (auto &e : vec) {
        std::cout << e << " ";
    }
    cout << endl;
}
class BinaryTree {
  private:
    vector<int> key;
    vector<int> left;
    vector<int> right;

  public:
    void read_input() {
        int n;
       cin >> n;
        key.resize(n);
        left.resize(n);
        right.resize(n);
        for (int i = 0; i < n; ++i) {
           cin >> key[i] >> left[i] >> right[i];
        }
    }

   vector<int> in_order_traversal() {
        vector<int> result;
       set<int> processed;
        stack<int> to_process;
        processed.insert(-1);
        to_process.push(0);
        while (not to_process.empty()) {
            auto idx = to_process.top();
            if (processed.find(left[idx]) != processed.end()) {
                result.push_back(key[idx]);
                processed.insert(idx);
                to_process.pop();
                if (right[idx] != -1) {
                    to_process.push(right[idx]);
                }
            } else {
                to_process.push(left[idx]);
            }
        }
        return result;
    }

    vector<int> pre_order_traversal() {
        vector<int> result;
        stack<int> to_process;
        to_process.push(0);
        while (not to_process.empty()) {
            auto idx = to_process.top();
            result.push_back(key[idx]);
            to_process.pop();
            if (right[idx] != -1) {
                to_process.push(right[idx]);
            }
            if (left[idx] != -1) {
                to_process.push(left[idx]);
            }
        }
        return result;
    }

    vector<int> post_order_traversal() {
        vector<int> result;
        set<int> processed;
        stack<int> to_process;
        processed.insert(-1);
        to_process.push(0);
        while (not to_process.empty()) {
            auto idx = to_process.top();
            bool flag{true};
            if (processed.find(right[idx]) == processed.end()) {

                to_process.push(right[idx]);
                flag = false;
            }
            if (processed.find(left[idx]) == processed.end()) {
                to_process.push(left[idx]);
                flag = false;
            }
            if (flag) {
                result.push_back(key[idx]);
                to_process.pop();
                processed.insert(idx);
            }
        }
        return result;
    }
};

int main() {
    BinaryTree t;
    t.read_input();
    display(t.in_order_traversal());
    display(t.pre_order_traversal());
    display(t.post_order_traversal());
    return 0;
}
