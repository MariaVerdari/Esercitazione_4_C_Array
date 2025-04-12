#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Utils.hpp"

using namespace std;

int main()
{
	string inputFile = "data.txt";
	int n ;
	double S;
	double*w= nullptr;
	double*r = nullptr;
	bool a = ImportVectors(inputFile,n, S, w, r);
	
	
	if (!a) {
		return 1; 
	}
	
	
	
	double V = FinalValue(n, S, w, r);
                       
						
	double ror= RateOfReturn(n, S, w, r);
                       
                        
	string outputFile = "result.txt";
	
	bool b = ExportResult( outputFile, S, n, w, r, V, ror);
				
			
                 
	if (!b) {
		return 1; 
	}

	
    return 0;
	
}

