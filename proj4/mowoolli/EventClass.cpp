#include <iostream>
#include <cstdlib>
#include "ListNodeClass.h"
#include "SortedListClass.h"
#include "EventClass.h"

using namespace std;
int EventClass::getArriveTime(int &previousTime, int &min, int &max)
{
  int seedVal = 22;
//  min = 5;
//  max = 15;

//  srand(seedVal);
  int uniRand;
  uniRand = rand() % ((max + 1) - min) + min;
  arrivalTime = uniRand;
  int getArriveTime = arrivalTime + previousTime;

  return (getArriveTime);
}

int EventClass::getDepartTime(int &inputTime, float &mean, float &stdDev)
{
//  mean = 7;
//  stdDev = 1.5;
  const int NUM_UNIFORM = 12;
  const int MAX = 1000;
  const float ORIGINAL_MEAN = NUM_UNIFORM * 0.5;
  float sum;
  int i;
  float standardNormal;
  float newNormal;
  int uni;
  sum = 0;

  for (i = 0; i < NUM_UNIFORM; i++)
  {
    uni = rand() % (MAX + 1);
    sum += uni;
  }
    sum = sum / MAX;
    standardNormal = sum - ORIGINAL_MEAN;
    newNormal = mean + stdDev * standardNormal;
  if (newNormal < 0)
  {
    newNormal *= -1;
  }

  serveTime = (int)newNormal;
  int getServeTime = serveTime + inputTime;

  return (getServeTime);
}

