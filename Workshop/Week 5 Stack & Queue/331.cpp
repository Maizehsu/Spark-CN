class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string t;
        vector<string> v;
        while (getline(ss, t, ',')) {
            v.push_back(t);
        }
        /**
         * For a full binary tree, # of node = # of branch + 1, 
         * thus if we manually add a branch to the root, 
         * then the # of branchs = the # of nodes;
         * For a node, it consumes one branch and produces 2 new branches (if not null).
         */
        int nodes = 1;
        for (int i = 0; i < v.size(); i++) {
            nodes--; // consume one branch
            if (nodes < 0) return false;
            if (v[i] != "#") nodes += 2; // generate 2 branches
        }
        return nodes == 0;
    }
};