#include "dijkstras.h"

int main() {

    Graph graph;

    file_to_graph("src/small.txt", graph);

    vector<int> prev;
    auto dist = dijkstra_shortest_path(graph, 0, prev);

    auto path = extract_shortest_path(dist, prev, 2);

    int total = 0;
    for (auto n : dist) {
        total += n;
    }

    print_path(path, total);




}