#include <stdio.h>
int main()
{
int r=2,c=3;
int mat1[3][3], mat[3][3], sum[3][3];
int i,j;
printf("Enter first matrix elements:\n");
for (i=0; i<r; i++){
for (j=0; j<c; j++){
scanf ("%d",&mat1[i][j]);
}
}
printf("Enter second matrix element:\n");
for (i=0; i<r; i++){
for (j=0; j<c; j++){
scanf ("%d",&mat[i][j]);
}
}
for (i=0; i<r; i++){
for (j=0; j<c; j++){
sum[i][j]= mat1[i][j] + mat[i][j];
}
}
printf("Addition of two matrices is:\n");
for (i=0; i<r; i++){
for (j=0; j<c; j++){
printf("%d",sum[i][j]);
}
printf("\n");
}
return 0;
}
