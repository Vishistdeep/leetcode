class Solution {
public:
    string reversePrefix(string word, char ch) {
        int left = 0;
    int right = word.find(ch);
    if (right == std::string::npos) {
        return word;
    }
    string arr = word;
    
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    
    return arr; 
    }
};