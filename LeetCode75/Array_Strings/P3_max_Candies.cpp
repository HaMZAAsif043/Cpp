#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = candies[0];
        for (int i = 1; i < candies.size(); ++i) {
            if (max < candies[i]) {
                max = candies[i];
            }
        }

        // Now 'max' holds the maximum number of candies
        vector<bool> result;
        for (int i = 0; i < candies.size(); ++i) {
            result.push_back(candies[i] + extraCandies >= max);
        }

        return result;
    }
};

int main() {
    // Example usage
    Solution s;
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;

    // Find out which kids can have the greatest number of candies
    vector<bool> result = s.kidsWithCandies(candies, extraCandies);

    cout << "Result: ";
for (int i = 0; i < result.size(); ++i) {
    cout << (result[i] ? "true" : "false") << " ";
}
cout << endl;

    return 0;
}
