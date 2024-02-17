#pragma once
#include <stdio.h>
#include <string>
using namespace std;
class Rooms
{
public:

	string roomsArray[64][5] = {};
	int P;

	void roomsDeclaration() {
		for (int i=0; i < 64; i++) 
		{

			//rooms number
			int a = i + 1;
			roomsArray[i][0] = to_string(a);

			//rooms floor
			if (i < 16)
			{
				roomsArray[i][1] = '1';
			}
			else if (i < 32)
			{
					roomsArray[i][1] = '2';
			}
			else if (i < 48)
			{
				roomsArray[i][1] = '3';
			}
			else
			{
				roomsArray[i][1] = '4';
			}
			//Room Type
			if (((i >= 0) and (i < 4)) or ((i >= 16) and (i < 20)) or ((i >= 32) and (i < 36)) or ((i>=48) and (i < 52))) {
				roomsArray[i][2] = "AC";  //AC
				roomsArray[i][3] = "Single";//Single
			}

			else if (((i >=4) and (i < 8)) or ((i >=20) and (i < 24)) or ((i >= 36) and (i < 40)) or ((i >=52) and (i < 56))) {
				roomsArray[i][2] = "AC"; //AC
				roomsArray[i][3] = "Double";//Double
			}

			else if (((i >=8) and (i < 12)) or ((i >=24) and (i < 28)) or ((i >= 40) and (i < 44)) or ((i >=56) and (i < 60))) {
				roomsArray[i][2] = "NonAC"; //Non AC
				roomsArray[i][3] = "Single";//Single
			}

			else {
				roomsArray[i][2] = "NonAC"; //Non AC
				roomsArray[i][3] = "Double";//Double
			}

			//Room Availability
			for(int n = 0; n < 64; n++) {
				roomsArray[i][4] = "Available";
			}



		}
	}

	int roomPriceRecognizing(int roomNo) {

		roomsDeclaration();
		if (roomsArray[roomNo - 1][2] == "AC" && roomsArray[roomNo - 1][3] == "Single")
			P = rooms[0];
		if (roomsArray[roomNo - 1][2] == "NonAC" && roomsArray[roomNo - 1][3] == "Single")
			P = rooms[1];
		if (roomsArray[roomNo - 1][2] == "AC" && roomsArray[roomNo - 1][3] == "Double")
			P = rooms[2];
		if (roomsArray[roomNo - 1][2] == "NonAC" && roomsArray[roomNo - 1][3] == "Double")
			P = rooms[3];
		return P;


	}

	void notAvaialbilty(int roomNo) {
		
		roomsArray[roomNo - 1][4] = "Not Available";
	}

	void avaialbilty(int roomNo) {
		roomsArray[roomNo - 1][4] = "Available";
	}

	/*void printRoomsAvailable(char a, char b) {
		string typeA, typeB;
		switch (a) {
			case '1':
				typeA = "AC";
				break;
			case '2':
				typeA = "Non AC";

		}

		switch (b) {
		case '1':
			typeB = "Single";
			break;
		case '2':
			typeB = "Double";

		}
		cout << "Room No\tFloor" << endl;
		for (int a = 0; a < 64; a++) {
			if ((roomsArray[a][2]==typeA) && (roomsArray[a][3]==typeB) && (roomsArray[a][4]=="Available"))
			{
				cout << roomsArray[a][0] << "\t\t" << roomsArray[a][1] << endl;;
			}
			cout << endl;

		}

		
	}*/



	void printRooms() {
		cout << "Room Number\t" << "Floor\t\t" << "AC/Non AC\t" << "Single/Double\t" << "Avialabilty" << endl;
		for (int a = 0; a < 64; a++) {
			for (int b = 0; b < 5; b++) {
				cout <<roomsArray[a][b]<<"\t\t";
				
			}
			cout << endl;

		}
		
		
		
	}

	//Prices for various type of Rooms Per Day  
	int rooms[4] = { 15000,12000,20000,17000 };
	
	void selectRoomsTypes() {
		cout << "Select your preference: " << endl;
		cout << "AC Single Room          |    " << 1 << "          " << endl;
		cout << "Non AC Single Room      |    " << 2 << "          " << endl;
		cout << "AC Double Room          |    " << 3 << "          " << endl;
		cout << "Non AC Double Room      |    " << 4 << "          " << endl;
		cout << "Select your preference: " << endl;
		
		cout << endl;
		char choice;
		cin >> choice;
		cout << "These are the AVAILABLE ROOMS on your preference..." << endl<<endl;
		cout << "Room No:\t" << "Floor" << endl;
		switch (choice) {
		case'1':
			for (int i = 0; i < 64; i++) {
				if (roomsArray[i][2] == "AC" && roomsArray[i][3] == "Single" && roomsArray[i][4] == "Available")
					cout << roomsArray[i][0] << "\t\t" << roomsArray[i][1] << endl;
			}
			break;
		case '2':
			for (int i = 0; i < 64; i++) {
				if (roomsArray[i][2] == "NonAC" && roomsArray[i][3] == "Single" && roomsArray[i][4] == "Available")
					cout << roomsArray[i][0] << "\t\t" << roomsArray[i][1] << endl;
			}
			break;
		case '3':
			for (int i = 0; i < 64; i++) {
				if (roomsArray[i][2] == "AC" && roomsArray[i][3] == "Double" && roomsArray[i][4] == "Available")
					cout << roomsArray[i][0] << "\t\t" << roomsArray[i][1] << endl;
			}
			break;
		case '4':
			for (int i = 0; i < 64; i++) {
				if (roomsArray[i][2] == "NonAC" && roomsArray[i][3] == "Double" && roomsArray[i][4] == "Available")
					cout << roomsArray[i][0] << "\t\t" << roomsArray[i][1] << endl;
			}
			break;
		}

	}
		
	


	void printRoomPrices() {
		cout << "================================================" << endl;
		cout << "          Prices of Room Per Day(Rs.)              " << endl;
		cout << "================================================" << endl;
		cout << "AC Single Room          |    " << rooms[0] << "          " << endl;
		cout << "Non AC Single Room      |    " << rooms[1] << "          " << endl;
		cout << "AC Double Room          |    " << rooms[2] << "          " << endl;
		cout << "Non AC Double Room      |    " << rooms[3] << "          " << endl;
	}
};

