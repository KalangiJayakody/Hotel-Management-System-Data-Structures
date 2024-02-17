#pragma once
#include <iostream>
#include "Rooms.h"
#include "Meal.h"
#include <string>
Rooms R1;
MealRegistration MR1;
using namespace std;

class Node {
public:
	int refNo;
    int roomSelected;
    string fName;
    string lName;
    string nicNo;
    string contactNo;
    string a1;
    string a2;
    string a3;
    int noOfResidents;//
    int noOfDates;//
    bool isMealNeeded;//
    int totalPrice;
    bool paymentDone;
   

	Node* next;

    

	Node(int RefNo,int Room, string Fn, string Ln, string NicNo, string ContactNo, string A1, string A2, string A3,int noResidents,int noDates,bool food,int bill) {
        refNo = RefNo;
        roomSelected = Room;
        fName = Fn;
        lName = Ln;
        nicNo = NicNo;
        contactNo = ContactNo;
        a1 = A1;
        a2 = A2;
        a3 = A3;
        noOfResidents = noResidents;
        noOfDates = noDates;
        isMealNeeded = food;
        totalPrice=bill;
        paymentDone = false;
		next = NULL;
	}
};

class CustomerRegistration {
public:
    Node* head;
    Node* tail;
    


    CustomerRegistration() {
        head = NULL;
        tail = NULL;
        

    }


    void newCustomerRegistration(int RefNo, int Room, string Fn, string Ln, string NicNo, string ContactNo, string A1, string A2, string A3, int noResidents, int noDates, bool food, int bill) {
        Node* temp = new Node(RefNo,Room,Fn,Ln,NicNo, ContactNo, A1, A2, A3,noResidents, noDates, food, bill);
        if (head == NULL) {					//if(tail==NULL)
           
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        
    }
    

    bool searchCustomer(int customerRef)
    {
        bool b = false;
        Node* current = head;
        while (current != NULL) {
            if (current->refNo == customerRef) {
                b = true;
                cout << "o  Name: " << current->fName << " " << current->lName << endl;
                cout << "o  Room No: " << current->roomSelected << endl;
                cout << "o  NIC No:"<<current->nicNo << endl;
                cout << "o  Contact No:"<<current->contactNo << endl;
                cout << "o  Address: "<<current->a1 << "," << current->a2 << "," << current->a3 <<endl;
                cout << "o  No of Residents: "<<current->noOfResidents <<endl;
                cout << "o  No of Dates :"<<current->noOfDates <<endl;
                if (current->isMealNeeded == 1)
                {
                    cout << "o  Meal Requirement: YES" << endl;
                }
                else cout <<"o  Meal Requirement: NO" << endl;
                cout << "o  Bill: "<<current->totalPrice << endl;

                if (current->paymentDone == 1)
                {
                    cout <<"o   Payment: PAID" << endl;

                }
                else cout <<"o  Payment: NOT PAID" << endl;
                cout << endl;
            }
            current = current->next;
        }
        if (b == false)
        {
            cout << ">> No Customer Found..." << endl;
        }
           

        return b;
        
    }

    void calculateBill(int customerRef)
    {
        Node* current = head;
        while (current != NULL)
        {
            if (current->refNo == customerRef)
            {
                Rooms R;
                //current->totalPrice = 0;
                current->totalPrice = R.roomPriceRecognizing(current->roomSelected) * current->noOfDates;
                if(current->isMealNeeded==true)
                {
                    MealRegistration m;
                    current->totalPrice += current->totalPrice + m.recognizingMealPrice(customerRef) * current->noOfDates * current->noOfResidents;
                }
                
            }
            current = current->next;
            
        }
    }


    void editNoOfResidents(int customerRef) {
        Node* current = head;

        
        while (current!=NULL) {
            
            if (current->refNo == customerRef) {
                
                cout << "o   Enter new No of Residents: " << endl;
                int no;
                cin >> no;
                Rooms r;
                current->noOfResidents = no;
                
                cout << endl;
                cout << "Successful..." << endl;
                calculateBill(customerRef);
                }
            current = current->next;
            
        }
        
        
    }
   
    void editNoOfDates(int customerRef) {
        Node* current = head;


        while (current != NULL) {
            if (current->refNo == customerRef) {
                cout << " Enter new No of Dates: " << endl;
                int no1;
                cin >> no1;
                Rooms r;
                current->noOfDates = no1;
                

                cout << endl;
                cout << "Successfull" << endl;
                calculateBill(customerRef);
            }
            current = current->next;
        }
        
    }

    void editMeal(int customerRef) {
        Node* current = head;
       

        while (current != NULL) {
            if (current->refNo == customerRef) {
                
                MR1.printMeals();
                cout << " Select your NEW choice: ";
                int meal1;
                cin >> meal1;
                current->totalPrice = current->noOfResidents * current->noOfDates * MR1.meals[meal1 - 1] + R1.roomPriceRecognizing(current->roomSelected) * current->noOfDates;

                cout << endl;
                cout << "Successfull" << endl;
                calculateBill(customerRef);
            }
            current = current->next;
        }
        
    }

    void mealRequirement(int customerRef) {
        Rooms R1;
        MealRegistration MR1;
        Node* current = head;


        while (current != NULL) {
            if (current->refNo == customerRef) {
                cout << " Do you want meal?: Press 1 if want else press 0" << endl;
                int no;
                cin >> no;
                if (no == 1)
                {
                    
                    MR1.printMeals();
                    int mealRefNo;
                    cout << " Meal Ref No: ";
                    cin >> mealRefNo;
                    cout << endl;
                    int customerRefNo = customerRef;
                    int selectedMeal;
                    cout << " Meal No: ";
                    cin >> selectedMeal;
                    cout << endl;
                    int mealPrice = MR1.meals[selectedMeal - 1] * current->noOfDates * current->noOfResidents;
                    MR1.newMealRegistration(mealRefNo, customerRef, selectedMeal, mealPrice);
                    current->totalPrice += mealPrice;
                }
                else if (no == 0)
                {
                    //
                    current->totalPrice= R1.roomPriceRecognizing(current->roomSelected) * current->noOfResidents * current->noOfDates;
                }
               
            }
            current = current->next;
        }
        
    }

    void completionPayment(int customerRef) {
        Rooms r2;
        Node* current = head;


        while (current != NULL) {
            if (current->refNo == customerRef) {
                cout << "Your Payment: " << current->totalPrice << endl;
                current->paymentDone = true;
                if (current->paymentDone == true) cout << 1;
                r2.roomsArray[current->roomSelected - 1][4] = "Not Avaialble";
            }

            cout << endl;
            cout << "Successfull" << endl;
        
        current = current->next;
        }
        
    }
    
    void print() {
        cout << "ReferenceNo.\t" << "RoomNo.\t\t" << "Name\t\t\t" << "NICNo\t\t" << "ContactNo\t" << "Address\t\t\t" << "No of Residents\t\t" << "No of Dates\t\t" << "Food Requirement\t"<<"Bill\t\t" << "Payment\t" << endl;
        Node* current = head;

        while (current != NULL) {
            cout << current->refNo << "\t\t";
            cout << current->roomSelected << "\t\t";
            cout << current->fName << " " << current->lName<<"\t\t";
            cout << current->nicNo << "\t";
            cout << current->contactNo << "\t";
            cout << current->a1 << " " << current->a2 << " " << current->a3 << "\t\t";
            cout << current->noOfResidents << "\t\t\t";
            cout << current->noOfDates << "\t\t\t";
            if (current->isMealNeeded == 1)
            {
                cout << "YES" << "\t\t\t";
            }
            else cout << "NO" << "\t\t\t";
            cout << current->totalPrice << "\t\t";
            if (current->paymentDone == 1)
            {
                cout << "PAID" << "\t";

            }
            else cout << "NOT PAID" << "\t";
            cout << endl;
            current = current->next;
        }
        
   
    }

    int searchRoomNo(int id)
    {
        Node* current = head;
        while (current != NULL)
        {
            if (current->refNo == id)
            {
                return current->roomSelected;
            }
        }
        return -1;
    }
    
 };


    

