#include <stdio.h>
#include <stdbool.h>
#define C 3
#define min(a, b) a>b?b:a
#define max(a, b) a>b?a:b
int main(){
   int k = 3, l = 3;
   int mat[][3] = {
      { 1, 2, 3 },
      { 4, 5, 6 },
      { 7, 8, 9 }
   };
   int row = 0, col = 0;
   bool flag = false;
   int i, j, len, diag;
   int MAX;
   int mn = min(k, l); //to check the minimum number and return that minimum number
   for ( len = 1; len <= mn; ++len) {
      for ( i = 0; i < len; ++i) {
         printf("%d ", mat[row][col]); //Printing the matrix in zigzag format
         if (i + 1 == len)
            break;
         if (flag)
            ++row, --col;
         else
            --row, ++col;
      }
      if (len == mn)
         break;
      if (flag)
         ++row, flag = false;
      else
          ++col, flag = true;
   }
   if (row == 0) {
      if (col == k - 1)
         ++row;
      else
         ++col;
         flag = 1;
   } else {
      if (row == l - 1)
         ++col;
      else
         ++row;
      flag = 0;
   }
   MAX = max(k, l) - 1; //To check the maximum element
   for ( len, diag = MAX; diag > 0; --diag) { //Loop to go diagonally.
      if (diag > mn)
         len = mn;
      else
         len = diag;
      for ( i = 0; i < len; ++i) {
         printf("%d ", mat[row][col]);
         if (i + 1 == len)
            break;
         if (flag)
            ++row, --col;
         else
            ++col, --row;
      }
      if (row == 0 || col == k - 1) {
         if (col == k - 1)
            ++row;
         else
            ++col;
         flag = true;
      }
      else if (col == 0 || row == l - 1) {
         if (row == l - 1)
            ++col;
         else
            ++row;
         flag = false;
      }
   }
   return 0;
}
