#include <iostream>
#include <string>
using namespace std;

string random(int x) {
  char alphabet[47] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                       'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                       'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6',
                       '7', '8', '9', '!', '@', '#', '$', '%', '^', '&', '*'};
  string out;
  string randomchar;
  out += alphabet[rand() % 47];
  for(int a = 1; a <= x; a++) {
    randomchar = alphabet[rand() % 47];
    if(randomchar == out.substr(a-1, a)) {
      a--;
      continue;
    } else {
      out.append(randomchar);
    }
  }
  return out;
}

int main() {
  int length;
  cin >> length;
  srand(time(NULL));
  string result = random(length);
  cout << result << endl;
  return 0;
}
