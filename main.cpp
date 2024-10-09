#include "USBConnection.h"
#include <iostream>

int main() {
    auto conn1 = USBConnection::create();
    auto conn2 = USBConnection::create();
    auto conn3 = USBConnection::create();
    auto conn4 = USBConnection::create(); 

    if (conn4 == nullptr) {
        std::cout << "No available ports!" << std::endl;
    }

    conn1.reset();
    conn4 = USBConnection::create();

    if (conn4 != nullptr) {
        std::cout << "Port available for conn4!" << std::endl;
    }

    return 0;
}
