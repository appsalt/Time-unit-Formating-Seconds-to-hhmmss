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
    srand(time(NULL));
    const int day_s{ 60 * 60 * 24 };
    
    int T_s{ rand()*rand() };
    T_s = T_s % day_s;
    //int T_s{ day_s -2 };

    TFs_hhmmss_arr3 a(T_s);
    int* hhmmss = a.outPutt();

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
