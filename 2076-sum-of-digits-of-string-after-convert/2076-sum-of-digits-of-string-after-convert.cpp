class Solution {
public:
    int getLucky(string s, int k) {
        string number;

        // Convert each character in the string to its corresponding number
        for (auto elem : s) {
            number += to_string(elem - 'a' + 1);
        }

        // Convert the string to an integer if possible, else sum digits in string directly
        int num = 0;
        for (char digit : number) {
            num += digit - '0';
        }

        // Perform the transformation `k` times
        while (k > 1) {
            int new_num = 0;
            while (num > 0) {
                new_num += num % 10;
                num /= 10;
            }
            num = new_num;
            k--;
        }

        return num;
    }
};
