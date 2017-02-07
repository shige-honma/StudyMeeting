// $Id$ 
///////////////////////////////////////////////////////////////////////////////
/**
 * @file  VendingMachine.h
 * @brief Declaration of the Class VendingMachine
 * @version 
 * @e 1.0 17-1-2017
 */
///////////////////////////////////////////////////////////////////////////////
//              Copyright (c) 2017 Tokyo Electron Limited.
//                         All rights reserved.                  
///////////////////////////////////////////////////////////////////////////////
#if !defined(TINA_CE534419_CFC3_4fd6_AFA5_2C8F22C82171__INCLUDED_)
#define TINA_CE534419_CFC3_4fd6_AFA5_2C8F22C82171__INCLUDED_

#include "Drink.h"



namespace vending 
{
    /**
     * �����̔��@
     */
    class  VendingMachine
    {

    public:
        /**
         * �f�t�H���g�R���X�g���N�^
         */
        VendingMachine();

        /**
         * �R���X�g���N�^
         */
        VendingMachine(int quantityOfCoke, int quantityOfDietCoke, int quantityOfTea, int numberOf100Yen );

        /**
         * �f�X�g���N�^
         */
        ~VendingMachine();

        /**
         * �W���[�X���w������.
         *
         * @param i           �������z. 100�~��500�~�̂ݎ󂯕t����.
         * @param kindOfDrink �W���[�X�̎��.
         *                    �R�[��({@code Juice.COKE}),�_�C�G�b�g�R�[��({@code Juice.DIET_COKE},����({@code Juice.TEA})���w��ł���.
         * @return �w�肵���W���[�X. �݌ɕs����ނ�K�s���Ŕ����Ȃ������ꍇ�� {@code null} ���Ԃ����.
         */
        vending::Drink buy(int i, int kindOfDrink);

        /**
         * ���ނ�����o��.
         *
         * @return ���ނ�̋��z
         */
        int refund();

    private:
        VendingMachine(const VendingMachine& other);
        const VendingMachine& operator=(const VendingMachine& other);

        /**
         * �R�[���̍݌ɐ�
         */
        int quantityOfCoke_;

        /**
         * �_�C�G�b�g�R�[���̍݌ɐ�
         */
        int quantityOfDietCoke_;

        /**
         * �����̍݌ɐ�
         */
        int quantityOfTea_;

        /**
         * 100�~�̍݌�
         */
        int numberOf100Yen_;

        /**
         * ����
         */
        int charge_;

    };
}
#endif // !defined(TINA_CE534419_CFC3_4fd6_AFA5_2C8F22C82171__INCLUDED_)
