// Top K Frequent Elements
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;

        priority_queue<pair<int,int>> pq;
        for (auto& p : freq) pq.push({p.second, p.first});

        vector<int> result;
        while (k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};