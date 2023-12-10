#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

// Queue structure for BFS
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Initialize an empty queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

// Check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Add an element to the rear of the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Remove and return an element from the front of the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Graph structure
struct Graph {
    int n; // Number of nodes
    int m; // Number of edges
    int matrix[MAX_NODES][MAX_NODES]; // Adjacency matrix
};

// Initialize the graph
void initializeGraph(struct Graph* graph, int n, int m) {
    graph->n = n;
    graph->m = m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph->matrix[i][j] = 0;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int u, int v) {
    graph->matrix[u - 1][v - 1] = graph->matrix[v - 1][u - 1] = 1;
}

// Breadth-First Search traversal
void BFS(struct Graph* graph, int start, int distance[]) {
    struct Queue* queue = createQueue(MAX_NODES);
    int visited[MAX_NODES] = {0};

    visited[start - 1] = 1;
    distance[start - 1] = 0;
    enqueue(queue, start);

    while (!isEmpty(queue)) {
        int current = dequeue(queue);
        printf("%d ", current);

        for (int i = 0; i < graph->n; i++) {
            if (graph->matrix[current - 1][i] && !visited[i]) {
                visited[i] = 1;
                distance[i] = distance[current - 1] + 2;
                enqueue(queue, i + 1);
            }
        }
    }

    free(queue->array);
    free(queue);
}

int main() {
    struct Graph graph;
    int n, m, u, v, start;

    // Input
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    initializeGraph(&graph, n, m);

    printf("Enter the edges (u v): \n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(&graph, u, v);
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    // Breadth-First Search
    int distance[MAX_NODES];
    for (int i = 0; i < n; i++)
        distance[i] = -1;

    printf("BFS Traversal: ");
    BFS(&graph, start, distance);

    // Output distances
    printf("\nDistance: [");
    for (int i = 0; i < n; i++) {
        printf("%d", distance[i]);
        if (i < n - 1)
            printf(" ");
    }
    printf("]\n");

    return 0;
}
