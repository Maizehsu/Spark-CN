class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int len = 0, sIndex = 0, size = fruits.size();
        int fruitA = fruits[0], fruitB = fruits[1];
        if (size == 1) return 1;
        for (int fIndex = 1; fIndex < size; fIndex++) {
            int temp = fruits[fIndex];
            if (temp == fruitA || temp == fruitB) {
                if (fIndex - sIndex + 1 > len) len = fIndex - sIndex + 1;
            }
            else {
                fruitA == fruits[fIndex - 1] ? fruitB = temp : fruitA = temp;
                for (int i = fIndex - 1; i >= 0; i--) {
                    if (fruits[i] != fruitA && fruits[i] != fruitB) break;
                    sIndex = i;
                    if (fIndex - sIndex + 1 > len) len = fIndex - sIndex + 1;
                }
            }
        }
        return len;
    }
};