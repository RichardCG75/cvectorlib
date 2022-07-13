# cvectorlib
cvectorlib is a C library to make it easy to work with 3 dimensional vectors.
Just like in linear algebra, with this library we can perform the basic operations (addition, subtraction, dot product, cross product... etc)
between vectors as well as other cool features like easy to get angles and norms.

Written in C for max performance and C++ compatibility. The code pretend to imitate the OOP so in that way it can be used in as core in other programs
such like (next goal) visual C++ etc.

---

## Install and run
This current library version consists just by 2 files, one header file and one C file. So using it is pretty easy, the only thing to do here is to copy
the files into our the directory and ``` #include ``` the header file in our main.c file, and that's all we're ready to work

1. Create a main.c file
2. Copy the vector.h & vector.c files into the same directory that main.c file
3. Into the main.c file write ``` #include "vector.h"```
4. Write some code...
5. Open the command line and run ``` gcc main.c vector.c -lm -o myProgram ``` & ``` ./myProgram ```
  
It's pretty easy, isn't it?  

So we can download the files into a .zip file using https on GitHub, we can clone the repository, we can simply copy & paste the code directly from GitHub 
or whatever you consider easier

---

## How to use it?
Once we have the files in the working directory we are ready to use them in a program

### Create a vector
We can build a vector in a single step using create_vector() function
```C
//arg1 = x value, arg2 = y value, arg3 = z value

vector v = create_vector(1.0, 2.0, 3.0);   //create: V = (1, 2, 3)
```

As well, we can build an empty vector and then assign the values using set_values() function
```C
//arg1 = target, arg2 = x value, arg3 = y value, arg4 = z value

vector v = create_vector(0, 0, 0);     //create empty vector: V = (0, 0, 0)  
set_values(v, 1.0, 2.0, 3.0);          //set values to: V = (1, 2, 3)
```

---

**NOTE: It's important to mention that modifying any value of a vector we are altering the whole vector (components, angles, resulting... etc) 
so be careful**
### Setting values to vector
Using set_values() function we are able to change the x, y, z values of any vector  
```C
//arg1 is any vector reference that we want to set the values
 
set_values(v, 1.0, 2.0, 3.0);          //set values to: V = (1, 2, 3)
```

Also, we can set individual values using set_xval(), set_yval(), set_zval() functions

```C
vector v = create_vector(0, 0, 0);     //new void vector: V = (0, 0, 0)

set_xval(v, 2.0);                       //set x value: V = (2, 0, 0)
set_yval(v, -7.0);                      //set y value: V = (2, -7, 0)
set_zval(v, 4.0);                       //set z value: V = (2, -7, 4)

//note here that v can be the reference of any other vector that we have created before
```

---

### Getting values from any vector

#### Getting components

We can retrieve any value from any vector using get_xval(), get_yval(), get_zval() functions

```C
vector v = create_vector(2, -7, 5);     //new vector: V = (2, -7, 5)

double x = get_xval(v);                  //x = 2
double y = get_yval(v);                  //y = -7
double z = get_zval(v);                  //z = 5

//note here that v can be the reference of any other vector that we have created before
```

#### Getting angles
We can get any angle from any vector using get_xangle(), get_yangle(), get_zangle() functions   
**NOTE: Angles are in radians** so if you aren't familiarized with radians I recommend to use a unit degree-radians converter

```C
vector v = create_vector(2, -7, 5);     //new vector: V = (2, -7, 5)

double get_xangle(v)                    //x angle = 1.3423 radians
double get_yangle(v)                    //y angle = 2.4858 radians
double get_zangle(v)                    //z angle = 0.9689 radians


//param v can be the reference of any other vector that we have created before
```

#### Getting the norm from any vector

We can retrieve the norm also called modulus of any vector using the get_norm() function

```C
vector v = create_vector(2, -7, 5);     //new vector: V = (2, -7, 5)

double get_norm(v);

//param v can be the reference of any other vector that we have created before
```

---

### Vector operations  

Resulting vector is stored at the first passed vector, in all the examples below, the resulting (final) vector is stored in v1

#### Summation  
We are able to perform an addition among vectors using summation() function
```C
vector v1 = create_vector(2, -7, 5);     //new vector: V = (2, -7, 5)
vector v2 = create_vector(3, 12, 4);     //new vector: V = (3, 12, 4)

summation(2, v1, v2);                    //resulting vector: V = (5, 5, 9)

//first argument (int) is the number of vectors we want to add
//the rest are the vectors to sum
```

#### Subtraction
To perform a subtraction among vectors we use the subtraction() function... Its not that hard, right?
```C
vector v1 = create_vector(2, -7, 5);     //new vector: V = (2, -7, 5)
vector v2 = create_vector(3, 12, 4);     //new vector: V = (3, 12, 4)

subtraction(2, v1, v2);                  //resulting vector: V = (-1, -19, 1)

//first argument (int) is the number of vectors we want to subtract
//the rest are the vectors to subtract
```

#### Dot product
Dot product among vectors is performed by dot_product() function 
```C
vector v1 = create_vector(2, -7, 5);     //new vector: V = (2, -7, 5)
vector v2 = create_vector(3, 12, 4);     //new vector: V = (3, 12, 4)

dot_product(2, v1, v2);                  //resulting vector: V = (6, -84, 20)

//again,first argument (int) is the number of vectors we want to perform the dot product
//the rest are the vectors to multiply
```

#### Cross product

Cross product among vectors is performed by cross_product() function
```C
vector v1 = create_vector(2, -7, 5);     //new vector: V = (2, -7, 5)
vector v2 = create_vector(3, 12, 4);     //new vector: V = (3, 12, 4)

cross_product(2, v1, v2);                //resulting vector: V = (-88, -7, 45)

//again,first argument (int) is the number of vectors we want to perform the cross product
//the rest are the vectors to multiply
```

### Example test
Here is a little code to test the library by your own...
```C
#include <stdio.h>
#include "vector.h"

int main()
{

    vector v1 = create_vector(2, 7, 5);
    vector v2 = create_vector(4, 1, 2);

    printf("summation()\n");
    summation(2, v1, v2);
    printf("x: %lf y: %lf z: %lf\n", get_xval(v1), get_yval(v1), get_zval(v1));
    printf("x ang: %lf y ang: %lf z ang: %lf\n\n", get_xangle(v1), get_yangle(v1), get_zangle(v1));

    printf("subtraction()\n");
    subtraction(2, v1, v2);
    printf("x: %lf y: %lf z: %lf\n", get_xval(v1), get_yval(v1), get_zval(v1));
    printf("x ang: %lf y ang: %lf z ang: %lf\nn", get_xangle(v1), get_yangle(v1), get_zangle(v1));

    printf("dot product()\n");
    dot_product(2, v1, v2);
    printf("x: %lf y: %lf z: %lf\n", get_xval(v1), get_yval(v1), get_zval(v1));
    printf("x ang: %lf y ang: %lf z ang: %lf\n\n", get_xangle(v1), get_yangle(v1), get_zangle(v1));

    printf("cross product\n");
    cross_product(2, v1, v2);
    printf("x: %lf y: %lf z: %lf\n", get_xval(v1), get_yval(v1), get_zval(v1));
    printf("x ang: %lf y ang: %lf z ang: %lf\n\n", get_xangle(v1), get_yangle(v1), get_zangle(v1));

    printf("set value()\n");
    set_xval(v1, 3);
    set_yval(v1, 4);
    set_zval(v1, 5);
    printf("x: %lf y: %lf z: %lf\n", get_xval(v1), get_yval(v1), get_zval(v1));
    printf("x ang: %lf y ang: %lf z ang: %lf\n\n", get_xangle(v1), get_yangle(v1), get_zangle(v1));

    printf("set values()\n");
    set_values(v1, 0, 0, 0);
    printf("x: %lf y: %lf z: %lf\n", get_xval(v1), get_yval(v1), get_zval(v1));
    printf("x ang: %lf y ang: %lf z ang: %lf\n", get_xangle(v1), get_yangle(v1), get_zangle(v1));

    return 0;
}
```
You can just copy this code into a file called main.c in a folder containing vector.h and vector.c and then execute ```gcc -lm -o test main.c vector.c``` on
your command line and play around with the code and see the outputs  

So this is all for now, if you have any suggestion, or you want to contribute please let me know... Thanks for reading.
