#ifndef utilH
#define utilH
#include <string>
#include <vector>
using namespace std;

string tolowercase(string s);
vector<string> split(string str, char delimiter);
unsigned int ipv4AsBits(string ip);
string ipv4AsBitsString(string ip);
#endif
