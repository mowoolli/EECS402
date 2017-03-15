#include <iostream>

using namespace std;

//Programmer: Marc Woolliscroft
//Date: February 18, 2013

//This program is used to make histograms

const int MAXIMUM_SIZE_OF_DATA_SETS = 100;
const int MAXIMUM_NUMBER_OF_BINS = 100;
const double PARTITION_PRECISION = 0.0000005;
const int NUMBER_OF_PRINTED_VALUES = 5;

//This function will present the program menu to the user, and
//request user input from standard input (i.e. "cin"). If the
//user enters an invalid choice, an error message is printed,
//and the menu is re-printed and the user is re-prompted. This
//continues until the user finally enters a valid choice, and
//that choice will be returned from the function.
int promptUserAndGetChoice();
Exit the program
class SamplingClass
{
  public:
    char samplingIdentifier;
    int numberOfValues;
    double arrayOfSamples[MAXIMUM_SIZE_OF_DATA_SETS];
    bool characterEntered;

    //This function reads attributes describing a SamplingClass object
    //from standard input (i.e. "cin"). The user will be prompted for a
    //character identifier, then will be allowed to enter as many
    //floating point values as desired (up to the maximum allowed by
    //the program) and will indicate completion by entering the special
    //value "-999", at which point data value entry will cease, and
    //this last special value will NOT be included in the sample set.
    //The function returns true upon success, and false on failure.
    bool readFromKeyboard();

    //This function prints out the attributes of a SamplingClass object
    //to the screen, including the identifying character, the total
    //number of samples in the sample set, and each individual data
    //value. Multiple data values will be printed on each line – the
    //number per line will be defined in a global constant, with the
    //possible obvious exception of the last line printed if the number
    //of samples doesn't evenly divide the number to be printed per
    //line. The function returns true for ANY sample set for which the
    //user has entered at least an identifying character, false when
    //called to print a sample set that the user has not initialized.
    bool printToScreen();
};

class HistogramClass
{
  private:
    double minimumOfRange;
    double maximumOfRange;
    int numberOfBins;
    int binCounts[MAXIMUM_NUMBER_OF_BINS];
    bool histogramSetup;

  public:  
    //This function allows the user to setup a histogram by reading
    //values for the minimum bin value, maximum bin value, and the
    //number of bins, which can be up to the maximum number of bins
    //allowed by the program, which will be stored in an appropriately
    //named global constant. The function returns true when the user
    //enters valid values supported by the program, false otherwise.
    bool setupHistogram();

    //This function adds counts to a previously set-up histogram's bins
    //appropriately. Data values are taken from the sampling parameter,
    //and one bin count is incremented for each value in the sampling.
    //Note: This function adds data to a histogram, and does NOT re-
    //initialize the counts to zero when called! If a user wishes to
    //start a new histogram with new counts, then setupHistogram() must
    //be called. The function returns true on success, and false
    //otherwise. One possible failure would be if the necessary objects
    //haven't been setup/initialized by the user.
    bool addDataToHistogram(SamplingClass &sampling);

    //This function simply prints out the bin counts (and percentages)
    //for each bin in the previously set up histogram. Specific output
    //format can be seen in example outputs. Returns true on success,
    //false otherwise.
    bool printHistogramCounts();

    //This function displays a graph-like representation of the
    //histogram contents, allowing users to easily see how the sample
    //data values are distributed in the bin range they have set up.
    //Each bin will be indicated by a series of bars (equal-sign
    //characters), one bar for each 2%. In other words, if a bin
    //contains 12.5% of the total count in all bins, that bin would be
    //displayed with 6 bars. Specific output format can be seen in
    //example outputs. Returns true on success, false otherwise.
    bool displayHistogram();
};

SamplingClass sampling;
HistogramClass histoData;
//HistogramClass histoData2;

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else

int main()
{

  int menuSelection = promptUserAndGetChoice();

  while (menuSelection != 0)
  {
    if (menuSelection == 1)
    {
      sampling.SamplingClass::readFromKeyboard();
      menuSelection = promptUserAndGetChoice();
    }
    else if (menuSelection == 2)
    {
      sampling.SamplingClass::printToScreen();
      menuSelection = promptUserAndGetChoice();
    }
    else if (menuSelection == 3)
    {
      histoData.HistogramClass::setupHistogram();
      menuSelection = promptUserAndGetChoice();
    }
    else if (menuSelection == 4)
    {
      histoData.HistogramClass::addDataToHistogram(sampling);
      menuSelection = promptUserAndGetChoice();
    }
    else if (menuSelection == 5)
    {
      histoData.HistogramClass::printHistogramCounts();
      menuSelection = promptUserAndGetChoice();
    }
    else if (menuSelection == 6)
    {
      histoData.HistogramClass::displayHistogram();
      menuSelection = promptUserAndGetChoice();
    }
  }

  if (menuSelection == 0)
  {
    cout << "Thanks for using the histogram generator!" << endl;
 t the program 

  return (0);
}

#endif

int promptUserAndGetChoice()
{
  int menuChoice;

  cout << " " << endl;
  cout << "1. Enter a sample set of data values" << endl;
  cout << "2. Print the contents of the current sample set" << endl;
  cout << "3. Reset / Provide values for setting up a histogram" << endl;
  cout << "4. Add the contents of current sample set to histogram" << endl;
  cout << "5. Print bin counts contained in histogram" << endl;
  cout << "6. View the histogram in graphical form" << endl;
  cout << "0: Exit the program" << endl;
  cout << " " << endl;
  cout << "Your Choice: ";
  cin >> menuChoice;
  cout << " " << endl;

  while (menuChoice != 1 && menuChoice != 2 && menuChoice != 3 && menuChoice !=
         4 && menuChoice != 5 && menuChoice != 6 && menuChoice != 0)
  {
    cout << "Sorry that is an invalid menu choice - try again!" << endl;
    cout << " " << endl;
    cout << "1. Enter a sample set of data values" << endl;
    cout << "2. Print the contents of the current sample set" << endl;
    cout << "3. Reset / Provide values for setting up a histogram" << endl;
    cout << "4. Add the contents of current sample set to histogram" << endl;
    cout << "5. Print bin counts contained in histogram" << endl;
    cout << "6. View the histogram in graphical form" << endl;
    cout << "0: Exit the program" << endl;
    cout << " " << endl;
    cout << "Your Choice: ";
    cin >> menuChoice;
    cout << " " << endl;
  }

  return (menuChoice);
}

bool SamplingClass::readFromKeyboard()
{
  double sampleValue;
  int specialEndingValue = -999;
  bool specialEndingValueEntered = false;
  bool exceededMaximumSetSize = false;
  characterEntered = false;
  numberOfValues = 0;

  cout << "Enter character identifier for this sampling: ";
  cin >> samplingIdentifier;
  cout << " " << endl;
  cout << "Enter all samples, then enter -999 to end:" << endl;

  characterEntered = true;

  while (!specialEndingValueEntered && !exceededMaximumSetSize)
  {
    cin >> sampleValue;

    if (sampleValue == specialEndingValue)
    {
      specialEndingValueEntered = true;
    }
    else if (numberOfValues == MAXIMUM_SIZE_OF_DATA_SETS)
    {
      cout <<"ERROR: Too many samples input! Stopping input after 100 samples!";
      cout << endl;
      exceededMaximumSetSize = true;
    }
    else
    {
      arrayOfSamples[numberOfValues] = sampleValue;
      numberOfValues++;
    }
  }

  if (numberOfValues == MAXIMUM_SIZE_OF_DATA_SETS)
  {
    cout << "Last Operation Successful: NO" << endl;
    return (false);
  }
  else
  {
    cout << "Last Operation Successful: YES" << endl;
    return (true);
  }
}

bool SamplingClass::printToScreen()
{
  int elementCounter = 0;

  if (characterEntered == false)
  {
    cout << "ERROR: Can not print uninitialized sampling!" << endl;
    cout << "Last Operation Successful: NO" << endl;
    cout << " " << endl;
    
    return (false);
  }
  else
  {
    cout << "Data stored for sampling with identifier " << samplingIdentifier
    << ":" << endl;
    cout << "  Total Samples: " << numberOfValues << endl;
    cout << "  Samples (5 samples per line):" << endl;

      for (int i = 0; i < numberOfValues; i++)
      {
        cout << arrayOfSamples[i] << " ";
        elementCounter++;

        if (elementCounter == 5)
        {
          cout << " " << endl;
          elementCounter = 0;
        }
      }

    cout << "Last Operation Successful: YES" << endl;

    return (true);
  }
} 

bool HistogramClass::setupHistogram()
{
  histogramSetup = false;

  cout << "Enter minimum value: ";
  cin >> minimumOfRange;
  cout << endl;
  cout << "Enter maximum value: ";
  cin >> maximumOfRange;
  cout << endl;

  if (minimumOfRange >= maximumOfRange)
  {
    cout << "ERROR: The minimum must be less than the maximum" << endl;
    cout << "Last Operation Successful: NO" << endl;

    return (false);
  }

  cout << "Enter number of bins: ";
  cin >> numberOfBins;
  cout << endl;

  if (numberOfBins <= 0)
  {
    cout << "ERROR: Number of bins must be positive and less than 100" << endl;
    cout << "Last Operation Successful: NO" << endl;
    
    return (false);
  }
  else if (numberOfBins > MAXIMUM_NUMBER_OF_BINS)
  {
    cout << "ERROR: Maximum number of bins allowed is ";
    cout << MAXIMUM_NUMBER_OF_BINS << endl;
    cout << "Last Operation Successful: NO" << endl;
    
    return (false);
  }
  else
  {
    cout << "Last Operation Successful: YES" << endl;
    histogramSetup = true;

    return (true);
  }
}

bool HistogramClass::addDataToHistogram(SamplingClass &sampling)
{
  if (histogramSetup == false)
  {
    cout << "ERROR: Histogram is not ready to be generated!" << endl;
    cout << "Last Operation Successful: NO" << endl;

    return (false);
  }
  else if (sampling.characterEntered == false)
  {
    cout << "ERROR: No samples to put into histogram!" << endl;
    cout << "Last Operation Successful: NO" << endl;

    return (false);
  }

  int k = 1;

  for (int r = 0; r <= sampling.numberOfValues; r++)
  {
    if (sampling.arrayOfSamples[r] <= minimumOfRange + PARTITION_PRECISION)
    {
      binCounts[0]++;
    }
    else if (sampling.arrayOfSamples[r] >= maximumOfRange + PARTITION_PRECISION)
    {
      binCounts[numberOfBins + 1]++;
    }
    else
    {
    }
  }

  binCounts[0]--;

  while (k <= numberOfBins)
  {
    for (int j = 0; j <= sampling.numberOfValues; j++)
    {
      if (sampling.arrayOfSamples[j] < (((maximumOfRange - minimumOfRange) /
          numberOfBins) * k + minimumOfRange) + PARTITION_PRECISION &&
          sampling.arrayOfSamples[j] > (((maximumOfRange - minimumOfRange) /
          numberOfBins) * (k - 1) + minimumOfRange) + PARTITION_PRECISION)
      {
        binCounts[k]++;
      }
    }
    
    k++;

  }

  cout << "Last Operation Successful: YES" << endl;

  return (true);

}

bool HistogramClass::printHistogramCounts()
{
  if (histogramSetup == false)
  {
    cout << "ERROR: Can not display uninitialized histogram!" << endl;
    cout << "Last Operation Successful: NO" << endl;

    return (false);
  }

  int t;

  cout << "Bin <min: " << binCounts[0] << "  (";
  cout << ((double)binCounts[0]/(double)sampling.numberOfValues)*100 << "%)";
  cout << endl;

  for (t = 1; t <= numberOfBins; t++)
  {
    cout << "Bin    " << t << ": " << binCounts[t] << "  (";
    cout << ((double)binCounts[t]/(double)sampling.numberOfValues)*100 << "%)";
    cout << endl;
  }

  cout << "Bin >max: " << binCounts[t] << "  (";
  cout << ((double)binCounts[t]/(double)sampling.numberOfValues)*100 << "%)";
  cout << endl;
  cout << "Last Operation Successful: YES" << endl;

  return (true);
}

bool HistogramClass::displayHistogram()
{
  int q;
  int p = 1;

  if (histogramSetup == false)
  {
    cout << "ERROR: Can not display uninitialized histogram!" << endl;
    cout << "Last Operation Successful: NO" << endl;

    return (false);
  }

  cout << "Bin <min: ";

  for (q = 2; q <= (((double)binCounts[0]/(double)sampling.numberOfValues)*100);
       q = q + 2)
  {
    cout << "=";
  }
  
  cout << endl;

  while (p <= numberOfBins)
  { 
    cout << "Bin    " << p << ": ";
  
    for (q = 2; q <= (((double)binCounts[p]/(double)sampling.numberOfValues)
         *100); q = q + 2)
    {
      cout << "=";
    }
    cout << endl;
    p++;
  }

  cout << "Bin >max: ";
  
  for (q = 2; q <= (((double)binCounts[p]/(double)sampling.numberOfValues)*100);
       q = q + 2)
  {
    cout << "=";
  }

  cout << endl;
  cout << "Last Operation Successful: YES" << endl;
  return (true);
}
