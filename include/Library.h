#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Book.h"
#include "Tools.h"

using namespace std;

class Library {
public:
  vector<Book*> books;

  void print() const {
    Tools::print(books);
  }

  void add(Book* b) {
    books.push_back(b);
  }

  void changeStatus(vector<Book*> founds) {
    for(int i = 0; i < founds.size(); i++){
      founds[i]->changeStatus();
    }
  }

  void load(string fileName){
    ifstream file(fileName);

    if(file.is_open()){
      string line;
      while(getline(file, line)){
        Book* a = new Book(line);
        add(a);
      }
    }else{
      cout << "error"<< endl;
      return;
    }
    file.close();
  }

  vector<Book*> search(string keyword, int place){
    vector <Book*> founds;
    for(int i = 0; i < books.size(); i++){
      string temp;
      if (place == 0){
        temp = Tools::toLowerCase(books[i]->name);
      }else if (place == 1){
        temp = Tools::toLowerCase(books[i]->author);
      }else if (place == 2){
         for(int j = 0; j < books[i]->genres.size(); j++){
           if(Tools::contains(books[i]->genres[j], Tools::toLowerCase(keyword))){
              founds.push_back(books[i]);
           }
         }
      }else if (place == 3){
        temp = books[i]->isbn;
      }
      if(Tools::contains(temp, Tools::toLowerCase(keyword))){
        founds.push_back(books[i]);
      }
    }
    return founds;
  }
};
