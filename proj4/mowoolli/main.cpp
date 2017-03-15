#include <iostream>
#include "ListNodeClass.h"
#include "SortedListClass.h"
#include "QueueClass.h"
#include "EventClass.h"

using namespace std;
int main()
{

  int curTime = 0; //Will be set to openTime from user input
  int custDepart = 0; //Will initially be set to openTime from user input
  float runTime; //Will be set to closeTime from user input
  int custEntered = 0; //Initially set to zero. Will increment for every customer that enters
  int custServed = 0; //Initially set to zero. Will increment for every customer served
  int custArrive = 0; //Initially set to zero
  int timeServing = 0; //Keeps track of how long the server is busy helping customers during restaurant hours
  int hadToWait = 0; //Keeps track of the number of customers that have to wait in line
  int maxLineLength = 0; //Initially set to zero. Will keep track of the maximum length of the line
  int maxWaitTime = 0; //Initially set to zero. Will keep track of maximum time a served customed had to wait
  int getArrive = 1; //Used as the input for getting a value at an index of the sorted list
  int getDepart = 1; //Used as the input for getting a value at an index of the sorted list
  int previousArrive = 0; //Used to get the previous customer's arrival time
  float hoursOpen; //Number of hours the restaurant will be open
  bool validHours; //Used to reprint the hours option if the entry were invalid
  bool validMin; //Used to reprint the time between customers option if the entry were invalid
  bool validMax; //Used to reprint the time between customers option if the entry were invalid
  bool validMean; //Used to reprint the service time option if the entry were invalid
  bool validStdDev; //Used to reprint the service time option if the entry were invalid
  int min; //Used for the minimum time between customers
  int max; //Used for the maximum time between customers
  float mean; //Used for the mean service time
  float stdDev; //Used for the service time standard deviation
  int waitTime = 0; //Initially set to zero. Will increase as customers wait in line

  cout << endl;
  cout << "Welcome to The Restaurant Simulator!" << endl;
  cout << "Enter the number of hours you want your restaurant to be open: ";

  validHours = false;

  while (!validHours)
  {
    cin >> hoursOpen;
    cout << endl;
    if (cin.fail() || hoursOpen <= 0)
    {
      cin.clear();
      cin.ignore(200, '\n');
      cout <<"Error: the hours must be a number greater than zero!" << endl;
      cout << "Enter the number of hours the restaurant should be open: ";
    }
    else
    {
      validHours = true;
    }
  }
  
  cout << "Enter the minimum time between customers: ";

  validMin = false;

  while (!validMin)
  {
    cin >> min;
    cout << endl;
    if (cin.fail() || min <= 0)
    {
      cin.clear();
      cin.ignore(200, '\n');
      cout <<"Error: the minimum time between customers must be an integer greater than zero!" << endl;
      cout << "Enter the minimum time between customers: ";
    }
    else
    {
      validMin = true;
    }
  }

  cout << "Enter the maximum time between customers: ";

  validMax = false;

  while (!validMax)
  {
    cin >> max;
    cout << endl;
    if (cin.fail() || max < min)
    {
      cin.clear();
      cin.ignore(200, '\n');
      cout <<"Error: the maximum time between customers must be an integer greater than or equal to the minimum time!" << endl;
      cout << "Enter the maximum time between customers: ";
    }
    else
    {
      validMax = true;
    }
  }

  cout << "Enter the mean service time: ";

  validMean = false;

  while (!validMean)
  {
    cin >> mean;
    cout << endl;
    if (cin.fail() || mean <= 0)
    {
      cin.clear();
      cin.ignore(200, '\n');
      cout <<"Error: the mean service time must be a number greater than zero!" << endl;
      cout << "Enter the mean service time: ";
    }
    else
    {
      validMean = true;
    }
  }

  cout << "Enter the service time standard deviation: ";

  validStdDev = false;

  while (!validStdDev)
  {
    cin >> stdDev;
    cout << endl;
    if (cin.fail() || stdDev < 0)
    {
      cin.clear();
      cin.ignore(200, '\n');
      cout <<"Error: the service time standard deviation must be a number greater than or equal to zero!"                   << endl;
      cout << "Enter the service time standard deviation: ";
    }
    else
    {
      validStdDev = true;
    }
  }

  runTime = 60*hoursOpen;
  runTime = (int)runTime;

  EventClass *arrive;
  arrive = new EventClass;

  SortedListClass< int > *arrivalTime;
  arrivalTime = new SortedListClass< int >;

  SortedListClass< int > *departureTime;
  departureTime = new SortedListClass< int >;

  QueueClass< int > *custQueue;
  custQueue = new QueueClass< int >;

  EventClass *depart;
  depart = new EventClass;

  do 
  {
    curTime = custArrive;

    custArrive = arrive->EventClass::getArriveTime(curTime, min, max);

//The following loop is if a customer tries to enter after the restaurant closes

    if (custArrive > runTime)
    {
      break;
    }
    
    arrivalTime->SortedListClass< int >::insertValue(custArrive);

//The following loop is if there is no line at the restaurant

    if (custQueue->QueueClass< int >::sizeOfQueue() == 0)
    {

//The following loop is if there is no line but the server is unavailable

      if (custArrive < custDepart)
      {
        custQueue->QueueClass< int >::enqueue(custEntered);

        arrivalTime->SortedListClass< int >::getElemAtIndex(custEntered - 1, previousArrive);

        timeServing = timeServing + (custArrive - previousArrive);

        hadToWait++;
      }

//The following loop is if there is no line and the server is available

      else
      {
        custDepart = depart->EventClass::getDepartTime(custArrive, mean, stdDev);

        departureTime->SortedListClass< int >::insertValue(custDepart);

        timeServing = timeServing + (custDepart - custArrive);

        custServed++;
      }
    }

//The following loop is if there is a line at the restaurant

    else
    {

//The following loop is if there is a line but the server finished serving someone

      if (custArrive >= custDepart)
      {
        custDepart = depart->EventClass::getDepartTime(custArrive, mean, stdDev);

        departureTime->SortedListClass< int >::insertValue(custDepart);

//The following loop is if a customer arrived strictly before closing

        if (custArrive < runTime)
        {
          custQueue->QueueClass< int >::dequeue();

          arrivalTime->SortedListClass< int >::getElemAtIndex(custServed, getArrive);
          departureTime->SortedListClass< int >::getElemAtIndex(custServed - 1, getDepart);

          waitTime = waitTime + getDepart - getArrive;

          if (getDepart - getArrive > maxWaitTime)
          {
            maxWaitTime = getDepart - getArrive;
          }

          timeServing = timeServing + (custDepart - custArrive);

          custServed++;
        }
      }

      else
      {
        arrivalTime->SortedListClass< int >::getElemAtIndex(custEntered - 1, previousArrive);

        timeServing = timeServing + (custArrive - previousArrive);
      }

      custQueue->QueueClass< int >::enqueue(custEntered);

      hadToWait++;
    }

//The following loop is to keep track of the maximum line length

    if (custQueue->QueueClass< int >::sizeOfQueue() > maxLineLength)
    {
      maxLineLength++;
    }

    custEntered++;
 
  cout << "Serving time = " << timeServing << " minutes" << endl;
  cout << "Customer number " << custEntered << " arrives at " << custArrive << " minutes" << endl;
  cout << "Next departure time for a customer is " << custDepart << " minutes" << endl;
  cout << endl;

  } while (custArrive < runTime);

  float percentTimeServing = (timeServing/(float)runTime)*100;
  float percentCustWait = (hadToWait/(float)custEntered)*100;
  float averageWaitTime = waitTime/((float)custEntered - (float)custQueue->QueueClass< int >::sizeOfQueue());

  cout << "Total number of customers that entered the restaurant : " << custEntered << endl;
  cout << "Percentage of time server was busy helping customers : " << percentTimeServing << "%" << endl;
  cout << "Percentage of customers that had to wait in line : " << percentCustWait << "%" << endl;
  cout << "The longest the line was during restaurant hours : " << maxLineLength << " customers" << endl;
  cout << "Average time all customers who were served spent waiting in line : " << averageWaitTime << " minutes"        << endl;
  cout << "Maximum time a customer who was served spent waiting in line : " << maxWaitTime << " minutes" << endl;
  cout << "Number of customers left unserved at closing time : " << custQueue->QueueClass< int >::sizeOfQueue()         << endl;

  return (0);
}

