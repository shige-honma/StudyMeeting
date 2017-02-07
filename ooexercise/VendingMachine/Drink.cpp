// $Id$ 
///////////////////////////////////////////////////////////////////////////////
/**
 * @file  Drink.cpp 
 * @brief Implementation of the Class Drink
 * @version 
 * @e 1.0 17-1-2017
 */
///////////////////////////////////////////////////////////////////////////////
//              Copyright (c) 2017 Tokyo Electron Limited.
//                         All rights reserved.                  
///////////////////////////////////////////////////////////////////////////////
#include "Drink.h"

using vending::Drink;


Drink::Drink()
    : kind_( UNKNOWN_ )
{
}



Drink::~Drink()
{
}



Drink::Drink(int kind)
    : kind_( kind )
{
}



int Drink::getKind()
{
    return kind_;
}
