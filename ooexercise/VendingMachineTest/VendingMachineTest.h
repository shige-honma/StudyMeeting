// $Id$ 
///////////////////////////////////////////////////////////////////////////////
/**
 * @file  VendingMachineTest.h
 * @brief Declaration of the Class VendingMachineTest
 * @version 
 * @e 1.0 18-1-2017
 */
///////////////////////////////////////////////////////////////////////////////
//              Copyright (c) 2017 Tokyo Electron Limited.
//                         All rights reserved.                  
///////////////////////////////////////////////////////////////////////////////
#if !defined(TINA_05C6BD1E_F51E_4ace_9C75_80ACE52C83FD__INCLUDED_)
#define TINA_05C6BD1E_F51E_4ace_9C75_80ACE52C83FD__INCLUDED_

#include <cppunit/extensions/HelperMacros.h>



namespace vending 
{
    /**
     * VendingMachineのテスト
     */
    class VendingMachineTest : public CPPUNIT_NS::TestFixture
    {
        CPPUNIT_TEST_SUITE( VendingMachineTest);
        CPPUNIT_TEST( testBuyCoke );
        CPPUNIT_TEST( testBuyDietCoke );
        CPPUNIT_TEST( testBuyTea );
        CPPUNIT_TEST( testBuyUsing500Yen );
        CPPUNIT_TEST( testInsertedMoneyCannotAcceptable );
        CPPUNIT_TEST( testCokeIsSoldOut );
        CPPUNIT_TEST( testDietCokeIsSoldOut );
        CPPUNIT_TEST( testTeaIsSoldOut );
        CPPUNIT_TEST( testChangeIsShort );
        CPPUNIT_TEST_SUITE_END( );

    public:
        //デフォルトコンストラクタ
        VendingMachineTest();
        //デストラクタ
        virtual ~VendingMachineTest();

    private:
        //コーラを買うテスト
        void testBuyCoke();
        //ダイエットコーラを買うテスト
        void testBuyDietCoke();
        //紅茶を買うテスト
        void testBuyTea();

        //500円で買うテスト
        void testBuyUsing500Yen();

        //投入されたお金を受け付けない場合のテスト
        void testInsertedMoneyCannotAcceptable();

        //コーラが売り切れの場合のテスト
        void testCokeIsSoldOut();
        //ダイエットコーラが売り切れの場合のテスト
        void testDietCokeIsSoldOut();
        //紅茶が売り切れの場合のテスト
        void testTeaIsSoldOut();
        //つり銭が足りない場合のテスト
        void testChangeIsShort();

    };
}
#endif // !defined(TINA_05C6BD1E_F51E_4ace_9C75_80ACE52C83FD__INCLUDED_)
