/*
문제
길이가 N인 수식이 있다. 수식은 0보다 크거나 같고, 9보다 작거나 같은 정수와 연산자(+, -, ×)로 이루어져 있다.
연산자 우선순위는 모두 동일하기 때문에, 수식을 계산할 때는 왼쪽에서부터 순서대로 계산해야 한다.
예를 들어, 3+8×7-9×2의 결과는 136이다.

수식에 괄호를 추가하면, 괄호 안에 들어있는 식은 먼저 계산해야 한다. 단, 괄호 안에는 연산자가 하나만 들어 있어야 한다.
예를 들어, 3+8×7-9×2에 괄호를 3+(8×7)-(9×2)와 같이 추가했으면, 식의 결과는 41이 된다. 하지만, 중첩된 괄호는 사용할 수 없다.
즉, 3+((8×7)-9)×2, 3+((8×7)-(9×2))은 모두 괄호 안에 괄호가 있기 때문에, 올바른 식이 아니다.

수식이 주어졌을 때, 괄호를 적절히 추가해 만들 수 있는 식의 결과의 최댓값을 구하는 프로그램을 작성하시오.
추가하는 괄호 개수의 제한은 없으며, 추가하지 않아도 된다.

입력
첫째 줄에 수식의 길이 N(1 ≤ N ≤ 19)가 주어진다. 둘째 줄에는 수식이 주어진다. 수식에 포함된 정수는 모두 0보다 크거나 같고,
9보다 작거나 같다. 문자열은 정수로 시작하고, 연산자와 정수가 번갈아가면서 나온다. 연산자는 +, -, * 중 하나이다.
여기서 *는 곱하기 연산을 나타내는 × 연산이다. 항상 올바른 수식만 주어지기 때문에, N은 홀수이다.

출력
첫째 줄에 괄호를 적절히 추가해서 얻을 수 있는 결과의 최댓값을 출력한다. 정답은 231보다 작고, -231보다 크다.
*/

#include <iostream>
#include <cstring>

#define PLUS '+'
#define MINUS '-'
#define MUL '*'
#define MIN_INT -2147483648

int N;
int num[10];
char op[9];
bool branket[9]={false,};
bool w_branket[9];
int result=MIN_INT;

inline int operation(int a,int b,char op);
void dfs(int idx);
int calc();

void printExpression();

int main()
{
    //printf("lol\n");
    scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
        if(i%2==0)
        {
            //printf("num:");
            scanf("%d",&num[i/2]);
            //dp[i/2][i/2]=num[i/2];
        }
        else
        {
            //printf("op:");
            scanf("%c",&op[i/2]);
        }
    }

    dfs(0);
    printExpression();

    //printf("calc:%d\n",calc());
    printf("%d\n",result);
}

void dfs(int idx)
{
    if(idx==N-1)
    {
        int c = calc();

        if(c>result)
            std::copy(branket,branket+N/2,w_branket);

        result=std::max(result,calc());
        printf("\n");
        return;
    }
    else
    {
        if(idx==0||!branket[idx-1])
        {
            branket[idx]=true;
            dfs(idx+1);
            branket[idx]=false;
            dfs(idx+1);
        }
        else
        {
            dfs(idx+1);
        }
    }
}

int calc()
{
    int temp[10];
    std::copy(num,num+N/2+N%2,temp);
    int result;
    for(int i=0;i<N/2;i++)
    {
        if(branket[i])
        {
            temp[i]=operation(temp[i],temp[i+1],op[i]);
            //temp[i]=temp[i+1];
        }
    }

    result = temp[0];

    //printf("result:%d\n",result);

    for(int i=0;i<N/2;i++)
    {
        if(!branket[i])
        {
            result=operation(result,temp[i+1],op[i]);
            //printf("%d %d result:%d\n",N/2,i,result);
        }
    }
    return result;
}

inline int operation(int a,int b,char op)
{
    switch(op)
    {
    case PLUS:
        return a+b;
        break;
    case MINUS:
        return a-b;
        break;
    case MUL:
        return a*b;
        break;
    }
}


void printExpression()
{
    bool br=false;
    printf("expression : ");
    for(int i=0;i<N;i++)
    {

        if(i%2==0)
        {

            if(w_branket[i/2])
            {
                br=true;
                printf("(");
                printf("%d",num[i/2]);
            } else if(br)
            {
                printf("%d",num[i/2]);
                printf(")");
                br=false;
            }
            else
            {
                printf("%d",num[i/2]);
            }


        }
        else
            printf("%c",op[i/2]);
    }
    printf("\n");

    for(int i=0;i<N/2;i++)
    {
        if(w_branket[i])
            printf("o ");
        else
            printf("x ");
    }
    printf("\n");
}
