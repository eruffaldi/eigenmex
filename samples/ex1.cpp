// 
// Assuming Eigen3 in the path
//
// mex ex1.cpp -I../include
#include <mex.h>
#include "eigenMat.h"

using namespace Eigen;

void mexFunction( int nlhs, mxArray *plhs[],int nrhs, const mxArray *prhs[]) 
{
	if(nrhs == 2 && nlhs == 1)
	{
		if(isValidMATd(prhs[0]) && isValidMATd(prhs[1]))
		{
			Map<MatrixXd> a = fromMATd(prhs[0]);   
			Map<MatrixXd> b = fromMATd(prhs[1]); 
			if(a.cols() != b.rows())
			{
				mexErrMsgIdAndTxt("eigenmex:ex1","c = ex1(a,b) with a cols same as b rows");
			}       	
			Eigen::MatrixXd c = Eigen::MatrixXd(a.rows(),b.cols());
			c = a*b; 	
			plhs[0] = toMAT(c);
		}
	}
	else
		mexErrMsgIdAndTxt("eigenmex:ex1","c = ex1(a,b)");
}
