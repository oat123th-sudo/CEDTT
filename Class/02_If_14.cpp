#include <iostream>
#include <string>
int gradeToNum(char g)
{
    if (g == 'A')
        return 1;
    if (g == 'B')
        return 2;
    if (g == 'C')
        return 3;
    return 4; // worse than C
}
int main()
{
    std::string id1, id2;
    double gpax1, gpax2;
    char com1, cal11, cal12, com2, cal21, cal22;
    std::cin >> id1 >> gpax1 >> com1 >> cal11 >> cal12 >> id2 >> gpax2 >> com2 >> cal21 >> cal22;
    char grade1[] = {com1, cal11, cal12};
    char grade2[] = {com2, cal21, cal22};
    int numgrade1[] = {gradeToNum(grade1[0]), gradeToNum(grade1[1]), gradeToNum(grade1[2])};
    int numgrade2[] = {gradeToNum(grade2[0]), gradeToNum(grade2[1]), gradeToNum(grade2[2])};
    bool pass1 = numgrade1[1]<=3 && com1 == 'A'&&numgrade1[2]<=3;
    bool pass2 = numgrade2[1]<=3 && com2 == 'A'&&numgrade2[2]<=3;
    if (!pass1 && !pass2)
    {
        std::cout << "None";
    }
    else if (pass1 && (!pass2 ||
             gpax1 > gpax2 ||
             (gpax1 == gpax2 && numgrade1[0] < numgrade2[0]) ||
             (gpax1 == gpax2 && numgrade1[0] == numgrade2[0] && numgrade1[1] < numgrade2[1]) ||
             (gpax1 == gpax2 && numgrade1[0] == numgrade2[0] && numgrade1[1] == numgrade2[1] && numgrade1[2] < numgrade2[2])))
    {
        std::cout << id1;
    }
    else if (pass2 && (!pass1 ||
             gpax2 > gpax1 ||
             (gpax2 == gpax1 && numgrade2[0] < numgrade1[0]) ||
             (gpax2 == gpax1 && numgrade2[0] == numgrade1[0] && numgrade2[1] < numgrade1[1]) ||
             (gpax2 == gpax1 && numgrade2[0] == numgrade1[0] && numgrade2[1] == numgrade1[1] && numgrade2[2] < numgrade1[2])))
    {
        std::cout << id2;
    }
    else
    {
        std::cout << "Both";
    }
}