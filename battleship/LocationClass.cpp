//
//  LocationClass.cpp
//  b3
//
//  Created by Jordan Fleischer on 4/16/13.
//  Copyright (c) 2013 Jordan Fleischer. All rights reserved.
//

#include "LocationClass.h"

LocationClass::LocationClass(int r, int c){
   row = r;
   col = c;
}

int LocationClass::getCol()const{
   return col;
}

int LocationClass::getRow()const{
   return row;
}


bool LocationClass::operator<(const LocationClass &rhs) const{
   bool status = false;
   
   if (row < rhs.getRow()) {
      status = true;
   } else if(col < rhs.getCol()){
      status = true;
   }
   
   return status;
}

bool LocationClass::operator>(const LocationClass &rhs)const{
   bool status = false;
   
   if (row > rhs.getRow()) {
      status = true;
   } else if(col > rhs.getCol()){
      status = true;
   }
   
   return status;
}

bool LocationClass::operator<=(const LocationClass &rhs)const{
   bool status = false;
   
   if (row <= rhs.getRow()) {
      status = true;
   } else if(col <= rhs.getCol()){
      status = true;
   }
   
   return status;
}

bool LocationClass::operator>=(const LocationClass &rhs)const{
   bool status = false;
   
   if (row >= rhs.getRow()) {
      status = true;
   } else if(col >= rhs.getCol()){
      status = true;
   }
   
   return status;
}

bool LocationClass::operator==(const LocationClass &rhs)const{
   bool status = false;
   
   if (row == rhs.getRow()) {
      status = true;
   } else if(col == rhs.getCol()){
      status = true;
   }
   
   return status;
}



