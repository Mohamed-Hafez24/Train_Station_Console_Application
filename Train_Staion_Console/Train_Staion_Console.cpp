/*
This Is a final project for programming fundmental Course (CS102) in first year college
Project Name : Train Station booking Console Application Using C++.
Location : Egypt -  Assiut University Faculty of computer and information
Students Name : Mohamed Saber Sayed - Kerolos Thrwat Fouad
Date : 8/5/2018
*/
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

// our new type that will store each carriage info
struct carriages
{
	int clas;
	int price;
	bool seat[30];
};

// Declaration of all the functions in this project
int show();
carriages  book(carriages *arr, int size, int cl);
carriages cancel(carriages *arr);
void available(carriages *arr, int size);
void profits(carriages *arr, int size);


void main()
{
	// This is the beginning of our program
	// This code allows the administrator to enter the information of the certain train

	// This loop is just for print design
	for (int sp = 0; sp<20; sp++)
		cout << "*";

	int cnum;
	cout << endl << "Enter the number of carriages :";
	cin >> cnum;

	// This is the main array that we use to store our train info.
	carriages *arr = new carriages[cnum];
	for (int i = 0; i<cnum; i++)
	{
		cout << "carriage #" << i + 1 << " :" << endl;
		cout << "Enter class : ";
		cin >> arr[i].clas;
		cout << "Enter price : ";
		cin >> arr[i].price;
		for (int s = 0; s<30; s++)
		{
			arr[i].seat[s] = false;
		}
	}

	// This loop is just for print design
	for (int sp = 0; sp<20; sp++)
		cout << "*";

	// This Code is to allow the menu option to show after every action we did
	// Also it allows the program to work continuously until we stopped it by choosing the exit option
	int ch;
	do
	{
		ch = show();
		if (ch == 0)
		{
			cout << endl << "This program was programmed by Mohamed S. Sayed & Kerolos T. Fouad " << endl;
			cout << endl << "Thanks for using our program !" << endl;
			delete[]arr;
		}
		else if (ch == 1)
		{
			int n, cl;
			// here you enter the number of ticktes you need to book
			cout << endl << "Enter number of tickets : ";
			cin >> n;
			cout << endl << "Enter class : ";
			cin >> cl;
			while (n > 0)
			{
				*arr = book(arr, cnum, cl);
				n--;
			}
		}
		else if (ch == 2)
			cancel(arr);
		else if (ch == 3)
			available(arr, cnum);
		else if (ch == 4)
			profits(arr, cnum);
		else
			cout << endl << "The choice you entered is invalid !\n";
	} while (ch != 0);
	cout << endl << endl << endl << endl;

	system("pause");
	return;

}

// This function is to show the menu option
int show()
{
	int choice;
	cout << endl << "Enter 1 to book a ticket .\n";
	cout << "Enter 2 to cancel a ticket .\n";
	cout << "Enter 3 to show available seats .\n";
	cout << "Enter 4 to print profits in details .\n";
	cout << "Enter 0 to exit .\n";
	cout << "Your choice : ";
	cin >> choice;

	// This loop is just for print design
	for (int sp = 0; sp<20; sp++)
		cout << "*";
	return choice;
}

// This function is to book the ticket in certain class
carriages book(carriages *arr, int size, int cl)
{
	for (int c = 0; c < size; c++)
	{
		if (arr[c].clas == cl)
		{
			for (int s = 0; s < 30; s++)
			{
				if (arr[c].seat[s] == false)
				{
					arr[c].seat[s] = true;
					cout << endl << "your seat is in carriage #" << c + 1 << " seat #" << s + 1 << endl;

					// This loop is just for print design
					for (int sp = 0; sp < 20; sp++)
						cout << "*";

					return *arr;
				}
			}
		}
		else if ((c + 1) == size)
		{
			// If the class doesn't exist in this train will print this message
			cout << "The class you entered is invalid !\n";

			// This loop is just for print design
			for (int sp = 0; sp < 20; sp++)
				cout << "*";
			return *arr;
		}
	}

	// This loop is just for print design
	for (int sp = 0; sp<20; sp++)
		cout << "*";
}

// This function is to cancel the tickect with the seat number and carriage number
carriages cancel(carriages *arr)
{
	int seatt, car;

	cout << endl << "Enter seat number and carriage number :\n"
		<< "Seat number : ";
	cin >> seatt;
	cout << endl << "Carriage number : ";
	cin >> car;
	// check whether this seat is already booked or not 
	if (arr[--car].seat[--seatt] == true)
	{
		// make the value of the seat false
		arr[car].seat[seatt] = false;
		cout << "Ticket canceled !\n";
	}
	else
		// if the seat is not boked before show this message
		cout << "This seat is not booked !!\n" << "You CANNOT cancel an empty seat !\n";

	// This loop is just for print design
	for (int sp = 0; sp<20; sp++)
		cout << "*";

	return *arr;
}

// This function is to show all available seats in each carriage and their number 
void available(carriages *arr, int size)
{
	int count = 0;
	for (int c = 0; c<size; c++)
	{
		// This loop is just for print design
		for (int sp = 0; sp<20; sp++)
			cout << "*";

		cout << endl << "Available seats in carriage #" << c + 1 << endl;
		count = 0;
		for (int s = 0; s<30; s++)
		{
			if (arr[c].seat[s] == false)
			{
				count += 1;
				cout << "seat #" << s + 1 << endl;
			}
		}
		// This print the total number of available seats
		cout << "The number of available seats in carriage #" << c + 1 << " is " << count << endl;

		// This loop is just for print design
		for (int sp = 0; sp<20; sp++)
			cout << "*";
	}
}

// This function shows the profits that each carriage have and the total profits from this train 
void profits(carriages *arr, int size)
{
	int count = 0;
	double Tcount = 0.0;
	double profit;
	for (int c = 0; c < size; c++)
	{
		// This loop is just for print design
		for (int sp = 0; sp<20; sp++)
			cout << "*";

		cout << endl << "The booked seats in carriage #" << c + 1 << endl;
		count = 0;
		for (int s = 0; s<30; s++)
		{

			if (arr[c].seat[s] == true)
			{
				count += 1;
				cout << "seat #" << s + 1 << endl;
			}
		}
		if (count > 1)
			cout << "The number of booked seats in carriage #" << c + 1 << " are " << count << " seats\n";
		else if (count == 1)
			cout << "The number of booked seats in carriage #" << c + 1 << " is " << count << " seat\n";
		else if (count == 0)
			cout << "There are no booked seats in carriage #" << c + 1 << endl;

		// This print the price of the ticket in this carriage
		cout << "The ticket in this carriage costs  " << arr[c].price << endl;
		profit = arr[c].price * count;

		// This print the total profits of the booked seats in this carriage
		cout << "The profits of this carriage = " << profit << endl;
		Tcount += profit;

		// This loop is just for print design
		for (int sp = 0; sp<20; sp++)
			cout << "*";
	}

	cout << endl << "The total profits of the train = " << Tcount << endl;

	// This loop is just for print design
	for (int sp = 0; sp<20; sp++)
		cout << "*";
	return;
}