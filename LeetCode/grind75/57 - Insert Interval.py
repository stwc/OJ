class Solution1:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        res = []

        for i in range(len(intervals)):
            if newInterval[0] > intervals[i][1]:
                # non-overlapping and newInterval > intervals[i]
                res.append(intervals[i])
            elif newInterval[1] < intervals[i][0]:
                # non-overlapping and newInterval < intervals[i]
                res.append(newInterval)
                # remaining intervals
                for interval in intervals[i:]:
                    res.append(interval)
                return res
            else:
                # overlapping, update newInterval
                newInterval[0] = min(intervals[i][0], newInterval[0])
                newInterval[1] = max(intervals[i][1], newInterval[1])

        # case: newInterval insert at the end
        res.append(newInterval)
        return res


class Solution2:
    def insert(
        self, intervals: list[list[int]], newInterval: list[int]
    ) -> list[list[int]]:
        res = []

        for interval in intervals:
            if newInterval[1] < interval[0]:
                res.append(newInterval)
                newInterval = interval
            elif newInterval[0] > interval[1]:
                res.append(interval)
            else:
                newInterval[0] = min(newInterval[0], interval[0])
                newInterval[1] = max(newInterval[1], interval[1])

        res.append(newInterval)
        return res
