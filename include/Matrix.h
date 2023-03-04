//========================================================================
// Matrix.h
//========================================================================
// Declarations for calculator matrix object.

#ifndef Matrix_H
#define Matrix_H


class Matrix {
    
    public: 
        // constructor and deconstructor 
        Matrix();
        ~Matrix();

        // methods
        Matrix inverse();

    private:
        int ncols;
        int nrows;
};

#endif