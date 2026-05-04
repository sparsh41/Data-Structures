#include "Graph.hpp"
#include "MinHeap.hpp"
#include "Forest.hpp"

#include <climits> // for INT_MAX
#include <algorithm> // for reverse

using namespace std;

Graph::Graph() {}

Graph::Graph(string file_name) {
    // Setup vars
    ifstream file(file_name);
    string line = "";

    // Clear header
    getline(file, line); 

    // Read whole file
    while (getline(file, line)) {
        string from = "";
        string to = "";
        string from_city = "";
        string to_city = "";
        string dist = "";
        string cost = "";
        
        // manual string work to get all info 
        int i = 0;

        while (line[i] != ',') {
            from += line[i];
            i++;
        }
        i++;

        while (line[i] != ',') {
            to += line[i];
            i++;
        }
        i += 2;

        while (line[i] != '\"') {
            from_city += line[i];
            i++;
        }
        i += 3;

        while (line[i] != '\"') {
            to_city += line[i];
            i++;
        }
        i += 2;

        while (line[i] != ',') {
            dist += line[i];
            i++;
        }
        i++;

        while (line[i]) { // go until end of line
            cost += line[i];
            i++;
        }

        // add edge to graph
        addEdge(from, from_city, to, to_city, stoi(dist), stoi(cost));
    }
}

// Add an airport to graph's list
int Graph::addAirport(string code, string city) {
    
    // Check if already known
    int result = contains(airport_codes, code);
    
    // If yes, return that mapped idx
    if (result != -1) {
        return result;
    }
    
    // else add and return
    airport_codes.push_back(code);
    airport_cities.push_back(city);
    return airport_codes.size() - 1;
}

// Add an Flight/flight to the graph
void Graph::addEdge(string from, string from_city, string to, string to_city, int dist, int cost) {

    // Gather airport info
    int u = addAirport(from, from_city);
    int v = addAirport(to, to_city);

    // Need to resize matrix if we don't already know both airports
    int old_size = matrix.size();
    int new_size = airport_codes.size();

    // Resize of necessary
    if (new_size > old_size) {
        matrix.resize(new_size);
        for (int i = 0; i < new_size; i++) {
            matrix[i].resize(new_size); // new space is filled with invalid flights
        }
    }

    // add flight info at (u,v)
    matrix[u][v] = Flight(dist, cost, u, v);
}

// Print graph
void Graph::printGraph() { // DELETE BEOFRE SUBMITTING

    cout << "\nDirected Graph\n";

    // 2D matrix navigation
    for (int i = 0; i < matrix.size(); i++) {

        // Output departure airport name (remember idx is mapped the same in matrix and airport_list)
        cout << airport_codes[i] << endl;

        // 2D matrix nav
        for (int j = 0; j < matrix[i].size(); j++) {

            // Get info about flight from i to j
            Flight flight = matrix[i][j];

            if (flight.valid) { // probably invalid, if not print
                cout << " ->" << airport_codes[j];
                cout << " (c" << flight.cost << " d" << flight.dist << ")\n";
            }
        }
    }
    cout << endl;
}

// check if airport code is already stored in our list
int Graph::contains(vector<string> v, string code) {
    for(int i = 0; i < v.size(); i++) {
        if (code == v[i]) {return i;} // return index as mapped int
    }
    return -1;
}

// Compute shortest path by distance from startCode to endCode
void Graph::dijkstra(string startCode, string endCode) {
    // Indices fo start and end airports
    int start = contains(airport_codes, startCode);
    int end = contains(airport_codes, endCode);

    // Input validation
    if (start == -1 || end == -1) {
        cout << "Shortest route from " << startCode << " to " << endCode << ": None\n";
        return;
    }

    int n = airport_codes.size();

    // Distance & cost array, initialized to infinity
    vector<double> dist(n, INT_MAX);
    vector<double> cost(n, INT_MAX);

    // Track visited nodes
    vector<bool> visited(n, false);

    // Track previous node (for path reconstruction)
    vector<int> prev(n, -1);

    dist[start] = 0;
    cost[start] = 0;

    // Dijkstra
    for (int i = 0; i < n; i++) {
        int u = -1;
        double minDist = INT_MAX;

        // Find unvisited node with smallest distance
        for (int j = 0; j< n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        // No reachable node left
        if (u == -1) {
            break;
        }

        visited[u] = true;

        // Relax Flights from u
        for (int v = 0; v < n; v++) {
            if (matrix[u][v].valid) {
                double d = matrix[u][v].dist;
                double c = matrix[u][v].cost;

                if (!visited[v] && dist[u] + d < dist[v]) {
                    dist[v] = dist[u] + d;
                    cost[v] = cost[u] + c;
                    prev[v] = u;
                }
            }
        }
    }

    if (dist[end] == INT_MAX) {
        cout << "Shortest route from " << startCode << " to " << endCode << ": None\n\n";
        return;
    }

    // Reconstruct path
    vector<int> path;
    for (int i = end; i != -1; i = prev[i]) {
        path.push_back(i);
    }

    // Reverse path to correct order
    reverse(path.begin(), path.end());

    // Print path
    cout << "Shortest route from " << startCode << " to " << endCode << ": ";
    for (int i = 0; i < path.size(); i++) {
        cout << airport_codes[path[i]];
        if (i != path.size() - 1) cout << "->";
    }

    cout << ". The length is " << dist[end] << ". The cost is " << cost[end] << ".\n\n";
}

// Recursive DFS to find path with exact number of stops
void dfsStops(int cur, int end, int stopsLeft, 
    vector<bool>& visited, 
    vector<int>& path, 
    int curDist, int curCost, 
    int& bestDist, int& bestCost, 
    vector<int>& bestPath, 
    const vector<vector<Flight>>& matrix) {

    // If dest reached with exact stops
    if (cur == end && stopsLeft == -1) {
        if(curDist < bestDist) {
            bestDist = curDist;
            bestCost = curCost;
            bestPath = path;
        }
        return;
    }
    
    // Stop if too many Flights
    if (stopsLeft < -1) {
        return;
    }

    visited[cur] = true;

    // Explore all outgoing flights
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[cur][i].valid && !visited[i]) {
            path.push_back(i);

            dfsStops(i, end, stopsLeft - 1, 
                visited, path,
                curDist + matrix[cur][i].dist,
                curCost + matrix[cur][i].cost,
                bestDist, bestCost, bestPath,
                matrix);

            path.pop_back();
        }
    }
    visited[cur] = false;
}

// Find shortest path with exactly "stops" Flights
void Graph::shortestPathWithStops(string startCode, string endCode, int stops) {
    int start = contains(airport_codes, startCode);
    int end = contains(airport_codes, endCode);

    if (start == -1 || end == -1) {
        cout << "Invalid airport code\n";
        return;
    }

    int n = airport_codes.size();

    vector<bool> visited(n, false);
    vector<int> path;
    vector<int> bestPath;

    int bestDist = INT_MAX;
    int bestCost = 0;

    // Start path from source
    path.push_back(start);

    // Call DFS search
    dfsStops(start, end, stops, visited, path, 0, 0, bestDist, bestCost, bestPath, matrix);

    // No valid path found
    if (bestDist == INT_MAX) {
        cout << "Shortest route from "<< startCode << " to " << endCode << " with " << stops << " stops: None\n\n";
        return;
    }

    // Print result
    cout << "Shortest route from "<< startCode << " to " << endCode << " with " << stops << " stops:\n";
    for (int i = 0; i < bestPath.size(); i++) {
        cout << airport_codes[bestPath[i]];
        if (i != bestPath.size() - 1) {
            cout << "->";
        }
    }

    cout << "\nTotal distance: " << bestDist;
    cout << "\nTotal Cost: " << bestCost << "\n\n";
}

// Compute shortest paths from starting airport to list of target airports
void Graph::shortestPathsFromSource(string startCode, string state, vector<string> targets) {
    int start = contains(airport_codes, startCode);

    if (start == -1) {
        cout << "Invalid starting airport\n";
        return;
    }

    int n = airport_codes.size();

    // Distance & cost array, initialized to infinity
    vector<double> dist(n, INT_MAX);
    vector<double> cost(n, INT_MAX);

    // Track visited nodes
    vector<bool> visited(n, false);

    // Track previous node (for path reconstruction)
    vector<int> prev(n, -1);

    dist[start] = 0;
    cost[start] = 0;

    // Dijkstra
    for (int i = 0; i < n; i++) {
        int u = -1;
        double minDist = INT_MAX;

        // Find unvisited node with smallest distance
        for (int j = 0; j< n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        // No reachable node left
        if (u == -1) {
            break;
        }

        visited[u] = true;

        // Relax Flights from u
        for (int v = 0; v < n; v++) {
            if (matrix[u][v].valid) {
                double d = matrix[u][v].dist;
                double c = matrix[u][v].cost;

                if (!visited[v] && dist[u] + d < dist[v]) {
                    dist[v] = dist[u] + d;
                    cost[v] = cost[u] + c;
                    prev[v] = u;
                }
            }
        }
    }


    // Print output header
    cout << "Shortest paths from " << startCode << " to " << state << " state airports are:\n";
    cout << "Path \t\tLength\tCost\n";

    // Process each target airport
    for (int t = 0; t < targets.size(); t++) {
        int end = contains(airport_codes, targets[t]);

        // Skip if invvalid or unreachable
        if (end == -1 || dist[end] == INT_MAX) {
            continue;
        }

        // Reconstruct path
        vector<int> path;
        for (int i = end; i != -1; i = prev[i]) {
            path.push_back(i);
        }

        // Reverse path to correct order
        reverse(path.begin(), path.end());

        // Print path
        for (int i = 0; i < path.size(); i++) {
            cout << airport_codes[path[i]];
            if (i != path.size() - 1) cout << "->";
        }
        // Print distance and cost
        cout << " \t" << dist[end] << "\t" << cost[end] << endl;
    }

    cout << "\n";
}

void Graph::shortestToState(string startCode, string dest_state) {
    vector<string> state_airports;

    // Get airports from cetain state
    for(int i = 0; i < airport_cities.size(); i++) {

        string city = airport_cities[i];
        string state = city.substr(city.length() - 2);

        if (state == dest_state && startCode != airport_codes[i]) {
            state_airports.push_back(airport_codes[i]);
        }
    }

    shortestPathsFromSource(startCode, dest_state, state_airports);
}

// Print number of incoming, outgoing Flights and total connections per airport
void Graph::printConnectivity() {
    int n = airport_codes.size();

    vector<pair<int, int>> stats;

    //Calculate connections for each airport
    for (int i = 0; i < n; i++) {
        int total = 0;

        // Count outgoing Flights
        for (int j = 0; j < n; j++) {
            // Count both outgoing and incoming Flights
            if (matrix[i][j].valid) total++; // Outgoing 
            if (matrix[j][i].valid) total++; // Incoming 
        }

        // Store the results
        stats.push_back({i, total});
    } 
    
    // Sort by total connections in descending order
    sort(stats.begin(), stats.end(), [](const pair<int, int>& a, const pair<int, int>& b) { 
        return a.second > b.second;
    }); 

    // Print results
    cout << "Airport        " << "Connections\n";
    for (const auto& entry : stats) {
        cout << airport_codes[entry.first] << "            " << entry.second << endl;
    }
    cout << endl;
}

void Graph::createUndirectedGraph(){

    // Loop through flight matrix
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {

            // If the flight is valid
            if (matrix[i][j].valid) {

                // No return flight
                if (!matrix[j][i].valid) {
                    matrix[j][i] = Flight(matrix[i][j].dist, matrix[i][j].cost, j, i);
                }
                else { // If there is a return flight, check the cost, then update
                    if (matrix[j][i].cost > matrix[i][j].cost) {
                        matrix[j][i].cost = matrix[i][j].cost;
                    }
                }
            }
        }
    }
}

void Graph::createMST_Prim() {

    // Make sure graph is undirected
    createUndirectedGraph();

    int size = airport_codes.size();

    vector<int> mst(size, -1);          // parent array
    vector<bool> mst_vertices(size, false);
    vector<int> keys(size, INT_MAX);

    keys[0] = 0; // start from vertex 0

    for (int i = 0; i < size - 1; i++) {

        int u = getMinVertex(keys, mst_vertices);

        if (u == -1) {
            cout << "Minimal Spanning Tree: impossible using Prim's Algorithm\n\n";
            return;
        }

        mst_vertices[u] = true;

        // Explore all neighbors
        for (int v = 0; v < size; v++) {

            if (matrix[u][v].valid && !mst_vertices[v] &&
                matrix[u][v].cost < keys[v]) {

                mst[v] = u;
                keys[v] = matrix[u][v].cost;
            }
        }
    }

    // Print MST
    cout << "Minimal Spanning Tree:\n";
    cout << "Edge --------- Weight\n";

    int total = 0;

    for (int i = 1; i < size; i++) {
        if (mst[i] == -1) {
            cout << "Minimal Spanning Tree: impossible using Prim's Algorithm\n\n";
            return;
        }

        cout << numToCode(mst[i]) << " - " << numToCode(i)
             << " ---- " << matrix[mst[i]][i].cost << "\n";

        total += matrix[mst[i]][i].cost;
    }

    cout << "Total cost of MST: " << total << "\n\n";
}

int Graph::getMinVertex(vector<int> keys, vector<bool> mst_set) {
    // Keep track of val and idx
    int min_val = INT_MAX;
    int min_index = -1; // no min index = no full mst

    for (int i = 0; i < mst_set.size(); i++) {
        // if still not in mst and new best, we have new val and index
        if (!mst_set[i] && keys[i] < min_val) {
            min_val = keys[i];
            min_index = i;
        }
    }
    // with full dataset this returns -1 at the end
    return min_index;
}

// Maps an existing airport's number to its code
string Graph::numToCode(int num) {

    if (num < airport_codes.size()) {
        return airport_codes[num];
    }
    return "null";
}

// Create an MST using Kruskal's algorithm
void Graph::createMSF_Kruskal() {

    // Check if graph exists
    int size = airport_codes.size();
    if (size == 0) return;

    // Ensure graph is undirected
    createUndirectedGraph();

    // Disjoint Set / Forest
    Forest forest(size);

    // Step 1: Collect edges (u, v, cost)
    vector<vector<int>> edges;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {

            if (!matrix[i][j].valid) continue;

            edges.push_back({i, j, matrix[i][j].cost});
        }
    }

    // Step 2: Sort edges by cost
    sort(edges.begin(), edges.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

    // Step 3: Kruskal's Algorithm
    for (int i = 0; i < edges.size(); i++) {

        int u = edges[i][0];
        int v = edges[i][1];
        int cost = edges[i][2];

        if (forest.find_tree(u) != forest.find_tree(v)) {
            forest.combine_trees(u, v, cost);
        }
    }

    // Step 4: Group edges by tree root
    vector<vector<vector<int>>> tree_groups(size);

    for (int i = 0; i < forest.mst_edges.size(); i++) {

        int u = forest.mst_edges[i][0];
        int root = forest.find_tree(u);

        tree_groups[root].push_back(forest.mst_edges[i]);
    }

    // Step 5: Print MSF
    cout << "Minimum Spanning Forest (Kruskal):\n\n";

    int tree_num = 1;

    for (int i = 0; i < size; i++) {

        if (tree_groups[i].empty()) continue;

        cout << "Tree " << tree_num++ << endl;

        int total_cost = 0;

        for (int j = 0; j < tree_groups[i].size(); j++) {

            int u = tree_groups[i][j][0];
            int v = tree_groups[i][j][1];
            int cost = tree_groups[i][j][2];

            cout << numToCode(u) << " - "
                 << numToCode(v) << " ---- "
                 << cost << endl;

            total_cost += cost;
        }

        cout << "Total Cost: " << total_cost << "\n\n";
    }

    // Step 6: Handle isolated nodes (no edges at all)
    for (int i = 0; i < size; i++) {

        bool hasEdge = false;

        for (int j = 0; j < forest.mst_edges.size(); j++) {
            if (forest.mst_edges[j][0] == i ||
                forest.mst_edges[j][1] == i) {
                hasEdge = true;
                break;
            }
        }

        if (!hasEdge) {
            cout << "Tree " << tree_num++ << endl;
            cout << numToCode(i) << " (isolated)\n\n";
        }
    }
}