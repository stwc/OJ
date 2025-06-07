class Solution:
    def isPalindrome(self, s: str) -> bool:
        i = 0
        j = len(s) - 1
        while i < j:
            while not s[i].isalnum() and i < j:
                i = i + 1
            while not s[j].isalnum() and i < j:
                j = j - 1

            if s[i].lower() != s[j].lower():
                return False
            i = i + 1
            j = j - 1

        return True
