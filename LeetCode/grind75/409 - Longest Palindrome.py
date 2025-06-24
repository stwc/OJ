class Solution1:
    def longestPalindrome(self, s: str) -> int:
        freq = {}
        for c in s:
            freq[c] = freq.get(c, 0) + 1

        total_count = len(s)
        odd_count = 0
        for value in freq.values():
            if value & 1:
                odd_count += 1

        if odd_count == 0:
            return total_count
        else:
            return total_count - odd_count + 1


class Solution2:
    def longestPalindrome(self, s: str) -> int:
        odd_freq_chars_count = 0
        frequency_map = {}

        for c in s:
            frequency_map[c] = frequency_map.get(c, 0) + 1

            if frequency_map[c] % 2 == 1:
                odd_freq_chars_count += 1
            else:
                odd_freq_chars_count -= 1

        if odd_freq_chars_count > 0:
            return len(s) - odd_freq_chars_count + 1
        else:
            return len(s)
