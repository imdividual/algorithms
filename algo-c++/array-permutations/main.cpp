#include <bits/stdc++.h>
using namespace std;

void gen(vector<vector<int>> &perms, vector<int> &perm, int i) {
    if(i == perm.size()-1) perms.emplace_back(perm);
    for(int j = i; j < perm.size(); ++j) {
        swap(perm[i], perm[j]);
        gen(perms, perm, i+1);
        swap(perm[i], perm[j]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> perms;
    gen(perms, nums, 0);
    return perms;
}

int main() {
    vector<int> nums{1, 2, 3};
    vector<vector<int>> perms = permute(nums);
    for(auto perm : perms) {
        for(auto i : perm) cout << i << " ";
        cout << endl;
    }
    return 0;
}
