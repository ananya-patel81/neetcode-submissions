class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // skip non-alphanumeric on left
            while (left < right && !isalnum(static_cast<unsigned char>(s[left]))) {
                left++;
            }

            // skip non-alphanumeric on right
            while (left < right && !isalnum(static_cast<unsigned char>(s[right]))) {
                right--;
            }

            // compare characters (case-insensitive)
            if (tolower(static_cast<unsigned char>(s[left])) !=
                tolower(static_cast<unsigned char>(s[right]))) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};