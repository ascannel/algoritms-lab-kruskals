#ifndef KRUSKALS_HEADER_HPP
#define KRUSKALS_HEADER_HPP

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <chrono>

class DisjointSet;

struct Edge {
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

bool compareEdges(const Edge& a, const Edge& b);
std::vector<Edge> kruskalMST(std::vector<Edge>& edges, int vertices, bool use_path_compression);
void writeOutputToFile(const std::vector<Edge>& mst, const std::string& filename);
std::vector<Edge> generateRandomGraph(int numVertices, int numEdges, int minWeight, int maxWeight);
void generateRandomGraphToFile(int numVertices, int numEdges, int minWeight, int maxWeight);

#endif // KRUSKALS_FUNCTIONS_H