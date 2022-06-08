class Solution {
public:
    bool backspaceCompare(string s, string t) {
        result sRes = backspaceString(s);
        result tRes = backspaceString(t);
        if (sRes.num == 0) {
            if (tRes.num == 0) return true;
            else return false;
        }
        else if (tRes.num == 0) return false;
        else {
            cout << sRes.str.substr(0, sRes.num) << endl;
            cout << tRes.str.substr(0, tRes.num);
            return sRes.str.substr(0, sRes.num) == tRes.str.substr(0, tRes.num);    
        }
    }

private:
    struct result {
        string str;
        int num;
    };
    
    result backspaceString(string s) {
        int sIndex = 0, fIndex = 0;
        int size = s.size();
        while (fIndex < size) {
            if (s[fIndex] != '#') {
                s[sIndex++] = s[fIndex++];
            }
            else {
                // Circumstance: a##b or #ab#
                if (sIndex - 1 >= 0) {
                    sIndex--;
                }
                // Circumstance #ab#
                if (fIndex == size - 1) {
                    s[sIndex] = '#';
                    fIndex++;
                }
                else {
                    fIndex++;
                    s[sIndex] = s[fIndex];    
                }
            }
        }
        return {s, sIndex};
    }
};