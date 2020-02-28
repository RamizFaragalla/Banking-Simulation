#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include "ArrayQueue.h"
#include "Teller.h"
#include "Customer.h"
using namespace std;

void arrival(ArrayQueue<Customer>&, int);
void departure(Teller[], ArrayQueue<Customer>&, int);

//global variables 
double totalWaitTime = 0;
int numCustomers = 0;
int numTellers;
double distributionTime;	//1 customer every x minutes
int expectedServiceTime;

int main()
{
	cout << fixed << setprecision(2);
	//seed random number generator
	srand(time(NULL));

	int max_time;						//length of simulation
	int clock;							//loop counter
	Teller bankTellers[5];				//array of tellers, at most 5
	ArrayQueue<Customer> waitingLine;	//waiting line of customers

	//simulation input
	cout << "How many tellers are working (max 5)? ";
	cin >> numTellers;

	cout << "\nWhat is the distribution of arrival times?\n1 customer every _ minutes. ";
	cin >> distributionTime;
	distributionTime = 1 / distributionTime;

	cout << "\nWhat is the expected service time per customer? ";
	cin >> expectedServiceTime;

	cout << "\nWhat is the length of the simulation? ";
	cin >> max_time;

	//arrivals and departures of customers from the waiting line
	for (clock = 1; clock <= max_time; clock++)
	{
		arrival(waitingLine, clock);

		departure(bankTellers, waitingLine, clock);
	}

	//help the remaining customers on the line
	while (!waitingLine.isEmpty())
	{
		departure(bankTellers, waitingLine, clock);
		clock++;
	}

	clock--; //decrement the clock back because the last statment is clock++;

	//output result of the simulation
	cout << endl << "Number of customers served: " << numCustomers << endl;
	cout << "The average wait time is: " << totalWaitTime / numCustomers << " minutes per customer!\n\n";

	system("PAUSE");
	return 0;
}

void arrival(ArrayQueue<Customer>& line, int time)
{
	float prob;		//probability of a customer entering the bank
	Customer temp1;

	prob = float(rand()) / float(RAND_MAX);

	//if customer arrives
	if (prob <= distributionTime)
	{
		temp1.arrivalTime = time;	//set arrival time of customer
		line.enqueue(temp1);		//customer enters the back of the line
		numCustomers++;				//increment totalCustomers
	}
}

void departure(Teller bankTellers[], ArrayQueue<Customer>& line, int time)
{
	Customer temp2;

	//check every teller that is working
	for (int i = 0; i < numTellers; i++)
	{
		//if teller is free and line is not empty
		if (bankTellers[i].isFree && !line.isEmpty())
		{
			temp2 = line.peekFront();
			line.dequeue();					//take customer in the front of line

			bankTellers[i].isFree = false;	//teller is now busy
			bankTellers[i].serviceTime = expectedServiceTime;

			temp2.departTime = time;		//set customer's depart time
			totalWaitTime += temp2.departTime - temp2.arrivalTime;
		}

		//if teller is not free
		else
			bankTellers[i].serviceTime--;

		//if tellers is finished helping the customer
		if (bankTellers[i].serviceTime == 0)
			bankTellers[i].isFree = true;
	}
}