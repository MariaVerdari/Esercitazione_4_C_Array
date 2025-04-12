#include "Utils.hpp"
#include <string>
#include "iostream"
#include "fstream"
#include "sstream"
#include<iomanip>
#include <array>


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
	getline(fstr, temp);
	
	int i = temp.find(";");

	S = std::stod(temp.substr(i+1,temp.size()));
      
	
	
	getline(fstr, temp);
	
	i = temp.find(";");
	
	n =std::stoi(temp.substr(i+1,temp.size()));
	
	
	
	getline(fstr, temp);//tolgo riga
	
	
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


  double FinalValue(const int& n, const double S,
                        const double* const& w,
                        const double* const& r)
{
	double V = 0;
	
	for (unsigned int i = 0; i<n; i++){
		V+=(1+r[i])*w[i]*S;
		
	}
	
    return V;
}


 double RateOfReturn(const int& n, const double S,
                        const double * const& w,
                        const double* const& r)
{
	/*
	double V = 0;
	
	for (unsigned int i = 0; i<n; i++){
		V+=(1+r[i])*w[i]*S;
		
	}
	*/
	double V = FinalValue(n, S, w, r);
	double ror = (V/S) - 1.0;
	
    return ror;
}



bool ExportResult(const string& outputFilePath,
				const double S,
			
                  const int& n,
                  const double * const& w,
                  const double * const& r,
                  const double& FinalValue,
				  const double& RateOfReturn)
{
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
	
	file<<"Rate of return of the portfolio: "<<fixed<<setprecision(4)<<RateOfReturn<<endl;
	file<<"V: "<<fixed<<setprecision(2)<<FinalValue<<endl;

   
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


