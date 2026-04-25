 #include "BusSystem.h"

string BusSystem::formatName(string s) {
    for (char &c : s)
        if (c == '_') c = ' ';
    return s;
}

void BusSystem::addRoute(string u, string v, int d, string bus) {
    adj[u].push_back({v, d, bus});
    adj[v].push_back({u, d, bus});
}

void BusSystem::loadFromFile(string filename) {
    ifstream file(filename);

    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    string u, v, bus;
    int d;

    while (file >> u >> v >> d >> bus) {
        addRoute(u, v, d, bus);
    }

    cout << "Data Loaded Successfully!\n";
    cout << "Total Stops: " << adj.size() << endl;
}

void BusSystem::displayStops() {
    cout << "\nStops:\n";
    for (auto &i : adj)
        cout << "- " << formatName(i.first) << endl;
}

int BusSystem::calculateFare(int distance, int changes) {
    return 5 + (distance * 2) + (changes * 5);
}

void BusSystem::shortestPath(string src, string dest) {

    unordered_map<string, int> dist;
    unordered_map<string, string> parent;
    unordered_map<string, string> parentBus;

    for (auto &i : adj)
        dist[i.first] = INT_MAX;

    priority_queue<
        tuple<int, string, string>,
        vector<tuple<int, string, string>>,
        greater<>
    > pq;

    dist[src] = 0;
    pq.push({0, src, ""});

    while (!pq.empty()) {
        auto [cost, node, currBus] = pq.top();
        pq.pop();

        if (cost > dist[node]) continue;

        for (auto &edge : adj[node]) {

            int penalty = (currBus != "" && currBus != edge.busNo) ? 5 : 0;
            int newCost = cost + edge.distance + penalty;

            if (newCost < dist[edge.nextStop]) {
                dist[edge.nextStop] = newCost;
                parent[edge.nextStop] = node;
                parentBus[edge.nextStop] = edge.busNo;

                pq.push({newCost, edge.nextStop, edge.busNo});
            }
        }
    }

    if (dist[dest] == INT_MAX) {
        cout << "No route found!\n";
        return;
    }

    vector<string> path;
    vector<string> buses;

    string temp = dest;

    while (temp != src) {
        path.push_back(temp);
        buses.push_back(parentBus[temp]);
        temp = parent[temp];
    }

    path.push_back(src);
    reverse(path.begin(), path.end());
    reverse(buses.begin(), buses.end());

    cout << "\nRoute:\n";

    string prevBus = buses[0];
    cout << formatName(path[0]);

    int changes = 0;

    for (int i = 1; i < path.size(); i++) {

        if (buses[i-1] != prevBus) {
            cout << "\nChange to Bus " << buses[i-1] << "\n";
            changes++;
            prevBus = buses[i-1];
        }

        cout << " --(" << buses[i-1] << ")--> " << formatName(path[i]);
    }

    int totalDistance = 0;

    for (int i = 0; i < path.size() - 1; i++) {
        for (auto &e : adj[path[i]]) {
            if (e.nextStop == path[i+1]) {
                totalDistance += e.distance;
                break;
            }
        }
    }

    int fare = calculateFare(totalDistance, changes);
    int time = totalDistance * 3 + changes * 5;

    cout << "\n\nDistance: " << totalDistance << " km";
    cout << "\nFare: Rs " << fare;

    // ⏱️ TIME CONVERSION (FINAL FIX)
    int hours = time / 60;
    int minutes = time % 60;

    if (hours > 0 && minutes > 0)
        cout << "\nTime: " << hours << " hr " << minutes << " min";
    else if (hours > 0)
        cout << "\nTime: " << hours << " hr";
    else
        cout << "\nTime: " << minutes << " min";

    cout << "\nBus Changes: " << changes << endl;
}