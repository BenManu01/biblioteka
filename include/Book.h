#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Book {

public:
  string name;
  string author;
  string isbn;
  vector<string> genres;

  bool available = true;

  Book(string name, string author, string isbn, vector<string> genres){
    this->name = name;
    this->author = author;
    this->isbn = isbn;
    this->genres = genres;
  }

  Book(string line){
    vector<int> collumns;
    for(int i = 0; i < line.length(); i++){
      if(line[i] == ';'){
        collumns.push_back(i);
        if (collumns.size() == 1){
          name = line.substr(0, collumns[0]);
        }
        else if (collumns.size() == 2){
          author = line.substr(collumns[0] + 1, collumns[1] - collumns[0] - 1);
        }
        else if (collumns.size() == 3){
          isbn = line.substr(collumns[1] + 1, collumns[2] - collumns[1] - 1);
        }
        else if (collumns.size() == 4){
          vector<string> genres;
          collumns.clear();
          string genres_line = line.substr(collumns[2] + 1, collumns[3] - collumns[2]);
          //cout << genres_line << endl;
          for(int i = 0; i < genres_line.length(); i++){
            if(genres_line[i] == ','){
              collumns.push_back(i);
              if (collumns.size() == 1){ //pierwszy przecinek
                genres.push_back(genres_line.substr(0, collumns[0]));
              }
              else if (collumns.size() == 2){ //drugi przecinek
                genres.push_back(genres_line.substr(collumns[0] + 1, collumns[1] - collumns[0] - 1));
              }
            }
            else if(genres_line[i] == ';'){
               collumns.push_back(i);
               genres.push_back(genres_line.substr(collumns[collumns.size() - 2] + 1, genres_line.length() - collumns[collumns.size() - 2] -2));
            }
          }
          this->genres = genres;
        }
      }
    }
  }

  void changeStatus(){
    available = !available;
  }

  friend ostream& operator<<(ostream& os, Book& obj) {
    os << "Name: " << obj.name << ", Author: " << obj.author << ", Isbn: " << obj.isbn <<  ", Genres: " << obj.vectorToText() << "Status: " << obj.available;
    return os;
  }
private:
  string vectorToText(){
    string result;
    for(int i = 0; i < genres.size(); i++){
       result += genres[i] + ", ";
    }
    return result;
  }
};
