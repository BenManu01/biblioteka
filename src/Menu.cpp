#include "Menu.h"

void searchMenu(Library *lib, Client *c){
  int option;
  string text;
  vector<Book*> searchResults;
  cout<<"What do you want to search for:"<< endl;
  cout<<"1. title 2. author 3. genre 4. isbn"<< endl;
  cin>>option;
  while(option > 4 || option < 1){
    cout << "Provide number from 1 - 4:" << endl;
    cin>>option;
  }
  cout<<"search: ";
  cin>>text;
  searchResults = lib->search(text, option-1);
  Tools::printWithNumbers(searchResults);
  cout << "What do you want to do: ";
  cout << "1. Borrow 2. Exit";
  cin>>option;
  if(option == 1){
    cout << "Which book would you like to borrow? " << endl;
    cin>>option;
    c->borrowBook(lib, searchResults[option - 1]);
    c->save();
  } else{
    return;
  }
}

void viewMenu(Library *lib, Client *c){
  if(c->books.size() == 0){
    cout << "You don't have any books" << endl;
    return;
  }
  int option;
  string text;
  Tools::printWithNumbers(c->books);
  cout << "What do you want to do: ";
  cout << "1. Return 2. Return All 3. Exit";
  cin>>option;
  if(option == 1){
    cout << "Which book would you like to return? " << endl;
    cin>>option;
    while(option > c->books.size() || option < 1){
      cout << "Provide valid book number:" << endl;
      cin>>option;
    }
    c->returnBook(lib, c->books[option - 1]);
    c->save();
  }else if(option == 2){
    int booksSize = c->books.size();
    for(int i = 0; i < booksSize; i++){
      c->returnBook(lib, c->books[0]);
    }
    c->save();
  } else{
    return;
  }
}

void Menu::menu(){
  Library lib;
  lib.load("books.txt");
  Client c;
  c.load(&lib);

  int option;
  string text;

  while(true){
    cout<<"What do you want to do:"<< endl;
    cout<<"1. Search 2. View your books 3. Exit" << endl;
    cin>>option;

    if(option == 1){
      searchMenu(&lib, &c);
    }else if(option == 2){
      viewMenu(&lib, &c);
    }else if(option == 3){
      return;
    }else{
      cout << "Wrong option" << endl;
    }
  }
}
