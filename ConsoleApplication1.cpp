// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<conio.h>
#include<time.h>
#include <iostream>
#include <stdlib.h>
#include "Rooms.h"
#include "CustomerRegistration.h"
#include "Meal.h"
#include "Logging.h"
//#include "LoggingUsers.h"

#include <string>
using namespace std;

void userLogging();
void mainMenu();
void customerMenuDisplay();
void roomsMenuDisplay();
void mealsMenuDisplay();

Rooms R;
MealRegistration MR;
CustomerRegistration CR;
HashTable Users;



int main() {
	Users.insertUser("aaaa", "1111");
	Users.insertUser("bbbb", "2222");
	Users.insertUser("cccc", "3333");
	Users.insertUser("dddd", "4444");


	R.roomsDeclaration();
	
	//TO show to functions of array and linked lists are worked for when more than one records
	CR.newCustomerRegistration(001,1, "Saman", "Perera", "200012342340", "0763456789", "25", "Main Road", "Kandy", 2, 2,true,49000);
	MR.newMealRegistration(001, 001, 1, 19000);
	R.notAvaialbilty(1);
	CR.newCustomerRegistration(002,10, "Chandana", "Silva", "200016734340", "0763286789", "90", "Galle Road", "Colombo", 2,2, true,42000);
	MR.newMealRegistration(002, 002, 2, 18000);
	R.notAvaialbilty(10);

	userLogging();
	
		
	
	
}

void userLogging()
{
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$$                           USER LOGGING                                $$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "o	Enter username: ";
	string username;
	cin >> username;

	cout << "o	Enter password: ";
	string password;
	cin >> password;

	system("CLS");

	bool UserExist = Users.isUserExist(username, password);




	if (UserExist)
	{
		
		char begin;
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << "$                                                                         $" << endl;
		cout << "$                                                                         $" << endl;
		cout << "$                                                                         $" << endl;
		cout << "$         Welcome to NEW HOPE Hotel Management System                     $" << endl;
		cout << "$                                                                         $" << endl;
		cout << "$                                                                         $" << endl;
		cout << "$                                                                         $" << endl;
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << "Press 1 to continue :";
		cin >> begin;
		if (begin == '1') {
			system("CLS");
			mainMenu();
		}
	

	}
	else
	{
		cout << "\n  Login unsuccessful. Please try again." << endl;
		userLogging();

	}
	system("CLS");
		
}


void mainMenu() {
	char main;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$$                             MAIN MENU                                 $$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "                                                                           " << endl;
	cout << "  Press the given number to continue>>                                     " << endl;
	cout << "                                                                           " << endl;
	cout << "                    1. Customer Details Handling =>  1                     " << endl;
	cout << "                    2. Rooms Handling            =>  2                     " << endl;
	cout << "                    3. Meals Handling            =>  3                     " << endl;
	cout << "                    4. Exit                      =>  4                     " << endl;
	cout << "                                                                           " << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cin >> main;
	system("CLS");
	switch (main) {
	case '1':
		customerMenuDisplay();
		cout << "To Continue Press 1..." << endl;
		char cont;
		cin >> cont;
		if (cont == '1')
			system("CLS");
			mainMenu();
		break;
	case '2':
		roomsMenuDisplay();
		cout << "To Continue Press 1..." << endl;
		char cont1;
		cin >> cont1;
		if (cont1 == '1')
			system("CLS");
			mainMenu();
		break;
	case '3':
		mealsMenuDisplay();
		cout << "To Continue Press 1..." << endl;
		char cont2;
		cin >> cont2;
		if (cont2 == '1')
			system("CLS");
			mainMenu();
		break;
	case '4':
		break;
	}
}


void customerMenuDisplay() {
	char customerMenu;

	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$$                             CUSTOMER DETAILS HANDLING                 $$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "                                                                           " << endl;
	cout << "  Press the given number to continue>>                                     " << endl;
	cout << "                                                                           " << endl;
	cout << "                    1. New Booking                 =>  1                   " << endl;
	cout << "                    2. Edit Booking                =>  2                   " << endl;
	cout << "                    3. Booking Payment             =>  3                   " << endl;
	cout << "                    4. Show Booking Deatls         =>  4                   " << endl;
	cout << "                    5. Search Customer's Details   =>  5                   " << endl;
	cout << "                    6. Go Back                     =>  6                   " << endl;
	cout << "                    7. Exit                        =>  7                   " << endl;
	cout << "                                                                           " << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cin >> customerMenu;
	system("CLS");
	int refNo, roomNo, noResidents, noDates, mealPrice, roomPrice, bill,cuRef;
	string fn, ln, nic, contactNo, a1, a2, a3;
	bool  food, search1;
	switch (customerMenu) {
		
		case '1':
			

			cout << "-------------------------------------------------------------------------" << endl;
			cout << "--                                   NEW BOOKING                       --" << endl;
			cout << "-------------------------------------------------------------------------" << endl;
			cout << "                                                                         " << endl;
			int refNo;
			cout << "o	Customer Ref No: ";
			cin >> refNo;
			
			cout << endl;
			R.printRoomPrices();
			cout << endl;
		
			R.selectRoomsTypes();
			cout << endl;
			
			cout << "o	Selected room no :";
			cin >> roomNo;
			R.notAvaialbilty(roomNo);
			cout << endl;
			
			cout << "o	First Name :";
			cin >> fn;
			cout << endl;
			
			cout << "o	Last Name :";
			cin >> ln;
			cout << endl;
			
			cout << "o	NIC No :";
			cin >> nic;
			cout << endl;
			
			cout << "o	Contact No :";
			cin >> contactNo;
			cout << endl;

			cout << "o	Address:" << endl;
			
			cout << "	No :";
			cin >> a1;
			
			cout << "	Street/City :";
			cin >> a2;
			
			cout << "	Town/City :";
			cin >> a3;
			cout << endl;

			
			cout << "o	No of Residents :";
			cin >> noResidents;
			cout << endl;
			
			cout << "o	No of Dates :";
			cin >> noDates;
			cout << endl;
			
			cout << ">> Need Food? :"<<endl;
			cout << "	If YES press 1 else press 0: ";
			cin >> food;
			
			if (food == true) {
				MR.printMeals();
				int mealRefNo;
				cout << "~	Meal Ref No: ";
				cin >> mealRefNo;
				cout << endl;
				int customerRefNo = refNo;
				int selectedMeal;
				cout << "~	Meal No: ";
				cin >> selectedMeal;
				cout << endl;
				mealPrice = MR.meals[selectedMeal - 1] * noDates * noResidents;
				MR.newMealRegistration(mealRefNo, refNo, selectedMeal, mealPrice);
			}
			roomPrice = R.roomPriceRecognizing(roomNo) * noDates;
			bill = roomPrice + mealPrice;
			cout << endl;

			CR.newCustomerRegistration(refNo,roomNo, fn, ln, nic, contactNo, a1, a2, a3, noResidents, noDates, food, bill);
			cout << endl;
			cout << endl;
			cout<<"****Your booking is Successful****" << endl;
			cout << ">>Your Ref No: " << refNo << endl<<endl;
			cout << "To Continue Press 1..." << endl;
			char cont;
			cin >> cont;
			if (cont == '1')
				system("CLS");
				mainMenu();
			break;



	case '2':
		
		//This function is only valid at the moment registered.
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "--                                  EDIT BOOKING                       --" << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "                                                                         " << endl;
		cout << "o	Enter Ref No: ";
		int ref;
		cin >> ref;
		bool search;
		search= CR.searchCustomer(ref);
		//cout << " If TRUE press 1 to continue: ";
		//char c;
		//cin >> c;
		
		if (search==true)
		{
			char edit;
			cout << "                                                                           " << endl;
			cout << "  Press the given number to continue>>                                     " << endl;
			cout << "                                                                           " << endl;
			cout << "                    1. Edit No of Residents        =>  1                   " << endl;
			cout << "                    2. Edit No of Dates            =>  2                   " << endl;
			cout << "                    3. Edit Meal Requirement       =>  3                   " << endl;
			cout << "                    4. Go Back                     =>  4                   " << endl;
			cout << "                    5. Exit                        =>  5                   " << endl;
			cout << endl;
			cin >> edit;
			system("CLS");
			cout << "-------------------------------------------------------------------------" << endl;
			cout << "--                                  EDIT BOOKING                       --" << endl;
			cout << "-------------------------------------------------------------------------" << endl;
			switch (edit) {
			case '1':
				CR.editNoOfResidents(ref);
				cout << "To Continue Press 1" << endl;
				char cont;
				cin >> cont;
				if (cont == '1')
					system("CLS");
					mainMenu();
				break;
			case '2':
				CR.editNoOfDates(ref);
				cout << "To Continue Press 1" << endl;
				char cont3;
				cin >> cont3;
				if (cont3 == '1')
					system("CLS");
					mainMenu();
				break;
			case '3':
				CR.mealRequirement(ref);
				cout << "To Continue Press 1" << endl;
				char cont4;
				cin >> cont4;
				if (cont4 == '1')
					system("CLS");
					mainMenu();
				break;
			case '4':
				system("CLS");
				mainMenu();
				break;
			case '5':
				break;
			}
			
		}
		else {
			
			cout << "No customer found..." << endl;
			cout << "Press 2 to continue...." << endl;
			char contin = 1;
			if (contin == '2')
			{
				system("CLS");
				mainMenu();
			}
		}

		break;
	case '3':
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "--                               BOOKING PAYMENT                       --" << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "                                                                         " << endl;
		int cuRef;
		cout << "o	Enter Ref No: ";
		int n;
		cin >> n;
		bool search1;
		search1= CR.searchCustomer(n);
		if (search1 == true)
		{
			CR.completionPayment(n);
			int room = CR.searchRoomNo(n);
			R.avaialbilty(room);
			cout << "To Continue Press 1..." << endl;
			char cont5;
			cin >> cont5;
			if (cont5 == '1')
			{
				system("CLS");
				mainMenu();
			}
			
		}
		else
		{
			cout << "No customer found..." << endl;
			cout << "Press 2 to continue...." << endl;
			char contin = 1;
			if (contin == '2')
			{
				system("CLS");
				mainMenu();
			}
		}
		
		break;
	case '4':
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "--                               BOOKING DETAILS                       --" << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "                                                                         " << endl;
		CR.print();
		cout << "To Continue Press 1" << endl;
		char cont6;
		cin >> cont6;
		if (cont6 == '1')
			system("CLS");
			mainMenu();
		break;

	case '5':
		cout << "o	Enter the Reference No: ";
		cin >> cuRef;
		CR.searchCustomer(cuRef);
		cout << "To Continue Press 1" << endl;
		char cont7;
		cin >> cont7;
		if (cont7 == '1')
			system("CLS");
			mainMenu();
		break;
	case '6':
		system("CLS");
		mainMenu();
		break;
	case '7':
		break;
	}
	
}


void roomsMenuDisplay() {
	char roomMenu;

	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$$                             ROOMS HANDLING                            $$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "                                                                           " << endl;
	cout << "  Press the given number to continue>>                                     " << endl;
	cout << "                                                                           " << endl;
	cout << "                    1. Rooms Details               =>  1                   " << endl;
	cout << "                    2. Go Back                     =>  2                   " << endl;
	cout << "                    3. Exit                        =>  3                   " << endl;
	cout << "                                                                           " << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cin >> roomMenu;
	switch (roomMenu) {
	case '1':
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "--                                  ROOM DETAILS                       --" << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		R.printRooms();
		cout << "To Continue Press 1" << endl;
		char cont;
		cin >> cont;
		if (cont == '1')
			system("CLS");
			mainMenu();
		break;
	case '2':
		system("CLS");
		mainMenu();
		break;
	case'3':
		break;
	}
}

void mealsMenuDisplay() {
	char mealsMenu;
	int meal1, mealprice1,cuRef1;

	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "$$                             MEALS HANDLING                            $$" << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cout << "                                                                           " << endl;
	cout << "  Press the given number to continue>>                                     " << endl;
	cout << "                                                                           " << endl;
	cout << "                    1. Meals Details               =>  1                   " << endl;
	cout << "                    2. Edit Meals                  =>  2                   " << endl;
	cout << "                    3. Go Back                     =>  3                   " << endl;
	cout << "                    4. Exit                        =>  4                   " << endl;
	cout << "                                                                           " << endl;
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
	cin >> mealsMenu;
	switch (mealsMenu) {
	case '1':
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "--                                 MEAL DETAILS                        --" << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		MR.print1();
		cout << "To Continue Press 1..." << endl;
		char cont;
		cin >> cont;
		if (cont == '1')
			system("CLS");
			mainMenu();
		break;
	case '2':
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "--                                  EDIT MEALS                         --" << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "o	Enter Ref No: ";
		int n;
		cin >> n;
		CR.searchCustomer(n);
		cout << " If TRUE press 1 to continue: ";  //
		char c1;
		cin >> c1;
		if (c1 == '1')
		{
			CR.editMeal(n);
		}
		cout << "To Continue Press 1" << endl;

		char cont8;
		cin >> cont8;
		if (cont8 == '1')
			system("CLS");
			mainMenu();
		break;
	case '3':
		system("CLS");
		mainMenu();
		break;
	case'4':
		exit(0);
		break;
	}

}
