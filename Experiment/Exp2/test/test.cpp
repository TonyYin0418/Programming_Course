//
//  test.cpp
//  test
//
//  Created by TonyYin on 2024/11/2.
//

#include <iostream>
#include "client.h"

using namespace std;

int main() {
    CLIENT a("abcde");
    cout << CLIENT::getClientNum() << endl;
    CLIENT b("edcba");
    cout << CLIENT::getClientNum() << endl;
    a.changeServerName("aaaaa");
    cout << CLIENT::getClientNum() << endl;
    return 0;
}
