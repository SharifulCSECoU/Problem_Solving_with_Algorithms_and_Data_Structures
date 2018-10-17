#include<bits/stdc++.h>

#define Infinity 9999999

using namespace std;

vector <int> Graph[100005], Cost[100005];

int Distance1[100005], Distance2[100005], Node, Edge, i;

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

void Dijkstra1(int Source)
{
    for(i = 0; i < Node; i++)
        Distance1[i] = Infinity;

    Distance1[Source] = 0;

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

            if(Distance1[v] > Distance1[u] + Cost[u][i])
            {
                Distance1[v] = Distance1[u] + Cost[u][i];

                PQ.push(Nod(v,Distance1[v]));
            }
        }
    }
}

void Dijkstra2(int Source)
{
    for(i = 0; i < Node; i++)
        Distance2[i] = Infinity;

    Distance2[Source] = 0;

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

            if(Distance2[v] > Distance2[u] + Cost[u][i])
            {
                Distance2[v] = Distance2[u] + Cost[u][i];

                PQ.push(Nod(v,Distance2[v]));
            }
        }
    }
}

int main()
{
    int Test, u, v, Source, End, Case = 1;

    cin >> Test;

    while(Test--)
    {
        cin >> Node >> Edge;

        for(i = 0; i < Edge; i++)
        {
            cin >> u >> v;

            Graph[u].push_back(v);
            Graph[v].push_back(u);

            Cost[u].push_back(1);
            Cost[v].push_back(1);
        }

        cin >> Source >> End;

        int Ans = 0;

        Dijkstra1(Source);
        Dijkstra2(End);

        for(i = 0; i < Node; i++)
            Ans = max( Ans , (Distance1[i] + Distance2[i]) );

        cout << "Case " << Case++ << ": " << Ans << endl;

        for(i = 0; i < Node; i++)
        {
            Graph[i].clear();
            Cost[i].clear();
        }
    }

    return 0;
}
