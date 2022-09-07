#include "matalg.h"
#include "internal.hpp"

using namespace std;

vector<double> matalg::solve_linSystem(const vector<vector<double>>& A, const vector<double>& B)
{
	//This function solves a unique linear system Ax = B using Gauss-Jordan elimination. I could use Couchy's theorm too since
	//the determinant function is fast anyway. But this uses basically same process and a few times faster for large matrices.
	//So, this is nearly a copy-paste of the process from matalg::det function.
	//The solution procedure is to first make a partitioned matrix (A|B) and then decompose it to (I|X) using row reduction.
	//I am too tired to explain more or put example here. Just Google it.

    const size_t n = A.size();
    double detA = matalg::det(A);

    if (detA == 0){
        throw runtime_error("System cannot be solved. Error: Coefficient determinant is 0.");
    }

    if (n != B.size()){
        throw runtime_error("System cannot be solved. Error: Invalid dimensions.\n");
    }

	vector<vector<double>> A1 = A;		//Again, regardless of what VS says, IT IS INTENTIONAL.
	vector<double> X(n), row(n);
	double head_n1, head_n2, coef;

	for (size_t i = 0; i < n; i++) { A1[i].push_back(B[i]); }

	for (size_t i = 0; i < n; i++)
	{
		head_n1 = A1[i][i];
		for (size_t j = 0; j < n; j++)
		{
			if (i != j)
			{
				head_n2 = A1[j][i];
				coef = head_n2 / head_n1;
				row = coef * A1[i];
				A1[j] = A1[j] - row;
			}
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		coef = 1 / A1[i][i];
		A1[i] = coef * A1[i];
		X[i] = A1[i][n];
	}

	return X;
}
