#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        unordered_map<char, int> window;
        int required = need.size();
        int formed = 0;

        int left = 0, minLen = INT_MAX, minStart = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            window[c]++;
            if (need.count(c) && window[c] == need[c]) formed++;

            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                char leftChar = s[left];
                window[leftChar]--;
                if (need.count(leftChar) && window[leftChar] < need[leftChar]) formed--;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};