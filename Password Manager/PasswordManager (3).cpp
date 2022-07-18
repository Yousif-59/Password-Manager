//PasswordManager.cpp
//Yousif Al Saadi
//No Collaborators 
//03-19-2022
//PA4
//CS 2308 Spring 2022
//The specific part to make any changes and updates.


#include <iostream>
#include <string>
#include "PasswordManager.h"
using namespace std;



// PasswordManager/encrypt: it calculates the new password
// ins: the size of the array 
// returns: it bring back the new password

string PasswordManager:: encrypt(string ins){
  string newPw; 
  for(int index=0; index < ins.length(); index++){
    int val =(ins[index]-33) + 37;
    int val2 = val % 94 + 33;
    char element = (char) val2;
    newPw = newPw + element;
  }
  return newPw;
}

// PasswordManager/meetsCriteria: it check if it meats its criteria
// fm: the string variable 
// returns: it check if it meets criteria, return true else false

bool PasswordManager:: meetsCriteria(string fm){
  bool upper_flag =0, lower_flag = 0, digit_flag = 0, punct_flag = 0;
  int count = 0;
  if (fm.length() < 14 )
    return false;
  else
  for(int index=0; index < fm.length(); index++){
    if (isupper(fm[index]))
    upper_flag = 1;
    if(islower(fm[index]))
    lower_flag = 1;
    if (isdigit(fm[index]))
    digit_flag = 1;
    if (ispunct(fm[index]))
    punct_flag = 1;
    
  }

  if(upper_flag){
    count++;
  }
  if(lower_flag){
    count++;
  }
  if(digit_flag){
    count++;
  }
  if(punct_flag){
    count++;
  }
  
  if (count >=3)
    return true;
  else
    return false;
}


// PasswordManager/setUsername: it sets the user name
// name: the string variable 
// returns: no return



void PasswordManager:: setUsername(string name)
  {
  userName = name;
  }


// PasswordManager/getUsername: getter menas it return the name 
// returns: it returns the username

string PasswordManager:: getUsername() const{
  return userName;
}

// PasswordManager/setEncryptedPassword: it sets the encrypted password
// pw: the string variable 
// returns: no return

void PasswordManager:: setEncryptedPassword(string pw){
  encryptedPass = pw;
}

// PasswordManager/getEncryptedPassword: it get the password and return it
// returns: it returns the encrypted password 


string PasswordManager:: getEncryptedPassword() const{
  return encryptedPass;
}


// PasswordManager/setNewPassword: it sets the new password
// pw: the string variable 
// returns: return true if the password meets criteria else false. 



bool PasswordManager::setNewPassword(string pw){
  if (meetsCriteria(pw)){
  encryptedPass = encrypt(pw);
  return true;
  }
  else
    return false;
}


// PasswordManager/authentication: it return true/false
// pw: the string variable 
// returns: either return true or false


bool PasswordManager:: authenticate(string pw){
  string PWT = encrypt(pw);
    if (PWT == encryptedPass)
      return true;
    else
    return false;
}

