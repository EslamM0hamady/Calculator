// File: CS112_A2_T3_Sec28_20230057_20230061_20230626.cpp
// Purpose: This is a rational number calculator it is calculate operation on the integer number and rational number  
// Authors: Eslam Tamer Abdraboo Amin - Sec28
//        : Eslam Mohamady AbdElmoaty - sec28
//        : Essam Mamdouh Saad - sec28  
// Email 1: 01010573818e@gmail.com
// Email 2: eslammohamady39@gmail.com
// Email 3: Essammamdouh53@gmail.com
// ID1: 20230057 – [multiply-addtion]
// ID2: 20230061 – [subtraction - Division]
// ID3: 20230626 – [menu]
//__________________________________________________________________________________________________________________________
// Algorithm : 
// link : https://drive.google.com/file/d/1k3vl_6jx1tyQMnJ76mMqg3_kX8YHOTZL/view?usp=drive_link
//__________________________________________________________________________________________________________________________
#include <iostream>
#include<string>
#include<stdlib.h>
#include<cmath>
#include<regex>
#include<vector>
#include <algorithm>
using namespace std;
bool ifvalid(string op)//this function cheak if the input if valid or not
{
    regex pattern("^(\\+?\\d/\\+?\\d|\\+?\\d|\\-\\d|\\-\\d/\\d|\\d/\\-\\d|\\-\\d/\\-\\d)+ (\\+|\\*|\\-|/) (\\+?\\d/\\+?\\d|\\+?\\d|\\-\\d|\\-\\d/\\d|\\d/\\-\\d|\\-\\d/\\-\\d)+$");//this is the pattern
    return regex_match(op, pattern);

}
int gcd(long long x, long long y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}


int main()
{
    cout << "                           ______________________________" << endl;
    cout << "                           | rational number calculator |" << endl;
    cout << "____________________________________________________________________________________________________" << endl;
    cout << "In order not to cause any problems, please put a space between the number and the operation you want" << endl;
    cout << " and Write the number in fractional form, not decimal form and Do not use anything other than these " << endl;
    cout << "operations (+ , - , * , / )" << endl;
    cout << "For Example : 1/2 + 1/4" << endl;
    cout << "____________________________________________________________________________________________________" << endl;
    while (true)//to the user can Write new Equation
    {
        string num1, num2, sum1 = "", sum2 = "", sum3 = "", sum4 = "", x, op;//declare
        int alt = 0;
        cout << "please enter your Equation : ";
        getline(cin, op);//take the Equation from the user
        if (ifvalid(op) == false)//cheak
        {
            cout << "your Equation not valid,Try again" << endl;
            continue;
        }
        num1 = op.substr(0, op.find(" "));//put the first number in variable
        num2 = op.substr(op.find(" ") + 3, op.size() - 1);//put the operations in variable
        x = op[op.find(" ") + 1];//put the second number in variable
        for (int i = 0; i < num1.size(); i++)//if num is not rational
        {
            if (num1[i] == '/')
            {
                alt = 1;
            }
        }
        if (alt == 0)
        {
            num1 += "/1";
        }
        alt = 0;
        for (int i = 0; i < num2.size(); i++)//if num is not rational
        {
            if (num2[i] == '/')
            {
                alt = 1;
            }
        }
        if (alt == 0)
        {
            num2 += "/1";
        }
        for (int i = 0; i < num1.size(); i++)//put the numerator and denominator in variables 
        {
            if (num1[i] == '/')
            {
                for (int y = 0; y < i; y++)
                {
                    sum1 += num1[y];
                }
                for (int y = i + 1; y < num1.size(); y++)
                {
                    sum2 += num1[y];
                }
            }
        }
        for (int i = 0; i < num2.size(); i++)//put the numerator and denominator in variables 
        {
            if (num2[i] == '/')
            {
                for (int y = 0; y < i; y++)
                {
                    sum3 += num2[y];
                }
                for (int y = i + 1; y < num2.size(); y++)
                {
                    sum4 += num2[y];
                }
            }
        }
        if (sum1[0] == '+')
        {
            sum1 = sum1.substr(1, -1);
        }
        if (sum2[0] == '+')
        {
            sum2 = sum2.substr(1, -1);
        }
        if (sum3[0] == '+')
        {
            sum3 = sum3.substr(1, -1);
        }
        if (sum4[0] == '+')
        {
            sum4 = sum4.substr(1, -1);
        }
        long long r1 = atoi(sum1.c_str());//string to integer
        long long r2 = atoi(sum2.c_str());//string to integer
        long long r3 = atoi(sum3.c_str());//string to integer
        long long r4 = atoi(sum4.c_str());//string to integer
        if (r2 == 0 || r4 == 0)//cheak
        {
            cout << "Division by zero not allowed" << endl;
            continue;
        }
        if (x == "*")//if the operation = *
        {
            long long res1 = r1 * r3;//calculate
            long long res2 = r2 * r4;
            if (res2 < 0)//if denominator is negative
            {
                res2 *= -1;
                res1 *= -1;
            }
            if (res1 < 0)//if num is negative
            {
                res1 *= -1;
                for (int i = max(res1, res1); i > 1; i--)//smplify
                {
                    if (res1 % i == 0 && res2 % i == 0)
                    {
                        res1 = res1 / i;
                        res2 = res2 / i;
                        break;
                    }
                }
                res1 *= -1;
            }
            else
            {
                for (int i = max(res1, res1); i > 1; i--)//smplify
                {
                    if (res1 % i == 0 && res2 % i == 0)
                    {
                        res1 = res1 / i;
                        res2 = res2 / i;
                        break;
                    }
                }
            }
            if (res1 == 0)//smplify and Result
            {
                cout << "| Result : 0 |" << endl;
            }
            else if (res2 == 1)//smplify and Result
            {
                cout << "| Result : " << res1 << " |" << endl;
            }
            else {//result
                cout << "| Result : " << res1 << "/" << res2 << " |" << endl;
            }
        }
        else if (x == "+")//if the operation = +
        {
            if (r2 != r4)//union the denominators
            {
                r1 = r1 * r4;
                r3 = r3 * r2;
            }
            long long res1 = r1 + r3;//calculate
            long long res2 = r2 * r4;
            if (res2 < 0)
            {
                res2 *= -1;
                res1 *= -1;
            }
            if (res1 < 0)//if num is negative
            {
                res1 *= -1;
                for (int i = max(res1, res1); i > 1; i--)//smplify
                {
                    if (res1 % i == 0 && res2 % i == 0)
                    {
                        res1 = res1 / i;
                        res2 = res2 / i;
                        break;
                    }
                }
                res1 *= -1;
            }
            else {
                for (int i = max(res1, res2); i > 1; i--)
                {
                    if ((res1 % i == 0 && res2 % i == 0))//smplify
                    {
                        res1 = res1 / i;
                        res2 = res2 / i;
                        break;
                    }
                }
            }
            if (res1 == 0)//smplify and Result
            {
                cout << "| Result : 0 |" << endl;
            }
            else if (res2 == 1)//smplify and Result
            {
                cout << "| Result : " << res1 << " |" << endl;
            }
            else {//Result
                cout << "| Result : " << res1 << "/" << res2 << " |" << endl;
            }
        }
        else if (x == "-")//if the operation = -
        {
            long long a = ((r1 * r4) - (r2 * r3)) / abs(gcd(((r1 * r4) - (r2 * r3)), (r2 * r4)));
            long long b = (r2 * r4) / abs(gcd(((r1 * r4) - (r2 * r3)), (r2 * r4)));
            if (b == 1)
            {
                cout << "| Result : " << a << " |" << endl;
            }
            else if (a == 0)
            {
                cout << "| Result : 0 |" << endl;
            }
            else
            {
                cout << "| Result : " << a << "/" << b << " |" << endl;
            }
        }
        else if (x == "/")//if the operation = /
        {
            long long a, b;
            if (r3 == 0)
            {
                cout << "Division by zero not allowed" << endl;
                continue;
            }
            if ((r1 * r4) < 0 && (r2 * r3) < 0)
            {
                a = (r1 * r4) / (gcd((r1 * r4), (r2 * r3)));
                b = (r2 * r3) / (gcd((r1 * r4), (r2 * r3)));
            }
            else
            {
                a = (r1 * r4) / abs(gcd((r1 * r4), (r2 * r3)));
                b = (r2 * r3) / abs(gcd((r1 * r4), (r2 * r3)));
            }
            if (b == 1)
            {
                cout << "| Result : " << a << " |" << endl;
            }
            else if (r1 == 0)
            {
                cout << "| Result : 0 |" << endl;
            }
            else
            {
                cout << "| Result : " << a << "/" << b << " |" << endl;
            }
        }
        cout << "" << endl;
        cout << "Do you want to calculate another number?" << endl;//ask user if he want Write again
        cout << "1) yes i want (Go to main menu)" << endl;
        cout << "2) No, Exit program " << endl;
        string choice;
        cout << "please choose 1 or 2 : ";
        cin >> choice;
        while (choice != "1" and choice != "2")//cheak
        {
            cout << " Your choice not valid, Try again :";
            cin >> choice;
        }
        if (choice == "1")//if user again
        {
            cout << "                           ______________________________" << endl;
            cout << "                           | rational number calculator |" << endl;
            cout << "_" << endl;
            cout << "In order not to cause any problems, please put a space between the number and the operation you want" << endl;
            cout << " and Write the number in fractional form, not decimal form and Do not use anything other than these " << endl;
            cout << "operations (+ , - , * , / )" << endl;
            cout << "For Example : 1/2 + 1/4" << endl;
            cout << "_" << endl;
            cin.ignore(1, '\n');
        }
        else//if user exit program
        {
            break;
        }
    }
    return 0;
}