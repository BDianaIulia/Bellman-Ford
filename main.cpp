#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <fstream>
#define maxi 50001
#define infinite 99999999

using namespace std;

ifstream fin("bellmanford.in");
ofstream fout("bellmanford.out");

vector< tuple<int,int,int> > L;
int dist[maxi];
int n, m , x, y ,c;


int main()
{
    fin >> n >> m;
    for( int i = 1 ; i <= m ; i++ )
    {
        fin >> x >> y >> c;
        L.push_back( make_tuple(x, y , c) );
    }

    for( int i = 1 ; i <= n ; i++ )
            dist[i] = infinite;

    dist[1] = 0;

    for( int i = 1 ; i < n ; i++ )
    {
        for( auto it : L )
        {
            int src , dest, cost;
            tie(src, dest, cost) = it;
            dist[dest] = min( dist[dest] , dist[src] + cost );
        }
    }

    for( auto it : L )
    {
        int src , dest, cost;
        tie(src, dest, cost) = it;
        if( dist[dest] > dist[src] + cost )
        {
            fout << "Ciclu negativ!";
            return 0;
        }
    }

    for( int i = 2 ; i <= n ; i++ )
        fout << dist[i] << " ";
    return 0;
}
