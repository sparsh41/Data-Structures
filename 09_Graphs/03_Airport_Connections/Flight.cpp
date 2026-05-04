#include "Flight.hpp"

// Default constructor is invalid flight
Flight::Flight() {
    valid = false;
}

// Flight for undirected graph
Flight::Flight(int cost, int to) {
    valid = true;
    this->cost = cost;
    this->to = to;
    dist = -1;
    from = -1;
}

// Manual constructor is valid
Flight::Flight(int dist, int cost, int from, int to) {
    this->dist = dist;
    this->cost = cost;
    this->from =from;
    this->to = to;
    valid = true;
}