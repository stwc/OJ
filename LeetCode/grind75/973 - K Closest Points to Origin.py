class Solution1:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        for p in points[:k]:
            dist = self.getDistance(p[0], p[1])
            heapq.heappush(heap, (-dist, p[0], p[1]))

        for p in points[k:]:
            dist = self.getDistance(p[0], p[1])
            if dist < -heap[0][0]:
                heapq.heappushpop(heap, (-dist, p[0], p[1]))

        res = []
        for i in range(k):
            _, x, y = heapq.heappop(heap)
            res.append([x, y])

        return res

    def getDistance(self, x, y):
        return math.sqrt(x * x + y * y)


class Solution2:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []

        for x, y in points:
            dist = -(x * x + y * y)
            if len(heap) == k:
                heapq.heappushpop(heap, (dist, x, y))
            else:
                heapq.heappush(heap, (dist, x, y))

        return [(x, y) for (dist, x, y) in heap]
