class Trie1:
    def __init__(self):
        self.isWord = False
        self.nextNode = {}

    def insert(self, word: str) -> None:
        if len(word) == 0:
            self.isWord = True
            return

        ch = word[0]
        if ch not in self.nextNode:
            self.nextNode[ch] = Trie()

        self.nextNode[ch].insert(word[1:])

    def search(self, word: str) -> bool:
        if len(word) == 0:
            return self.isWord

        ch = word[0]
        if ch not in self.nextNode:
            return False

        return self.nextNode[ch].search(word[1:])

    def startsWith(self, prefix: str) -> bool:
        if len(prefix) == 0:
            return True

        if prefix[0] not in self.nextNode:
            return False

        return self.nextNode[prefix[0]].startsWith(prefix[1:])


class Trie2:
    def __init__(self):
        self.isWord = False
        self.nextNode = {}

    def insert(self, word: str) -> None:
        curr_node = self
        for ch in word:
            if ch not in curr_node.nextNode:
                curr_node.nextNode[ch] = Trie()
            curr_node = curr_node.nextNode[ch]
        curr_node.isWord = True

    def search(self, word: str) -> bool:
        curr_node = self
        for ch in word:
            if ch not in curr_node.nextNode:
                return False
            curr_node = curr_node.nextNode[ch]
        return curr_node.isWord

    def startsWith(self, prefix: str) -> bool:
        curr_node = self
        for ch in prefix:
            if ch not in curr_node.nextNode:
                return False
            curr_node = curr_node.nextNode[ch]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
