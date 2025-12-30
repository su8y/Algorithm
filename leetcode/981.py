''' 981. Time Based Key-Value Store '''
class TimeMap:

    def __init__(self):
        self.mp = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        heapq.heappush(self.mp[key], (timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        lst = self.mp[key]
        n = len(lst)

        if n == 0: 
            return "" 

        left,right = -1, n # (0, n)
        while left + 1 < right:
            mid = (left + right) // 2
            if lst[mid][0] <= timestamp:
                left = mid
            else:
                right = mid
        if left == -1:
            return ""
        return lst[left][1]
        

        


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
