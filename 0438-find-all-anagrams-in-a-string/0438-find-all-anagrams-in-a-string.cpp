#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.length() < p.length()) return result;

        vector<int> need(26, 0), window(26, 0);
        for (char c : p) need[c - 'a']++;

        int windowSize = p.length();

        for (int i = 0; i < s.length(); i++) {
            window[s[i] - 'a']++;

            if (i >= windowSize) {
                window[s[i - windowSize] - 'a']--;
            }

            if (i >= windowSize - 1 && window == need) {
                result.push_back(i - windowSize + 1);
            }
        }
        return result;
    }
};