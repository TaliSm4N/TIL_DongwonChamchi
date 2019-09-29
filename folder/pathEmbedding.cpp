#include <iostream>
#include <queue>

//아이디어 막힌듯 시간 제한내로 못풀 것같음
struct Edge
{
    int u;
    int v;
};

int main()
{
    int n;
    Edge e[100000];
    int v[100000];
    bool visit[100000];
    std::queue<int> target;
    std::queue<len> length;

    std::cin>>n;

    for(int i=0;i<n-1;i++)
    {
        std::cin>>e[i].u>>e[i].v;
    }

    for(int i=0;i<n;i++)
    {
        std::cin>>v[i];
    }

    for(int i=0;i<n-1;i++)
    {
        int now=v[i];
        int len=0;
        visit[now]=true;
        while(len<=3&&!target.empty())
        {
            for(int j=0;j<n-1;j++)
            {
                if(e[j].u==now&&!visit[e[j].v])
                {
                    target.push(e[j].v);
                    length.push(len+1);
                    visit[e[j].v]=true;
                }
                else if(e[j].v==now&&!visit[e[j].u])
                {
                    target.push(e[j].u);
                    length.push(len+1);
                    visit[e[j].u]=true;
                }
            }

        }
    }

}
