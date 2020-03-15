#include <iostream>
#include<fstream>
#include<vector>
#include<memory>
#include "templateimplemetation.h"

using namespace std;

//using unique_ptr
void tryUniquePointer(){
    unique_ptr<int> ptr(new int);
    //shared_ptr<int> sptr = make_shared<int>();  //I can still use the declaration as it is for the unique pointer

    int a = 7;
    *ptr = a;

    cout <<"The pointer is on : "<< *ptr <<endl;
    cout <<"oh yeah"<<endl;
}

//trying vector
void tryVector(){
vector<string> tableauv;

tableauv.push_back("onetwo");
tableauv.push_back("troisquatre");

for(auto i : tableauv ){
    cout<< i <<endl;
}

}


//try lambda expression
void testlambda(void (*pFunc)()) {
    pFunc();
}


void functCallingLambda(){
    auto func = [](){ cout << "Hello" << endl;};


    auto fofo = [](){
        int i = 5;
        i++;
        cout << "The variable is: " << i <<endl;
    };

    func();
    testlambda(fofo);

}


//try for loop for c++11
void newForLoop(){
    auto texts = {"one", "two","three","Felix"};

    for(auto text: texts){
        cout<< text <<endl;
    }
}



//exception handling
void mightGoWrong(){
    bool status = true;


    if(status){
        throw 8;
    }
}

void Catchingexception(){
    try {
        mightGoWrong();
    } catch (int e) {
        cout<< "Error code: " << e << endl;
    }

    cout<< "still running" <<endl;
}


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
    cout <<"6 : Exception handling"<<endl;
    cout <<"7 : New for loop c++11"<<endl;
    cout <<"8 : To try lambda"<<endl;
    cout <<"9 : Use vector"<<endl;
    cout <<"10 : Unique pointer"<<endl;
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
        case 6:Catchingexception();
            break;
        case 7:newForLoop();
            break;
        case 8:functCallingLambda();
            break;
        case 9:tryVector();
            break;
        case 10:tryUniquePointer();
            break;
        default: cout<< "Wrong choice dear. Are you blind?!!!"<<endl;
            break;
    }

     cout << "**********Thank you for the visit! Do come by soon**********" << endl;

    return 0;
}

