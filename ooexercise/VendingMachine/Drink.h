// $Id$ 
///////////////////////////////////////////////////////////////////////////////
/**
 * @file  Drink.h
 * @brief Declaration of the Class Drink
 * @version 
 * @e 1.0 17-1-2017
 */
///////////////////////////////////////////////////////////////////////////////
//              Copyright (c) 2017 Tokyo Electron Limited.
//                         All rights reserved.                  
///////////////////////////////////////////////////////////////////////////////
#if !defined(TINA_FDA1241C_0A65_4a7e_A5BA_65A580D5ACA8__INCLUDED_)
#define TINA_FDA1241C_0A65_4a7e_A5BA_65A580D5ACA8__INCLUDED_



namespace vending 
{
    /**
     * 飲み物クラス
     */
    class  Drink
    {

    public:
        /**
         * デフォルトコンストラクタ
         */
        Drink();

        /**
         * コンストラクタ
         * @param[in] kind 
         */
        Drink(int kind);

        /**
         * デストラクタ
         */
        virtual ~Drink();

        /**
         * コピーコンストラクタ
         * @param[in] other コピー元
         */
        Drink(const Drink& other);

        /**
         * コピーコンストラクタ
         * @param[in] other コピー元
         */
        Drink operator=(const Drink& other);

        /**

         *  
         */
        int getKind();

        static const int UNKNOWN_ = 0;
        static const int COKE_ = 1;
        static const int DIET_COKE_ = 2;
        static const int TEA_ = 3;

    private:
        /**

         */
        int kind_;

    };
}
#endif // !defined(TINA_FDA1241C_0A65_4a7e_A5BA_65A580D5ACA8__INCLUDED_)
