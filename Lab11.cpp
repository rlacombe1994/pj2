#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <set>
#include <algorithm>


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

struct ByUin
{
	bool operator()(const Student& s1 , const Student s2){
		return s1.UIN < s2.UIN;
	}
};

istream& operator>>(istream& is, map<int,double>& mid)
{
        ifstream f_in("Student.txt",ios::in);
    
    int UIN;
    double GPA;
        
        string next;
        int nextint;
        double nextdouble;

        while(!f_in.eof())
    {
        f_in >> next;
                if(next=="UIN:") 
                {
                        f_in >> nextint;
                        UIN=nextint;
                }
                if(next=="GPA:")
                {
                        f_in >> nextdouble;
                        GPA=nextdouble;
                        mid.insert(pair<int,double>(UIN,GPA));
                }
        }   
        return is;
}

istream& operator>>(istream& is, set<Student,ByUin>& All)
{
    ifstream f_in("Student.txt",ios::in);
    
	bool unique = true;
    string last_name;
    int UIN;
    double GPA;
        
        string next;
        int nextint;
        double nextdouble;
        
        while(!f_in.eof())
    {
        f_in >> next;
        last_name=next;
                
                f_in >> nextint;
        UIN=nextint;
                
                f_in >> nextdouble;
        GPA=nextdouble;
                
        Student A(last_name,UIN,GPA);
        for(set<Student>::iterator it=All.begin(); it!=All.end(); ++it)
		{
			if((*it).UIN == A.UIN)
				unique =false;
		}
		if(unique == true)
			All.insert(A);
		unique =true;
    }
        
        return is;
} 

ostream& operator<<(ostream& os, set<Student,ByUin>& All)
{
        for(set<Student>::iterator it=All.begin(); it!=All.end(); ++it)
        {
                os << it->last_name << "\t" << "GPA: " << it->GPA <<"\tUIN: "<< it->UIN<< '\n';
        }
        return os;
}

ostream& operator<<(ostream& os, map<int,double>& mid)
{
        for(map<int,double>::iterator it=mid.begin(); it!=mid.end(); ++it)
        {
                cout << "UIN: " << it->first << "\t" << "GPA: " << it->second << '\n';
        }
        return os;
}

ostream& operator<<(ostream& os, map<double,int>& mid)
{
        for(map<double,int>::iterator it=mid.begin(); it!=mid.end(); ++it)
        {
                cout << "GPA: " << it->first << "  \t" << "UIN: " << it->second << '\n';
        }
        return os;
}

void binaryserach(set<Student,ByUin>& All,int Uin)
{
    int middle=All.size()/2;
    int end=All.size();
    int place=All.size()/2;
        int old=-1;
        int counter=0;
        int loop=1;
        
        set<Student>::iterator i;
        
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
        }
        else 
        {
            cout << (*i).last_name << '\t' <<"GPA: " <<(*i).GPA <<"\tUIN: "<< (*i).UIN <<endl;
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

void linearsearch(set<Student,ByUin>& All,double Gpa)
{
    set<Student,ByUin> GpA;
    set<Student>::iterator i;
        
    int j=0;
    for(i=All.begin();i!=All.end();++i)
    {
        if((*i).GPA==Gpa)
        {
            GpA.insert(*i);
            ++j;
        }
    }
    cout << GpA;
}

void remove(set<Student,ByUin>& All,string target)
{
		bool removed = false;
        set<Student>::iterator it=All.begin();
        for(it;it!=All.end();++it)
			if((*it).last_name== target)
			{
				All.erase(it);
				removed =true;
				break;
			}
		if(!removed)	
			cout<<target<<" Not found!"<<endl<<endl;
}

double aver(map<int,double>& mid)
{
        double total=0;
        int keys=0;
        
        for(map<int,double>::iterator it=mid.begin(); it!=mid.end(); ++it)
        {
                total+= it->second;
                ++keys;
        }
        return total/keys;
}

void remove(map<int,double>& mid)
{
        map<int,double>::iterator it=mid.end();
        --it;
        mid.erase(it);
}

void copyswap(map<double,int>& mdi, map<int,double>& mid)
{
        for(map<int,double>::iterator it=mid.begin(); it!=mid.end(); ++it)
        {
                mdi.insert(pair<double,int>(it->second,it->first));
        }
}

int main()
{ 

	cout << "----#1 part A----\n\n";
	set<Student,ByUin> All;
	cin>>All;
	cout<<All;
	cout << "----#1 part BC----\n\n";
	binaryserach(All,123456789);	
	cout << "----#1 part BD----\n\n";
	linearsearch( All,1.7);
	cout << "----#1 part BE----\n\n";
	All.insert(Student("Smith", 204394130, 3.4));
	cout<<All;
	cout<<endl<<endl;
	cout << "----#1 part BF----\n\n";
	remove(All,"Smith");
	cout<<All;
	/*
        map<int,double> mid;
        cin >> mid;
        
        cout << "----All Pairs----\n";
        cout << mid;
        
        cout << "----Average----\n";
        cout << aver(mid) << '\n';
        
        cout << "----Remove----\n";
        remove(mid);
        cout << mid;
        
        cout << "----mdi----\n";
        map<double,int> mdi;
        copyswap(mdi,mid);
        cout << mdi; */
}
