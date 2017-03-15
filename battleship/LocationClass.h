//
//  LocationClass.h
//  b3
//
//  Created by Jordan Fleischer on 4/16/13.
//  Copyright (c) 2013 Jordan Fleischer. All rights reserved.
//

#ifndef __b3__LocationClass__
#define __b3__LocationClass__

#include <iostream>

class LocationClass {
private:
   int row;
   int col;
   
public:
   LocationClass(int r, int c);
   int getRow() const;
   int getCol() const;
   
   bool operator<(const LocationClass &rhs)const;
   bool operator>(const LocationClass &rhs)const;
   bool operator<=(const LocationClass &rhs)const;
   bool operator>=(const LocationClass &rhs)const;
   bool operator==(const LocationClass &rhs)const;
   
};

#endif /* defined(__b3__LocationClass__) */
