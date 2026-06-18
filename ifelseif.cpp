#include <iostream>


class Solution {
public:

    void studentGrade(int marks) {
        // If else conditional chain
        if (marks >= 90) {
            std::cout << "Grade A"<<std::endl;
        } else if (marks >= 70) {
            std::cout << "Grade B"<<std::endl;
        } else if (marks >= 50) {
            std::cout << "Grade C"<<std::endl;
        } else if (marks >= 35) {
            std::cout << "Grade D"<<std::endl;
        } else {
            std::cout << "Fail"<<std::endl;
        }
    }
};

