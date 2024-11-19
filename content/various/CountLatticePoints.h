/**
 * Author: Daniel Zhang
 * Description: Counts number of integer pairs (x, y) with x > 0, y > 0, ax + by <= c, assuming answer is finite.
 */

int lattice(int a,int b,int c){
  return (c<a+b)?0:lattice(b,a%b,c-a/b*c/a*b)+(a/b*c/a)*(c/a)-(c/a)*(c/a+1)/2*(a/b);
}
