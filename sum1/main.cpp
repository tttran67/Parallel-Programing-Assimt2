#include <iostream>
#include<windows.h>
using namespace std;

int main()
{
    int step = 100;
    long long freq,head,tail;
    float sum = 0;
    for(int n = 100;n <= 10000;n += step){
        float* a = new float [n];

        /*赋初值*/
        for(int i = 0;i < n;i ++) a[i] = i + 0.9;
        /*当n小于1000时需要重复计算取平均值*/
        if(n < 1000) freq = 40000/n;
        else freq = 1;
        /*QueryPerformanceFrequency((LARGE_INTEGER *)&freq);*/
        QueryPerformanceCounter((LARGE_INTEGER *)&head);
        for(int f = 0;f < freq;f++){
            for(int i = 0;i < n;i ++) sum += a[i];
        }
        QueryPerformanceCounter((LARGE_INTEGER *)&tail);
        cout<<n<<" "<<freq<<" "<<(tail - head) / (freq * 10000.0)<<"ms"<<endl;
        if(n >= 1000) step = 1000;
    }

    return 0;
}
