// $Id$ 
///////////////////////////////////////////////////////////////////////////////
/**
 * @file  VendingMachineTest.cpp 
 * @brief Implementation of the Class VendingMachineTest
 * @version 
 * @e 1.0 18-1-2017
 */
///////////////////////////////////////////////////////////////////////////////
//              Copyright (c) 2017 Tokyo Electron Limited.
//                         All rights reserved.                  
///////////////////////////////////////////////////////////////////////////////
#include "VendingMachineTest.h"
#include "VendingMachine.h"


using vending::VendingMachineTest;

CPPUNIT_TEST_SUITE_REGISTRATION( vending::VendingMachineTest );



VendingMachineTest::VendingMachineTest()
{
}

VendingMachineTest::~VendingMachineTest()
{
}

void VendingMachineTest::testBuyCoke()
{
    vending::VendingMachine vendingMachine( 5, 5, 5, 10 );
    vending::Drink drink = vendingMachine.buy( 100, vending::Drink().COKE_ );

    CPPUNIT_ASSERT( drink.getKind() == vending::Drink().COKE_ );
    CPPUNIT_ASSERT( vendingMachine.refund() == 0 );
}

void VendingMachineTest::testBuyDietCoke()
{
    vending::VendingMachine vendingMachine( 5, 5, 5, 10 );
    vending::Drink drink = vendingMachine.buy( 100, vending::Drink().DIET_COKE_ );

    CPPUNIT_ASSERT( drink.getKind() == vending::Drink().DIET_COKE_ );
    CPPUNIT_ASSERT( vendingMachine.refund() == 0 );
}

void VendingMachineTest::testBuyTea()
{
    vending::VendingMachine vendingMachine( 5, 5, 5, 10 );
    vending::Drink drink = vendingMachine.buy( 100, vending::Drink().TEA_ );

    CPPUNIT_ASSERT( drink.getKind() == vending::Drink().TEA_ );
    CPPUNIT_ASSERT( vendingMachine.refund() == 0 );
}

void VendingMachineTest::testBuyUsing500Yen()
{
    vending::VendingMachine vendingMachine( 5, 5, 5, 4 );

    vending::Drink drink = vendingMachine.buy( 500, vending::Drink().TEA_ );

    CPPUNIT_ASSERT( drink.getKind() == vending::Drink().TEA_ );
    CPPUNIT_ASSERT( vendingMachine.refund() == 400 );
}

void VendingMachineTest::testInsertedMoneyCannotAcceptable()
{
    vending::VendingMachine vendingMachine( 5, 5, 5, 10 );
    vending::Drink drink = vendingMachine.buy( 1000, vending::Drink().COKE_ );

    CPPUNIT_ASSERT( drink.getKind() == vending::Drink().UNKNOWN_ );
    CPPUNIT_ASSERT( vendingMachine.refund() == 1000 );
}

void VendingMachineTest::testCokeIsSoldOut()
{
    vending::VendingMachine vendingMachine( 1, 5, 5, 10 );
    {
        vending::Drink drink = vendingMachine.buy( 100, vending::Drink().COKE_ );
        CPPUNIT_ASSERT( drink.getKind() == vending::Drink().COKE_ );
        CPPUNIT_ASSERT( vendingMachine.refund() == 0 );
    }
    {
        vending::Drink drink = vendingMachine.buy( 100, vending::Drink().COKE_ );
        CPPUNIT_ASSERT( drink.getKind() == vending::Drink().UNKNOWN_ );
        CPPUNIT_ASSERT( vendingMachine.refund() == 100 );
    }
}

void VendingMachineTest::testDietCokeIsSoldOut()
{
    vending::VendingMachine vendingMachine( 5, 1, 5, 10 );
    {
        vending::Drink drink = vendingMachine.buy( 100, vending::Drink().DIET_COKE_ );
        CPPUNIT_ASSERT( drink.getKind() == vending::Drink().DIET_COKE_ );
        CPPUNIT_ASSERT( vendingMachine.refund() == 0 );
    }
    {
        vending::Drink drink = vendingMachine.buy( 100, vending::Drink().DIET_COKE_ );
        CPPUNIT_ASSERT( drink.getKind() == vending::Drink().UNKNOWN_ );
        CPPUNIT_ASSERT( vendingMachine.refund() == 100 );
    }
}

void VendingMachineTest::testTeaIsSoldOut()
{
    vending::VendingMachine vendingMachine( 5, 5, 1, 10 );
    {
        vending::Drink drink = vendingMachine.buy( 100, vending::Drink().TEA_ );
        CPPUNIT_ASSERT( drink.getKind() == vending::Drink().TEA_ );
        CPPUNIT_ASSERT( vendingMachine.refund() == 0 );
    }
    {
        vending::Drink drink = vendingMachine.buy( 100, vending::Drink().TEA_ );
        CPPUNIT_ASSERT( drink.getKind() == vending::Drink().UNKNOWN_ );
        CPPUNIT_ASSERT( vendingMachine.refund() == 100 );
    }
}

void VendingMachineTest::testChangeIsShort()
{
    vending::VendingMachine vendingMachine( 5, 5, 5, 3 );
    {
        vending::Drink drink = vendingMachine.buy( 500, vending::Drink().TEA_ );
        CPPUNIT_ASSERT( drink.getKind() == vending::Drink().UNKNOWN_ );
        CPPUNIT_ASSERT( vendingMachine.refund() == 500 );
    }
    {
        vending::Drink drink = vendingMachine.buy( 100, vending::Drink().TEA_ );
        CPPUNIT_ASSERT( drink.getKind() == vending::Drink().TEA_ );
        CPPUNIT_ASSERT( vendingMachine.refund() == 0 );
    }
    {
        vending::Drink drink = vendingMachine.buy( 500, vending::Drink().TEA_ );
        CPPUNIT_ASSERT( drink.getKind() == vending::Drink().TEA_ );
        CPPUNIT_ASSERT( vendingMachine.refund() == 400 );
    }
}



