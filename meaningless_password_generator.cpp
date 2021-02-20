#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

static void show_usage(string name) {
  cerr << "Usage: " << name << " {OPTION} [VALUE]" << endl
                    << "{-h | --help}" << endl
                    << "{-l | --length} [value]" << endl;
}

string random(int x) {                                                          //string randomizer
  char charList[71] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                       'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                       'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                       'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                       'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2',
                       '3', '4', '5', '6', '7', '8', '9', '!', '@', '#', '$',
                       '%', '^', '&', '*'};
  string out;
  string randomChar;
  if(x != 0) {
    out += charList[rand() % 71];
  }
  for(int a = 1; a < x; a++) {                                                  //generate x characters randomly
    randomChar = charList[rand() % 71];
    if(randomChar == out.substr(a-1, a)) {                                      //check if the random character is the same as the previous one
      a--;
      continue;
    } else {
      out.append(randomChar);
    }
  }
  return out;
}

int main(int argc, char* argv[]) {
  int length;
  if(argc == 1) {
    cerr << "No parameters detected." << endl;
    show_usage(argv[0]);
    return 1;
  } else if(argc > 3) {
    cerr << "Too many parameters." << endl;
    show_usage(argv[0]);
    return 1;
  } else {
    if(strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--length") == 0) {        //-l or --length
      if(argc == 2) {
        cout << "No value detected." << endl;
        show_usage(argv[0]);
        return 1;
      } else {
        length = atoi(argv[2]);
        srand(time(NULL));
        string result = random(length);                                         //using the randomizer function to generate a password string
        cout << result << endl;
        ofstream pwd_file;                                                      //save the password string to password.txt file
        pwd_file.open("password.txt");
        pwd_file << result;
        pwd_file.close();
      }
    } else if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {   //-h or --help
      show_usage(argv[0]);
    } else {
      show_usage(argv[0]);
      return 1;
    }
  }

  return 0;
}
