#pragma once
#include <iostream>
#include <string>
using namespace std;



class Node1 {
public:
	int mealRefNo;
	int refNo;
	int selectedMeal;
	int mealPrice;
	Node1* next;

	Node1 (int mealNo, int RefNo,int meal,int priceMeal) {
		mealRefNo = mealNo;
		refNo = RefNo;
		selectedMeal = meal;
		mealPrice = priceMeal;
		next = NULL;

	}
};

class MealRegistration {
public:
	Node1* head1;
	Node1* tail1;
	int size1;
	


	MealRegistration() {
		head1 = NULL;
		tail1 = NULL;
		size1 = 0;

	}

	void newMealRegistration(int mealNo, int RefNo, int meal, int priceMeal) {
		Node1* temp = new Node1( mealNo, RefNo, meal,priceMeal);

		if (head1 == NULL) {					//if(tail==NULL)
			//Lnked List is empty
			head1 = temp;
			tail1 = temp;
		}
		else {
			tail1->next = temp;
			tail1 = temp;
		}
		size1++;
	}


	void deleteLastMealRegistrtion() {
		if (head1 == NULL)
			cout << "Empty List";

		else {
			Node1* temp = tail1;
			if (size1 == 1) {
				delete temp;
				head1 = NULL;
				tail1 = NULL;
			}
			else {
				Node1* current = head1;
				for (int i = 0; i < size1 - 2; i++) {
					current = current->next;
				}
				tail1 = current;
				tail1->next = NULL;
				delete temp;
			}
		}
		size1--;
	}


	void print1() {
		cout << "MealReferenceNo.\t" << "Customer Ref. No.\t" << "Selected Meals\t" << "Price for Meal\t"  << endl;
		Node1* current = head1;

		while (current != NULL) {
			cout << current->mealRefNo << "\t\t\t";
			cout << current->refNo << "\t\t\t";
			cout << current->selectedMeal << "\t\t";
			cout << current->mealPrice <<endl;
			current = current->next;
			
		}
		
		
		
	}


	void editMeal() {

	}

	int meals[3] = {4750,4500,4250};

	void printMeals() {
		cout << "                                     ============================" << endl;
		cout << "                                              Package 01" << endl;
		cout << "                                     ============================" << endl;
		cout << endl;
		cout << "                                         Menu                                Price(Rs.)" << endl;
		cout << endl;
		cout << "                Breakfast :    String Hoppers/hoppers                        1000" << endl;
		cout << "                Lunch     :    Rice and Curry                                1750" << endl;
		cout << "                Dinner    :    Noodles/Fried rice/Kottu                      2000" << endl;
		cout << "                Total     :                                                  4750" << endl;

		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;


		cout << "                                     ============================" << endl;
		cout << "                                              Package 02" << endl;
		cout << "                                     ============================" << endl;
		cout << endl;
		cout << "                                         Menu                                Price(Rs.)" << endl;
		cout << endl;
		cout << "                Breakfast :    Noodles/Rice                                  1250" << endl;
		cout << "                Lunch     :    Rice and Curry/Those                          1500" << endl;
		cout << "                Dinner    :    Noodles/Fried rice/Those                      1760" << endl;
		cout << "                Total     :                                                  4500" << endl;

		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;

		cout << "                                     ============================" << endl;
		cout << "                                              Package 03" << endl;
		cout << "                                     ============================" << endl;
		cout << endl;
		cout << "                                         Menu                                Price(Rs.)" << endl;
		cout << endl;
		cout << "                Breakfast :    French toast                                  1750" << endl;
		cout << "                Lunch     :    Rice and Curry/Milk rice                      1500" << endl;
		cout << "                Dinner    :    Hoppers/Coconut roti/Parata/Chapathi          1750" << endl;
		cout << "                Total     :                                                  4250" << endl;
	
	}

	int recognizingMealPrice(int ref) {
		Node1* current = head1;


		while (current != NULL) {
			if (current->refNo == ref) {
				int price = meals[current->selectedMeal - 1];
				return price;
			}
			current = current->next;
		}
	}
	
	
};