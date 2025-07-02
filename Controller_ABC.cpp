#include<stdlib.h>
#include<stdio.h>
#include<math.h>
 void main()
  {
 int i,j,k,n,ne,no,Nint[10][30],m,q;
 float R[20],R1[12][7],R2[12][7],Nfloat[7][20];
 float f[7][20],fi[7][20],sumfi[20],p[7][20],x1[7][20],x2[7][20];
 float x1max,x1min,x2max,x2min,s1,s2,min[7][20],min1[20],minf[20];
 float x1new[12][7][20],x2new[12][7][20],fnew[12][7][20],p1[7][20];
 float z[7][20],con1[7][20],con2[7][20],pc1,x3[7][20];
 float x3new[12][7][20],znew[12][7][20],con1new[12][7][20];
 float R3[12][7],R4[12][7],s3,s4,x3max,x3min,x4max,x4min,x4[7][20];
 float x4new[12][7][20];
 printf("\nEnter the No.of iterations:");
 scanf("%d",&n);
 printf("\nEnter Number of Employed Bees:");
 scanf("%d",&ne);
 printf("\nEnter Number of Onlookers Bees:");
 scanf("%d",&no);
 x1min=0.5; x2min=0;     
 x1max=5;   x2max=20;  
 s1=(x1max-x1min)/6; s2=(x2max-x2min)/6; 
 x1[1][0]=3;     x2[1][0]=5; 
 x1[2][0]=4;     x2[2][0]=2; 
 x1[3][0]=5;     x2[3][0]=1; 
 x1[4][0]=3;     x2[4][0]=6; 
 x1[5][0]=1;     x2[5][0]=5; 
 for(k=0;k<=n-1;k++)
 {
  minf[k]=999999;
 for(j=1;j<=ne;j++)
 {
  z[j][k]=abs(20-(20*x1[j][k]*(1-x2[j][k]*exp(-x2[j][k])-exp(-x2[j][k]))))+x2[j][k]; 
 f[j][k]=z[j][k];
//printf("\n Function value=%f",f[j][k]);
 }
for(j=1;j<=ne;j++)
 {
  fi[j][k]=1/f[j][k];    }
 for(j=1;j<=ne;j++)
 {
  fi[0][k]=0;
  fi[j][k]=fi[j][k]+fi[j-1][k];
 }
 sumfi[k]=fi[ne][k];
 for(j=1;j<=ne;j++)
 {
  p[j][k]=(sumfi[k]*f[j][k]);
  p1[j][k]=1/p[j][k];
 //printf("\n Probability=%f",p1[j][k]);
   }
for(j=1;j<=ne;j++)
 {
   Nfloat[j][k]=p1[j][k]*no;
   Nint[j][k]=Nfloat[j][k];
//printf("\nNumber of Onlookers bees assigned to source %d=%d",j,Nint[j][k]);
  }
for(j=1;j<=ne;j++)
 {
    for(i=1;i<=Nint[j][k];i++)
 {
 R1[i][j]=((float)(rand() % 100)/100);
 R2[i][j]=((float)(rand() % 100)/100);
 // printf("R1[%d]=%f  and  R2[%d]=%f",k,k,R1[k],R2[k]);
   x1new[i][j][k]=x1[j][k]+(s1*(R1[i][j]-0.5));
   x2new[i][j][k]=x2[j][k]+(s2*(R2[i][j]-0.5));
      if(x1new[i][j][k]>x1max) x1new[i][j][k]=x1max; else x1new[i][j][k]=x1new[i][j][k];
   if(x2new[i][j][k]>x2max) x2new[i][j][k]=x2max; else x2new[i][j][k]=x2new[i][j][k];
      if(x1new[i][j][k]<x1min) x1new[i][j][k]=x1min;  else x1new[i][j][k]=x1new[i][j][k];
   if(x2new[i][j][k]<x2min) x2new[i][j][k]=x2min;  else x2new[i][j][k]=x2new[i][j][k];
   znew[i][j][k]=abs(20-((20*x1new[i][j][k])*(1-x2new[i][j][k]*exp(-x2new[i][j][k])-exp(-x2new[i][j][k]))))+x2new[i][j][k]; 
    fnew[i][j][k]=znew[i][j][k];
    printf("\nX1new %d,X2new %d for bee %d=%f, %f",i,i,j,x1new[i][j][k],x2new[i][j][k]);
  printf("\nFnew %d for bee %d=%f",i,j,fnew[i][j][k]);
  }
    }
 for(j=1;j<=ne;j++)
 {
  min[j][k]=999999;
  for(i=1;i<=Nint[j][k];i++)
 {
 if(fnew[i][j][k]<min[j][k])
 {
 min[j][k]=fnew[i][j][k];
 m=i;
 }
  }
 if(min[j][k]<f[j][k])
 {
 x1[j][k+1]=x1new[m][j][k];
 x2[j][k+1]=x2new[m][j][k];
}
  else
 {
 x1[j][k+1]=x1[j][k];
 x2[j][k+1]=x2[j][k];
  }
  }
  min1[k]=999999;
  for(j=1;j<=ne;j++)
 {

  if(min[j][k]<min1[k])
  {
  min1[k]=min[j][k];
  q=j;
  }
   }/* previous j loop ends */
  min1[-1]=999999;
  if(min1[k]<min1[k-1]) min1[k]=min1[k];
  else min1[k]=min1[k-1];
  printf("\nMin.function value at the end of iteration %d=%f",k,min1[k]);
  printf("\nBest solution found at the end of iteration %d=%f,%f,",k,x1[q][k+1],x2[q][k+1]);
    }   /* k loop ends here */
     }
