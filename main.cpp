#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<string> getLine(string str)
{

    // delete all operation on file in function getLine()

    ofstream file;

    string name = "new.txt";

    file.open(name, ios::app);

    vector<string> words;

    string word = "";
    for (auto x : str)
    {
        if (x == ' ')
        {
            file << word << "\n";
            words.push_back(word);
            word = "";
        }
        else
        {
            word = word + x;
        }
    }
    file << word << "\n";
    words.push_back(word);
    file.close();
    return words;
}

vector<double> sortingNumbers(vector<double> tmpVector){
    for (int i = 1; i < tmpVector.size(); i++){
        int j = i;
       while (j > 0){
           if (tmpVector[j] < tmpVector[j-1]){
            double tmp = tmpVector[j];
            tmpVector[j] = tmpVector[j-1];
            tmpVector[j-1] = tmp;
           }
           j--;
        }
    }

    return tmpVector;
}

vector<double> removeNumber(vector<double> tmpVector, int number){

    cout << number << endl;
    // replace the number with last element after that pop back last element that is the number

    return tmpVector;
}
int main()
{

    ifstream input("lorem.txt");

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
    
    for (int i = 0; i < jobs.size(); i++)
    {
        if (jobs[i][0] == "add")
        {
            for (int j = 1; j < jobs[i].size(); j++)
            {
                double tmp = stod(jobs[i][j]);
                numbers.push_back(tmp);
            }
            numbers = sortingNumbers(numbers);
            cout << endl; 
        }
        else if (jobs[i][0] == "remove")
        {
            //function remove(){return tmpVector without numbers}
            for (int j = 1; j < jobs[i].size(); j++)
            {
                double tmp = stod(jobs[i][j]);
                removeNumber(numbers, tmp);
            }
        }
        else if (jobs[i][0] == "print" && jobs[i].size() != 1)
        {
            if (jobs[i][1] == "+")
            {
                // add sorted number to file (name.txt) where name is variable just add not clean file

                string name = jobs[i][2];
                cout << "add to file " << name << endl;

                name = name + ".txt";

                fstream print;

                print.open(name, ios::app | ios::out);

                for (int i = 0; i < numbers.size(); i++)
                {
                    print << numbers[i] << "\n";
                }
                print.close();
                
            }
            else if(jobs[i].size() == 2)
            {
                // create file (name.txt) where name is variable clean file add sorted numbers
                string name = jobs[i][1];

                cout << "add to file cleane file " << name << endl;

                name = name + ".txt";

                fstream print;

                print.open(name, ios::trunc | ios::out);

                for (int i = 0; i < numbers.size(); i++)
                {
                    print << numbers[i] << "\n";
                }
                print.close();
                 
            }
        }
        else if (jobs[i][0] == "print" && jobs[i].size() == 1)
            {
                // only print numbers in cmd

                cout << "just print" << endl;
                for (int i = 0; i < numbers.size(); i++)
                {
                   if (i == numbers.size()-1)
                   {
                        cout << numbers[i];
                   }
                   else
                   {
                        cout << numbers[i] << " ; ";
                   }
                   
                   
                }
                cout << endl;
                
            }
        else if (jobs[i][0] == "graph" && jobs[i].size() != 1)
        {
            if (jobs[i][1] == "+")
            {
                // add graoh to file (name.txt) where name is variable just add not clean file
                string name = jobs[i][2];
                cout << "add graph to file " << name << endl;
                
            }
            else if(jobs[i].size() == 2)
            {
                // create file (name.txt) where name is variable clean file add graph
                string name = jobs[i][1];
                cout << "add graph to file cleane file " << name << endl;
                
            }
        }
        else if (jobs[i][0] == "graph" && jobs[i].size() == 1)
        {
            // show graph in cmd 
            cout << "graph" << endl;
        }
        else
        {
            // tell no comand like this
            cout << " No comend like this: " << jobs[i][0] << endl;
        }
    }
    
    


    return 0;
}