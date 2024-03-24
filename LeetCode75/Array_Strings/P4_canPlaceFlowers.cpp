
    #include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        
        // Check if flowers can be planted in the first plot
        if ((flowerbed[0] == 0 && flowerbed[1] == 0) || size == 1 && flowerbed[0] == 0) {
            flowerbed[0] = 1;
            n--;
        }
        
        // Check if flowers can be planted in the middle plots
        for (int i = 1; i < size - 1; i++) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }
        
        // Check if flowers can be planted in the last plot
        if (flowerbed[size - 1] == 0 && flowerbed[size - 2] == 0) {
            flowerbed[size - 1] = 1;
            n--;
        }
        
        return n <= 0;
    }
};

int main() {
    Solution s;
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;

    // Check if n new flowers can be planted
    bool result = s.canPlaceFlowers(flowerbed, n);

    // Print the result
    cout << "Result: " << (result ? "true" : "false") << endl;

    return 0;
}