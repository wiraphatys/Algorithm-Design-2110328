#include <bits/stdc++.h>
using namespace std;

int main() {
    int Vertices, Edges, a, b;
    cin >> Vertices >> Edges;

    map<int, set<int> > graph;
    for (int i = 0; i < Vertices; ++i) graph[i] = set<int>();

    while (Edges--) {
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    auto now = graph.begin();
    vector<set<int> > colored;
    set<int> temp;
    temp.insert(now->first);
    colored.push_back(temp);
    Vertices--;
    now++;
    while (Vertices--) {
        bool found;
        for (auto &s : colored) {
            found = false;
            // found = True
            for (auto &e : now->second) {
                if (s.find(e) != s.end()) {
                    found = true;
                    break;
                }
            }
            // found = False
            if (!found) {
                s.insert(now->first);
                break;
            }
        }
        if (found) {
            set<int> temp;
            temp.insert(now->first);
            colored.push_back(temp);
        }
        now++;
    }

    cout << colored.size();
    return 0;
}