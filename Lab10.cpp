#include <iostream>
#include <string>
#include <vector>
#include <list>
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

void sortlastname(list<Student>& All)
{
    Student Temp("Bill",123,4.0);
	list<Student>::iterator i;
	list<Student>::iterator j; 
    for(i=All.begin();i!=All.end();++i)
	{
        for(j=All.begin();j!=All.end();++j)
        { 

            if((*j).last_name > (*j++).last_name)
            {
                Temp.last_name=(*j).last_name;
				Temp.UIN=(*j).UIN;
				Temp.GPA=(*j).GPA;
				
                (*j).last_name=(*j++).last_name;
				(*j).UIN=(*j++).UIN;
				(*j).GPA=(*j++).GPA;
				
                (*j++).last_name=Temp.last_name;			
				(*j++).UIN=Temp.UIN;
				(*j++).GPA=Temp.GPA;
            } 
        }
    } 
}

void sortUIN(list<Student>& All)
{
    Student Temp("Bill",123,4.0);
	list<Student>::iterator i;
	list<Student>::iterator j; 
    for(i=All.begin();i!=All.end();++i)
	{
        for(j=All.begin();j!=All.end();++j)
        { 

            if((*j).UIN > (*j++).UIN)
            {
                Temp.last_name=(*j).last_name;
				Temp.UIN=(*j).UIN;
				Temp.GPA=(*j).GPA;
				
                (*j).last_name=(*j++).last_name;
				(*j).UIN=(*j++).UIN;
				(*j).GPA=(*j++).GPA;
				
                (*j++).last_name=Temp.last_name;			
				(*j++).UIN=Temp.UIN;
				(*j++).GPA=Temp.GPA; 
            } 
        }
    } 
}

void sortUIN(list<Student>& All)
{
    Student Temp("Bill",123,4.0);
	list<Student> temps;
	list<Student>::iterator i;
	list<Student>::iterator j; 
    for(i=All.begin();i!=All.end();++i)
	{
        for(j=All.begin();j!=All.end();++j)
        { 

            if((*j).UIN > (*j++).UIN)
            {
                Temp=(*j);
                (*j)=(*j++);
                (*j++)=Temp; 
            } 
        }
    } 
}

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

istream& operator>>(istream& is, list<Student>& All)
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
		All.push_back(A);
	
    }
}

ostream& operator<<(ostream& os, vector<Student>& All)
{
	 for(int i=0;i<All.size();++i)
    {
        if(All[i].last_name!="")
			os << All[i].last_name << '\t' << All[i].UIN << '\t' << All[i].GPA << endl;
    }
    return os;
}

ostream& operator<<(ostream& os, list<Student>& All)
{
	list<Student>::iterator i;
	Student temp;
    for( i=All.begin();i!=All.end();++i)
    {
		
		os<< (*i).last_name<<'\t'<< (*i).UIN<<'\t'<<(*i).GPA<<endl;
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
    int combobreaker=0;
    while(true)
    {
        if(combobreaker==10) break;
        else if(All[place].UIN<Uin)
          {
              if(place>=middle) place=(place+end)/2;
              else place=(place+middle)/2;
              //cout << place << '\n';
          }
        else if(All[place].UIN>Uin)
          {
              if(middle<place && place<=end)
              {
                  place=(place+middle)/2;
              }
              else place=(place)/2;
              //cout << place << '\n';
          }
        else return (place+1);
                ++combobreaker;
    }
        return -1;
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
int linearsearch_n(vector<Student>& All,string name)
{
    for(int i=0;i<All.size();++i)
    {
        if(All[i].last_name==name)
        {
            return i;
        }
    }
    return -1;
}

void insert(vector<Student>& All, Student add)
{
        All.push_back(add);
}
void remove(vector<Student>& All, Student del)
{
        
        int index = linearsearch_n(All,del.last_name);
        if(index <0)
                cout<<del.last_name<<" is not in the vector"<<endl;
        else
                All.erase(All.begin()+index);
}



int main()
{
        vector<Student> vi(10);
		list<Student> li;
        cin >> vi;
		cin>>li;
    
	
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
