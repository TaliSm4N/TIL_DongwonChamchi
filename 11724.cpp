/*
문제
방향 없는 그래프가 주어졌을 때,
연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다.
(1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다.
(1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

출력
첫째 줄에 연결 요소의 개수를 출력한다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

struct Edge
{
    int start;
    int end;
};

int main()
{
    int N,M;
    Edge e;
    int cnt=0;
    int vertex;
    int p[1001][1001]={0};
    //std::vector<Edge> edgeList;
    //std::queue<int> vertexList;
    //std::vector<Edge>::iterator iter;
    //bool flag[1001]={false,};

    scanf("%d%d",&N,&M);

    for(int i=0;i<M;i++)
    {
        //printf("%d:",i);
        scanf("%d%d",&e.start,&e.end);
        p[e.start][e.end]=1;
        p[e.end][e.start]=1;
        //edgeList.push_back(e);
    }
/*
    while(!edgeList.empty())
    {
        if(vertexList.empty())
        {
            vertexList.push((*edgeList.begin()).start);
            vertexList.push((*edgeList.begin()).end);
            cnt++;
        }
        else
        {
            vertex=vertexList.front();
            flag[vertex]=true;
            vertexList.pop();
            for(iter=edgeList.begin();iter!=edgeList.end();)
            {
                if((*iter).start==vertex)
                {
                    vertexList.push((*iter).end);
                    iter=edgeList.erase(iter);
                }
                else if((*iter).start==vertex)
                {
                    vertexList.push((*iter).start);
                    iter=edgeList.erase(iter);
                }
                else
                {
                    iter++;
                }
            }
        }
        //printf("----\n");
    }

    while(!vertexList.empty())
    {
        flag[vertexList.front()]=true;
        vertexList.pop();
    }

    for(int i=1;i<=N;i++)
    {
        if(!flag[i])
        {
            //printf("i:%d\n",i);
            cnt++;
        }
    }
    */
    printf("%d\n",cnt);
}
