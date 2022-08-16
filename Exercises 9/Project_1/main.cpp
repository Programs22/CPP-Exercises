#include <iostream>

using namespace std;

#define size 100

class Matrix{
private:
    int m, n; // m - Number of rows; n - Number of columns
    int matrix[size][size];
public:
    Matrix(int r=1, int c=1){
        m=r;
        n=c;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                matrix[i][j]=0;
    }
    Matrix(Matrix &M){
        m=M.m;
        n=M.n;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                matrix[i][j]=M.matrix[i][j];
    }
    friend ostream &operator<<(ostream &output, Matrix &M){
        for(int i=0;i<M.m;i++){
            for(int j=0;j<M.n;j++)
                output << M.matrix[i][j] << " ";
            output << endl;
        }
        return output;
    }
    friend istream &operator>>(istream &input, Matrix &M){
        for(int i=0;i<M.m;i++){
            for(int j=0;j<M.n;j++){
                cout << "Enter a number for the matrix" << endl;
                input >> M.matrix[i][j];
            }
        }
        return input;
    }
    int operator[](int i){ // Counter i for the row number
        cout << "Enter the column number of the matrix" << endl;
        int j;
        cin >> j;
        return matrix[i][j];
    }
    Matrix operator+(Matrix &M){
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                matrix[i][j]+=M.matrix[i][j];
        return *this;
    }
    Matrix operator-(Matrix &M){
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                matrix[i][j]-=M.matrix[i][j];
        return *this;
    }
    friend Matrix operator*(Matrix &M1, Matrix &M2){
        Matrix result(M1.m,M2.n);
        int r1=0, c1=0, r2=0, c2=0;
        for(int i=0;i<result.m;i++){
            for(int j=0;j<result.n;j++){
                while(c1<M1.n&&r2<M2.m){
                    result.matrix[i][j]+=M1.matrix[r1][c1]*M2.matrix[r2][c2];
                    c1++;
                    r2++;
                }
                c1=0;
                r2=0;
                c2++;
            }
            r1++;
            c2=0;
        }
        return result;
    }
    friend void operator*(Matrix &M, int number){
        for(int i=0;i<M.m;i++)
            for(int j=0;j<M.n;j++)
                M.matrix[i][j]*=number;
    }
    friend void operator*(int number, Matrix &M){
        for(int i=0;i<M.m;i++)
            for(int j=0;j<M.n;j++)
                M.matrix[i][j]*=number;
    }
    bool operator==(Matrix &M){
        bool flag=true;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(matrix[i][j]!=M.matrix[i][j]){
                    flag=false;
                    break;
                }
        return flag;
    }
};

int main()
{
    Matrix M1(3,3), M2(3,3);
    cout << "Enter the matrix" << endl;
    cin >> M1;
    cout << "Enter the matrix" << endl;
    cin >> M2;
    Matrix M3=M1*M2;
    cout << M3;
    M1*3;
    cout << M1;
    cout << M1[2] << endl;
    M2+M1;
    cout << M2;
    if(M1==M2)
        cout << "The matrices are equal" << endl;
    else
        cout << "The matrices are not equal" << endl;
    return 0;
}
