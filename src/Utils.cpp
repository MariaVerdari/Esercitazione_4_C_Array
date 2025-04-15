#include "Utils.hpp"
#include <string>
#include "iostream"
#include "fstream"
#include "sstream"
#include <iomanip>
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
	

	string temp;
	
	char separator = ';';
	
    getline(fstr, temp, separator); 
	getline(fstr, temp); 
	
	S = stod(temp);
	
	getline(fstr, temp, separator);
	getline(fstr, temp); 
	
	n =stod(temp);
	
	
	
	getline(fstr, temp);//tolgo riga
	
	
	w = new double[n]; //alloco n double
	r = new double[n];
	

	
	for (unsigned int j = 0; j<n; j++)
	{
			
	getline(fstr, temp, separator);
	w[j]=std::stod(temp);
	
	getline(fstr, temp); 
	r[j] =std::stod(temp);
	
	}
	
	fstr.close();
	

    return true;
}


  double FinalValue(const int n, const double S,
                        const double* const& w,
                        const double* const& r)
{
	double V = 0;
	
	for (unsigned int i = 0; i<n; i++){
		V+=(1+r[i])*w[i]*S;
		
	}
	
    return V;
}


 double RateOfReturn(const int n, const double S,
                        const double* const& w,
                       const double* const& r)
{

	double V = FinalValue(n, S, w, r);
	double ror = (V/S) - 1.0;
	
    return ror;
}



bool ExportResult(const string& outputFilePath,
				  const double S,
				  const int n,
                  const double * const& w,
                  const double * const& r,
                  const double FinalValue,
				  const double RateOfReturn)
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


