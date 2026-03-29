class EventManager:

    def __init__(self, events: list[list[int]]):
        self.mp = {}
        self.pq = []
        
        for event_id, pr in events:
            self.mp[event_id] = pr
            heapq.heappush(self.pq, (-pr, event_id))

    def updatePriority(self, eventId: int, newPriority: int) -> None:
        self.mp[eventId] = newPriority
        heapq.heappush(self.pq, (-newPriority, eventId))

    def pollHighest(self) -> int:
        while self.pq:
            neg_pr, event_id = heapq.heappop(self.pq)
            pr = -neg_pr
            if event_id in self.mp and self.mp[event_id] == pr:
                del self.mp[event_id]  # remove event
                return event_id
        
        return -1
        


# Your EventManager object will be instantiated and called as such:
# obj = EventManager(events)
# obj.updatePriority(eventId,newPriority)
# param_2 = obj.pollHighest()