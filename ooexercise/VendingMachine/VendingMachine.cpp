// $Id$ 
///////////////////////////////////////////////////////////////////////////////
/**
 * @file  VendingMachine.cpp 
 * @brief Implementation of the Class VendingMachine
 * @version 
 * @e 1.0 17-1-2017
 */
///////////////////////////////////////////////////////////////////////////////
//              Copyright (c) 2017 Tokyo Electron Limited.
//                         All rights reserved.                  
///////////////////////////////////////////////////////////////////////////////
#include "VendingMachine.h"

using vending::VendingMachine;


VendingMachine::VendingMachine()
    : quantityOfCoke_(0)
    , quantityOfDietCoke_(0)
    , quantityOfTea_(0)
    , numberOf100Yen_(0)
    , charge_(0)
{
}

VendingMachine::VendingMachine(int quantityOfCoke, int quantityOfDietCoke, int quantityOfTea, int numberOf100Yen)
    : quantityOfCoke_(quantityOfCoke)
    , quantityOfDietCoke_(quantityOfDietCoke)
    , quantityOfTea_(quantityOfTea)
    , numberOf100Yen_(numberOf100Yen)
    , charge_(0)
{
}

VendingMachine::~VendingMachine()
{
}

vending::Drink VendingMachine::buy(int i, int kindOfDrink)
{
    // 100‰~‚Æ500‰~‚¾‚¯Žó‚¯•t‚¯‚é
    if ((i != 100) && (i != 500)) {
        charge_ += i;
        return vending::Drink();
    }

    if ((kindOfDrink == vending::Drink().COKE_) && (quantityOfCoke_ == 0)) {
        charge_ += i;
        return vending::Drink();
    } else if ((kindOfDrink == vending::Drink().DIET_COKE_) && (quantityOfDietCoke_ == 0)) {
        charge_ += i;
        return vending::Drink();
    } else if ((kindOfDrink == vending::Drink().TEA_) && (quantityOfTea_ == 0)) {
        charge_ += i;
        return vending::Drink();
    }

    // ’Þ‚è‘K•s‘«
    if (i == 500 && numberOf100Yen_ < 4) {
        charge_ += i;
        return vending::Drink();
    }

    if (i == 100) {
        // 100‰~‹Ê‚ð’Þ‚è‘K‚ÉŽg‚¦‚é
        numberOf100Yen_++;
    } else if (i == 500) {
        // 400‰~‚Ì‚¨’Þ‚è
        charge_ += (i - 100);
        // 100‰~‹Ê‚ð’Þ‚è‘K‚ÉŽg‚¦‚é
        numberOf100Yen_ -= (i - 100) / 100;
    }

    if (kindOfDrink == vending::Drink().COKE_) {
        quantityOfCoke_--;
    } else if (kindOfDrink == vending::Drink().DIET_COKE_) {
        quantityOfDietCoke_--;
    } else {
        quantityOfTea_--;
    }

    return Drink(kindOfDrink);
}

int VendingMachine::refund()
{
    int result = charge_;
    charge_ = 0;
    return result;
}
