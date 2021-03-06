// Time unit Formating Seconds to hhmmss.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>

class TFs_hhmmss_arr3
{
public:
    TFs_hhmmss_arr3()
    {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "TFs_hhmmss() SAYS: Got no input";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    TFs_hhmmss_arr3(int& T)
        :_ss(T)
    {
        _hh = _ss / (60 * 60);
        _ss = _ss - (_hh * 60 * 60);
        _mm = _ss / 60;
        _ss = _ss - (_mm * 60);

        R[0] = _hh;
        R[1] = _mm;
        R[2] = _ss;
    }

    int* outPutt()
    {
        return R;
    }

private:
    int _ss{};
    int _mm{};
    int _hh{};
    int* R = new int[3]{};
};

int main()
{
    // We seed the random and create a variable that is the total amount of seconds in a day
        srand(time(NULL));
        const int day_s{ 60 * 60 * 24 };
    
    // We create an integer with a random number of seconds below the total amount of seconds in a day
        int T_s{ rand()*rand() };
        T_s = T_s % day_s;

    // An object initalizes with the amount of seconds and stores number of hour minutes and seconds that represent
        TFs_hhmmss_arr3 a(T_s);

    // The object has a function that return a pointer to and array[3] with {hours,minutes,secons}
        int* hhmmss = a.outPutt();

    // We end by formating the result
        std::cout << std::endl;
        std::cout << "seconds: ";
        std::cout << T_s;
        std::cout << std::endl;
        std::cout << hhmmss[0];
        std::cout << "h ";
        std::cout << hhmmss[1];
        std::cout << "m ";
        std::cout << hhmmss[2];
        std::cout << "s ";
        std::cout << std::endl;


    return 0;
}
