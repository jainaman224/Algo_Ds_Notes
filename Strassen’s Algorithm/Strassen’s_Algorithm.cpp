    #include <assert.h>

    #include <stdio.h>

    #include <stdlib.h>

    #include <time.h>

     

    #define M 2

    #define N (1<<M)

     

    typedef double datatype;

    #define DATATYPE_FORMAT "%4.2g"

    typedef datatype mat[N][N]; // mat[2**M,2**M]  for divide and conquer mult.

    typedef struct

    {

            int ra, rb, ca, cb;

    } corners; // for tracking rows and columns.

    // A[ra..rb][ca..cb] .. the 4 corners of a matrix.

     

    // set A[a] = I

    void identity(mat A, corners a)

    {

        int i, j;

        for (i = a.ra; i < a.rb; i++)

            for (j = a.ca; j < a.cb; j++)

                A[i][j] = (datatype) (i == j);

    }

     

    // set A[a] = k

    void set(mat A, corners a, datatype k)

    {

        int i, j;

        for (i = a.ra; i < a.rb; i++)

            for (j = a.ca; j < a.cb; j++)

                A[i][j] = k;

    }

     

    // set A[a] = [random(l..h)].

    void randk(mat A, corners a, double l, double h)

    {

        int i, j;

        for (i = a.ra; i < a.rb; i++)

            for (j = a.ca; j < a.cb; j++)

                A[i][j] = (datatype) (l + (h - l) * (rand() / (double) RAND_MAX));

    }

     

    // Print A[a]

    void print(mat A, corners a, char *name)

    {

        int i, j;

        printf("%s = {\n", name);

        for (i = a.ra; i < a.rb; i++)

        {

            for (j = a.ca; j < a.cb; j++)

                printf(DATATYPE_FORMAT ", ", A[i][j]);

            printf("\n");

        }

        printf("}\n");

    }

     

    // C[c] = A[a] + B[b]

    void add(mat A, mat B, mat C, corners a, corners b, corners c)

    {

        int rd = a.rb - a.ra;

        int cd = a.cb - a.ca;

        int i, j;

        for (i = 0; i < rd; i++)

        {

            for (j = 0; j < cd; j++)

            {

                C[i + c.ra][j + c.ca] = A[i + a.ra][j + a.ca] + B[i + b.ra][j

                        + b.ca];

            }

        }

    }

     

    // C[c] = A[a] - B[b]

    void sub(mat A, mat B, mat C, corners a, corners b, corners c)

    {

        int rd = a.rb - a.ra;

        int cd = a.cb - a.ca;

        int i, j;

        for (i = 0; i < rd; i++)

        {

            for (j = 0; j < cd; j++)

            {

                C[i + c.ra][j + c.ca] = A[i + a.ra][j + a.ca] - B[i + b.ra][j

                        + b.ca];

            }

        }

    }

     

    // Return 1/4 of the matrix: top/bottom , left/right.

    void find_corner(corners a, int i, int j, corners *b)

    {

        int rm = a.ra + (a.rb - a.ra) / 2;

        int cm = a.ca + (a.cb - a.ca) / 2;

        *b = a;

        if (i == 0)

            b->rb = rm; // top rows

        else

            b->ra = rm; // bot rows

        if (j == 0)

            b->cb = cm; // left cols

        else

            b->ca = cm; // right cols

    }

     

    // Multiply: A[a] * B[b] => C[c], recursively.

    void mul(mat A, mat B, mat C, corners a, corners b, corners c)

    {

        corners aii[2][2], bii[2][2], cii[2][2], p;

        mat P[7], S, T;

        int i, j, m, n, k;

     

        // Check: A[m n] * B[n k] = C[m k]

        m = a.rb - a.ra;

        assert(m==(c.rb-c.ra));

        n = a.cb - a.ca;

        assert(n==(b.rb-b.ra));

        k = b.cb - b.ca;

        assert(k==(c.cb-c.ca));

        assert(m>0);

     

        if (n == 1)

        {

            C[c.ra][c.ca] += A[a.ra][a.ca] * B[b.ra][b.ca];

            return;

        }

     

        // Create the 12 smaller matrix indexes:

        //  A00 A01   B00 B01   C00 C01

        //  A10 A11   B10 B11   C10 C11

        for (i = 0; i < 2; i++)

        {

            for (j = 0; j < 2; j++)

            {

                find_corner(a, i, j, &aii[i][j]);

                find_corner(b, i, j, &bii[i][j]);

                find_corner(c, i, j, &cii[i][j]);

            }

        }

     

        p.ra = p.ca = 0;

        p.rb = p.cb = m / 2;

     

    #define LEN(A) (sizeof(A)/sizeof(A[0]))

        for (i = 0; i < LEN(P); i++)

            set(P[i], p, 0);

     

    #define ST0 set(S,p,0); set(T,p,0)

     

        // (A00 + A11) * (B00+B11) = S * T = P0

        ST0;

        add(A, A, S, aii[0][0], aii[1][1], p);

        add(B, B, T, bii[0][0], bii[1][1], p);

        mul(S, T, P[0], p, p, p);

     

        // (A10 + A11) * B00 = S * B00 = P1

        ST0;

        add(A, A, S, aii[1][0], aii[1][1], p);

        mul(S, B, P[1], p, bii[0][0], p);

     

        // A00 * (B01 - B11) = A00 * T = P2

        ST0;

        sub(B, B, T, bii[0][1], bii[1][1], p);

        mul(A, T, P[2], aii[0][0], p, p);

     

        // A11 * (B10 - B00) = A11 * T = P3

        ST0;

        sub(B, B, T, bii[1][0], bii[0][0], p);

        mul(A, T, P[3], aii[1][1], p, p);

     

        // (A00 + A01) * B11 = S * B11 = P4

        ST0;

        add(A, A, S, aii[0][0], aii[0][1], p);

        mul(S, B, P[4], p, bii[1][1], p);

     

        // (A10 - A00) * (B00 + B01) = S * T = P5

        ST0;

        sub(A, A, S, aii[1][0], aii[0][0], p);

        add(B, B, T, bii[0][0], bii[0][1], p);

        mul(S, T, P[5], p, p, p);

     

        // (A01 - A11) * (B10 + B11) = S * T = P6

        ST0;

        sub(A, A, S, aii[0][1], aii[1][1], p);

        add(B, B, T, bii[1][0], bii[1][1], p);

        mul(S, T, P[6], p, p, p);

     

        // P0 + P3 - P4 + P6 = S - P4 + P6 = T + P6 = C00

        add(P[0], P[3], S, p, p, p);

        sub(S, P[4], T, p, p, p);

        add(T, P[6], C, p, p, cii[0][0]);

     

        // P2 + P4 = C01

        add(P[2], P[4], C, p, p, cii[0][1]);

     

        // P1 + P3 = C10

        add(P[1], P[3], C, p, p, cii[1][0]);

     

        // P0 + P2 - P1 + P5 = S - P1 + P5 = T + P5 = C11

        add(P[0], P[2], S, p, p, p);

        sub(S, P[1], T, p, p, p);

        add(T, P[5], C, p, p, cii[1][1]);

     

    }

    int main()

    {

        mat A, B, C;

        corners ai = { 0, N, 0, N };

        corners bi = { 0, N, 0, N };

        corners ci = { 0, N, 0, N };

        srand(time(0));

        // identity(A,bi); identity(B,bi);

        // set(A,ai,2); set(B,bi,2);

        randk(A, ai, 0, 2);

        randk(B, bi, 0, 2);

        print(A, ai, "A");

        print(B, bi, "B");

        set(C, ci, 0);

        // add(A,B,C, ai, bi, ci);

        mul(A, B, C, ai, bi, ci);

        print(C, ci, "C");

        return 0;

    }

Output:

$ g++ StrassenMulitplication.cpp
$ a.out
 
A = {
 1.2, 0.83, 0.39, 0.41, 
 1.8,  1.9, 0.49, 0.23, 
0.38, 0.72,  1.8,  1.9, 
0.13,  1.8, 0.48, 0.82, 
}
B = {
 1.2,  1.6,  1.4,  1.6, 
0.27, 0.63,  0.3, 0.79, 
0.58,  1.2,  1.1, 0.07, 
   2,  1.9, 0.47, 0.47, 
}
C = {
 2.7,  3.7,  2.6,  2.9, 
 3.4,    5,  3.7,  4.5, 
 5.3,  6.7,  3.6,  2.2, 
 2.5,  3.5,  1.6,  2.1, 
}
