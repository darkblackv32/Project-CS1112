#include <iostream>
using namespace std;

string generarador_id() {
  string id = "";
  for (int i = 0; i < 8; i++) {
    id += (char)(rand() % ('z' - 'a')) + 'a';
  }
  return id;
}