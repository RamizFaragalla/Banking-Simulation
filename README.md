# Banking-Simulation

This program simulatese a bank-teller’s line! It has a queuing system, which consists of servers (tellers) and a queue of objects to be served (customers).

The goal is to compute the average wait time - how long a customer waits until his transaction is performed by the bank-teller.  We need to know 4 things to simulate a queuing system:

  1.	The number of events (2 in this case – arrivals and departures) and how they affect the system
  2.	The number of servers  
  3.	The distribution of arrival times (for example, a customer might arrive approximately every 5 minutes).
  4.	The expected service time (for example, 6 minutes)
  Note: Changing the values of these parameters will affect the average wait time.

To simulate the passing of a unit of time (a minute for example) we increment the clock and run the simulation for a predetermined amount of time – say 100 minutes i.e. use a loop.

For each value of the clock (say 1-100) the following actions are processed (loop body):
  1.	If a customer arrives they enter the back of the line (the queue) and their arrival time is stored.
  2.	If a teller is free and someone is waiting, the customer at the front of the line moves to the teller and the service time is           initialized (to 6 for example) and the customer’s total wait time can be determined.
  3.	If a customer is at the teller’s window, the time remaining for that customer to be serviced is decremented.

Average wait time = total wait time for all customers/total number of customers

Input: The number of servers, the distribution of arrival times, the expected service time and the length of the simulation.

Objects were created that represent customers (they keep track of how long they are waiting), tellers( they can be busy or free), the line ( a queue of customers) and timers(tellers decrement their timer and customers on line increment their timers).

A random number generator was used to determine the probability of a customer arriving during each loop iteration: (0.0 – no arrival to 1.0 – definitely arrives). For example, if a customer arrives on an average of every 5 minutes, the probability is 1 chance in 5 (or .2)
