//PasswordManager.h
//Yousif Al Saadi
//No Collaborators 
//03-19-2022
//PA4
//CS 2308 Spring 2022
//setting up the class function.


#include <iostream>
#include <string.h>

using namespace std;

class PasswordManager{

public: 
  void setUsername(string);
  string getUsername() const;
  void setEncryptedPassword(string);
  string getEncryptedPassword() const;
  bool setNewPassword(string);
  bool authenticate(string);
  

private: 
  string userName;
  string encryptedPass;
  string encrypt(string);
  bool meetsCriteria(string);


};
