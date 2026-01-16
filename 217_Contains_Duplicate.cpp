#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;   // ordered set

        for (int x : nums) {
            if (s.find(x) != s.end()) {
                return true;   // duplicate found
            }
            s.insert(x);
        }
        return false;  // no duplicate
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 1};

    if (sol.containsDuplicate(nums))
        cout << "Contains Duplicate" << endl;
    else
        cout << "No Duplicate" << endl;

    return 0;
}
