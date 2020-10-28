// Camerie Mazreku - Assingment 2
// I first included every library that i will need to use in order for this program to work
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;    
//I created the function getLetterGrade() of data type char because it will return only one character and inside it I created some conditions depending on the grade. 
char getLetterGrade(float value){
    if ((value >= 0) && ( value <= 59)){
        return 'F';
    }
    else if ((value >= 60) && (value <= 69)){
        return 'D';
    }
    else if ((value >= 70) && (value <= 79)){
        return 'C';
    }
    else if ((value >= 80) && (value <= 89)){
        return 'B';
    }
    else if ((value >= 90) && (value <= 100)){
        return 'A';
    }
    else {
        return 'X';
    }
}
 //I created the function printGradeTable() so when the user asks for the grade conversion table it shows up and they can input their points and it returns the grade by calling getLetterGrade() function. I made this function void because we will never use it for a variable just for the display.
void printGradeTable(){
  cout << "\n" << setfill('-') << setw(38) << "-" << endl;
    cout << "\t\tFrom\t\tTo\t\tLetter";
    cout << "\n" << setfill('-') << setw(38) << "-" << endl;
    cout <<setfill(' ')<<setw(12)<<"0"<<setw(10)<<"59"<<setw(9)<<getLetterGrade(59)<<endl
           << setw(12)<<"60"<<setw(10)<<"69"<<setw(9)<<getLetterGrade(69)<<endl
           << setw(12)<<"70"<<setw(10)<<"79"<<setw(9)<<getLetterGrade(79)<<endl
           << setw(12)<<"80"<<setw(10)<<"89"<<setw(9)<<getLetterGrade(89)<<endl
           <<setw(12)<<"90"<<setw(10)<<"100"<<setw(9)<<getLetterGrade(100)<<endl
           << setw(18)<<"Other"<<setw(13)<<"X"<<endl;
   cout <<setfill('-')<<setw(38)<<"-"<<endl;
   }

//I continued by creating the function fileSummary which is also void type because we will only use it for display. I opened the file and got string (Student(no.)), number(grades) and output the grade in letter. 
void fileSummary(){
    string file;
    int count=0;
    float grade, min = INT32_MAX, max = INT32_MIN, sum=0;
    ifstream inFile;
    inFile.open("grades.data");
    if (inFile){
      //I used setfill to create borders of the information
        cout << "\n" << setfill('-') << setw(38) << "-" << endl;
        cout << setfill(' ') << setw(10) << "Name" << setfill(' ') << setw(12) << "Average" << setfill(' ') << setw(10) << "Letter";
        cout << "\n" << setfill('-') << setw(38) << "-" << endl;
        //While loop is to count and find minimum, maximum and sum of the grades.
        while (inFile >> file){
            inFile >> grade;
            count++;
            sum += grade;
            if (grade < min)
                min = grade;
            if (grade > max)
                max = grade;
            
          cout << setfill(' ') << setw(12) << file << setw(9) << grade <<setw(8) <<getLetterGrade(grade) << endl;
        }
        //when the loop is over it displays minimum, maximum and average
        cout << "\nMin: " << min;
        cout << "\nMax: " << max;
        cout << "\nAverage: " << (sum/count)<<endl;
    }
    else 
        cout << "Error, cannot open file: grades.data" << endl;
}
//Finally I created the program which will use this functions
int main() {
  //declared every variable that I will need 
  char option;
  float grade;
  char continue1;
  while (true){
       // We display the menu
         cout<<" A) Grade conversion table."<<endl
             <<" B) Summaries a grade file."<<endl
             <<" C) Exit. "<<endl
             <<" Select an option()"<<endl;
        
        cin >> option;
        //Since switch accepts only char and int I created a char switch 
        switch(option){
          case 'a':  case 'A':
              printGradeTable(); //Option A calls grade conversion  function 
              break;
            
          case 'b':   case 'B':
               fileSummary(); //Option B calls fileSummary() function
               break;
          case 'c': case 'C':
              cout<<"You terminated the program"; //ends the program
              return 0;
          default:
           cout <<"'"<<option<<"'" <<"is not a valid choice."<<endl;//if the user inputs an invalid character
           break;}
      }}
    
