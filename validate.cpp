#include "matalg.h"

using namespace std;

bool matalg::validate_matrix(const vector<vector<double>>& A)
{
    for(size_t i = 1; i < A.size(); i++)
    {
        if(A[i].size() == A[i-1].size())
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool matalg::validate_equal_dimension(const vector<vector<double>>& A, const vector<vector<double>>& B)
{
    if(A.size() == B.size())
    {
        if(A[0].size() == B[0].size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool matalg::validate_squareMat(const vector<vector<double>>& inMat)
{
    size_t matSize = inMat.size();

    for (size_t i = 0; i < matSize; i++)
    {
        if (inMat[i].size() == matSize)
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

