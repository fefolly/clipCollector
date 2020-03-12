#include <iostream>
#include<fstream>

using namespace std;
void readFile();

void writeInFile();


int main()
{
    cout << "**********Beginning of the project**********" << endl;
    cout << " NOW WRITING IN A FILE" << endl;
    writeInFile();
    cout << " NOW READING A FILE" << endl;
    readFile();

    return 0;
}


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
