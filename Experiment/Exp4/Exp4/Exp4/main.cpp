//
//  main.cpp
//  Exp4
//
//  Created by TonyYin on 2024/11/8.
//

#include <iostream>

using namespace std;

//(1)
class Animal {
public:
    int age;
public:
    Animal(int a = 0) : age(a) {}
    int getAge() const { return age; }
};
class dog : public Animal {
public:
    void setAge(int n) {
        age = n;
    }
};

//(2)
class BaseClass {
public:
    int Number;
    BaseClass(int num) : Number(num) {
        cout << "BaseClass construct\n";
    }
    ~BaseClass() {
        cout << "Baseclass destruct\n";
    }
};
class DerivedClass : public BaseClass{
    DerivedClass(int num) : BaseClass(num) {
        cout << "DerivedClass construct\n";
    }
    ~DerivedClass() {
        cout << "DerivedClass destruct\n";
    }
};

//(3)
class Vehicle {
public:
    int maxSpeed, weight;
    Vehicle(int speed = 0, double w = 0.0) : maxSpeed(speed), weight(w) {
        cout << "Vehicle constructor called.\n";
    }
    virtual void run() const {
        cout << "Vehicle : run()\n";
    }
    virtual void stop() const {
        cout << "Vehicle : stop()\n";
    }
    virtual ~Vehicle() {
        cout << "Vehicle destructor called.\n";
    }
};

class Bicycle : public virtual Vehicle {
public:
    int height;
    Bicycle(int _s, int _w, int _h) : Vehicle(_s, _w), height(_h) {
        cout << "Bicycle constructor called.\n";
    }
    void run() { cout << "Bicycle : run() \n"; }
    void stop() { cout << "Bicycle: stop() \n"; }
};
class Motorcar : public virtual Vehicle {
public:
    int seatNum;
    Motorcar(int _s, int _w, int _n) : Vehicle(_s, _w), seatNum(_n) {
        cout << "Motorcar constructor called.\n";
    }
    void run() { cout << "Motorcar : run() \n"; }
    void stop() { cout << "Motorcar: stop() \n"; }
};
class Motorcycle : public virtual Bicycle, public virtual Motorcar {
public:
    Motorcycle(int _s, int _w, int _h, int _n) : Vehicle(_s, _w), Bicycle(_s, _w, _h), Motorcar(_s, _w, _n) {
        cout << "Motorcycle constructor called.\n";
    }
    void run() { cout << "Motorcycle : run() \n"; }
    void stop() { cout << "Motorcycle: stop() \n"; }
};
//(4)
class Point {
public:
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
    friend Point& operator++(Point &p) { //前置
        p.x++; p.y++;
        return p;
    }
    friend Point operator++(Point& p, int) { //后置
        Point temp = p;
        p.x++; p.y++;
        return temp;
    }
    friend Point& operator--(Point &p) { //前置
        p.x--; p.y--;
        return p;
    }
    friend Point operator--(Point& p, int) { //后置
        Point temp = p;
        p.x--; p.y--;
        return temp;
    }
    inline void print() const {
        printf("Point(%d, %d)\n", x, y);
    }
};
int main() {
/*
    //7.3
    Vehicle *vehicle1 = new Bicycle(1, 2, 3);
    Vehicle *vehicle2 = new Motorcar(1, 2, 3);
    Vehicle *vehicle3 = new Motorcycle(1, 2, 2, 3);

    vehicle1->run();
    vehicle1->stop();
    vehicle2->run();
    vehicle2->stop();
    vehicle3->run();
    vehicle3->stop();
*/
    
/*
    //7.4
    Point p(3, 4);
    p++;
    p.print();
*/
    return 0;
}
