#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
  bool NotVowel(char c) {
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U';
   } //here the function NotVowel is used to check whether the character is vowel or not. If it is not a vowel then it will return false
  string reverseVowels(string s) {
   int i =0 ;
   int j = s.size() - 1;
//    here the main logic starts loop will run until j is greater and in the if condition we check if s[i]is vowel or not if not then we increment the index and continue due to two conditions cannot run together thats way we used continue key word if the vowel is found we swap it
    while(i < j) {
      if(NotVowel(s[i])) {
         i++;
         continue;
      }
      if(NotVowel(s[j])) {
         j--;
         continue;
      }
      swap(s[i], s[j]);
      i++;
      j--;
    }
    return s;
  }
};
int main() {
    Solution s;
    string name;
    cout<<"Enter a string: ";
    cin>>name;
    cout<<s.reverseVowels(name);
    return 0;
}