#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

struct Student
{
	string last_name;
	int UIN;
	double GPA;
	Student(string ln, int uin, double gpa)
		: last_name(ln),UIN(uin), GPA(gpa) {}
	Student () {}
};

istream& operator>>(istream& is, vector<Student>& All)
{
	ifstream f_in("Student.txt",ios::in);
    
    string last_name;
    int UIN;
    double GPA;
	
	string next;
	int nextint;
	double nextdouble;
	
	
	int i=0;
	
	while(!f_in.eof())
    {
        f_in >> next;
        last_name=next;
		
		f_in >> nextint;
        UIN=nextint;
		
		f_in >> nextdouble;
        GPA=nextdouble;
		
		Student A(last_name,UIN,GPA);
		All[i]=A;
		
		++i;
	}
        
	return is;
}

ostream& operator<<(ostream& os, vector<Student>& All)
{
    for(int i=0;i<All.size();++i)
    {
        if(All[i].last_name!="") cout << All[i].last_name << '\t' << All[i].UIN << '\t' << All[i].GPA << endl;
    }
    return os;
}

void sortlastname(vector<Student>& All)
{
	Student Temp("Bill",123,4.0);
	for(int i=0;i<All.size();++i)
		{
			for(int j=0;j<(All.size()-1);++j)
			{
				if(All[j].last_name>All[(j+1)].last_name)
				{
					Temp=All[j];
					All[j]=All[j+1];
					All[j+1]=Temp;
				}
			}
		}
}

void sortUIN(vector<Student>& All)
{
	Student Temp("Bill",123,4.0);
	for(int i=0;i<All.size();++i)
    {
        for(int j=0;j<(All.size()-1);++j)
        {
            if(All[j].UIN>All[(j+1)].UIN)
            {
                Temp=All[j];
                All[j]=All[j+1];
                All[j+1]=Temp;
            }
        }
    }
}

int binaryserach(vector<Student>& All,int Uin)
{
    int middle=All.size()/2;
    int end=All.size();
    int place=All.size()/2;
    while(true)
    {
          if(All[place].UIN<Uin)
          {
              if(place>=middle) place=(place+end)/2;
              else place=(place+middle)/2;
              cout << place << '\n';
          }
          else if(All[place].UIN>Uin)
          {
              if(middle<place && place<=end)
              {
                  place=(place+middle)/2;
              }
              else place=(place)/2;
              cout << place << '\n';
          }
          else return (place+1);
    }
}

void linearsearch(vector<Student>& All,double Gpa)
{
    vector<Student> GpA(10);
    int j=0;
    for(int i=0;i<All.size();++i)
    {
        if(All[i].GPA==Gpa)
        {
            GpA[j]=All[i];
            ++j;
        }
    }
    cout << GpA;
}

int main()
{
	vector<Student> vi(10);
	cin >> vi;
    
    cout << "---part A---\n";
	sortlastname(vi);
    cout << vi;
    
    cout << "---part B---\n";
    sortUIN(vi);
    cout << vi;
    
    cout << "---part C---\n";
    int UIN;
    cout << "UIN: ";
    cin >> UIN;
    cout << binaryserach(vi,UIN) << '\n';
    
    cout << "---part D---\n";
    double GPA;
    cout << "GPA: ";
    cin >> GPA;
    linearsearch(vi,GPA);
}
