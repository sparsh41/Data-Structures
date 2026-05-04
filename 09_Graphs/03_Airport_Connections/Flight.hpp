#ifndef FLIGHT_HPP
#define FLIGHT_HPP

// Flight Class for defining all flights, both directed and undirected
class Flight {
    public:
        int dist;
        int cost;
        int from;
        int to;
        bool valid;
        Flight();
        Flight(int cost, int to);
        Flight(int dist, int cost, int from, int to);

        // Overloading Operators for comparisions
        bool operator<(const Flight& other) {
            return (cost < other.cost); 
        }
        bool operator>(const Flight& other) {
            return (cost > other.cost); 
        }
};

#endif