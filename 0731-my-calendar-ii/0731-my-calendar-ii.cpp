class MyCalendarTwo {
public:
    // Stores single bookings
    vector<pair<int, int>> single_bookings;
    // Stores double bookings (overlapping intervals of two events)
    vector<pair<int, int>> double_bookings;

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        // First check if the new event overlaps with any event in double bookings
        for (auto& db : double_bookings) {
            if (max(start, db.first) < min(end, db.second)) {
                // If there is an overlap with any double booking, return false
                return false;
            }
        }
        
        // Check for overlap with single bookings and add to double bookings if overlap is found
        for (auto& sb : single_bookings) {
            if (max(start, sb.first) < min(end, sb.second)) {
                // Add the overlapping part to double bookings
                double_bookings.push_back({max(start, sb.first), min(end, sb.second)});
            }
        }
        
        // Add the new event to single bookings
        single_bookings.push_back({start, end});
        return true;
    }
};
