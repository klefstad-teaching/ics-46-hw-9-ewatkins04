#include "dijkstras.h"

int main() {

    Graph graph;

    file_to_graph("src/small.txt", graph);

    vector<int> prev;
    auto d = dijkstra_shortest_path(graph, 0, prev);

    extract_shortest_path(d, prev, 1);

    print_path(d, 0);




}