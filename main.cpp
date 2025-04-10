#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Utils.hpp"

using namespace std;
int main()
{
	
	std ::string inputFile = "data.txt";
	int n ;
	double S;
	double*w= nullptr;
	double*r = nullptr;
	bool a = ImportVectors(inputFile,n, S, w, r);
	
	
	if (!ImportVectors(inputFile,n, S, w, r)) {
		return 1; // se importvector è falso
	}
	
	
	
	long double V = FinalValue( n, S,
                         w,
                        r);
						
	double rof= RateOfReturn( n, S,
                        w,
                         r);
	
	
	std ::string outputFile = "result.txt";
	
	bool b = ExportResult( outputFile,
				 S,
			
                   n,
                   w,
                   r,
                  V,
				  rof);
	
	

	
    return 0;
	
	cout<<w[0];
}

