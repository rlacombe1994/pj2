#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <algorithm>


using namespace std;

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
	cout << mdi;
}
