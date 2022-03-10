#include <iostream>
#include<windows.h>
using namespace std;

int main()
{
    int step = 100;
    long long freq,head,tail;
    for(int n = 100;n <= 10000;n += step){
        int* a = new int [n];
        int** b = new int* [n];
        int* sum = new int [n];

        /*赋初值*/
        for(int i = 0;i < n;i ++){
            a[i] = i + 1;
            b[i] = new int [n];
            for(int j = 0;j < n;j ++) b[i][j] = i + j;
        }
        /*当n小于1000时需要重复计算取平均值*/
        if(n < 1000) freq = 40000/n;
        else freq = 1;
        /*QueryPerformanceFrequency((LARGE_INTEGER *)&freq);*/
        QueryPerformanceCounter((LARGE_INTEGER *)&head);
        for(int f = 0;f < freq;f++){
            for(int i = 0;i < n;i ++) sum[i] = 0;
            for(int j = 0;j < n;j ++){
                for(int i = 0;i < n;i ++) sum[i] += b[j][i] * a[j];
            }
        }
        QueryPerformanceCounter((LARGE_INTEGER *)&tail);
        cout<<n<<" "<<freq<<" "<<(tail - head)/ freq<<"ms"<<endl;
        if(n >= 1000) step = 1000;
    }

    return 0;
}
