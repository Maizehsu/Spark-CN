class Bitset {
public:
    string str;
    string cstr;
    int ones;
    
    Bitset(int size) {
        str.assign(size, '0');
        cstr.assign(size, '1');
        ones = 0;
    }
    
    void fix(int idx) {
        if (str[idx] == '0') {
            ones += 1;
            str[idx] = '1';
            cstr[idx] = '0';
        };
    }
    
    void unfix(int idx) {
        if (str[idx] == '1') {
            str[idx] = '0';
            cstr[idx] = '1';
            ones -= 1;    
        }
    }
    
    void flip() {
        string temp = str;
        str = cstr;
        cstr = temp;
        ones = str.size() - ones;
    }
    
    bool all() {
        return ones == str.size();
    }
    
    bool one() {
        return ones > 0;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        return str;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */