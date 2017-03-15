#include <iostream>
using namespace std;

//Programmer: Marc Woolliscroft
//Date: January 30, 2013
//Purpose: The purpose of this program is to calculate the area between a cubic
//curve and the x-axis.

double toThePower(double val, int power);
//Takes "val" and raises it to the power "power" when called

void printMenu();
//Prints the main menu options for the user when called

double approximateAreaWithRect(double aCoeff, double bCoeff, double cCoeff, 
double dCoeff, double startX, double endX, int num);
//Approximates the area between the cubic function y = a * x^3 + b * x^2 + c * x
//+ d and the x-axis using "num" number of rectangles

double approximateAreaWithTrap(double aCoeff, double bCoeff, double cCoeff, 
double dCoeff, double startX, double endX, int num); 
//pproximates the area between the cubic function y = a * x^3 + b * x^2 + c * x
//+ d and the x-axis using "num" number of trapezoids

int main()
{
    int menuChoice;

    printMenu();

    cin >> menuChoice;

    while (menuChoice != 5)
    {
        if (menuChoice == 1)
        {
            double aCoeff;
            double bCoeff;
            double cCoeff;
            double dCoeff;
            double startX;
            double endX;
            int num;

            cout <<"YOUR CHOICE: " << menuChoice << endl;
            cout <<"Enter (a b c d) for function y = a*x^3 + b*x^2 + c*x + d: "
            << endl;
            cin >> aCoeff >> bCoeff >> cCoeff >> dCoeff;
            cout <<"Now enter x start and end values: " << endl;
            cin >> startX >> endX;

            while (startX >= endX)
            {
                cout <<"Invalid range entered " << endl;
                cout <<"Now enter x start and end values: " << endl;
                cin >> startX >> endX;
            }

            cout <<"Enter the number of rectangles to use: " << endl;
            cin >> num;

            while (num <= 0)
            {
                cout <<"Invalid number of rectangles " << endl;
                cout <<"Enter the number of rectangles to use: " << endl;
                cin >> num;
            }

            double area = approximateAreaWithRect(aCoeff, bCoeff, cCoeff,
            dCoeff, startX, endX, num);
            cout <<"Rectangle result is: " << area << endl;
            printMenu();
            cin >> menuChoice;
        }
        else
            if (menuChoice == 2)
            {
                double aCoeff;
                double bCoeff;
                double cCoeff;
                double dCoeff;
                double startX;
                double endX;
                int num;

                cout <<"YOUR CHOICE: " << menuChoice << endl;
                cout <<"Enter (a b c d) for function y = a*x^3 + b*x^2 + c*x + "
                << "d: " << endl;
                cin >> aCoeff >> bCoeff >> cCoeff >> dCoeff;
                cout <<"Now enter x start and end values: " << endl;
                cin >> startX >> endX;

                while (startX >= endX)
                {
                    cout <<"Invalid range entered " << endl;
                    cout <<"Now enter x start and end values: " << endl;
                    cin >> startX >> endX;
                }
    
                cout <<"Enter the number of trapezoids to use: " << endl;
                cin >> num;

                while (num <= 0)
                {
                    cout <<"Invalid number of trapezoids " << endl;
                    cout <<"Enter the number of trapezoids to use: " << endl;
                    cin >> num;
                }

                double area = approximateAreaWithTrap(aCoeff, bCoeff, cCoeff,
                dCoeff, startX, endX, num);
                cout <<"Trapezoid result is: " << area << endl;
                printMenu();
                cin >> menuChoice;
            }
        else
            if (menuChoice == 3)
            {
                double aCoeff;
                double bCoeff;
                double cCoeff;
                double dCoeff;
                double startX;
                double endX;
                double correctAreaWithRect;
                double precisionWithRect;
                int num = 1;
                bool oneHundredRectTried;
                
                cout <<"YOUR CHOICE: " << menuChoice << endl;
                cout <<"Enter (a b c d) for function y = a*x^3 + b*x^2 + c*x + " 
                << "d: " << endl;
                cin >> aCoeff >> bCoeff >> cCoeff >> dCoeff;
                cout <<"Now enter x start and end values: " << endl;
                cin >> startX >> endX;
    
                while (startX >= endX)
                {
                    cout <<"Invalid range entered " << endl;
                    cout <<"Now enter x start and end values: " << endl;
                    cin >> startX >> endX;
                }
    
                cout <<"Enter correct answer: " << endl;
                cin >> correctAreaWithRect;
                cout <<"Enter precision to reach: " << endl;
                cin >> precisionWithRect;

                if (approximateAreaWithRect(aCoeff, bCoeff, cCoeff, dCoeff, 
                startX, endX, num) > correctAreaWithRect)
                {
                    do
                    {                        
                        approximateAreaWithRect(aCoeff, bCoeff, cCoeff, dCoeff,
                        startX, endX, num);
                        num++;
                        oneHundredRectTried = false;

                        if (num == 100)
                        {
                            cout <<"Tried 100 rectangles without reaching " 
                            << "precision" << endl;
                            oneHundredRectTried = true;
                        }
                
                    }
                    while (approximateAreaWithRect(aCoeff, bCoeff, cCoeff, 
                    dCoeff, startX, endX, num) - correctAreaWithRect > 
                    precisionWithRect && !oneHundredRectTried);

                    if (num < 100)
                    {
                        cout <<"Rectangles needed to reach precision: " << num
                        << endl;
                    }
                }
                else
                {
                    do
                    {
                        approximateAreaWithRect(aCoeff, bCoeff, cCoeff, 
                        dCoeff, startX, endX, num);
                        num++;
                        oneHundredRectTried = false;

                        if (num == 100)
                        {
                            cout <<"Tried 100 rectangles without reaching " 
                            << "precision" << endl;
                            oneHundredRectTried = true;
                        }

                    }
                    while (correctAreaWithRect - approximateAreaWithRect(aCoeff,
                    bCoeff, cCoeff, dCoeff, startX, endX, num) > 
                    precisionWithRect && !oneHundredRectTried);

                    if (num < 100)
                    {
                        cout <<"Rectangles needed to reach precision: " << num 
                        << endl;
                    }
                }

                printMenu();
                cin >> menuChoice;
            }
        else
            if (menuChoice == 4)
            {
                double aCoeff;
                double bCoeff;
                double cCoeff;
                double dCoeff;
                double startX;
                double endX;
                double correctAreaWithTrap;
                double precisionWithTrap;
                int num = 1;
                bool oneHundredTrapTried;

                cout <<"YOUR CHOICE: " << menuChoice << endl;
                cout <<"Enter (a b c d) for function y = a*x^3 + b*x^2 + c*x + "
                << "d: " << endl;
                cin >> aCoeff >> bCoeff >> cCoeff >> dCoeff;
                cout <<"Now enter x start and end values: " << endl;
                cin >> startX >> endX;

                while (startX >= endX)
                {
                    cout <<"Invalid range entered " << endl;
                    cout <<"Now enter x start and end values: " << endl;
                    cin >> startX >> endX;
                }

                cout <<"Enter correct answer: " << endl;
                cin >> correctAreaWithTrap;
                cout <<"Enter precision to reach: " << endl;
                cin >> precisionWithTrap;
                
                if (approximateAreaWithTrap(aCoeff, bCoeff, cCoeff, dCoeff, 
                startX, endX, num) > correctAreaWithTrap)
                {
                    do
                    {
                        approximateAreaWithTrap(aCoeff, bCoeff, cCoeff, dCoeff,
                        startX, endX, num);
                        num++;
                        oneHundredTrapTried = false;

                        if (num == 100)
                        {
                            cout <<"Tried 100 trapezoids without reaching "
                            << "precision" << endl;
                            oneHundredTrapTried = true;
                        }
                    }
                    while (approximateAreaWithTrap(aCoeff, bCoeff, cCoeff, 
                    dCoeff, startX, endX, num) - correctAreaWithTrap > 
                    precisionWithTrap && !oneHundredTrapTried);
               
                    if (num < 100)
                    { 
                        cout <<"Trapezoids needed to reach precision: " << num 
                        << endl;
                    }      
                }
                else
                {
                    do
                    {                        
                        approximateAreaWithTrap(aCoeff, bCoeff, cCoeff, dCoeff,
                        startX, endX, num);
                        num++;
                        oneHundredTrapTried = false;

                        if (num == 100)
                        {
                            cout <<"Tried 100 trapezoids without reaching "
                            << "precision" << endl;
                            oneHundredTrapTried = true;
                        }
                    }
                    while (correctAreaWithTrap - approximateAreaWithTrap(aCoeff,
                    bCoeff, cCoeff, dCoeff, startX, endX, num) > 
                    precisionWithTrap && !oneHundredTrapTried);

                    if (num < 100)
                    {
                        cout <<"Trapezoids needed to reach precision: " << num 
                        << endl;
                    }
                }

                printMenu();
                cin >> menuChoice;
            }
        else
        {
            cout <<"YOUR CHOICE: " << menuChoice << endl;
            cout <<"Ivalid menu choice entered " << endl;
            printMenu();
            cin >> menuChoice;
        }
    }

    if (menuChoice == 5)
    {
        cout <<"YOUR CHOICE: " << menuChoice << endl;
        cout <<"Thanks for using this program " << endl;
    }

    return (0);
}

double toThePower(double val, int power)
{
    double toThePowerResult;
    toThePowerResult = 1;

    for (int i = 1; i <= power; i++)
    {
        toThePowerResult = toThePowerResult*val;
    }
 
    return(toThePowerResult);
}

void printMenu()
{
    cout <<"1 Approximate Integral Using Rectangles" << endl;
    cout <<"2 Approximate Integral Using Trapezoids" << endl;
    cout <<"3 Experiment With Rectangle Precision" << endl;
    cout <<"4 Experiment With Trapezoid Precision" << endl;
    cout <<"5 Quit The Program" << endl;
}

double approximateAreaWithRect(double aCoeff, double bCoeff, double cCoeff,
double dCoeff, double startX, double endX, int num)
{
    double approximateAreaWithRect = 0.0;
    double rectWidth = (endX - startX)/num;

    for (int j = 1; j <= num; j++)
    {
        if (rectWidth*(aCoeff * toThePower(((startX + (j - 1) *
        rectWidth) + startX + j * rectWidth)/2, 3) + bCoeff * 
        toThePower(((startX + (j - 1) * rectWidth) + startX + j * 
        rectWidth)/2, 2) + cCoeff * toThePower(((startX + (j - 1) * rectWidth) 
        + startX + j * rectWidth)/2, 1) + dCoeff) < 0)
        {
            approximateAreaWithRect += -rectWidth*(aCoeff * 
            toThePower(((startX + (j - 1) * rectWidth) + startX + j * 
            rectWidth)/2, 3) + bCoeff * toThePower(((startX + (j - 1) * 
            rectWidth) + startX + j * rectWidth)/2, 2) + cCoeff * 
            toThePower(((startX + (j - 1) * rectWidth) + startX + j * 
            rectWidth)/2, 1) + dCoeff);
        }
        else
        {
            approximateAreaWithRect += rectWidth*(aCoeff * toThePower(((startX +
            (j - 1) * rectWidth) + startX + j * rectWidth)/2, 3) + bCoeff * 
            toThePower(((startX + (j - 1) * rectWidth) + startX + j * 
            rectWidth)/2, 2) + cCoeff * toThePower(((startX + (j - 1) * 
            rectWidth) + startX + j * rectWidth)/2, 1) + dCoeff);
        }
    }

    return(approximateAreaWithRect);
}

double approximateAreaWithTrap(double aCoeff, double bCoeff, double cCoeff,
double dCoeff, double startX, double endX, int num)
{
    double approximateAreaWithTrap = 0.0;
    double trapWidth = (endX - startX)/num;

    for (int k = 1; k <= num; k++)
    {
        if ((1.0/2.0)*trapWidth*(aCoeff * toThePower((startX + (k - 1) *
        trapWidth), 3) + aCoeff * toThePower((startX + k * trapWidth), 3) + 
        bCoeff * toThePower((startX + (k - 1) * trapWidth), 2) + bCoeff * 
        toThePower((startX + k * trapWidth), 2) + cCoeff * toThePower((startX +
        (k - 1) * trapWidth), 1) + cCoeff * toThePower((startX + k * 
        trapWidth), 1) + dCoeff + dCoeff) < 0)
        {
            approximateAreaWithTrap += -(1.0/2.0)*trapWidth*(aCoeff * 
            toThePower((startX + (k - 1) * trapWidth), 3) + aCoeff * 
            toThePower((startX + k * trapWidth), 3) + bCoeff * 
            toThePower((startX + (k - 1) * trapWidth), 2) + bCoeff * 
            toThePower((startX + k * trapWidth), 2) + cCoeff * 
            toThePower((startX + (k - 1) * trapWidth), 1) + cCoeff * 
            toThePower((startX + k * trapWidth), 1) + dCoeff + dCoeff);
        }
        else
        {
            approximateAreaWithTrap += (1.0/2.0)*trapWidth*(aCoeff * 
            toThePower((startX + (k - 1) * trapWidth), 3) + aCoeff * 
            toThePower((startX + k * trapWidth), 3) + bCoeff * 
            toThePower((startX + (k - 1) * trapWidth), 2) + bCoeff * 
            toThePower((startX + k * trapWidth), 2) + cCoeff * 
            toThePower((startX + (k - 1) * trapWidth), 1) + cCoeff * 
            toThePower((startX + k * trapWidth), 1) + dCoeff + dCoeff);
        }
    }

    return(approximateAreaWithTrap);

}


