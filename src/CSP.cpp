#include <iostream>
using namespace std;

bool checkCircuit(bool *a, bool *b, bool *c) {
  bool gate1 = a && b;
  bool gate2 = gate1 || c;
  bool gate3 = !gate2;
  return gate3;
}

int main(){
    bool a = true;
    int res = checkCircuit(&a,&a,&a);
    cout << res;
    return res;
    
}

