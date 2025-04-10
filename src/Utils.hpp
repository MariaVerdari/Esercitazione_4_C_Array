#pragma once

#include <iostream>

using namespace std;


bool ImportVectors(const string& inputFilePath,
                   int& n, double& S,
                   double*& w,
                   double*& r);
		
		
long double FinalValue(const size_t& n, const double S,
                        const double* const& w,
                        const double* const& r);
						
						
 double RateOfReturn(const size_t& n, const double S,
                        const double* const& w,
                        const double* const& r);
						
bool ExportResult(const string& outputFilePath,
				const double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const long double& FinalValue,
				  const double& RateOfReturn);						
						
		
						
						
						
						
						
						