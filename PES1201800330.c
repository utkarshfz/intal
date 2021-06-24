#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"

#define MAX_SIZE 1001




static int atoint(char a)
{
  return a-48;
}

static char atos(int a)
{
  return a+48;
}

// static int max(int a,int b)
// {
//   return a>b?a:b;
// }

char* intal_add(const char* intal1, const char* intal2)
{
  int l1=strlen(intal1)-1;
  int l2=strlen(intal2)-1;

  int sum=0;
  int carry=0;
  char * res=(char *)malloc(sizeof(char)*MAX_SIZE);
  char * im1=(char *)malloc(sizeof(char)*MAX_SIZE);
  char * im2=(char *)malloc(sizeof(char)*MAX_SIZE);
  char * im3=(char *)malloc(sizeof(char)*MAX_SIZE);
  //char * im4=(char *)malloc(sizeof(char)*MAX_SIZE);
  strcpy(im1,intal1);
  strcpy(im2,intal2);

  if(l1!=l2)
  {
    int index=0;
    if(l1<l2)
    {
      for(int i=0;i<l2-l1;i++)
      im3[index++]='0';
      for(int i=0;i<=l1;i++)
      im3[index++]=im1[i];
      im3[index]='\0';
      strcpy(im1,im3);
    }
    else
    {
      for(int i=0;i<l1-l2;i++)
      im3[index++]='0';
      for(int i=0;i<=l2;i++)
      im3[index++]=im2[i];
      im3[index]='\0';
      strcpy(im2,im3);
    }
  }

  l1=strlen(im1)-1;
  l2=strlen(im2)-1;

  //printf("%d %d\n",l1,l2);

  for(int i=l1;i>=0;i--)
  {
    sum=atoint(im1[i])+atoint(im2[i])+carry;
    carry=sum/10;
    sum=sum%10;
    im3[i]=atos(sum);
  }

  /*for(int i=0;i<=l1;i++)
  printf("%c",im3[i]);
  printf("\n");*/


  int index=0;
  if(carry!=0)
  res[index++]=atos(carry);

  for(int i=0;i<=l1;i++)
  res[index++]=im3[i];

  res[index]='\0';

  // for(int i=0;i<=l1;i++)
  // printf("%c",im1[i]);
  // printf("\n");
  //
  // for(int i=0;i<=l1;i++)
  // printf("%c",im2[i]);
  // printf("\n");
  //
  // for(int i=0;i<=strlen(res);i++)
  // printf("%c",res[i]);
  // printf("\n");

  free(im1);
  free(im2);
  free(im3);


  return res;
}

int intal_compare(const char* intal1, const char* intal2)
{
  if(strlen(intal1)==strlen(intal2))
  {
    int res=strcmp(intal1,intal2);
    if(res==0)
    return res;

    if(res>0)
    return 1;
    else
    return -1;
  }

  if(strlen(intal1)>strlen(intal2))
  return 1;
  else
  return -1;

}

char* intal_diff(const char* intal1, const char* intal2)//analyse_further!
{
  char * res=(char *)malloc(sizeof(char)*MAX_SIZE);
  char * i1=(char *)malloc(sizeof(char)*MAX_SIZE);
  char * i2=(char *)malloc(sizeof(char)*MAX_SIZE);

  if(intal_compare(intal1,intal2)==0)
  {
    strcpy(res,"0");
    free(i1);
    free(i2);
    return res;
  }

  if(intal_compare(intal1,intal2)>0)
  {
    strcpy(i1,intal1);
    strcpy(i2,intal2);
  }
  else
  {
    strcpy(i1,intal2);
    strcpy(i2,intal1);
  }

  int l1=strlen(i1)-1;
  int l2=strlen(i2)-1;
  /*for(int i=0;i<l1+1;i++)
  printf("%d",atoint(i1[i]));
  printf("\n");

  for(int i=0;i<l2+1;i++)
  printf("%d",atoint(i2[i]));
  printf("\n");*/

  while(l2>=0)
  {
    if(i1[l1]>=i2[l2])
    {
      i1[l1]=atos(atoint(i1[l1])-atoint(i2[l2]));
      //printf("%c\n",i1[l1]);
      l1--;
      l2--;
    }
    else
    {

      int j=l1-1;
      while(i1[j]=='0')
      {
        i1[j]='9';
        j--;
      }
      i1[j]=atos(atoint(i1[j])-1);
      //printf("%c\n",i1[l1]);
      i1[l1]=atos(atoint(i1[l1])+10-atoint(i2[l2]));
      //printf("%c\n",i1[l1]);
      l1--;
      l2--;
    }
  }

  int k=0;
  while(i1[k]=='0') k++;

  int index=0;
  l1=strlen(i1);

  while(k<l1)
  {
    res[index++]=i1[k++];
  }
  res[index]='\0';

  free(i1);
  free(i2);
  return res;


}

char* intal_multiply(const char* intal1, const char* intal2)
{
  char * res=(char *)malloc(sizeof(char)*MAX_SIZE);
  char * im1=(char *)malloc(sizeof(char)*MAX_SIZE);
  char * im2=(char *)malloc(sizeof(char)*MAX_SIZE);
  char * im3=(char *)malloc(sizeof(char)*MAX_SIZE);
  int l1=strlen(intal1)-1;
  int l2=strlen(intal2)-1;



  for(int i=l2;i>=0;i--)
  {
    int carry=0;
    int prod=0;
    int j;
    for(j=l1;j>=0;j--)
    {
      prod=atoint(intal1[j])*atoint(intal2[i])+carry;
      carry=prod/10;
      prod=prod%10;
      im1[j]=atos(prod);
      //printf("%c\n",im1[j]);
    }
    //printf("%d\n",carry);
    int index=0;
    if(carry!=0)
    im3[index++]=atos(carry);

    for(int k=0;k<=l1;k++)
    im3[index++]=im1[k];

    for(int k=0;k<l2-i;k++)
    im3[index++]='0';

    im3[index]='\0';

    // for(int k=0;k<index;k++)
    // printf("%c",im3[k]);
    // printf("\n");

    if(i==l2)
    strcpy(im2,im3);
    else
    {
      strcpy(im2,intal_add(im2,im3));
      /*for(int k=0;k<strlen(im2);k++)
      printf("%c",im2[k]);
      printf("\n");*/
    }

  }


  strcpy(res,im2);
  free(im1);
  free(im2);
  free(im3);
  return res;


}


static char * spl_div(const char * intal1)
{
  int carry=0;

  char * res=(char *)malloc(sizeof(char)*MAX_SIZE);
  char * i1=(char *)malloc(sizeof(char)*MAX_SIZE);

  for(int i=0;i<strlen(intal1);i++)
  {
    int temp=(atoint(intal1[i])+10*carry)/2;
    carry=(atoint(intal1[i])+10*carry)%2;
    i1[i]=atos(temp);
  }
  i1[strlen(intal1)]='\0';
  //printf("%s\n",i1);

  int index=0;
  int i=0;
  while(i1[i]=='0')
  i++;

  while(i!=strlen(intal1))
  res[index++]=i1[i++];
  res[index]='\0';

  free(i1);
  return res;

}
char* intal_mod(const char* intal1, const char* intal2)
{

  if(intal_compare(intal1,intal2)<0)
  {
    char * res=(char *)malloc(sizeof(char)*MAX_SIZE);
    strcpy(res,intal1);
    return res;
  }
  char * lo=(char *)malloc(sizeof(char)*MAX_SIZE);
  char * hi=(char *)malloc(sizeof(char)*MAX_SIZE);
  char * mid=(char *)malloc(sizeof(char)*MAX_SIZE);
  char * i1=(char *)malloc(sizeof(char)*MAX_SIZE);
  char * r=(char *)malloc(sizeof(char)*MAX_SIZE);
  char * def=(char *)malloc(sizeof(char)*MAX_SIZE);
  strcpy(def,intal1);
  lo[0]='0';
  lo[1]='\0';
  strcpy(hi,intal1);
  while(intal_compare(lo,hi)<=0)
  {

    strcpy(mid,spl_div(intal_add(hi,lo)));

    strcpy(i1,intal_multiply(intal2,mid));

    strcpy(r,intal_diff(intal1,i1));
  //  printf("%s %s %s\n",mid,i1,r);

    if(intal_compare(intal1,i1)>=0 && (intal_compare(r,"0")>=0 && intal_compare(r,intal2)<0))
    {
      free(lo);
      free(hi);
      free(mid);
      free(i1);
      free(def);

      return r;
    }

    if(intal_compare(intal1,i1)>0)
    {
      strcpy(lo,intal_add(mid,"1"));
    }
    else
    {
      strcpy(hi,intal_diff(mid,"1"));
    }





  }
  free(lo);
  free(hi);
  free(mid);
  free(i1);
  free(r);

  return def;



}

char* intal_pow(const char* intal1, unsigned int n)
{
  //printf("%d\n",n);
  char * res=(char *)malloc(sizeof(char)*MAX_SIZE);
  if(n==0)
  {
    res[0]=1;
    res[1]='\0';
    return res;
  }

  if(n==1)
  {
    strcpy(res,intal1);
    // printf("%s ^ %d = %s\n",intal1,n,res);
    return res;
  }

  if(n==2)
  {
    strcpy(res,intal_multiply(intal1,intal1));
    // printf("%s * %s = %s\n",intal1,intal1,res);
    return res;
  }

  if(n%2==0)
  {
    //printf("%s * %s\n",intal_pow(intal1,n/2),intal_pow(intal1,n/2));
    strcpy(res,intal_pow(intal_pow(intal1,n/2),2));
  }
  else
  {
    //printf("%s * %s\n",intal_pow(intal1,(n-1)/2),intal_pow(intal1,(n+1)/2));
    strcpy(res,intal_multiply(intal1,intal_pow(intal_pow(intal1,(n-1)/2),2)));
  }
  // printf("%s  ^ %d = %s\n",intal1,n,res);
  return res;
}

char* intal_gcd(const char* intal1, const char* intal2)
{
  char * res=(char *)malloc(sizeof(char)*MAX_SIZE);

  //printf("%s %s\n",intal1,intal2);
  if(intal_compare(intal2,"0")==0)
  {
    strcpy(res,intal1);
    return res;
  }


  strcpy(res,intal_gcd(intal2,intal_mod(intal1,intal2)));


  return res;
}

char* intal_fibonacci(unsigned int n)
{
  char * dp[n+1];
  dp[0]="0";
  dp[1]="1";

  for(int i=2;i<=n;i++)
  dp[i]=intal_add(dp[i-1],dp[i-2]);

  return dp[n];
}

char* intal_factorial(unsigned int n)
{
  char * dp[n+1];
  dp[0]="1";
  char * str=(char *)malloc(sizeof(char)*MAX_SIZE);
  for(int i=1;i<=n;i++)
  {
    sprintf(str, "%d", i);
    dp[i]=intal_multiply(dp[i-1],str);
  }
  free(str);
  return dp[n];
}

// static int min(int a,int b)
// {
//   return a<b?a:b;
// }

char* intal_bincoeff(unsigned int n, unsigned int k)
{
  if(n-k<k)
  k=n-k;
  
    char** dp=malloc(sizeof(char* ) * (k+1));
for(int i=0;i<=k;++i)
    	dp[i]="0";
dp[0]=malloc(sizeof(char)*2);
dp[0][0]=49;
dp[0][1]='\0';
for(int i=1;i<=n;++i)
    {
	int range=i>k?k:i;
    for(int j=range;j>0;--j)
    {
	dp[j]=intal_add(dp[j],dp[j-1]);
    }
	}
char *rult=malloc(sizeof(char)*strlen(dp[k]));
strcpy(rult,dp[k]);
for(int i=0;i<k+1;i++){
free(dp[i]);}
free(dp);
return rult;
}

int intal_max(char **arr, int n)
{
  int maxi=0;
  for(int i=0;i<n;i++)
  {
    if(intal_compare(arr[i],arr[maxi])>0)
    maxi=i;
  }

  return maxi;
}

int intal_min(char **arr, int n)
{


  int mini=0;
  for(int i=0;i<n;i++)
  {
    if(intal_compare(arr[i],arr[mini])<0)
    mini=i;
  }

  return mini;
}

int intal_search(char **arr, int n, const char* key)
{
  for(int i=0;i<n;i++)
  if(intal_compare(arr[i],key)==0)
    return i;

  return -1;
}

int intal_binsearch(char **arr, int n, const char* key)
{
  int start=0;
  int end=n-1;

  while(start<=end)
  {
    int mid=start+(end-start)/2;
    if(intal_compare(arr[mid],key)==0)
      return mid;

    if(intal_compare(arr[mid],key)>0)
      end=mid-1;
    else
      start=mid+1;

  }

  return -1;
}

static int partition(char ** arr,int start,int end)
{
  char * pivot = arr[end];

    int i = (start - 1);
    for (int j = start; j <= end- 1; j++)
    {
        if (intal_compare(arr[j], pivot)<0)
        {
            i++;
            char * temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    char * temp=arr[i+1];
    arr[i+1]=arr[end];
    arr[end]=temp;
    return (i + 1);

}


static void quick_sort(char ** arr,int start,int end)
{
  if(start<=end)
  {
    int pi=partition(arr,start,end);
    quick_sort(arr,start,pi-1);
    quick_sort(arr,pi+1,end);
  }
}


void intal_sort(char **arr, int n)
{
  quick_sort(arr,0,n-1);
}


static char * spl_max(char * a,char * b)
{
  /*printf("%s\n",a);
  printf("%s\n",b);
  printf("%d\n",intal_compare(a,b)>0);*/
  return (intal_compare(a,b)>0)?a:b;
}
char* coin_row_problem(char **arr, int n)
{

  char * dp[3];

  dp[0]=arr[0];
  dp[1]=arr[1];

  for(int i=2;i<n;i++)
  {
    dp[2]=spl_max(intal_add(arr[i],dp[0]),dp[1]);
    dp[0]=dp[1];
    dp[1]=dp[2];
    //printf("%s\n",dp[i]);
  }


  return dp[2];


}
