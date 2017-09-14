// Assignment 1 - Make Change.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void output(int amount, string name);

int main()
{
	double cost;
	double amountPaid;
	double additionalAmount;
	double amountDue;
	int totalChange;
	int dollarsDue=0;
	int	quartersDue=0;
	int dimesDue=0;
	int nicklesDue=0;
	bool another;
	
	//constants
	int dollar = 100;
	int quarter = 25;
	int dime = 10;
	int nickel = 5;

	do {
		cout << "Enter the cost of the item to be purchased: ";
		cin >> cost;

		cout << "Enter the amount paid: ";
		cin >> amountPaid;

		while (amountPaid < cost) {
			amountDue = cost - amountPaid; 
			cout << "\nInsufficient funds. You need $"<< setprecision(2) << fixed << amountDue << " more. \nEnter additional amount paid: ";
			cin >> additionalAmount;
			amountPaid += additionalAmount;
		};

		totalChange = (amountPaid - cost) * 100;
		cout << "\n\nChange Due:" << endl;

		// calculate dollars
		dollarsDue = totalChange / dollar;
		output(dollarsDue, " dollars");

		// calculate quarters
		quartersDue = totalChange % dollar / quarter;
		output(quartersDue, " quarters");

		// calculate dimes
		dimesDue = totalChange%dollar%quarter / dime;
		output(dimesDue, " dimes");

		// calculate nickles
		nicklesDue = totalChange%dollar%quarter%dime / nickel;
		output(nicklesDue, " nickles");

		// loop if 1 entered
		cout << "\n\nWould you like to calculate another transaction? (enter 1 for yes and 0 for no)" << endl;
		while (!(cin >> another)) {
			cout << "Please enter 1 for yes or 0 for no." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		};

	} while (another == 1);

    return 0;
}

void output(int amount, string name) {
	if (amount > 0){
		cout << "\t" << amount << name << endl;
	};
}

