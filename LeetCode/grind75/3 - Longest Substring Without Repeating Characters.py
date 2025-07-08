class Solution1:
    def lengthOfLongestSubstring(self, s: str) -> int:
        visited = {}
        max_len = 0
        start = 0

        for end in range(len(s)):
            last_index = visited.get(s[end])
            if last_index is not None and last_index >= start:
                start = last_index + 1

            visited[s[end]] = end
            max_len = max(max_len, end - start + 1)

        return max_len


class Solution2:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = 0
        left = 0
        last_seen = {}

        for right, c in enumerate(s):
            if c in last_seen and last_seen[c] >= left:
                left = last_seen[c] + 1

            max_length = max(max_length, right - left + 1)
            last_seen[c] = right

        return max_length
