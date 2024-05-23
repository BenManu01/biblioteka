#pragma once

#include <iostream>
#include <cstdio>
#include <vector>
#include "Library.h"

#include <fstream>
#include <sstream>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"


using namespace std;
using namespace rapidjson;

class Client{
public:
  string name = "test";
  string surname = "tests";
  int phone = 123123123;

  vector<Book*> books;

  void borrowBook(Library* l, Book* b);
  void returnBook(Library* l, Book* b);

  void load(Library *lib);
  void save();

  void print();

};

