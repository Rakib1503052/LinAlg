#include "matalg.h"

using namespace std;

vector<vector<double>> matalg::mat_I(size_t n)
{
    //In case it's not clear from the name, it returns an identity matrix.
    if(n == 0)
    {
        throw runtime_error("Error: Dimension size 'n' cannot be 0.");
    }

    vector<vector<double>> result (n, vector<double>(n, 0));

    for(size_t i = 0; i < n; i++)
    {
        result[i][i] = 1;
    }

    return result;
}

vector<vector<double>> matalg::mat_T(const vector<vector<double>>& A)
{
    //Again, if it's not clear from the name, it's to transpose a matrix.
    if(!matalg::validate_matrix(A))
    {
        throw runtime_error("Error: Matrix 'A' is not valid.");
    }


    size_t n = A.size(), m = A[0].size();
    vector<vector<double>> result (m, vector<double>(n));

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            result[j][i] = A[i][j];
        }
    }

    return result;
}

vector<vector<double>> matalg::companion(const vector<double>& P)
{
/*
Returns companion matrix of polynomial P(x)=p0+p1*x+p2*x^2+...+pn*x^n as
C=|-p1 -p2 ... -p(n-1) -pn|
  | 1   0  ...    0     0 |
  | 0   1  ...    0     0 |
  | .   .  ...    .     . |
  | 0   0  ...    1     0 |
Explicitly following Scipy.
*/
    size_t n = P.size() - 1;
    vector<double> firstRow(n, 0);

    for(size_t k = 0; k < n; k++)
    {
        firstRow[k] = (-1) * P[k+1];
    }

    vector<vector<double>> I = matalg::mat_I(n - 1);

    for(size_t k = 0; k < (n-1); k++)
    {
        I[k].insert(I[k].end(), 0);
    }

    I.insert(I.begin(), firstRow);

    return I;
}
