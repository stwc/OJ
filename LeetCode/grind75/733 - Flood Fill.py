class Solution1:
    def floodFill(
        self, image: List[List[int]], sr: int, sc: int, color: int
    ) -> List[List[int]]:
        m, n = len(image), len(image[0])
        orig_color = image[sr][sc]

        if color == orig_color:
            return image

        q = deque()
        q.append((sr, sc))

        while len(q) != 0:
            xy = q.popleft()
            x, y = xy[0], xy[1]
            image[x][y] = color

            if x - 1 >= 0 and image[x - 1][y] == orig_color:
                q.append((x - 1, y))
            if y - 1 >= 0 and image[x][y - 1] == orig_color:
                q.append((x, y - 1))
            if x + 1 < m and image[x + 1][y] == orig_color:
                q.append((x + 1, y))
            if y + 1 < n and image[x][y + 1] == orig_color:
                q.append((x, y + 1))

        return image


class Solution2:
    def floodFill(self, image, sr, sc, color):
        old = image[sr][sc]
        if old == color:
            return image
        m = len(image)
        n = len(image[0])

        def dfs(i, j):
            if i < 0 or i >= m or j < 0 or j >= n or image[i][j] != old:
                return
            image[i][j] = color
            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)

        dfs(sr, sc)
        return image
