#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <chrono>
#include <functional>
#include <queue>

#include <cmath>

using namespace std;
using namespace std::chrono;

typedef pair<int, int> pii;

const int INF = 1e9;

// Алгоритм Дейкстры
void Dijkstra(const vector<vector<pii>>& graph, int source, vector<int>& dist) {
    int numVertices = graph.size();
    dist.resize(numVertices, INF);
    dist[source] = 0;

    vector<bool> visited(numVertices, false);

    for (int i = 0; i < numVertices - 1; ++i) {
        int u = -1;
        for (int j = 0; j < numVertices; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INF) {
            break;
        }

        visited[u] = true;

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
}

// Алгоритм Флойда-Уоршелла
void FloydWarshall(const vector<vector<pii>>& graph, vector<vector<int>>& dist) {
    int numVertices = graph.size();
    dist.resize(numVertices, vector<int>(numVertices, INF));

    for (int u = 0; u < numVertices; ++u) {
        dist[u][u] = 0;
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            dist[u][v] = weight;
        }
    }

    for (int k = 0; k < numVertices; ++k) {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

// Алгоритм Форда-Беллмана
void BellmanFord(const vector<vector<pii>>& graph, int source, vector<int>& dist) {
    int numVertices = graph.size();
    dist.resize(numVertices, INF);
    dist[source] = 0;

    for (int i = 0; i < numVertices - 1; ++i) {
        for (int u = 0; u < numVertices; ++u) {
            for (const auto& edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
}

// Функция эвристической оценки расстояния от вершины u до вершины v (может быть заменена на другую функцию)
int heuristic(int u, int v) {
    // Пример эвристической функции - Евклидово расстояние между координатами вершин
    return sqrt(pow(u - v, 2));
}

struct AStarNode {
    int vertex;     // Индекс вершины
    int gScore;     // Расстояние от начальной вершины до текущей вершины
    int hScore;     // Предполагаемое расстояние от текущей вершины до конечной вершины

    AStarNode(int v, int g, int h) : vertex(v), gScore(g), hScore(h) {}

    bool operator<(const AStarNode& other) const {
        return (gScore + hScore) > (other.gScore + other.hScore);  // Обратный порядок для приоритетной очереди (меньшие значения имеют более высокий приоритет)
    }
};

// Алгоритм A*
void AStar(const vector<vector<pair<int, int>>>& graph, int source, int destination, vector<int>& dist) {
    int numVertices = graph.size();
    dist.resize(numVertices, INF);
    dist[source] = 0;

    priority_queue<AStarNode> pq;
    pq.emplace(source, 0, heuristic(source, destination));  // Исходная вершина с предполагаемым расстоянием hScore

    while (!pq.empty()) {
        AStarNode current = pq.top();
        pq.pop();

        int u = current.vertex;
        if (u == destination) {
            break;  // Достигнута конечная вершина, завершаем поиск
        }

        // Рассмотрим все соседние вершины
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Расстояние от начальной вершины до соседней вершины через текущую вершину
            int newDist = dist[u] + weight;

            // Если новое расстояние меньше текущего расстояния до соседней вершины
            if (newDist < dist[v]) {
                dist[v] = newDist;
                int hScore = heuristic(v, destination);  // Предполагаемое расстояние от соседней вершины до конечной
                pq.emplace(v, newDist, hScore);
            }
        }
    }
}



// Функция для замера времени выполнения функции
template<typename Func>
double measureTime(Func&& func) {
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();
    return (double)duration_cast<nanoseconds>(end - start).count();
}

// Генерация полного графа
void generateCompleteGraph(int numVertices, vector<vector<pii>>& graph) {
    srand(time(nullptr));
    graph.clear();
    graph.resize(numVertices);

    for (int u = 0; u < numVertices; ++u) {
        for (int v = u + 1; v < numVertices; ++v) {
            int weight = rand() % 10 + 1;
            graph[u].emplace_back(v, weight);
            graph[v].emplace_back(u, weight);
        }
    }
}

// Генерация связного графа с заданным коэффициентом плотности
void generateConnectedGraph(int numVertices, double density, vector<vector<pii>>& graph) {
    graph.clear();
    graph.resize(numVertices);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(0.0, 1.0);

    for (int i = 0; i < numVertices; ++i) {
        for (int j = i + 1; j < numVertices; ++j) {
            float random_value = dis(gen);

            if (random_value <= density) {
                int weight = rand() % 10 + 1;
                graph[i].emplace_back(j, weight);
                graph[j].emplace_back(i, weight);
            }
        }
    }
}

// Генерация разреженного графа (дерева)
void generateSparseGraph(int numVertices, vector<vector<pii>>& graph) {
    srand(time(nullptr));
    graph.clear();
    graph.resize(numVertices);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 11);
    for (int i = 1; i < numVertices; ++i) {
        int weight = dis(gen); // Генерируем случайный вес ребра
        int parent = i / 2; // Выбираем случайного родителя

        graph[parent].emplace_back(i, weight); // Добавляем ребро от родителя к текущей вершине
        graph[i].emplace_back(parent, weight); // Добавляем обратное ребро от текущей вершины к родителю
    }
}

int main() {
    ofstream outputFile("results.csv");
    outputFile << "Graph,NumVertices,NumEdges,TimeDijkstra,TimeFloydWarshall,TimeBellmanFord,TimeAStar" << endl;

    for (int numVertices = 10; numVertices <= 1010; numVertices += 50) {
        // Генерация графов
        vector<vector<pii>> graphComplete, graphConnected, graphSparse;
        generateCompleteGraph(numVertices, graphComplete);
        generateConnectedGraph(numVertices, 0.4, graphConnected);
        generateSparseGraph(numVertices, graphSparse);


        int numEdgesComplete = 0;
        for (const auto &neighbors : graphComplete) {
            numEdgesComplete += static_cast<int>(neighbors.size());
        }
        numEdgesComplete /= 2;


        int numEdgesConnected = 0;
        for (const auto &neighbors : graphConnected) {
            numEdgesConnected += static_cast<int>(neighbors.size());
        }
        numEdgesConnected /= 2;


        int numEdgesSparse = 0;
        for (const auto &neighbors : graphSparse) {
            numEdgesSparse += static_cast<int>(neighbors.size());
        }
        numEdgesSparse /= 2;


        int source = 0;
        int destination = numVertices - 1;

        // Выполнение алгоритма Дейкстры и замер времени
        vector<int> distDijkstra;
        double timeDijkstraAvg = 0.0;
        for (int i = 0; i < 5; ++i) {
            timeDijkstraAvg += measureTime([&]() {
                Dijkstra(graphComplete, source, distDijkstra);
            });
        }
        timeDijkstraAvg /= 5.0;

        // Выполнение алгоритма Флойда-Уоршелла и замер времени
        vector<vector<int>> distFloydWarshall;
        double timeFloydWarshallAvg = 0.0;
        for (int i = 0; i < 5; ++i) {
            timeFloydWarshallAvg += measureTime([&]() {
                FloydWarshall(graphComplete, distFloydWarshall);
            });
        }
        timeFloydWarshallAvg /= 5.0;

        // Выполнение алгоритма Форда-Беллмана и замер времени
        vector<int> distBellmanFord;
        double timeBellmanFordAvg = 0.0;
        for (int i = 0; i < 5; ++i) {
            timeBellmanFordAvg += measureTime([&]() {
                BellmanFord(graphComplete, source, distBellmanFord);
            });
        }
        timeBellmanFordAvg /= 5.0;

        // Выполнение алгоритма A* и замер времени
        vector<int> distAStar;
        double timeAStarAvg = 0.0;
        for (int i = 0; i < 5; ++i) {
            timeAStarAvg += measureTime([&]() {
                AStar(graphComplete, source, destination, distAStar);
            });
        }
        timeAStarAvg /= 5.0;

        outputFile << "Complete," << numVertices << "," << numEdgesComplete << "," << timeDijkstraAvg << "," << timeFloydWarshallAvg
                   << "," << timeBellmanFordAvg << "," << timeAStarAvg << endl;



        // Выполнение алгоритма Дейкстры и замер времени
        distDijkstra.clear();
        timeDijkstraAvg = 0.0;
        for (int i = 0; i < 5; ++i) {
            timeDijkstraAvg += measureTime([&]() {
                Dijkstra(graphConnected, source, distDijkstra);
            });
        }
        timeDijkstraAvg /= 5.0;

        // Выполнение алгоритма Флойда-Уоршелла и замер времени
        distFloydWarshall.clear();
        timeFloydWarshallAvg = 0.0;
        for (int i = 0; i < 5; ++i) {
            timeFloydWarshallAvg += measureTime([&]() {
                FloydWarshall(graphConnected, distFloydWarshall);
            });
        }
        timeFloydWarshallAvg /= 5.0;

        // Выполнение алгоритма Форда-Беллмана и замер времени
        distBellmanFord.clear();
        timeBellmanFordAvg = 0.0;
        for (int i = 0; i < 5; ++i) {
            timeBellmanFordAvg += measureTime([&]() {
                BellmanFord(graphConnected, source, distBellmanFord);
            });
        }
        timeBellmanFordAvg /= 5.0;

        // Выполнение алгоритма A* и замер времени
        distAStar.clear();
        timeAStarAvg = 0.0;
        for (int i = 0; i < 5; ++i) {
            timeAStarAvg += measureTime([&]() {
                AStar(graphConnected, source, destination, distAStar);
            });
        }
        timeAStarAvg /= 5.0;

        outputFile << "Connected," << numVertices << "," << numEdgesConnected << "," << timeDijkstraAvg << "," << timeFloydWarshallAvg
                   << "," << timeBellmanFordAvg << "," << timeAStarAvg << endl;



        // Выполнение алгоритма Дейкстры и замер времени
        distDijkstra.clear();
        timeDijkstraAvg = 0.0;
        for (int i = 0; i < 5; ++i) {
            timeDijkstraAvg += measureTime([&]() {
                Dijkstra(graphSparse, source, distDijkstra);
            });
        }
        timeDijkstraAvg /= 5.0;

        // Выполнение алгоритма Флойда-Уоршелла и замер времени
        distFloydWarshall.clear();
        timeFloydWarshallAvg = 0.0;
        for (int i = 0; i < 5; ++i) {
            timeFloydWarshallAvg += measureTime([&]() {
                FloydWarshall(graphSparse, distFloydWarshall);
            });
        }
        timeFloydWarshallAvg /= 5.0;

        // Выполнение алгоритма Форда-Беллмана и замер времени
        distBellmanFord.clear();
        timeBellmanFordAvg = 0.0;
        for (int i = 0; i < 5; ++i) {
            timeBellmanFordAvg += measureTime([&]() {
                BellmanFord(graphSparse, source, distBellmanFord);
            });
        }
        timeBellmanFordAvg /= 5.0;

        // Выполнение алгоритма A* и замер времени
        distAStar.clear();
        timeAStarAvg = 0.0;
        for (int i = 0; i < 5; ++i) {
            timeAStarAvg += measureTime([&]() {
                AStar(graphSparse, source, destination, distAStar);
            });
        }
        timeAStarAvg /= 5.0;

        outputFile << "Sparse," << numVertices << "," << numEdgesSparse << "," << timeDijkstraAvg << "," << timeFloydWarshallAvg
                   << "," << timeBellmanFordAvg << "," << timeAStarAvg << endl;
    }

    outputFile.close();

    return 0;
}



