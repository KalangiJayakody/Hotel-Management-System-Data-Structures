#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;



class User_Login {
public:
	string UserName;
	string pasword;

	User_Login() {
		UserName = "";
		pasword = "";
	}

	User_Login(string k, string v) {
		UserName = k;
		pasword = v;
	}
	
	
};


class HashTable {

private:
	static const int size = 10;
	list<User_Login> table[size];

public:
	//int getHashKey(string key);
	//void insertUser(string key, string val);

	//bool isKeyExist(string key);


	//bool isUserExist(string key, string Pasword);

	int getHashKey(string key)
	{
		int Key = 0;
		for (int i = 0; i < key.length(); i++) {
			Key = 2023 * key[i];

		}
		return Key % size;
	}


	void insertUser(string key, string val)
	{
		int index = getHashKey(key);


		User_Login user(key, val);


		if (!isKeyExist(key))
			table[index].push_back(user);
		else
			cout << "The key already exist" << endl;
	}


	bool isKeyExist(string key)
	{
		int index = getHashKey(key);
		for (User_Login user : table[index]) {
			if (user.UserName == key)
				return true;
		}
		return false;
	}



	bool  isUserExist(string key, string Pasword)
	{
		int index = getHashKey(key);


		for (User_Login user : table[index]) {
			if (user.pasword == Pasword && user.UserName == key) {
				cout << "Logging Successful..."<<endl;
				return true;

			}
			else if (user.UserName != key)
				cout << "\n  Error: incorrect User Name." << endl;
			else
				cout << "\n  Error: incorrect Pasword." << endl;
		}

		return false;


	}

	

};
