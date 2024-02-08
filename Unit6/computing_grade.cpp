#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <iomanip>



using namespace std;


void print_menu();
void test_score(string given_name, string student_name[],double first_test[],double second_test[], double third_test[],int lenght);
int find_student(string given_name, string student_name[], int lenght);


int main()
{
    string student_name[4], given_name;
    double first_test[4], second_test[4], third_test[4];
    int length = 4;
    int option = 0;
    bool sentinel = true;
    ifstream input_file;
    char answer = 'Y';
    string name_file = "../Unit5/student_list.txt";  
    input_file.open(name_file);

    if(!input_file)
    {
        cout<<"Incorrect path or file name"<<endl;
        exit(1);
    }

    int index = 0;
    while (!input_file.eof())
    {
        input_file >> student_name[index] >> first_test[index] >> second_test [index] >> third_test[index];
        index++;
    }
   
    
     while (answer == 'Y' )
     {
        print_menu();
        cout<<"Provide the selected option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            /* Find the student by the name */
            cout<<"Provide the student's name: ";
            cin >> given_name;
            test_score(given_name, student_name,first_test,second_test,third_test,length);
            break;
        case 2:
            /*Compute student's final grade*/
            cout<<"Provide the student's name: ";
            cin >> given_name;
            for(int i=0;i< 4; i++)
            {
                if(given_name == student_name[i])
                {
                    cout<<given_name<<endl;
                    cout<<"final grade: "<< (first_test[i] + second_test[i] + third_test[i])/3 <<endl;
                    break;
                }
            }

            if(sentinel)
            {
                cout<<"The stundet was not in the list."<<endl;
            }
            break;
        case 3:
            /*Compute all students final grades.*/
            for(int i=0; i<4; i++)
            {
            cout<< student_name[i] << "-- Final Grade: "<< (first_test[i] + second_test[i] + third_test[i])/3<<endl;
            }
            break;
        case 4:
            /*quit.*/
            cout<<"exit program"<<endl;
            exit(1);
            break;
        default:

            break;
        }
        cout<< "Do you want to keep using the APP, do Y or N: ";
        cin >> answer;
     } 
     
    return 0;
}

/******************************************* my functions *******************************************
*****************************************************************************************************/

void print_menu()
{
        cout<<right<<setfill('#')<<setw(20)<<" Menu "<<setfill('#')<<setw(20)<<"#"<<endl;
        cout<<"1. Find the student by the name."<<endl;
        cout<<"2. Compute student's final grade."<<endl;
        cout<<"3. Compute all students final grades."<<endl;
        cout<<"4. Quit."<<endl;
        cout<<right<<setfill('#')<<setw(40)<<"#"<<endl;
}

int find_student(string given_name, string student_name[], int lenght)
{
    int index=-1;
    bool sentinel = true;
    for(int i=0;i< lenght; i++)
    {
        if(given_name == student_name[i])
        {
            cout<<given_name<<endl;
            index = i;
            sentinel = false;
            break;
        }
    }
    if(sentinel)
    {
      cout<<"The stundet was not in the list."<<endl;
    }

    return index;
}

void test_score(string given_name, string student_name[],double first_test[],double second_test[], double third_test[],int lenght)
{
   int index = find_student( given_name, student_name, lenght);
   if(index != -1){
   cout<<student_name[index]<<setw(5)<<"first test: "<< first_test[index] <<" second test: "<< second_test[index] <<" third test: "<< third_test[index]<<endl;}
}