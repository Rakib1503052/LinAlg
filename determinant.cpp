#include "matalg.h"
#include "internal.hpp"

using namespace std;

double matalg::det(const vector<vector<double>>& A, bool validate)
{
    //This function uses Row elimination method to find the determinant in N*(N-1)/2 time.
    //Example: for a matrix,    |2 6 3|
    //                      A = |5 5 2|
    //                          |1 6 8|
    //To find the determinant, A is reduced to an upper triangle matrix.
    //    |2 6 3|        |2   6    3|        |2   6     3|
    //A = |5 5 2| -> A = |0 -10 -5.5| -> A = |0 -10  -5.5|
    //    |1 6 8|        |0   3  6.5|        |0   0  4.85|
    //
    // Then the determinant is simply the multiplication of all the numbers on the diagonal only.
    //i.e., A = 2*(-10)*4.85 = -97

    if (validate)
    {
        if (!matalg::validate_squareMat(A)){
            throw runtime_error("Error: Matrix is not square");
        }
    }

    size_t n = A.size();

    if (n == 1){
        return A[0][0];
    }

    else
    {
        auto A1 = A;            //VS shows this as potentially unintended copy. That is why I am the coder, not VS.
                                //This is completely intentional.
        double head_n1, head_n2, coef, detval = 1;
        vector<double> row(n);
        //double sum = 0;

        for (size_t i = 0; i < n; i++)
        {
            head_n1 = A1[i][i];

            //if (head_n1 == 0) { return 0; }     //Because if there is a 0 (zero) in the diagonal, the determinant is 0.
                                                  //Uncomment this check if you want to. Might make the result a bit unstable but improves performance.

            detval *= head_n1;
            for (size_t j = i + 1; j < n; j++)
            {
                head_n2 = A1[j][i];
                coef = head_n2 / head_n1;
                row = coef * A1[i];
                A1[j] = A1[j] - row;
            }
        }

        return detval;
    }
}
