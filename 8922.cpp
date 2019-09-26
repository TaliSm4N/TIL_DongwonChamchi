/*
문제
두찌 수열은 정수 n-튜플로 이루어진 수열이다. 정수 n-튜플 (a1, a2, ..., an)이 주어졌을 때, 수열에서 다음 수는 인접한 숫자 간의 차이이다.

(a1, a2, ..., an) -> (|a1-a2|, |a2-a3|, ..., |an-a1|)

두찌 수열은 항상 0으로 이루어진 튜플이 나오거나 주기적인 루프를 만나게 된다. 예를 들어, (8, 11, 2, 7)로 시작한 수열은 다음과 같이 5번 만에 0으로 이루어진 튜플이 된다.

(8,11,2,7) -> (3,9,5,1) -> (6,4,4,2) -> (2,0,2,4) -> (2,2,2,2) -> (0,0,0,0)

(4,2,0,2,0)으로 시작한 수열은 2단계 만에 주기적인 루프에 빠진다.

(4,2,0,2,0) -> (2,2,2,2,4) -> (0,0,0,2,2) -> (0,0,2,0,2) -> (0,2,2,2,2) -> (2,0,0,0,2) ->
(2,0,0,2,0) -> (2,0,2,2,2) -> (2,2,0,0,0) -> (0,2,0,0,2) -> (2,2,0,2,2) -> (0,2,2,0,0) ->
(2,0,2,0,0) -> (2,2,2,0,2) -> (0,0,2,2,0) -> (0,2,0,2,0) -> (2,2,2,2,0) -> (0,0,0,2,2) -> ...

n튜플이 주어졌을 때, 이 튜플로 시작하는 수열이 0으로 이루어진 튜플을 만드는지, 주기적인 루프에 빠지는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스의 첫째 줄에는 튜플의 크기 n이 주어진다. (3 ≤ n ≤ 15) 다음 줄에는 n튜플이 주어진다. 주어지는 수는 모두 0보다 크거나 같고, 1000보다 작거나 같다. 두찌 수열이 0을 만나거나, 루프를 만드는데 필요한 최대 단계수는 1,000을 넘지 않는다.

출력
두찌 수열이 루프에 빠지는 경우에는 LOOP, 0을 만나는 경우에는 ZERO를 출력한다.
*/

#include <iostream>
#include <algorithm>
#include <vector>

#define LOOP 1
#define ZERO -1

inline int dif(int a,int b)
{
    if(a-b>0)
        return a-b;
    else
        return b-a;
}

struct Tuple
{
    int item[15];
    int size;

    bool operator ==(Tuple &t)
    {
        for(int i=0;i<size;i++)
        {
            if(item[i]!=t.item[i])
                return false;
        }
        return true;
    }
};

std::vector<Tuple> stage;

bool ZeroTuple(Tuple &tuple)
{
    for(int i=0;i<tuple.size;i++)
    {
        if(tuple.item[i]!=0)
        {
            //printf("tuple.item[%d] %d\n",i,tuple.item[i]);
            return false;
        }
    }
    return true;
}

int next(Tuple &tuple)
{
    int temp = tuple.item[0];

    for(int i=0;i<tuple.size-1;i++)
    {
        tuple.item[i]=dif(tuple.item[i],tuple.item[i+1]);
    }
    tuple.item[tuple.size-1]=dif(tuple.item[tuple.size-1],temp);

    if(ZeroTuple(tuple))
    {
        return ZERO;
    }

    for(int i=0;i<stage.size();i++)
    {
        if(tuple==stage[i])
        {
            //printf("------fuck\n");
            return LOOP;
        }
    }

    stage.push_back(tuple);

    return 0;
}

void printTuple(Tuple &tuple)
{
    printf("(");
    for(int i=0;i<tuple.size;i++)
    {
        printf("%d ",tuple.item[i]);
    }
    printf(")\n");
}

int main()
{
    int T;
    int n;
    Tuple tuple;
    int flag=0;


    scanf("%d",&T);

    while(T-->0)
    {
        scanf("%d",&n);
        tuple.size=n;

        for(int i=0;i<n;i++)
        {
            scanf("%d",&tuple.item[i]);
        }
        //printf("===============\n");

        //printTuple(tuple);

        stage.push_back(tuple);

        while(flag==0)
        {
            flag=next(tuple);
            //printTuple(tuple);
        }
        if(flag==ZERO)
            printf("ZERO\n");
        else if(flag == LOOP)
            printf("LOOP\n");
        flag=0;
        stage.clear();
    }
}