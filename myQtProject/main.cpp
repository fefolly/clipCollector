#include <iostream>
#include<fstream>
#include "templateimplemetation.h"

using namespace std;

//learning template function
template <class FT>
void print(FT temp){
    cout << temp << endl;
}


//class to learn the usage of template class
template<class T>
class TestTemplate {
private:
    T TemplateObject;

public:
    TestTemplate(T theObject){
        this->TemplateObject = theObject;
    }

    void print(){
        cout << TemplateObject <<endl;
    }

};

//Function to write in a file
void writeInFile(){

    ofstream outFile;

    string outputFileName = "text.txt";

    outFile.open(outputFileName);

    if(outFile.is_open()){
        outFile << "Hello there" <<endl;
        outFile << "My name is fefo" <<endl;
        outFile << 123 <<endl;
        outFile.close();

    }
    else {
        cout << "Could not create file: "<< outputFileName <<endl;
    }
}


void readFile()
{
    string inFileName = "text.txt";

    ifstream inFile;

    inFile.open(inFileName);

    if(inFile.is_open()){
        string line;

        while(!inFile.eof()){
            getline(inFile, line);
            cout << line <<endl;
        }
        inFile.close();
    }
    else {
        cout <<"Cannot open file: "<< inFileName << endl;
    }

}



int main()
{
    int menuchoice;
    templateImplemetation temp;
     TestTemplate<string>robot("Hello, I am a robot!");

    cout << "**********Welcome, please select your number**********" << endl;
    cout <<"1 : Write into a file"<<endl;
    cout <<"2 : Read a file"<<endl;
    cout <<"3 : Try class template"<<endl;
    cout <<"4 : Try function class"<<endl;
    cout <<"5 : Trying connection .H & .cpp"<<endl;
    cin>>menuchoice;

    switch (menuchoice) {
        case 1: cout << " NOW WRITING IN A FILE" << endl;
                 writeInFile();
                 break;
        case 2: cout << " NOW READING A FILE" << endl;
                 readFile();
                 break;
        case 3: //Testing class template
                  print<string>("Mohamed");
                 print<int>(52343);
                 break;
        case 4: //Testing the template function call

                robot.print();
                break;
        case 5:
                //testing the connection to file.h & file.cpp

                 temp.salut();
                 break;
        default: cout<< "Wrong choice dear. Are you blind?!!!"<<endl;
            break;
    }

     cout << "**********Thank you for the visit! Do come by soon**********" << endl;

    return 0;
}

