/*
 * @lc app=leetcode.cn id=1603 lang=cpp
 *
 * [1603] 设计停车系统
 */

// @lc code=start
class ParkingSystem
{
private:
    int big = 0;
    int medium = 0;
    int small = 0;

public:
    ParkingSystem(int big, int medium, int small) : big(big), medium(medium), small(small)
    {
    }

    bool addCar(int carType)
    {
        switch (carType)
        {
        case 1:
            if (big > 0)
            {
                big--;
                return true;
            }
            else
                return false;
            break;
        case 2:
            if (medium > 0)
            {
                medium--;
                return true;
            }
            else
                return false;
            break;
        case 3:
            if (small > 0)
            {
                small--;
                return true;
            }
            else
                return false;
            break;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end
