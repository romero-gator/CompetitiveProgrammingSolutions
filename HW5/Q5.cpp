#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
    unordered_map<string, vector<string> > v;
    vector<string> combine(string w, vector<string> s) {
        for (int i = 0; i < s.size(); i++) {
            s[i] += " " + w;
        }
        return s;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (v.count(s) > 0) {
            return v[s];
        }
        unordered_set<string> dict;
        for (int i = 0; i < wordDict.size(); i++) {
            dict.insert(wordDict[i]);
        }
        vector<string> res;
        if (dict.count(s) > 0) {
            res.push_back(s);
        }
        for (int i = 1; i < s.size(); i++) {
            string word = s.substr(i);
            if (dict.count(word) > 0) {
                string temp = s.substr(0, i);
                vector<string> p = combine(word, wordBreak(temp, wordDict));
                res.insert(res.end(), p.begin(), p.end());
            }
        }
        v[s] = res;
        return res;
    }
};