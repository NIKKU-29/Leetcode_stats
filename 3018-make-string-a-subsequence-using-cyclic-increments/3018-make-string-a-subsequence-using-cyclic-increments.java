class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        int i = 0, j = 0;
        int n = str1.length(), m = str2.length();

        if (m > n) return false;

        while (i < n) {
            char current = str1.charAt(i);
            char next = (current == 'z') ? 'a' : (char)(current + 1);
            if (current == str2.charAt(j) || next == str2.charAt(j)) {
                j++;
                if (j == m) return true;
            }
            i++;
        }

        return false;
    }
}