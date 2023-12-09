#include <bits/stdc++.h>
using namespace std;

int color = 0;

int main()
{
    int Vertices, Edges, a, b;
    cin >> Vertices >> Edges;

    map<int, set<int>> graph;
    for (int i = 0; i < Vertices; ++i)
        graph[i] = set<int>();

    while (Edges--)
    {
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    auto now = graph.begin();
    set<int> colored;
    colored.insert(now->first);
    int prev = now->first;
    while (Vertices--)
    {
        auto next = graph.find(*((now->second).begin()));
        auto it = next->second.find(prev);

        int c = 0;
        for (auto &e : colored)
        {
            if (next->second.find(e) != next->second.end())
            {
                c++;
            }
        }
        if (c == colored.size())
        {
            color++;
            colored.insert(next->first);
        }

        if (it != next->second.end())
            next->second.erase(it);
        now = next;
        prev = now->first;
    }

    cout << color;
    return 0;
}

// set<int> s = now->second;
// auto next = graph.find(*(s.begin()));
// prev = now->first;
// auto delete_prev = next.find(prev);
// if (delete_prev != )