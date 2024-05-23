#include "Test.h"

void Test::allTest(){
  clientTest();
}

void Test::clientTest(){
  Library lib;

  Client client;

  Book* a = new Book("abcdcda", "sdgf", "1", {"ab", "abc"});
  Book* b = new Book("erty", "ssdf", "2", {"ab", "abc"});
  Book* c = new Book("abc", "sdgsdfhf", "3", {"ab", "abc"});

  lib.add(a);
  lib.add(b);
  lib.add(c);

  //lib.changeStatus(lib.search("ab"));
  lib.print();
  cout << "-------------------------------" << endl;

  client.borrowBook(&lib, b);

  lib.print();
  cout << "-------------------------------" << endl;
  client.print();
  client.returnBook(&lib, b);
  cout << "-------------------------------" << endl;
  lib.print();
  cout << "-------------------------------" << endl;
  client.print();
}

void Test::bookLoadTest(){
  string line1 = "To Kill a Mockingbird;J.D. Salinger;9783622859259;Fantasy,Science Fiction;";
  string line2 = "1984;Harper Lee;9780228815409;Thriller,Science Fiction,Fiction;";
  string line3 = "The Great Gatsby;George Orwell;9781476746461;Fantasy,Fiction,Science Fiction;";

  Book a(line1);
  Book b(line2);
  Book c(line3);

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
}
