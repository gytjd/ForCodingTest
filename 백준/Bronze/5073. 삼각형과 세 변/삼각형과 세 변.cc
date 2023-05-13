#include <iostream>
#include <algorithm>
#include <vector>
 
int main()
{
    while(true)
    {
        std::vector<int> vec(3, 0);
 
        std::cin >> vec[0] >> vec[1] >> vec[2];
 
        std::sort(vec.begin(), vec.end());
 
        if (!vec[0] && !vec[1] && !vec[2])
            return 0;
 
        if (!vec[0] || !vec[1] || !vec[2])
        {
            std::cout << "Invalid" << "\n";
            continue;
        }
 
        else if (vec[0] == vec[1] && vec[1] == vec[2])
        {
            std::cout << "Equilateral" << "\n";
            continue;
        }
 
        else if (vec[0] + vec[1] > vec[2])
        {
            if (vec[0] == vec[1] || vec[1] == vec[2])
            {
                std::cout << "Isosceles" << "\n";
                continue;
            }
 
            else
            {
                std::cout << "Scalene" << "\n";
                continue;
            }
        }
 
        else
        {
            std::cout << "Invalid" << "\n";
            continue;
        }
    }
}