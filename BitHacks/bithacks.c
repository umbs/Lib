#include <stdio.h> 

#define INT_SIZE    sizeof(int) * 8  
#define MSB_SET     (1 << (INT_SIZE-1))

/* compute sign of v 
 * -1 if negative 
 *  0 if non-negative */ 
int sign(int v)
{
        return -(v < 0);

        /* return ((v>0) - (v<0)) 
         * return (v >> (sizeof(int) * 8 - 1)) 
         * */
}

/* detect if 2 ints have opp signs */
int opp(int x, int y) 
{
        return (x^y) & (1 << (INT_SIZE-1));

        /* return ((x^y) < 0); */
}

/* compute absolute value of 'x' without branching 
 * TODO: Not working */
int absolute(int x)
{
        return ((x ^ -1)+1); 
}

/* return min of x, y */
int min(int x, int y)
{
        return (x & -(x<y)) + (y & -(y<x));  
}

/* return max of x, y */
int max(int x, int y)
{
        return (y & -(x<y)) + (x & -(y<x));  
}

/* Is 'v' power of 2? */
int pow2(int x) 
{
        return x && !(x & (x-1))
}

main() 
{
        /* compute sign of an int */
        int v = 2, w = -3; 
        printf("%d\n", max(v, w)); 
}
