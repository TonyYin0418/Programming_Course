#include "Framework.h"

class MyWindow: public Window
{
public:
    MyWindow(const char* title) : Window(title) {}
    void show_window()
    {
        cout<<"Mywindow \""<<window_title<<"\" is displayed!"<<endl;
    }
    void on_mouse_click(int x,int y)
    {
        cout << "Mywindow mouse_click\n";
        return;
    }

    void on_key(char c)
    {
        cout << "Mywindow key\n";
        return;
    }

    ~MyWindow() {
        cout << "Mywindow destroyed\n";
    }
    /*构造Window的派生类MyWindow，使其：
        1. 处理键盘或鼠标的消息时，在屏幕上显示相关的提示信息
        2. 对象销毁时在屏幕上显示相关的提示信息*/
};

class MyApp: public Application
{
public:
    void initialize()
    {
        main_window=new MyWindow("New MyWindow");
        main_window->show_window();
    }
    void on_message_quit()
    {
        cout << "MyApp quit\n";
        end_app=true;
        delete main_window;
    }
    /*构造Application的派生类MyApp，使其：
        1. 初始化时创建MyWindow类型的窗口对象，而非Window类型的窗口对象
        2. 处理退出消息时，在屏幕上显示相关的提示信息*/
};

MyApp _my_app;
