/************************************************************/
//Data types, variables and functions declarations
//to work with 3 dimensional vectors
/************************************************************/
#if !defined(VECTOR_H)
#define VECTOR_H

/**
 *@param xcomp vector component at x axis
 *@param ycomp vector component at y axis
 *@param zcomp vector component at z axis
*/
typedef struct vec *vector;

/**
 *@param xsize size of x component
 *@param ysize size of y component
 *@param zsize size of z component
 *@return brand new vector with the given values
*/
vector create_vector(double xsize, double ysize, double zsize);

/**
 Set x, y, z values to the given vector
 @param x value for x
 @param y value for y
 @param z value for z
*/
void set_values(vector v, double x, double y, double z);

/**
 @param v vector which x value is retrieved
 @return x_value of the given vector
*/
double get_xval(vector v);

/**
 @param v vector which x value is setted
*/
void set_xval(vector v, double val);

/**
 @param v vector which y value is retrieved
 @return y_value of the given vector
*/
double get_yval(vector v);

/**
 @param v vector which y value is setted
*/
void set_yval(vector v, double val);

/**
 @param v vector which z value is retrieved
 @return z value of the given vector
*/
double get_zval(vector v);

/**
 @param v vector which z value is set
*/
void set_zval(vector v, double val);

/**
 * Retrieves the x angle from the given vector
*/
double get_xangle(vector v);

/**
 * Retrieves the y angle from the given vector
*/
double get_yangle(vector v);

/**
 * Retrieves the z angle from the given vector
*/
double get_zangle(vector v);

/**
 * Retrieves the norm (modulues) of the given vector
 * @return norm of the vector
*/
double get_norm(vector v);

/**
* Perform the summation of all the given vectors
* @param args number of vectors to summation
* @param v vectors to be added
* @return the resulting vector
*/
void summation(int args, vector v, ...);

/**
* Perform the substraction of all the given vectors
* @param args number of vectors to subtraction
* @param v vectors to be substracted
* @return the resulting vector
*/
void subtraction(int args, vector v, ...);

/**
 Performs dot product operations with the given vectors
 Resulting vector is saved into the first vector pointer
 @param args number or vectors to multiply
 @param v vectors
*/
void dot_product(int args, vector v, ...);

/**
 Performs cross product operations with the given vectors
 Resulting vector is saved into the first vector pointer
 @param args number or vectors to multiply
 @param v vectors
*/
void cross_product(int args, vector v, ...);

#endif // VECTOR_H
