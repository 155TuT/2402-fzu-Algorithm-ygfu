/*
t1 二分法求多项式单根
分数 20
作者 杨起帆
单位 浙大城市学院
二分法求函数根的原理为：如果连续函数f(x)在区间[a,b]的两个端点取值异号，即f(a)f(b)<0，则它在这个区间内至少存在1个根r，即f(r)=0。

二分法的步骤为：

检查区间长度，如果小于给定阈值，则停止，输出区间中点(a+b)/2；否则
如果f(a)f(b)<0，则计算中点的值f((a+b)/2)；
如果f((a+b)/2)正好为0，则(a+b)/2就是要求的根；否则
如果f((a+b)/2)与f(a)同号，则说明根在区间[(a+b)/2,b]，令a=(a+b)/2，重复循环；
如果f((a+b)/2)与f(b)同号，则说明根在区间[a,(a+b)/2]，令b=(a+b)/2，重复循环。
本题目要求编写程序，计算给定3阶多项式f(x)=a3x^3+a2x^2+a1x+a 
0
​
 在给定区间[a,b]内的根。

输入格式：
输入在第1行中顺序给出多项式的4个系数a3、a2、a1、a0，在第2行中顺序给出区间端点a和b。题目保证多项式在给定区间内存在唯一单根。

输出格式：
在一行中输出该多项式在该区间内的根，精确到小数点后2位。

输入样例：
3 -1 -3 1
-0.5 0.5

输出样例：
0.33

代码长度限制 16 KB
时间限制 400 ms
内存限制 64 MB
栈限制 8192 KB
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double a3, a2, a1, a0;
double f(double x){
    return a3 * x * x * x + a2 * x * x + a1 * x + a0;
}
int main(){
    cin >> a3 >> a2 >> a1 >> a0;
    double a, b;
    cin >> a >> b;
    if(a > b)swap(a, b);
    double fa = f(a);
    double fb = f(b);
    const double eps1 = 0.001;
    const double eps2 = 1e-7;
    while(b - a >= eps1){
        double mid = (a + b) / 2;
        double fm = f(mid);
        if(fabs(fm) < eps2){
            a = mid;
            b = mid;
            break;
        }
        if(fa * fm < 0){
            b = mid;
            fb = fm;
        }else{
            a = mid;
            fa = fm;
        }
    }
    double root = (a + b) / 2;
    cout << fixed << setprecision(2) << root << endl;
    return 0;
}