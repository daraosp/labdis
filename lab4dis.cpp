#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <locale.h>

using namespace std;
using ll = long long;

const ll INF = numeric_limits<ll>::max();

struct Graph {
    vector<int> versh;
    vector<vector<pair<int, int>>> smezh;
    vector<pair<int, int>> reb;
    int vershcnt, rebcnt;
};

void inputGraph(Graph& g) {
    cout << "Введите количество вершин графа: ";
    cin >> g.vershcnt;
    cout << "Введите количество ребер графа: ";
    cin >> g.rebcnt;

    g.versh.resize(g.vershcnt);
    cout << "Введите номера вершин:\n";
    for (int i = 0; i < g.vershcnt; ++i) {
        cin >> g.versh[i];
    }

    g.smezh.resize(g.vershcnt);
    g.reb.resize(g.rebcnt);
    cout << "Введите ребра:\n";
    for (int i = 0; i < g.rebcnt; ++i) {
        cin >> g.reb[i].first >> g.reb[i].second;
    }
    cout << "Введите веса ребер:\n";
    for (int i = 0; i < g.rebcnt; ++i) {
        int weight;
        cout << "Вес ребра " << (i + 1) << ": ";
        cin >> weight;
        int from = g.reb[i].first;
        int to = g.reb[i].second;
 
        g.smezh[from].emplace_back(to, weight);
        g.smezh[to].emplace_back(from, weight);
    }
}

vector<int> shortestPath(const Graph& g, int start, int finish, ll& pathw) {
    vector<char> used(g.vershcnt, 0);
    vector<ll> dist(g.vershcnt, INF);
    vector<int> pred(g.vershcnt, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> priorque;

    dist[start] = 0;
    priorque.emplace(0, start);

    while (!priorque.empty()) {
        int v = priorque.top().second;
        priorque.pop();

        if (used[v]) continue;
        used[v] = 1;

        for (auto& reb : g.smezh[v]) {
            int to = reb.first; 
            int weight = reb.second;

            if (!used[to] && dist[to] > dist[v] + weight) {
                dist[to] = dist[v] + weight;
                pred[to] = v;
                priorque.emplace(dist[to], to);
            }
        }
    }

    pathw = dist[finish];
    if (pathw == INF) return {};

    vector<int> path;
    for (int v = finish; v != -1; v = pred[v]) {
        path.push_back(g.versh[v]);
    }
    reverse(path.begin(), path.end());

    return path;
}

void printPath(const vector<int>& path, ll pathw) {
    if (path.empty()) {
        cout << "Пути между данными вершинами не существует\n";
        return;
    }

    cout << "Кратчайший путь: ";
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i != path.size() - 1) cout << " -> ";
    }
    cout << "\nСуммарный вес пути: " << pathw << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    Graph g;
    inputGraph(g);

    int start, finish;
    cout << "Введите начальную вершину: ";
    cin >> start;
    cout << "Введите конечную вершину: ";
    cin >> finish;

    ll pathw;
    vector<int> path = shortestPath(g, start, finish, pathw);
    printPath(path, pathw);

    return 0;
}