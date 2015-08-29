/* This file is for Dudu's bitwise example
 * Copyright Heng Xiao: hengxiao@hengxiao.net
 */
#include <iostream>
#include <string>

using namespace std;

enum Incomplete {
  NONE = 0,
  FIRST_PAGE = 1,
  SECOND_PAGE = 1 << 1,
  THIRD_PAGE = 1 << 2,
};

int readBitwise(char *arg) {
  int input;
  try {
    input = stoi(string(arg));
  } catch (exception e) {
    cerr << "ERROR: input invalid" << endl;
    return -2;
  }					       
  cout << "input is " << input << "." << endl;
  if (input > ((1 << 3) - 1)) {
    cerr << "ERROR: input invalid" << endl;
    return -3;
  }
  cout << "First page is " << ((input & FIRST_PAGE) ? "INCOMPLETE" : "COMPLETED") << endl;
  cout << "Second page is " << ((input & SECOND_PAGE) ? "INCOMPLETE" : "COMPLETED") << endl;
  cout << "Third page is " << ((input & THIRD_PAGE) ? "INCOMPLETE" : "COMPLETED") << endl;
}

enum Result {
  NO = 0,
  YES = 1,
  INVALID = -1,
};
  

void writeBitwise() {
  int result = 0;
  Result completed = INVALID;
  string resultStr;
  while (completed == INVALID) {
    cout << "Is first page completed? (yn): ";
    cin >> resultStr;
    if (resultStr == "y") {
      completed = YES;
    } else if (resultStr == "n") {
      completed = NO;
    }
  }
  if (completed == NO) {
    result |= FIRST_PAGE;
  }

  completed = INVALID;
  while (completed == INVALID) {
    cout << "Is second page completed? (yn): ";
    cin >> resultStr;
    if (resultStr == "y") {
      completed = YES;
    } else if (resultStr == "n") {
      completed = NO;
    }
  }
  if (completed == NO) {
    result |= SECOND_PAGE;
  }

  completed = INVALID;
  while (completed == INVALID) {
    cout << "Is third page completed? (yn): ";
    cin >> resultStr;
    if (resultStr == "y") {
      completed = YES;
    } else if (resultStr == "n") {
      completed = NO;
    }
  }
  if (completed == NO) {
    result |= THIRD_PAGE;
  }

  cout << "Result is " << result << "." << endl;
}

int main(int argc, char **argv) {
  switch (argc) {
  case 1:
    writeBitwise();
    break;
  case 2:
    readBitwise(argv[1]);
    break;
  default:
    cerr << "ERROR: input invalid" << endl;
    return -1;
  }
  return 0;
}

