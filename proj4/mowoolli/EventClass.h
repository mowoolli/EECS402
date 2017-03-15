#ifndef EVENTCLASS_H_
#define EVENTCLASS_H_
class EventClass
{
  private:
    int arrivalTime;
    int serveTime;
    int totalTime;

  public:
    int getArriveTime(int &previousTime, int &min, int &max);
    int getDepartTime(int &inputTime, float &mean, float &stdDev);
};
#endif
