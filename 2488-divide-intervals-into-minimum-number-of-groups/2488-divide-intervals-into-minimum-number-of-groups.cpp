class Solution {
public:
    int minGroups(std::vector<std::vector<int>>& intervals) {
        std::vector<std::pair<int, int>> events;

        // Step 1: Create start and end events for each interval.
        for (const auto& interval : intervals) {
            events.emplace_back(interval[0], +1); // Start of an interval
            events.emplace_back(interval[1] + 1,
                                -1); // End of an interval (use right + 1)
        }

        // Step 2: Sort events by time. If two events have the same time,
        // process end events first.
        std::sort(events.begin(), events.end());

        int maxGroups = 0;
        int activeIntervals = 0;

        // Step 3: Sweep through the events.
        for (const auto& [time, event] : events) {
            activeIntervals +=
                event; // Add 1 for a start, subtract 1 for an end.
            maxGroups = std::max(maxGroups, activeIntervals);
        }

        return maxGroups;
    }
};
