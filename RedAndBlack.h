#ifndef _RED_AND_BLACK_H
#define _RED_AND_BLACK_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include "RedAndBlack.h"

using namespace std;
/**
*function to show all commands when wrong one will be used
**/
void help()
{
    ifstream file;

    file.open("help.txt");

    if (file.is_open())
    {

        string word;

        while (getline(file, word))
        {
            cout << word << endl;
        }
    }
    file.close();
}

/**
*function to delete all spaces from string
*@param str input string with spaces
*@return vector with only words
**/
vector<string> getLine(string str)
{
    vector<string> words;

    string word = "";
    for (auto x : str)
    {
        if (x == ' ')
        {
            words.push_back(word);
            word = "";
        }
        else
        {
            word = word + x;
        }
    }
    words.push_back(word);
    return words;
}

/**
*function to sort vector of numbers in order by ASC
*@param tmpVector input vector with not sorted numbers
*@return vector with sorted numbers 
**/

vector<double> sortingNumbers(vector<double> tmpVector)
{
    for (int i = 1; i < tmpVector.size(); i++)
    {
        int j = i;
        while (j > 0)
        {
            if (tmpVector[j] < tmpVector[j - 1])
            {
                double tmp = tmpVector[j];
                tmpVector[j] = tmpVector[j - 1];
                tmpVector[j - 1] = tmp;
            }
            j--;
        }
    }

    return tmpVector;
}

/**
*function to delete chosen number only if it is in vector, change number to last and delete last element
*@param tmpVector input vector with sorted numbers
*@param number element to delete from vector
*@return vector with out deleted number and sorted in ASC order
**/

vector<double> removeNumber(vector<double> tmpVector, double number)
{
    double tmp = -1;
    for (int i = 0; i < tmpVector.size(); i++)
    {
        if (number == tmpVector[i])
        {
            tmp = i;
        }
    }
    if (tmp >= 0)
    {

        double help = tmpVector.back();
        tmpVector.back() = tmpVector[tmp];
        tmpVector[tmp] = help;
        tmpVector.pop_back();
    }

    sortingNumbers(tmpVector);

    return tmpVector;
}

/**
*function to print sorted vector to new file or add at the end of file
*@param name input name of file to output
*@param plus input element says if print to new file or add at the end of file 
*@param tmpVector vector of sorted numbers to print
**/

void printToFile(string name, bool plus, vector<double> tmpNumbers)
{
    if (plus)
    {
        name = name + ".txt";

        fstream print;

        print.open(name, ios::app | ios::out);

        for (int i = 0; i < tmpNumbers.size(); i++)
        {
            print << tmpNumbers[i] << "\n";
        }
        print.close();
    }
    else
    {
        name = name + ".txt";

        fstream print;

        print.open(name, ios::trunc | ios::out);

        for (int i = 0; i < tmpNumbers.size(); i++)
        {
            print << tmpNumbers[i] << "\n";
        }
        print.close();
    }
}

/**
*function to print sorted vector in standart output
*@param tmpVector vector of sorted numbers to print
**/

void print(vector<double> tmpNumbers)
{
    for (int i = 0; i < tmpNumbers.size(); i++)
    {
        if (i == tmpNumbers.size() - 1)
        {
            cout << tmpNumbers[i];
        }
        else
        {
            cout << tmpNumbers[i] << " ; ";
        }
    }
    cout << endl;
}

/**
*function to print error of command after show error show all allowed commands
*@param command wrong command get from file
**/

void error(string command)
{
    cout << "No command like: " << command << endl;
    cout << "Command are between ' here ' " << endl;
    cout << endl;
    help();
}

/**
*function to print graph to new file or add at the end of file
*@param name input name of file to output
*@param plus input element says if print to new file or add at the end of file 
*@param tmpVector vector of sorted numbers to print
**/
void graphToFile(string name, bool plus, vector<double> tmpNumbers)
{
    if (plus)
    {
        name = name + ".txt";

        fstream gprint;

        gprint.open(name, ios::app | ios::out);

        vector<vector<double>> graph;
        int help = tmpNumbers.size() / 2;
        for (int i = 0; i <= help; i++)
        {
            vector<double> tmp;
            if (help + i == help - i)
            {

                tmp.push_back(tmpNumbers[help]);
            }
            else
            {
                tmp.push_back(tmpNumbers[help - i]);
                tmp.push_back(tmpNumbers[help + i]);
            }
            graph.push_back(tmp);
        }
        int color = 0;
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                if (color == 0)
                {
                    gprint << "[" << graph[i][j] << "]";
                }
                else
                {
                    gprint << "(" << graph[i][j] << ")";
                }
            }
            if (color == 0)
                color++;
            else
                color--;
            gprint << "\n";
        }
        gprint.close();
    }
    else
    {
        name = name + ".txt";

        fstream gprint;

        gprint.open(name, ios::trunc | ios::out);

        vector<vector<double>> graph;
        int help = tmpNumbers.size() / 2;
        for (int i = 0; i <= help; i++)
        {
            vector<double> tmp;
            if (help + i == help - i)
            {

                tmp.push_back(tmpNumbers[help]);
            }
            else
            {
                tmp.push_back(tmpNumbers[help - i]);
                tmp.push_back(tmpNumbers[help + i]);
            }
            graph.push_back(tmp);
        }
        int color = 0;
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                if (color == 0)
                {
                    gprint << "[" << graph[i][j] << "]";
                }
                else
                {
                    gprint << "(" << graph[i][j] << ")";
                }
            }
            if (color == 0)
                color++;
            else
                color--;
            gprint << "\n";
        }

        gprint.close();
    }
}

/**
*function to print gparh in standart output
*@param tmpVector vector of sorted numbers to print
**/

void graph(vector<double> tmpNumbers)
{
    vector<vector<double>> graph;
    int help = tmpNumbers.size() / 2;
    for (int i = 0; i <= help; i++)
    {
        vector<double> tmp;
        if (help + i == help - i)
        {

            tmp.push_back(tmpNumbers[help]);
        }
        else
        {
            tmp.push_back(tmpNumbers[help - i]);
            tmp.push_back(tmpNumbers[help + i]);
        }
        graph.push_back(tmp);
    }
    int color = 0;
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (color == 0)
            {
                cout << "[" << graph[i][j] << "]";
            }
            else
            {
                cout << "(" << graph[i][j] << ")";
            }
        }
        if (color == 0)
            color++;
        else
            color--;
        cout << endl;
    }
}

/**
  *Main function of program to choose what to do with inputed file
  *Work as swich but on strings most of function is sequance of if
  *At begin read "InputFile.txt" to know used commands 
  *Do the commands in order from first to last
  *@param inputFile name of input file
**/

void redAndBlack(string inputFile)
{
    /**
     * Get data from input file add it to 2D vector to know the order of comand
    **/
    ifstream input(inputFile);

    vector<double> numbers;

    vector<vector<string>> jobs;

    if (input.is_open())
    {
        vector<string> tmp;

        string word;

        int line = 0;

        while (getline(input, word))
        {
            tmp = getLine(word);
            jobs.push_back(tmp);
            ++line;
        }
    }
    input.close();
    /**
    *Start of swich
    **/
    for (int i = 0; i < jobs.size(); i++)
    {   
        // add numbers to vector of numbers
        if (jobs[i][0] == "add")
        {
            // add numbers to row
            for (int j = 1; j < jobs[i].size(); j++)
            {
                double tmp = stod(jobs[i][j]);
                numbers.push_back(tmp);
            }
            numbers = sortingNumbers(numbers);
        }
        // remove number from vector of numbers
        else if (jobs[i][0] == "remove")
        {
            //function remove(){return tmpVector without numbers}
            for (int j = 1; j < jobs[i].size(); j++)
            {
                double tmp = stod(jobs[i][j]);
                removeNumber(numbers, tmp);
            }
        }
        //  print vector of numbers to file 
        else if (jobs[i][0] == "print" && jobs[i].size() != 1)
        {
            if (jobs[i][1] == "+")
            {
                // print at the end of file (name.txt) vector of numbers

                string name = jobs[i][2];
                bool plus = 1;
                printToFile(name, plus, numbers);
            }
            else
            {
                // print to file (name.txt) vector of numbers 
                string name = jobs[i][1];
                bool plus = 0;
                printToFile(name, plus, numbers);
            }
        }
        else if (jobs[i][0] == "print" && jobs[i].size() == 1)
        {
            // only print vector of numbers in standart output
            print(numbers);
        }
        else if (jobs[i][0] == "graph" && jobs[i].size() != 1)
        {
            if (jobs[i][1] == "+")
            {
                // print graph to file (name.txt) at the end of it
                string name = jobs[i][2];
                bool plus = 1;
                graphToFile(name, plus, numbers);
            }
            else if (jobs[i].size() == 2)
            {
                // print graph to file (name.txt)
                string name = jobs[i][1];
                bool plus = 0;
                graphToFile(name, plus, numbers);
            }
        }
        else if (jobs[i][0] == "graph" && jobs[i].size() == 1)
        {
            //print graph in standart output 
            graph(numbers);
        }
        else
        {
            // tell no comand like this
            error(jobs[i][0]);
        }
    }
}

#endif