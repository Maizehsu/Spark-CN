/**
 * Sample solution from discussion.
/*
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m; // order doesn't matter, so we use unordered map
        for(int d : deck)
            m[d]++; // map created with frequency of each card no.
        int gcd = m[deck[0]];
        for(auto i : m)
            gcd = __gcd(gcd, i.second); // doing gcd with the frequency of all the cards
        return gcd != 1;  // if gcd is not equal to 1 it means we can create groups of size >= 2.
        
        return true;
    }
};