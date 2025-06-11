class Solution1:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        map1 = {}
        map2 = {}

        for i in range(len(s)):
            ch1, ch2 = s[i], t[i]

            if map1.get(ch1) is None:
                map1[ch1] = 1
            else:
                map1[ch1] = map1[ch1] + 1

            if map2.get(ch2) is None:
                map2[ch2] = 1
            else:
                map2[ch2] = map2[ch2] + 1

        if map1 == map2:
            return True
        else:
            return False


class Solution2:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        map = {}

        for ch in s:
            map[ch] = map.get(ch, 0) + 1

        for ch in t:
            count = map.get(ch, 0)
            if count == 0:
                return False

            map[ch] = count - 1

        return True
