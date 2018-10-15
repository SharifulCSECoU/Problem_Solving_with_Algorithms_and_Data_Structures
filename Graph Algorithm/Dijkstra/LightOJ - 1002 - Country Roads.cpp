#include<bits/stdc++.h>

#define Infinity 9999999

using namespace std;

vector <int> Graph[100005], Cost[100005];

int Distance[100005], Node, Edge, Parents[100005], i;

struct Nod
{
    int u, w;

    Nod(int a, int b)
    {
        u = a;
        w = b;
    }

    bool operator < (const Nod & p) const
    {
        return w > p.w;
    }
};

void Dijkstra(int Source)
{
    for(i = 0; i <= Node; i++)
    {
        Distance[i] = Infinity;

        Parents[i] = -1;
    }

    Distance[Source] = 0;

    priority_queue <Nod> PQ;

    PQ.push(Nod(Source,0));

    while(!PQ.empty())
    {
        Nod top = PQ.top();

        PQ.pop();

        int u = top.u;

        for(i = 0; i < Graph[u].size(); i++)
        {
            int v = Graph[u][i];

            /*if(Distance[v] > Distance[u] + Cost[u][i])
            {
                Distance[v] = Distance[u] + Cost[u][i];

                PQ.push(Nod(v,Distance[v]));

                Parents[v] = u;
            }*/

            int Temp = max(Distance[u] , Cost[u][i]);

            if(Temp < Distance[v])
            {
                Distance[v] = Temp;
                PQ.push(Nod(v, Distance[v]));
            }
        }
    }
}

int main()
{
    int Test, u, v, w, Source, Case = 1;

    cin >> Test;

    while(Test--)
    {
        cin >> Node >> Edge;

        for(i = 0; i < Edge; i++)
        {
            cin >> u >> v >> w;

            Graph[u].push_back(v);
            Graph[v].push_back(u);
            Cost[u].push_back(w);
            Cost[v].push_back(w);
        }

        cin >> Source;

        Dijkstra(Source);

        //for(i = 1; i<= Node; i++)
            //cout << "Node  = " << i << " Parent = " << Parents[i] << " Distance = " << Distance[i] << endl;

        cout << "Case " << Case++ << ":" << endl;

        for(i = 0; i < Node; i++)
        {
            if(Distance[i] == Infinity)
                cout << "Impossible" << endl;

            else
                cout << Distance[i] << endl;

            Graph[i].clear();
            Cost[i].clear();
        }
    }

    return 0;
}
