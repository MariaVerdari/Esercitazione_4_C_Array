#include "Utils.hpp"
#include <string>
#include "iostream"
#include "fstream"
#include "sstream"
#include<iomanip>
#include <vector>
#include <locale>


using namespace std;


bool ImportVectors(const string& inputFilePath,
                   int& n, double& S,
                   double*& w,
                   double*& r)
{
	ifstream fstr(inputFilePath);
	
	
	
	if (fstr.fail()) {
		return false;
	}
	

	std ::string temp;
	getline(fstr, temp);//tolgo prima riga
	
	int i = temp.find(";");

	 S = std::stod(temp.substr(i+1,temp.size()));
      

	
	
	
	std ::string temp1;
	getline(fstr, temp1);//tolgo prima riga
	
	int k = temp1.find(";");
	

	
	
	n =std::stoi(temp1.substr(k+1,temp1.size()));
	
	getline(fstr, temp);//tolgo altra rig
	
	w = new double[n];
	r = new double[n];
	
	
	
	for (unsigned int j = 0; j<n; j++)
	{
		
	std ::string temp;
	getline(fstr, temp);
	
	
	int i = temp.find(";");

	w[j]=std::stod(temp.substr(0,i) );
	r[j] =std::stod(temp.substr(i+1,temp.size()));
	}
	
	
	
	
	

    return true;
}


 long double FinalValue(const size_t& n, const double S,
                        const double * const& w,
                        const double* const& r)
{
	long double V = 0;
	
	for (unsigned int i = 0; i<n; i++){
		V+=(1+r[i])*w[i]*S;
		
	}
	
    return V;
}


 double RateOfReturn(const size_t& n, const double S,
                        const double * const& w,
                        const double* const& r)
{
	double V = 0;
	
	for (unsigned int i = 0; i<n; i++){
		V+=(1+r[i])*w[i]*S;
		
	}
	
	double rof = (V/S) - 1.0;
	
    return rof;
}



bool ExportResult(const string& outputFilePath,
				const double& S,
			
                  const size_t& n,
                  const double * const& w,
                  const double * const& r,
                  const long double& FinalValue,
				  const double& RateOfReturn)
{
    // Open File
    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }
	

    file << "S = "<<fixed<<setprecision(2)<<S <<", n = "<<defaultfloat <<n<<endl;
    file << "w = [ " ;
	for (unsigned int i = 0; i < n; i++)
        file << w[i]<< " ";
    file << "]"<<endl;
	
	file << "r = [ " ;
	for (unsigned int i = 0; i < n; i++)
        file << r[i]<< " ";
    file << "]"<<endl;
	
	file<<"Rate of return of the portfolio: "<<defaultfloat<<RateOfReturn<<endl;
	file<<"V: "<<FinalValue<<endl;

   

    // Close File
    file.close();
	
	
	cout << "S = "<<fixed<<setprecision(2)<<S<< ", n = " <<n<<endl;
    cout << "w = [ " ;
	for (unsigned int i = 0; i < n; i++)
        cout << w[i]<< " ";
    cout << "]"<<endl;
	
	cout << "r = [ " ;
	for (unsigned int i = 0; i < n; i++)
        cout << r[i]<< " ";
    cout << "]"<<endl;
	cout<<"Rate of return of the portfolio: "<<fixed<<setprecision(4)<<RateOfReturn<<endl;   
	cout<<"V: "<<fixed<<setprecision(2)<<FinalValue<<endl;
	
	


    return true;
}


