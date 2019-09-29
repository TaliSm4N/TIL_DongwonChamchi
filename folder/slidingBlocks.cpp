#include <iostream>

#define R_P(x) (rect[x].w+rect[x].x)
#define U_P(y) (rect[y].h+rect[y].y)

//덜품
struct Rect
{
    int w;
    int h;
    int x;
    int y;
    int d_x;
    int d_y;
};

std::istream& operator>>(std::istream& is, Rect& rect)
{
    is>>rect.w>>rect.h>>rect.x>>rect.y>>rect.d_x>>rect.d_y;
    return is;
}

std::ostream& operator<<(std::ostream& os, Rect& rect)
{
    os<<rect.w<<" "<<rect.h<<" "<<rect.x<<" "<<rect.y<<" "<<rect.d_x<<" "<<rect.d_y<<std::endl;
    return os;
}

int main()
{
    int n;
    std::cin>>n;
    Rect rect[1000];
    Rect moveRect;
    bool move = true;

    for(int i=0;i<n;i++)
    {
        std::cin>>rect[i];
    }

    for(int i=0;i<n;i++)
    {
        //첫번째 사각형 구석에 넣기
        if(i==0)
        {
            rect[i].x=0;
            rect[i].y=0;
            rect[i].d_x=0;
            rect[i].d_y=0;
            continue;
        }
        moveRect=rect[i];
        while(move)
        {
            if(rect[i].x-rect[i].d_x>0)
            {
                rect[i].x=0;
                rect[i].d_x=0;
            }
            if(rect[i].y-rect[i].d_y>0)
            {
                rect[i].y=0;
                rect[i].d_y=0;
            }

            for(int j=i-1;j>0;j--)
            {

            }
        }
        move = true;
    }

    for(int i=0;i<n;i++)
    {
        std::cout<<rect[i];
    }

    std::cout<<rect[n-1].x<<' '<<rect[n-1].y<<std::endl;
}
