// 3484. Design Spreadsheet

#include <bits/stdc++.h>
using namespace std;

class Spreadsheet
{
public:
    // vector<vector<int>> matrix;
    map<string, int> mpp;
    Spreadsheet(int rows)
    {
    }

    void setCell(string cell, int value)
    {
        mpp[cell] = value;
    }

    void resetCell(string cell)
    {
        mpp[cell] = 0;
    }

    int getValue(string formula)
    {
        int i = 0;
        string num1;
        string num2;
        i++;
        bool doesHaveChar1 = false;
        bool doesHaveChar2 = false;
        while (i < formula.length() && formula[i] != '+')
        {
            if (formula[i] >= 'A' && formula[i] <= 'Z')
                doesHaveChar1 = true;
            num1.push_back(formula[i]);
            i++;
        }
        if (formula[i] == '+')
            i++;
        while (i < formula.length() && formula[i] != '+')
        {
            if (formula[i] >= 'A' && formula[i] <= 'Z')
                doesHaveChar2 = true;
            num2.push_back(formula[i]);
            i++;
        }
        int int1;
        int int2;
        if (!doesHaveChar1)
        {
            int1 = stoi(num1);
        }
        else
        {
            int1 = mpp[num1];
        }
        if (!doesHaveChar2)
        {
            int2 = stoi(num2);
        }
        else
        {
            int2 = mpp[num2];
        }
        return int1 + int2;
    }
};
/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */