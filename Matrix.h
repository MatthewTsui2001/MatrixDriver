#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <fstream>

class Matrix{
    public:
    //constructors
    Matrix();
    Matrix(const std::string & file);
    //methods
    Matrix operator+(const Matrix & a);
    Matrix operator-(const Matrix & a);
    Matrix operator*(const Matrix & a);
    Matrix operator*(const int & a);
    int* &operator[](const int & a);
    friend std::ostream &operator<<(std::ostream &out, const Matrix & v);
    bool operator==(const Matrix & v);


    private:
    int **m;
    int col;
    int row;
};



/**
 * This method overload the operator + symbol to add the vectors together
 * input: a, a matrix class that will be added to the matrix class calling the method
 * output: p the matrix class that is a combination of the two classes
*/
Matrix Matrix::operator+(const Matrix & a){
    Matrix p;
    p.row=row;
    p.col=col;
    p.m = new int*[row];
    for(int i=0;i<row;i++){
        p.m[i]=new int[col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            p.m[i][j]=m[i][j]+a.m[i][j];
        }
    }
    return p;
}

/**
 * This method overload the operator - symbol to subtract the vectors together
 * input: a, a matrix class that will be subtracted to the matrix class calling the method
 * output: p the matrix class that is the difference of the two classes
*/
Matrix Matrix::operator-(const Matrix & a){
    Matrix p;
    p.row=row;
    p.col=col;
    p.m = new int*[row];
    for(int i=0;i<row;i++){
        p.m[i]=new int[col];
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            p.m[i][j]=m[i][j]-a.m[i][j];
        }
    }
    return p;
}

/**
 * This method overload the operator * symbol to multiply the vectors together
 * input: a, a matrix class that will be multiplied to the matrix class calling the method
 * output: p the matrix class that is the matrix multiplication of the two classes
*/
Matrix Matrix::operator*(const Matrix & a){
    //produces an error message if the two vectors can not be multiplied together
    if(a.row != col){
        std::cout<<"Empty"<<std::endl;
        Matrix p;
        return p;
    }

    //creating a new vector with the rows of the first vector and the columns of the second vector
    Matrix p;
    p.row=row;
    p.col=a.col;
    p.m = new int*[row];
    for(int i=0;i<row;i++){
        p.m[i]=new int[col];
    }
    
    //performing matrix multiplication
    for(int i=0;i<a.col;++i){
        for(int j=0;j<row;++j){
            for(int k=0;k<a.row;++k){
                p.m[j][i]+=m[j][k]*a.m[k][i];
            }
        }
    }
    return p;
}    
/**
 * This method overload the operator * symbol to multiply the vector by a value at a certain index
 * input: a, a matrix class that will be multiplied to the matrix class calling the method
 * output: p the matrix class that is the difference of the two classes
*/
Matrix Matrix::operator*(const int & a){
    Matrix p;
    p.row=row;
    p.col=col;
    p.m = new int*[row];
    for(int i=0;i<row;i++){
        p.m[i]=new int[col];
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            p.m[i][j]=m[i][j]*a;
        }
    }
    return p;
}

/**
 * This method overload the operator == symbol compare if the two matrix are the same
 * input: v, a matrix class that will be compared to the matrix class calling the method
 * output: true or false if the two matrixes are the same
*/
bool Matrix::operator==(const Matrix & v){
    bool match=true;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(m[i][j]!=v.m[i][j]){
                match=false;
            }
        }
    }
    return match;
}

/**
 * This method overload the operator [] symbol return the vector
 * input: a, an int for the index of the vector that we are returning
 * output: the vector index of index a
*/
int* & Matrix::operator[](const int & a){
    return m[a];
}

/**
 * This method overload the operator << symbol to print out the matrix
 * input: v, a matrix class that will be printed out 
 * input: out an outstream that will store the string and print it out
 * output: out an outstream that will be printed
*/
std::ostream& operator<<(std::ostream & out, const Matrix& v){
    for(int i=0;i<v.row;i++){
        for(int j=0;j<v.col;j++){
            out<<v.m[i][j]<< "\t";
        }
        out<<"\n";
    }
    return out;
}

//constructor
Matrix::Matrix(){
    
}

//constructor
Matrix::Matrix(const std::string & file){
    std::ifstream fin;
    fin.open(file);
    //storing the rows and columns
    fin >> row;
    fin >> col;
    //creating array
    m=new int*[row];
    for(int i=0;i<row;i++){
        m[i] = new int[col];
    }

    //storing the values of the array
    for(int i = 0; i < row; i++){
        for(int j = 0 ; j < col ; j++){
            fin >> m[i][j];
        }
    }
    
}

#endif
