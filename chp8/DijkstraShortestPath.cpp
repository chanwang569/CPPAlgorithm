#include <stdio.h>
#include <limits.h>
#define SIZE 7

int map[SIZE][SIZE];
int dist[SIZE];
int visit[SIZE]; // used for keep distance from one node to other Nodes.
int n;

int dijkstra(int from, int to)
{
     
    for (int i = 1; i <= n; i++)
    {
        // Mark all nodes as not visited
        visit[i] = 0;
        // init distance directly with graph info.
        dist[i] = map[from][i];
    }

    visit[from] = 1;

    int temp = from; // start from  from node. 

    for (int i = 1; i < n; ++i)
    {
        int min = INT_MAX;
       
        int pos = 0; 
        for (int j = 1; j <= n; ++j)
        {
            // To pick a node current node with nearest distance. 
            if (!visit[j] && min > map[temp][j])
            {
                pos = j;
                min = map[temp][j];
            }
        }
        // visit the newly picked node. 
        visit[pos] = 1;

        temp = pos; // next time, we start from the newly picked node. 

        // calculate all none visited node's distance based on newly added node. 
        for (int j = 1; j <= n; ++j)
        {
            if (!visit[j] && (dist[j] > (dist[pos] + map[pos][j])))
            {
                dist[j] = dist[pos] + map[pos][j];
            }
        }
    }

    return dist[to];
}


int main()
{
    int n = 6;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            map[i][j] = INF;
        }
    }

    map[1][2] = 6;
    map[1][3] = 3;
    map[2][3] = 2;
    map[2][4] = 5;
    map[3][4] = 3;
    map[3][5] = 4;
    map[4][5] = 2;
    map[4][6] = 3;
    map[5][6] = 5;

    int temp = INF;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (map[i][j] == temp)
                map[i][j] = map[j][i];
        }
    }

    int ans = dijkstra(1, 6);

    printf("%d", ans);

    return 0;
}

/*  Test Data
1 2 6
1 3 3
2 3 2
2 4 5
3 4 3
3 5 4
4 5 2
4 6 3
5 6 5
*/