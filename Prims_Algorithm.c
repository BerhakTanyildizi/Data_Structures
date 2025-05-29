#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define SIZE 8 // Assuming a fixed size graph as per the given Python example

// Graph structure in C
typedef struct Graph {
    int adj_matrix[SIZE][SIZE];
    char* vertex_data[SIZE];
    int size;
} Graph;

// Function to initialize the graph
void init_graph(Graph* g, int size) {
    g->size = size;
    for (int i = 0; i < size; i++) {
        g->vertex_data[i] = "";
        for (int j = 0; j < size; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }
}

// Function to add an edge
void add_edge(Graph* g, int u, int v, int weight) {
    if (u >= 0 && u < g->size && v >= 0 && v < g->size) {
        g->adj_matrix[u][v] = weight;
        g->adj_matrix[v][u] = weight; // For an undirected graph
    }
}

// Function to add vertex data
void add_vertex_data(Graph* g, int vertex, char* data) {
    if (vertex >= 0 && vertex < g->size) {
        g->vertex_data[vertex] = data;
    }
}

// Function to print the MST using Prim's Algorithm
void prims_algorithm(Graph* g) {
    bool in_mst[SIZE];
    int key_values[SIZE];
    int parents[SIZE];

    // Initialize all key values as INFINITE and in_mst as false
    for (int i = 0; i < g->size; i++) {
        key_values[i] = INT_MAX;
        in_mst[i] = false;
        parents[i] = -1;
    }

    // Starting from the first vertex
    key_values[0] = 0;

    printf("Edge \tWeight\n");
    for (int count = 0; count < g->size; count++) {
        // Find the minimum key vertex from the set of vertices not yet included in MST
        int min = INT_MAX, u = -1;

        for (int v = 0; v < g->size; v++) {
            if (!in_mst[v] && key_values[v] < min) {
                min = key_values[v];
                u = v;
            }
        }

        in_mst[u] = true;

        // Print the edge as it's added to the MST, skip if u is the starting vertex
        if (parents[u] != -1) {
            printf("%s-%s \t%d\n", g->vertex_data[parents[u]], g->vertex_data[u], g->adj_matrix[u][parents[u]]);
        }

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < g->size; v++) {
            if (g->adj_matrix[u][v] && !in_mst[v] && g->adj_matrix[u][v] < key_values[v]) {
                key_values[v] = g->adj_matrix[u][v];
                parents[v] = u;
            }
        }
    }
}

// Main function to demonstrate the Prim's Algorithm
int main() {
    Graph g;
    init_graph(&g, SIZE);

    add_vertex_data(&g, 0, "A");
    add_vertex_data(&g, 1, "B");
    add_vertex_data(&g, 2, "C");
    add_vertex_data(&g, 3, "D");
    add_vertex_data(&g, 4, "E");
    add_vertex_data(&g, 5, "F");
    add_vertex_data(&g, 6, "G");
    add_vertex_data(&g, 7, "H");

    // Add edges
    add_edge(&g, 0, 1, 4); // A - B
    add_edge(&g, 0, 3, 3);  // A - D
    add_edge(&g, 1, 2, 3);  // B - C
    add_edge(&g, 1, 3, 5);  // B - D
    add_edge(&g, 1, 4, 6);  // B - E
    add_edge(&g, 2, 4, 4);  // C - E
    add_edge(&g, 2, 7, 2);  // C - H
    add_edge(&g, 3, 4, 7);  // D - E
    add_edge(&g, 3, 5, 4);  // D - F
    add_edge(&g, 4, 5, 5);  // E - F
    add_edge(&g, 4, 6, 3);  // E - G
    add_edge(&g, 5, 6, 7);  // F - G
    add_edge(&g, 6, 7, 5);  // G - H

    printf("Prim's Algorithm MST:\n");
    prims_algorithm(&g);

    return 0;
}
