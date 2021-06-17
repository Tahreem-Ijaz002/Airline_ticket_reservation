#include <iostream>
#include<string>
using namespace std;
struct Passenger
{
	string Name, SeatNO;
	Passenger* next;
};
class PassengerLinkList
{
public:
	Passenger* head = NULL;
	void reserve()
	{
		string name, seatno;
		cout << "Enter Passenger's Name : ";
		cin >> name;
		cout << "Enter Seat No : ";
		cin >> seatno;
		Passenger* temp = new Passenger;
		temp->Name = name;
		temp->SeatNO = seatno;
		if (head == NULL)
		{
			temp->next = NULL;
			head = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
		cout << "\t\t\tYour Ticket Is Booked Successfully" << endl;
	}
	void deletenode()
	{
		string n;
		cout << "Enter Passenger's Name Whom Ticket You Want To Delete : ";
		cin >> n;
		Passenger *p, *q;
		q = head;
		p = head->next;
		if (q->Name == n)
		{
			head = p;
			delete(q);
		}
		else
		{
			while (p->Name != n)
			{
				p = p->next;
				q = q->next;
			}
			if (p->next == NULL)
			{
				q->next = NULL;
				delete(p);
			}
			else
			{
				q->next = p->next;
				delete(p);
			}
		}
		cout << endl << "\t\t\tYour Seat Has been Cancled";
	}
	void check()
	{
		string na;
		cout << "Enter Passenger's Name Whom Ticket You Want to Check : ";
		cin >> na;
		Passenger *temp = head;
		int j = 0;
		while (temp != NULL)
		{
			if (temp->Name == na)
			{
				cout << "\t\tPassenger's NAME : " << temp->Name << endl;
				cout << "\t\tSeat No : " << temp->SeatNO << endl;
				cout << "\t\t\tYour Ticket Is Checked";
				j++;
			}
			temp = temp->next;
		}
		if (j == 0)
		{
			cout << endl << "\t\t\tTicket not Found" << endl;
		}
	}
	void display()
	{
		Passenger* temp = head;
		int i = 1;
		while (temp != NULL)
		{
			cout << "\t\t***************" << endl;
			cout << "\t\t PASSENGER " << i << endl;
			cout << "\t\t***************" << endl;
			cout << "\t\tPassenger's NAME : " << temp->Name << endl;
			cout << "\t\tSeat No" << temp->SeatNO << endl;
			temp = temp->next;
			i++;
		}
	}
};
struct flight
{
	string FlightName, Flightf, Flightt;
	int FlightNo;
	flight *next;
	PassengerLinkList p;
};
flight* head1 = NULL;
class FlightLinkList
{
private:
	flight* head = NULL;
public:
	void insert(int flightno, string flightname, string flightf, string flightt)
	{
		flight* temp = new flight;
		temp->FlightNo = flightno;
		temp->FlightName = flightname;
		temp->Flightf = flightf;
		temp->Flightt = flightt;
		if (head == NULL)
		{
			temp->next = NULL;
			head = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
	}
	void deletenode(string n)
	{
		flight *p, *q;
		q = head;
		p = head->next;
		if (q->FlightName == n)
		{
			head = p;
			delete(q);
		}
		else
		{
			while (p->FlightName != n)
			{
				p = p->next;
				q = q->next;
			}
			if (p->next == NULL)
			{
				q->next = NULL;
				delete(p);
			}
			else
			{
				q->next = p->next;
				delete(p);
			}
		}
		cout << endl << "\t\tYour Flight Has been Deleted";
	}
	void check(string val)
	{
		flight *temp = head;
		int j = 0;
		while (temp != NULL)
		{
			if (temp->FlightName == val)
			{
				cout << "\t\tFlight No : " << temp->FlightNo << endl;
				cout << "\t\tFlight Name : " << temp->FlightName << endl;
				cout << "\t\tFlight From : " << temp->Flightf << endl;
				cout << "\t\tFlight To : " << temp->Flightt << endl;
				cout << "Your Flight Is Checked ";
				j++;
			}
			temp = temp->next;
		}
		if (j == 0)
		{
			cout << endl << "Flight not Found" << endl;
		}
	}
	void displayflight()
	{
		flight* temp = head;
		int i = 1;
		while (temp != NULL)
		{
			cout << "\t\t*************" << endl;
			cout << "\t\t FLIGHT " << i << endl;
			cout << "\t\t*************" << endl;
			cout << "\t\tFlight No : " << temp->FlightNo << endl;
			cout << "\t\tFlight Name : " << temp->FlightName << endl;
			cout << "\t\tFlight From : " << temp->Flightf << endl;
			cout << "\t\tFlight To : " << temp->Flightt << endl;
			temp = temp->next;
			i++;
		}
	}
	void reserveTicket()
	{
		system("cls");
		displayflight();
		int fn;
		cout << "Enter Flight No : ";
		cin >> fn;
		flight* temp = head;
		while (temp->FlightNo != fn)
		{
			temp = temp->next;
		}
		temp->p.reserve();
	}
	void cancleTicket()
	{
		int fn;
		cout << "Enter Flight No Whose Ticket You Want To Cancle : ";
		cin >> fn;
		flight* temp = head;
		while (temp->FlightNo != fn)
		{
			temp = temp->next;
		}
		temp->p.deletenode();
	}
	void checkTicket()
	{
		int fn;
		cout << "Enter Flight No Whose Ticket You Want To Check : ";
		cin >> fn;
		flight* temp = head;
		while (temp->FlightNo != fn)
		{
			temp = temp->next;
		}
		temp->p.check();
	}
	void displayTicket()
	{
		int fn;
		cout << "Enter Flight No Whose Tickets You Want To display : ";
		cin >> fn;
		flight* temp = head;
		while (temp->FlightNo != fn)
		{
			temp = temp->next;
		}
		temp->p.display();
	}
};
int main()
{
	int choice = 0;;
	char option;
	int fn;
	FlightLinkList f;
	f.insert(1, "ISLAMABAD1", "islamabad", "lahore");
	f.insert(2, "DUBAI2", "Dubai", "Saudia");
	f.insert(3, "LAHORE3", "lhr", "Karachi");
menu:
	cout << endl;
	cout << "\t\t" << "*****************************" << endl;
	cout << "\t\t " << "Airline Ticket Reservation" << endl;
	cout << "\t\t" << "*****************************" << endl;
	cout << "\t\t" << "1. Book Ticket" << endl;
	cout << "\t\t" << "2. Cancle Ticket" << endl;
	cout << "\t\t" << "3. Check Ticket" << endl;
	cout << "\t\t" << "4. Display Passengers" << endl;
	cout << "\t\t" << "5. Exit" << endl;
	cout << "\t" << "Enter Your Choice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		f.reserveTicket();
		break;
	case 2:
		f.cancleTicket();
		break;
	case 3:
		f.checkTicket();
		break;
	case 4:
		f.displayTicket();
		break;
	case 5:
		break;
	default:
		cout << "You Enter Wrong Choice" << endl;
		break;
	}
	cout << endl << "Enter 'C' to continue or 'S' to stop : ";
	cin >> option;
	switch (option)
	{
	case 'C':
		system("cls");
		goto menu;
	case 'c':
		system("cls");
		goto menu;
	case 'S':
		break;
	default:
		break;
	}
}