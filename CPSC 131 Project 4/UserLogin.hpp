#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

class UserLogin {
private:

    unordered_map< string, string > table;


public:
    UserLogin(); // default constructor

    void readIn(const string& filename); // add data from file to hash table

    size_t numberOfUsers(); // return the number of users

    string passWordCheck(const string& userName); // returns the passWord of the given user

    size_t wordBucketIdMethod1(const string& userName); // return the bucket number where the given user is located

    size_t wordBucketIdMethod2(const string& userName); // another way to find the bucket number where the given user is located

    bool validateUser(const string& userName); // look up given user

    bool authenticateUser(const string& userName, const string& passWord);// authenticate given user and password

};

UserLogin::UserLogin() {
}

// COMPLETE THE FOLLOWING FUNCTIONS

void UserLogin::readIn(const string& filename) {

  // TO DO
  std::ifstream file;
  std::string userName;
  std::string passWord;
  file.open(filename);
  if (file)
  {
    while (file >> userName)
    {
      file >> passWord;
      table[userName] = passWord;
    }
  }
}

size_t UserLogin::numberOfUsers() {

  // TO DO
  return table.size();
}

string UserLogin::passWordCheck(const string& userName) {

  // TO DO
  std::unordered_map<std::string,std::string>::const_iterator user = table.find(userName);
  if (user == table.end())
  {
    return "Non-existent User";
  }
  return user->second;
}

size_t UserLogin::wordBucketIdMethod1(const string& userName) {

    // TO DO
    return table.bucket(userName);
}

size_t UserLogin::wordBucketIdMethod2(const string& userName) {

  // TO DO
  unsigned bucketNum = table.bucket_count();
  for (unsigned i = 0; i < bucketNum; i++)
  {
    for (auto iterator = table.begin(i); iterator != table.end(i); iterator++)
    {
      if (iterator->first == userName)
      {
        return i;
      }
    }
  }
}

bool UserLogin::validateUser(const string& userName) {

  // TO DO
  std::unordered_map<std::string,std::string>::const_iterator user = table.find(userName);
  if (user == table.end())
  {
    return false;
  }
  return true;
}

bool UserLogin::authenticateUser(const string& userName, const string& passWord) {

  // TO DO
  std::unordered_map<std::string,std::string>::const_iterator user = table.find(userName);
  if (user == table.end())
  {
    return false;
  }
  if (user->second == passWord)
  {
    return true;
  }
  return false;
 }
