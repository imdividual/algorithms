#include <bits/stdc++.h>

using namespace std;

vector<int> k_most_freq(vector<int> &nums, int k) {
    unordered_map<int, int> freq;
    for (int i = 0; i < nums.size(); ++i) {
        ++freq[nums[i]];
    }

    vector<pair<int, int>> heap;
    for (auto x : freq) {
        heap.emplace_back(make_pair(x.second, x.first));
    }

    make_heap(heap.begin(), heap.end());

    vector<int> ele;

    for (int i = 0; i < k; ++i) {
        ele.emplace_back(heap.front().second);
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();
    }

    return ele;
}

int main() {
    vector<int> nums {-3, -3, -2, -2, -1, -1, -1, 0, 1, 1, 2, 3, 3, 3, 3, 3, 3, 3};
    int k = 3;
    vector<int> combos = k_most_freq(nums, k);
    for(auto combo: combos) {
        cout << combo << endl;
    }
    return 0;
}
