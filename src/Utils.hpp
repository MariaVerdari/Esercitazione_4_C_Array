#pragma once

#include <iostream>

using namespace std;


bool ImportVectors(const string& inputFilePath,
                   int& n, double& S,
                   double*& w,
                   double*& r);
		
		
 double FinalValue(const int& n, const double S,
                        const double* const& w,
                        const double* const& r);
						
						
 double RateOfReturn(const int& n, const double S,
                        const double* const& w,
                        const double* const& r);
						
bool ExportResult(const string& outputFilePath,
				const double S,
                  const int& n,
                  const double* const& w,
                  const double* const& r,
                  const  double& FinalValue,
				  const double& RateOfReturn);						
						
		
						
						
						
						
						
						