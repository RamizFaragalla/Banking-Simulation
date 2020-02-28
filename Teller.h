#ifndef Teller_h
#define Teller_h
struct Teller
{
	bool isFree = true;		//every teller starts out as free
	int serviceTime;		//amount of time it takes to help a customer
};

#endif