#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<string> sentence;
        string word = "";

        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    sentence.push(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }

        if (!word.empty()) {
            sentence.push(word);
        }

        string reversedSentence = "";
        while (!sentence.empty()) {
            reversedSentence += sentence.top();
            sentence.pop();
            if (!sentence.empty()) {
                reversedSentence += " ";
            }
        }

        return reversedSentence;
    }
};

int main() {
    Solution s;
    string input;
    cout << "Enter a sentence: ";
    getline(cin, input);
    cout << "Reversed sentence: " << s.reverseWords(input) << endl;
    return 0;
}
