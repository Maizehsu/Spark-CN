// Time exceeded
class Solution {
public:
    string minWindow(string s, string t) {
        int sIndex = 0, size = s.size();
        string result = s + "X"; 
        for (int fIndex = 0; fIndex < size; fIndex++) {
            string sub = s.substr(sIndex, fIndex - sIndex + 1);
            while (doesInclude(sub, t)) {
                if (result.size() > sub.size()) result = sub;
                sIndex++;
                sub = s.substr(sIndex, fIndex - sIndex + 1);
            }
        }
        return result.size() == size + 1 ? "" : result;
    }
    
private:
    bool doesInclude(string s, string t) {
        for (int i = 0; i < t.size(); i++) {
            bool result = false;
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == t[i]) {
                    result = true;
                    s.erase(s.begin() + j); // String remove certain element
                    break;
                }
            }
            if (result == false) return false;
        }
        return true;
    }
};

// Use map to deal with substring;
class Solution {
public:
    string minWindow(string s, string t) {
        // Statistic for count of char in t
        vector<int> map(128,0);
        // for(char const &c: t) map[c]++;
        for(auto c: t) map[c]++;
        
        int counter = t.size(), sIndex = 0, fIndex = 0, minLen = INT_MAX, minStart = 0;
        int size = s.size();
        
        while(fIndex < size){
            if(map[s[fIndex]] > 0) {
                counter--; // If char in s exists in t, decrease counter    
            }
            // Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
		    map[s[fIndex]]--;
            fIndex++;
            // When we found a valid window, move start to find smaller window.
            while(counter == 0) { // valid
                if(fIndex - sIndex < minLen) {
                    minStart = sIndex;
                    minLen = fIndex - sIndex;  
                }
                map[s[sIndex]]++;
                // When char exists in t, increase counter.
                if(map[s[sIndex]] > 0) counter++;  // make it invalid
                sIndex++;
            }  
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);  
    }
};

