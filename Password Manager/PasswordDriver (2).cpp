//PasswordDriver.cpp
//Yousif Al Saadi
//No Collaborators 
//03-19-2022
//PA4
//CS 2308 Spring 2022
//main function for passwords


#include <iostream>
#include <fstream>
#include "PasswordManager.h"
using namespace std;

int main() {
  PasswordManager ins[4]; //creating an array of 4 instances
  string userfile;
  string netid;
  string oldPass;
  string newPass;
  bool check;

  string name; //store usernam from file
  string password; //store password from file

  ifstream fin;

  
  cout << "Please enter the name of the input file:" << endl;
  cin >> userfile;
  fin.open(userfile.c_str());

  cout << "Please enter your netID:" << endl;
  cin >> netid;

  cout << "Please enter your old password:" <<       endl;
  cin >> oldPass; 

  cout << "Please enter your new password:" << endl;
  cin >> newPass;
  cout << endl;


   if(!fin){ //checks if the file exists
    cout << "Error has occured..." << endl;
  }
  else{ //reading the data from the file.  
    for(int i =0; i<4; i++){
      fin >> name;
      ins[i].setUsername(name);
      fin >> password;
      
      ins[i].setEncryptedPassword(password);
      fin >> ws; //need to review this part
    }
  }


int index = 0; //testcase to see if netID is valid
for(int i=0; netid != ins[i].getUsername() && i<4;i++)
{
  index++;
}
 
if(index == 4) //Test if netID is valid
{
  cout << "NetID is invalid, password not changed." << endl;
}
else
{
  for (int i=0; i<4; i++){
// If user enters a valid username
    if (netid == ins[i].getUsername()){ // Test if old password is correct
      if(!ins[i].authenticate(oldPass))
        cout << "Old password is incorrect." << endl;
      else{
      check = ins[i].setNewPassword(newPass);
        if (!check)
      cout << "New Password does not meet criteria." <<         endl;
    else{
      ins[index].setNewPassword(newPass);
      cout << "Password has been changed for netID: "
      << ins[i].getUsername() << endl;
    }  
  }  
  break;
  
  }
  
}
}
cout << endl; 

for (int i = 0; i < 4; i++) // Output data to the file
  cout << ins[i].getUsername() << "  "
  << ins[i].getEncryptedPassword() << endl;

//fout.close(); // Close file
fin.close();



  
  
return 0;
}

