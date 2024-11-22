//
//  main.cpp
//  Exp1
//
//  Created by TonyYin on 2024/10/29.
//

#include <iostream>

using namespace std;

const double pi = 3.1415926;

void solve_2_3() {
    int opt;
    double a, b;
    cout << "1. Circle\n2. Rectangle\n3. Square\n" << endl;
    cout << "Enter your choice (1/2/3): \n";
    cin >> opt;
    if(opt == 1) {
        cout << "Enter the radius: "; cin >> a;
        cout << "Area = " << pi * a * a << endl;
    } else if(opt == 2) {
        cout << "Enter the length "; cin >> a;
        cout << "Enter the width "; cin >> b;
        cout << "Area = " << a * b << endl;
    } else if(opt == 3) {
        cout << "Enter the length "; cin >> a;
        cout << "Area = " << a * a << endl;
    }
}
void solve_2_5() {
    struct Time {
        int year, month, day, hour, minute, second;
    } t;
    printf("请输入时间：年 月 日 时 分 秒\n");
    scanf("%d%d%d%d%d%d", &t.year, &t.month, &t.day, &t.hour, &t.minute, &t.second);
    printf("%04d年%02d月%02d日 %02d时%02d分%02d秒\n", t.year, t.month, t.day, t.hour, t.minute, t.second);
}
void solve_2_6() {
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            printf("%2d ", i * j);
        } cout << endl;
    }
}
const int N = 1357;

void solve_2_7() {
    char p[5], q[5];
    cin >> p;
    int n = N, tmp = 1000;
    for(int i = 0; i < 4; i++) {
        q[i] = n/tmp+'0';
        n -= tmp * (q[i]-'0');
        tmp /= 10;
    }
    int a = 0, b = 0;
    for(int i = 0; i < 4; i++)
        if(p[i] == q[i]) a++;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) if(i != j){
            if(p[i] == q[j]) {
                b++;
                break;
            }
        }
    }
    printf("%dA%dB\n", a, b);
}
double solve_3_1(double F) {
    return (F-32.0)*5.0/9.0;
}

int Max1(int a, int b) {
    return (a > b) ? a : b;
}
int Max1(int a, int b, int c) {
    int t = (a > b) ? a : b;
    return (t > c) ? t : c;
}
double Max1(double a, double b) {
    return (a > b) ? a : b;
}

int Fib(int x) {
    if(x == 1 || x == 2) return 1;
    return Fib(x - 1) + Fib(x - 2);
}

inline int toUpper(int c) {
    if('a'<=c && c<='z') return c-'a'+'A';
    else return c;
}
inline int toLower(int c) {
    if('A'<=c && c<='Z') return c-'A'+'a';
    else return c;
}

void solve_3_4() {
    int ch = getchar(), flag = 1;
    while(ch != '.') {
        if(flag == 1) ch = toUpper(ch);
        else ch = toLower(ch);
        flag = 0;
        if(ch == ' ') flag = 1;
        putchar(ch); ch = getchar();
    }
}

bool check_3_5(char *p, char *q) {
    int a = 0, b = 0;
    for(int i = 0; i < 4; i++)
        if(p[i] == q[i]) a++;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) if(i != j){
            if(p[i] == q[j]) {
                b++;
                break;
            }
        }
    }
    printf("%dA%dB\n", a, b);
    return (a == 4);
}
void solve_3_5() {
    char p[5], q[5];
    int n = N, tmp = 1000, cnt = 1;
    for(int i = 0; i < 4; i++) {
        q[i] = n/tmp+'0';
        n -= tmp * (q[i]-'0');
        tmp /= 10;
    }
    cin >> p;
    while(!check_3_5(p, q)) {
        cnt++;
        cin >> p;
    }
    cout << "猜测次数 = " << cnt << endl;
}

int main() {
    solve_3_5();
    return 0;
}
