class Solution1:
    """
    BFS
    time: O(mn)
    space: O(mn)
    """

    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])

        queue = deque()

        # for reusing original matrix, convert 1 to infinity at initialization
        for i, row in enumerate(mat):
            for j, ele in enumerate(row):
                if ele:
                    mat[i][j] = float("inf")
                else:
                    queue.append((i, j))

        directions = ((1, 0), (-1, 0), (0, 1), (0, -1))
        while queue:
            for count in range(len(queue)):
                i, j = queue.popleft()

                for x, y in directions:
                    row, col = i + x, j + y

                    if -1 < row < m and -1 < col < n and mat[row][col] > mat[i][j] + 1:
                        mat[row][col] = mat[i][j] + 1
                        queue.append((row, col))

        return mat


class Solution2:
    """
    DP
    space: O(mn)
    """

    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])
        res = [[math.inf] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    res[i][j] = 0

        for i in range(m):
            for j in range(n):
                if i > 0:
                    res[i][j] = min(res[i][j], res[i - 1][j] + 1)
                if j > 0:
                    res[i][j] = min(res[i][j], res[i][j - 1] + 1)

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if i < m - 1:
                    res[i][j] = min(res[i][j], res[i + 1][j] + 1)
                if j < n - 1:
                    res[i][j] = min(res[i][j], res[i][j + 1] + 1)

        return res


class Solution3:
    """
    DP
    space: O(1)
    """

    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])

        # scan from left-top
        for i, row in enumerate(mat):
            for j, ele in enumerate(row):
                if ele:
                    top = mat[i - 1][j] + 1 if i > 0 else math.inf
                    left = mat[i][j - 1] + 1 if j > 0 else math.inf
                    mat[i][j] = min(top, left)

        # scan from right-bottom
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                ele = mat[i][j]
                if ele:
                    bottom = mat[i + 1][j] + 1 if i < m - 1 else math.inf
                    right = mat[i][j + 1] + 1 if j < n - 1 else math.inf
                    mat[i][j] = min(ele, bottom, right)

        return mat
