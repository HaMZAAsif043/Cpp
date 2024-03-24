#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        int gcdLength = gcd(str1.length(), str2.length());
        return str1.substr(0, gcdLength);
    }
};

int main() {
    Solution solution;
    
    // Test cases
    cout << solution.gcdOfStrings("ABCABC", "ABC") << endl; // Output: "ABC"
    cout << solution.gcdOfStrings("ABABAB", "ABAB") << endl; // Output: "AB"
    cout << solution.gcdOfStrings("LEET", "CODE") << endl; // Output: ""
    
    return 0;
}
