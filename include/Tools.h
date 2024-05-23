#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <vector>
#include "Book.h"

using namespace std;

class Tools {
public:
  static void print(vector<Book*> b);
  static void printWithNumbers(vector<Book*> b);
  static string toLowerCase(string a);
  static bool contains(string a, string b);
  static bool equals(string a, string b);
  static int findIndex(vector<Book*> books, Book* b);
};

#endif // TOOLS_H
