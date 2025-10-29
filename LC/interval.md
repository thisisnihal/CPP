problem: https://neetcode.io/problems/meeting-schedule-ii?list=neetcode150

```java

public class Interval {
    public int start, end;
    public Interval(int start, int end) {
        this.start = start;
        this.end = end;
    }
}
 

public class Solution {
    public int minMeetingRooms(List<Interval> intervals) {
        if (intervals == null || intervals.size() == 0)
            return 0;

        // Step 1: Sort by start time
        intervals.sort((a, b) -> a.start - b.start);

        // Step 2: Min-heap for meeting end times
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        // Step 3: Add the first meeting's end time
        minHeap.add(intervals.get(0).end);

        // Step 4: Process the rest
        for (int i = 1; i < intervals.size(); i++) {
            Interval current = intervals.get(i);

            // If the current meeting starts after the earliest one ends → reuse room
            if (current.start >= minHeap.peek()) {
                minHeap.poll();
            }

            // Add the current meeting’s end time
            minHeap.add(current.end);
        }

        // Step 5: Number of rooms = heap size
        return minHeap.size();
    }
}
```
