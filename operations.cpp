#include "matalg.h"

using namespace std;

vector<vector<double>> matalg::mat_add(const vector<vector<double>>& A, const vector<vector<double>>& B)
{
    if(!matalg::validate_matrix(A))
    {
        throw runtime_error("Dimension error: Matrix 'A' is not valid. ");
    }
    if(!matalg::validate_matrix(B))
    {
        throw runtime_error("Dimension error: Matrix 'B' is not valid. ");
    }
    if(!matalg::validate_equal_dimension(A,B))
    {
        throw runtime_error("Dimension mismatch error: Dimensions of 'A' and 'B' don't match.");
    }


    size_t n = A.size(), m = A[0].size();
    vector<vector<double>> result (n, vector<double>(m, 0));

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
            result[i][j] = A[i][j] + B[i][j];
    }

    return result;
}

vector<vector<double>> matalg::mat_sub(const vector<vector<double>>& A, const vector<vector<double>>& B)
{
    if(!matalg::validate_matrix(A))
    {
        throw runtime_error("Dimension error: Matrix 'A' is not valid. ");
    }
    if(!matalg::validate_matrix(B))
    {
        throw runtime_error("Dimension error: Matrix 'B' is not valid. ");
    }
    if(!matalg::validate_equal_dimension(A,B))
    {
        throw runtime_error("Dimension mismatch error: Dimensions of 'A' and 'B' don't match.");
    }


    size_t n = A.size(), m = A[0].size();
    vector<vector<double>> result (n, vector<double>(m, 0));

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

vector<vector<double>> matalg::mat_scale(const vector<vector<double>>& A, double k)
{
    if(!matalg::validate_matrix(A))
    {
        throw runtime_error("Dimension error: Matrix 'A' is not valid. ");
    }


    size_t n = A.size(), m = A[0].size();
    vector<vector<double>> result (n, vector<double>(m, 0));

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            result[i][j] = A[i][j] * k;
        }
    }

    return result;
}

vector<vector<double>> matalg::mat_mul(const vector<vector<double>>& A, const vector<vector<double>>& B)
{
    if(!matalg::validate_matrix(A))
    {
        throw runtime_error("Dimension error: Matrix 'A' is not valid. ");
    }
    if(!matalg::validate_matrix(B))
    {
        throw runtime_error("Dimension error: Matrix 'B' is not valid. ");
    }
    if(A.size() != B[0].size())
    {
        throw runtime_error("Dimension mismatch error: The number of row of A and the number of row of B must be equal.");
    }

    size_t rowSize = A.size(); //Result row size
    size_t colSize = B[0].size(); //Result column size
    vector<vector<double>> result (rowSize, vector<double>(colSize, 0));

    for(size_t i = 0; i < rowSize; i++)
    {
        for(size_t j = 0; j < colSize; j++)
        {
            for(size_t k = 0; k < B.size(); k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}
