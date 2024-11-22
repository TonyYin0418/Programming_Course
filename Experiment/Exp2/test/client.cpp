//
//  client.cpp
//  Exp2
//
//  Created by TonyYin on 2024/11/2.
//

#include <iostream>
#include "client.h"

int CLIENT::clientNum = 0;
CLIENT::CLIENT(const string& _s) {
    serverName = _s;
    clientNum++;
}
CLIENT::~CLIENT() {
    clientNum--;
}
void CLIENT::changeServerName(string _s) {
    serverName = _s;
}
int CLIENT::getClientNum() const{
    return clientNum;
}
