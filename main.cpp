#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#define maxi 50001
#define infinite 99999999

using namespace std;

ifstream fin("bellmanford.in");
ofstream fout("bellmanford.out");

vector< pair<int,int> > L[maxi];
int n, m , x, y ,c;
set<int> tail;
int dist[maxi];
int visited[maxi];

int main()
{
    fin >> n >> m;
    for( int i = 1 ; i <= m ; i++ )
    {
        fin >> x >> y >> c;
        L[x].push_back( make_pair(y , c) );
    }

    for( int i = 1 ; i <= n ; i++ )
    {
        dist[i] = infinite;
        visited[i] = 0;
    }

    tail.insert(1);
    dist[1] = 0;

    while( !tail.empty() )
    {
        int node = *tail.begin();
        tail.erase( tail.begin() );

        visited[node]++;
        if( visited[node] == n )
        {
            fout << "Ciclu negativ!";
            return 0;
        }

        for( auto it = L[node].begin() ; it != L[node].end() ; it++ )
        {
            int vecin = it -> first;
            int cost = it -> second;

            if( dist[vecin] > dist[node] + cost )
            {
                dist[vecin] = dist[node] + cost;
                tail.insert(vecin);
            }
        }
    }


    for( int i = 2 ; i <= n ; i++ )
        fout << dist[i] << " ";
    return 0;
}
