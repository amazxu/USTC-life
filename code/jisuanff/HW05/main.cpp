#include <stdio.h>
#include <math.h>
#define epsilon 0.00000001

double f(double x){
    return pow(x, 3)/3 - x;
}
double tf(double x){
    return pow(x, 2) -1;
}
double Newton_g(double x){
    return x - f(x)/tf(x);
}
double StringCut_g(double x1, double x2){
    double x3 = x2 - f(x2)*(x2-x1)/(f(x2)-f(x1));
    return x3;
}
int main() {
    double Newton_Array[]={ 0.1, 0.2, 0.9, 9.0 };
    double StringCut_Array[][2]={ {-0.1, 0.1}, {-0.2, 0.2}, {-2, 0.9}, {0.9, 9} };
    double x1, x2, x3, x[4], y[4];
    int counter1[4]= {0, 0, 0, 0}, counter2[4]={1, 1, 1, 1};

    for(int i =0 ;i <4;i++){
        x1=Newton_Array[i];
    while(fabs(f(x1)) > epsilon)
        {
        x2=Newton_g(x1);
        x1 = x2;
        counter1[i]++;
        x[i] = x1;
        }
    }

    for(int i=0; i<4; i++){
        x1=StringCut_Array[i][0];
        x2=StringCut_Array[i][1];
        y[i] = StringCut_g(x1, x2);
        while(fabs(f(y[i])) > epsilon){
            counter2[i]++;
            x1 = x2;
            x2 = y[i];
            y[i] = StringCut_g(x1, x2);
        }
    }
    printf("Newton\n");
    for(int i=0;i<4;i++)
        printf("初值 = %.15f, 根 = %.15f, 迭代步数 = %d\n", Newton_Array[i], x[i], counter1[i]);
    printf("弦截法\n");
    for(int i=0;i<4;i++)
        printf("x0=%.1f, x1=%.1f, 根 = %.15f, 迭代步数 = %d\n", StringCut_Array[i][0], StringCut_Array[i][1], y[i], counter2[i]);
    //return 0;
}