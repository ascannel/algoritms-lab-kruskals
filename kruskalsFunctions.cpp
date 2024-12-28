#include "kruskalsHeader.hpp"

class DisjointSet {
private:
    std::vector<int> parent_;
    std::vector<int> rank_;

public:
    DisjointSet(int size) : parent_(size), rank_(size, 0) {
        for (int i = 0; i < size; ++i) {
            parent_[i] = i;
        }
    }

    int findSet(int x) {
        if (x != parent_[x]) {
            parent_[x] = findSet(parent_[x]);  // path compression
        }
        return parent_[x];
    }

    int findSetWithoutCompression(int x) {
        if (x == parent_[x]) {
            return x;
        }
        return findSetWithoutCompression(parent_[x]);
    }

    void unionSets(int x, int y) {
        int root_x = findSet(x);
        int root_y = findSet(y);
        if (root_x != root_y) {
            if (rank_[root_x] < rank_[root_y]) {
                std::swap(root_x, root_y);
            }
            parent_[root_y] = root_x;
            if (rank_[root_x] == rank_[root_y]) {
                rank_[root_x]++;
            }
        }
    }
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

std::vector<Edge> kruskalMST(std::vector<Edge>& edges, int vertices, bool use_path_compression) {
    std::sort(edges.begin(), edges.end(), compareEdges);
    DisjointSet ds(vertices);
    std::vector<Edge> mst;

    for (const auto& edge : edges) {
        int set_u = use_path_compression ? ds.findSet(edge.src)
            : ds.findSetWithoutCompression(edge.src);
        int set_v = use_path_compression ? ds.findSet(edge.dest)
            : ds.findSetWithoutCompression(edge.dest);

        if (set_u != set_v) {
            mst.push_back(edge);
            ds.unionSets(set_u, set_v);
        }
    }

    return mst;
}

void writeOutputToFile(const std::vector<Edge>& mst, const std::string& filename) {
    std::ofstream output_file(filename);
    if (output_file.is_open()) {
        for (const auto& edge : mst) {
            output_file << edge.src << " " << edge.dest << " " << edge.weight << std::endl;
        }
        output_file.close();
    }
    else {
        std::cerr << "unable to open output file " << filename << std::endl;
    }
}

std::vector<Edge> generateRandomGraph(int numVertices, int numEdges, int minWeight, int maxWeight) {
    std::vector<Edge> edges;
    std::set<std::pair<int, int>> edgeSet; // для проверки уникальности рёбер

    // Создание связного графа, добавляя рёбра между последовательными вершинами 
    for (int i = 0; i < numVertices - 1; ++i) {
        int weight = minWeight + rand() % (maxWeight - minWeight + 1);
        edges.emplace_back(i, i + 1, weight);
        edgeSet.insert({ i, i + 1 });
        edgeSet.insert({ i + 1, i });
    }

    // добавление случайных рёбер для достижения нужного количества 
    while (edges.size() < numEdges) {
        int u = rand() % numVertices;
        int v = rand() % numVertices;

        if (u != v && edgeSet.find({ u, v }) == edgeSet.end()) {
            int weight = minWeight + rand() % (maxWeight - minWeight + 1);
            edges.emplace_back(u, v, weight);
            edgeSet.insert({ u, v });
            edgeSet.insert({ v, u });
        }
    }
    return edges;
}

void generateRandomGraphToFile(int numVertices, int numEdges, int minWeight, int maxWeight) {
    std::vector<Edge> edges = generateRandomGraph(numVertices, numEdges, minWeight, maxWeight);

    writeOutputToFile(edges, "input.txt");
    std::cout << "graph was written in input.txt." << std::endl;
}

int main() {
    int vertices, edges, minWeight, maxWeight;
    //std::cin >> vertices >> edges >> minWeight >> maxWeight;
    //generateRandomGraphToFile(vertices, edges, minWeight, maxWeight);
    std::ifstream input_file("input.txt");
    //if (!input_file.is_open()) {
    //    std::cerr << "Unable to open input file" << std::endl;
    //    return 1;
    //}

   input_file >> vertices >> edges;

    std::vector<Edge> edge_list;
    for (int i = 0; i < edges; ++i) {
        int src, dest, weight;
        input_file >> src >> dest >> weight;
        edge_list.emplace_back(src, dest, weight);
    }
    input_file.close();

    std::vector<Edge> mst_without_compression = kruskalMST(edge_list, vertices, false);
    std::vector<Edge> mst_with_compression = kruskalMST(edge_list, vertices, true);

    writeOutputToFile(mst_without_compression, "output_without_compression.txt");
    writeOutputToFile(mst_with_compression, "output_with_compression.txt");

    return 0;
}