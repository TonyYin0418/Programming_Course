#include <iostream>
#include <string>
using namespace std;

enum CPU_Rank {P1=1,P2,P3,P4,P5,P6,P7};
class CPU2{
private:
//    CPU_Rank rank;
    int frequency;
    double voltage;
public:
    CPU2(int f, float v)
    :frequency(f), voltage(v) {
        cout << "CPU 构造函数" << endl;
    }
    ~CPU2() { cout << "CPU 析构函数" << endl; }
};

class CPU {
public:
    CPU(string x) : x(x) { cout << "CPU 构造函数" << endl; }
    ~CPU() { cout << "CPU 析构函数" << endl; }
    void show() const { cout << "CPU show: " << x << endl; }
private:
    string x;
};

class RAM {
public:
    RAM(int x) : x(x) { cout << "RAM 构造函数" << endl; }
    ~RAM() { cout << "RAM 析构函数" << endl; }
    void show() const { cout << "RAM show: " << x << endl; }
private:
    int x;
};

class CDROM {
public:
    CDROM(string x) : x(x) { cout << "CDROM 构造函数" << endl; }
    ~CDROM() { cout << "CDROM 析构函数" << endl; }
    void show() const { cout << "CDROM show: " << x << endl; }
private:
    string x;
};

class Computer {
public:
    Computer(CPU cpu, RAM ram, CDROM cdrom)
        : cpu(cpu), ram(ram), cdrom(cdrom) {
        cout << "Computer 构造函数" << endl;
    }
    ~Computer() {
        cout << "Computer 析构函数" << endl;
    }
    void run() {
        cout << "Computer run" << endl;
        cpu.show();
        ram.show();
        cdrom.show();
    }
    void stop() {
        cout << "Computer stop" << endl;
    }
private:
    CPU cpu;
    RAM ram;
    CDROM cdrom;
};

void solve_4_2() {
    CPU myCPU("abcde");
    RAM myRAM(10010);
    CDROM myCDROM("edcba");
    Computer myComputer(myCPU, myRAM, myCDROM);
    myComputer.run();
    myComputer.stop();
}

class Date {
public:
    Date(int _year, int _month, int _day) : year(_year), month(_month), day(_day) {}
    Date(const Date &_date) : year(_date.year), month(_date.year), day(_date.day) {}
    inline void show() {
        cout << year << "-" << month << "-" << day << endl;
    }
    ~Date() {}
private:
    int year, month, day;
};

class People{
public:
    People(int _number, int _sex, int _id, Date _birthdate) : number(_number), sex(_sex), id(_id), birthdate(_birthdate) {}
    inline void show() const {
        //xxx
        //xxx
        //xxx
    }
private:
    int number, sex, id;
    Date birthdate;
};


int main() {
    CPU cpu("dbnskdsk");
    RAM ram(134);
    CDROM cdrom("sfdhksajl");
    Computer(cpu, ram, cdrom);

    return 0;
}
