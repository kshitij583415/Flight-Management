#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

string displaytime()
{
    // Assuming you have a function to get the current time as a string
    // Replace this with your own implementation
    time_t now = time(nullptr);
    tm *ptm = localtime(&now);
    char buffer[32];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ptm);
    return buffer;
}
