#ifndef BUSSYSTEM_H
#define BUSSYSTEM_H

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    string nextStop;
    int distance;
    string busNo;
};

class BusSystem {
private:
    unordered_map<string, vector<Edge>> adj;

public:
    void addRoute(string u, string v, int d, string bus);
    void loadFromFile(string filename);
    void displayStops();
    void shortestPath(string src, string dest);
    int calculateFare(int distance, int changes);
    string formatName(string s);
};

#endif