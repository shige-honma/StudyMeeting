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
     * VendingMachine�̃e�X�g
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
        //�f�t�H���g�R���X�g���N�^
        VendingMachineTest();
        //�f�X�g���N�^
        virtual ~VendingMachineTest();

    private:
        //�R�[���𔃂��e�X�g
        void testBuyCoke();
        //�_�C�G�b�g�R�[���𔃂��e�X�g
        void testBuyDietCoke();
        //�g���𔃂��e�X�g
        void testBuyTea();

        //500�~�Ŕ����e�X�g
        void testBuyUsing500Yen();

        //�������ꂽ�������󂯕t���Ȃ��ꍇ�̃e�X�g
        void testInsertedMoneyCannotAcceptable();

        //�R�[��������؂�̏ꍇ�̃e�X�g
        void testCokeIsSoldOut();
        //�_�C�G�b�g�R�[��������؂�̏ꍇ�̃e�X�g
        void testDietCokeIsSoldOut();
        //�g��������؂�̏ꍇ�̃e�X�g
        void testTeaIsSoldOut();
        //��K������Ȃ��ꍇ�̃e�X�g
        void testChangeIsShort();

    };
}
#endif // !defined(TINA_05C6BD1E_F51E_4ace_9C75_80ACE52C83FD__INCLUDED_)
