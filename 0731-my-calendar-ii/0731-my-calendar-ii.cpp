#include <vector>
#include <map>

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        // Use a map to track the changes in overlap counts
        events[start]++;
        events[end]--;
        
        int ongoing = 0; // Number of ongoing events
        for (const auto& event : events) {
            ongoing += event.second; // Update ongoing events count
            
            // Check if ongoing events exceed 2
            if (ongoing > 2) {
                // Remove the changes since booking failed
                events[start]--;
                events[end]++;
                
                // Clean up map to prevent memory leak
                if (events[start] == 0) events.erase(start);
                if (events[end] == 0) events.erase(end);
                
                return false; // Reject the booking
            }
        }
        
        return true; // Accept the booking
    }

private:
    std::map<int, int> events; // Store changes in booking counts
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
