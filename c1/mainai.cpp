#include <QApplication>
#include"win1.h"
#include<chrono>
#include"QDebug"
long long int timestamp_ms;
int mainai() {

    auto now = std::chrono::system_clock::now();
    timestamp_ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    return 1;
}
