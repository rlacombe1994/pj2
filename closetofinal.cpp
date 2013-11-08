#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <list>

using namespace std;

int x=0;

struct Student
{
	string last_name;
	int UIN;
	double GPA;
	Student(string ln, int uin, double gpa)
		: last_name(ln),UIN(uin), GPA(gpa) {}
	Student () {}
};

void remove(list<Student>& All, string del);

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
		All.push_back(A);
		
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
        if(All[i].last_name!="") cout << All[i].last_name << '\t' << All[i].UIN << '\t' << All[i].GPA << endl;
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

void sortlastname(list<Student>& All)
{
   string maxU=" ";
   string newmax=" ";        
   int index =0;
   int count =0;
   int loop =1;
   
    list<Student>::iterator i;
    list<Student>::iterator j ; 
    list<Student>::iterator head = All.begin();
    list<Student>::iterator temp = head;
        list<Student>::iterator next = head;
        ++next;
        list<Student> sorted;
        list<Student> copy = All;
        string s;
        


    for(i=copy.begin();i!=copy.end();++i)
    {
        for(j=All.begin();j!=(All.end()) ;++j)
        {
                        if((*j).last_name > maxU)
                                newmax = (*j).last_name;
                        if(newmax >maxU)
                                index=count;
                        ++count;
                        maxU=newmax; 
        }
                for(int k=0; k< index; ++k)
                {
                        ++temp;        
                }
                if(index == 0)
                { 
                        sorted.push_front(*temp);
                        s = (*temp).last_name;
                        temp++;
                        remove(All,s); 
                }
                else
                {
                        sorted.push_front(*temp);
                        s = (*temp).last_name;
                        remove(All,s);
                        temp =All.begin();
                }
                maxU=" ";
                newmax=" ";
                index =0;
                count =0;
                ++loop; 
    }  
        All = sorted;
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

void sortUIN(list<Student>& All)
{
   int maxU =0; 
   int newmax=0;
   int index =0;
   int count =0;
   int loop =1;
   
    list<Student>::iterator i;
    list<Student>::iterator j ; 
        list<Student>::iterator head = All.begin();
        list<Student>::iterator temp = head;
        list<Student>::iterator next = head;
        ++next;
        list<Student> sorted;
        list<Student> copy = All;
        string s;
        


    for(i=copy.begin();i!=copy.end();++i)
    {  
        for(j=All.begin();j!=(All.end()) ;++j)
        { 
                        newmax = max((*j).UIN,maxU);
                        if(newmax >maxU)
                                index=count;
                        ++count;
                        maxU=newmax;
        }
                for(int k=0; k< index; ++k)
                {
                        ++temp;        
                }
                if(index == 0)
                {
                        sorted.push_front(*temp);
                        s = (*temp).last_name;
                        temp++;
                        remove(All,s);
                }
                else
                {
                        sorted.push_front(*temp);
                        s = (*temp).last_name;
                        remove(All,s);
                        temp =All.begin();
                }
                maxU=0;
                newmax=0;
                index =0;
                count =0;
                ++loop;
    } 
        All = sorted;
}


void binaryserach(vector<Student>& All,int Uin)
{
    int middle=All.size()/2;
    int end=All.size();
    int place=All.size()/2;
	int old=-1;
	int loop=1;
	
    while(Uin)
    {
			old=place;
          if(All[place].UIN<Uin)
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
          else 
		  {
			cout << All[place].last_name << '\t' << All[place].UIN << '\t' << All[place].GPA << endl;
			break;
		  }
		  if(old==place || loop==50) 
		  {
			cout << "Not found!\n";
			break;
			}
		  ++loop;
		  
    }
	return;
}

void binaryserach(list<Student>& All,int Uin)
{
    int middle=All.size()/2;
    int end=All.size();
    int place=All.size()/2;
	int old=-1;
	int counter=1;
	int loop=1;
	
	list<Student>::iterator i;
	
	for(i=All.begin();counter<place;++counter)
	{
		++i;
	}
	
    while(Uin)
    {	
		old=counter;
        if((*i).UIN<Uin)
        {
            if(place>=middle) 
			{
				place=(place+end)/2;
				for(;counter<place;++counter)
				{
					++i;
				}
			}
            else 
			{
				place=(place+middle)/2;
				for(;counter<place;++counter)
				{
					++i;
				}
			}
            //cout << counter << '\n';;
        }
        else if((*i).UIN>Uin)
        {
            if(middle<place && place<=end)
            {
                place=(place+middle)/2;
				for(;counter>place;--counter)
				{
					--i;
				}
            }
              else 
			{
				place=(place)/2;
				for(;counter>place;--counter)
				{
					--i;
				}
			}
            //cout << counter << '\n';
        }
        else 
		{
			cout << (*i).last_name << '\t' << (*i).UIN << '\t' << (*i).GPA << endl;
			break;
		}
		if(old==counter || loop==50) 
		{
			cout << "Not found!\n";
			break;
		}
		++loop;
		  
    }
	return;
}

void linearsearch(vector<Student>& All,double Gpa)
{
    vector<Student> GpA;
    int j=0;
    for(int i=0;i<All.size();++i)
    {
        if(All[i].GPA==Gpa)
        {
            GpA.push_back(All[i]);
            ++j;
        }
    }
    cout << GpA;
}

void linearsearch(list<Student>& All,double Gpa)
{
    list<Student> GpA;
	list<Student>::iterator i;
	
    int j=0;
    for(i=All.begin();i!=All.end();++i)
    {
        if((*i).GPA==Gpa)
        {
            GpA.push_back(*i);
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
			cout << "Removed: " << All[i].last_name << '\t' << All[i].UIN << '\t' << All[i].GPA << endl;
            return i;
        }
    }
    return -1;
}

void insert(vector<Student>& All, Student add)
{
        All.push_back(add);
}

void insert(list<Student>& All, Student add)
{
        All.push_back(add);
}

void remove(vector<Student>& All, string del)
{
        int index = linearsearch_n(All,del);
        if(index <0)
                cout<<del<<" is not in the vector"<<endl;
        else
                All.erase(All.begin()+index);
}

void remove(list<Student>& All, string del)
{
	list<Student>::iterator i;
    for(i=All.begin();i!=All.end();++i)
    {
        if((*i).last_name==del)
        {
			if(x==1) cout << "Removed: " << (*i).last_name << '\t' << (*i).UIN << '\t' << (*i).GPA << endl;
           i=All.erase(i);
		   return;
        }
    }
	cout << "Not found";
}

int main()
{
	vector<Student> vi;
	cin >> vi;
    
    cout << "---part A---\n";
	sortlastname(vi);
    cout << vi;
    
    cout << "---part B---\n";
    sortUIN(vi);
    cout << vi;
    
    cout << "---part C---\n";
    string UINs;
    cout << "UIN: ";
	cin >> UINs;
    int UIN=atoi(UINs.c_str());
    binaryserach(vi,UIN);
	
    cout << "---part D---\n";
    double GPA;
    cout << "GPA: ";
    cin >> GPA;
    linearsearch(vi,GPA);
	
	cout << "---part E---\n";
	insert(vi,Student("Smith",204394130, 3.4));
	cout << vi;
	
	cout << "---part F---\n";
	remove(vi,"Loe");
	cout << "---Updated---\n";
	cout << vi;
	
	cout << "---List---\n";
	list<Student> li;
    cin>>li;
	
	cout << "---part A-list---\n";
	sortlastname(li);
    cout << li;
    
    cout << "---part B-list---\n";
    sortUIN(li);
    cout << li;
	
	cout << "---part C-list---\n";
    string UINsl;
    cout << "UIN: ";
	cin >> UINsl;
    int UINl=atoi(UINsl.c_str());
    binaryserach(li,UINl);
	
	cout << "---part D-list---\n";
	double GPAl;
    cout << "GPA: ";
    cin >> GPAl;
    linearsearch(li,GPAl);
	
	cout << "---part E-list---\n";
	insert(li,Student("Smith",204394130, 3.4));
	cout << li;
	
	cout << "---part F-list---\n";
	x=1;
	remove(li,"Zoe");
	cout << "---Updated---\n";
	cout << li;
}
