#include "CheckStream.h"


bool checkStream(std::istream &Stream){
   bool valid = true;
   if (Stream.fail()) {
      valid = false;
      Stream.clear();
      Stream.ignore(200, '\n');
			cout << "Error: Please try again." << endl;
   }
	 
   return (valid);
}