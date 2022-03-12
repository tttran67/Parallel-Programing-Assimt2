#include <iostream>
#include<windows.h>
using namespace std;
int step = 100,i,j,n,f,freq;
void col_major(int n,float* &sum,float* &a,float** &b){
    for(i = 0;i < n;i ++){
        sum[i] = 0.0;
        for(j = 0;j < n;j ++) sum[i] += b[j][i] * a[j];
    }
}
void row_major(int n,float* &sum,float* &a,float** &b){
    for(i = 0;i < n;i++) sum[i] = 0.0;
    for(j = 0;j < n;j++)
        for(i = 0;i < n;i++) sum[i] += b[j][i] * a[j];
}
int main()
{
    long long head,tail;
    for(n = 100;n <= 10000;n += step){
        float* a = new float [n];
        float** b = new float* [n];
        float* sum = new float [n];

        /*赋初值*/
        for(i = 0;i < n;i ++){
            a[i] = i + 0.9;
            b[i] = new float [n];
            for(j = 0;j < n;j ++) b[i][j] = i + j + 0.2;
        }
        /*当n小于1000时需要重复计算取平均值*/
        if(n < 1000) freq = 40000/n;
        else freq = 1;
        QueryPerformanceCounter((LARGE_INTEGER *)&head);
        for(f = 0;f < freq;f++){
            col_major(n,sum,a,b);
        }
        QueryPerformanceCounter((LARGE_INTEGER *)&tail);
        cout<<n<<" "<<freq<<" "<<(tail - head) / (freq * 10000.0)<<"ms"<<endl;
        QueryPerformanceCounter((LARGE_INTEGER *)&head);
        for(f = 0;f < freq;f++){
            row_major(n,sum,a,b);
        }
        QueryPerformanceCounter((LARGE_INTEGER *)&tail);
        cout<<n<<" "<<freq<<" "<<(tail - head) / (freq * 10000.0)<<"ms"<<endl;
        if(n >= 1000) step = 1000;
    }
    return 0;
}
