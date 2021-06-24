                                                        REPORT
                                                      PES1201800330
Introduction

Intal is a library for integers of arbritray length which is implemented by storing digits as array of characters.Usually data types such as int and other data types inbuilt in C have a upper limit for the value they can hold.This may impose restrictions on implementations as the programmer has to be carefull enough about integer overflow.The intal library can lift off the programmers burden as intal can accomadate an extermely high integer value.
The intal library can hold an incredible value upto 10^1000 where as the standard int data type present in c usully has an upper limit of 2^64 or 2^32.
Intal can be successfully applied to scientific calulations involving data with a extremely high values.It can have applications to fields like rocket launching,research about space and planetary bodies,etc.


Implementation

1.intal_add
The intal_add function takes two char array as input.If the arrays are of same length each element is added starting from the least siginificant digit and if at the end a carry is left its appendeded as the most siginificant digit.If the two arrays are not of the same length the smaller one is made of the same length as the larger one by appending 0’s to the most significant position and the same process is follows as above.

2.intal_compare
If the two intals happen to be of same length then then we do a strcmp on that and return 0 if
equal,1 if greater and -1 if lesser.Else we return 1 if intal1 is greater else -1.

3.intal_diff
The intal_add function takes two char array as input.The elements are subtracted one by one starting from the least significant digit.If the first elemet happpens to be smaller than the second a borrow is taken from the subsequent elements.However if the subsequent elements happen to be 0’s
the we traverse till the first non zero element take the borrow from it and make all intermediate 0’s as 9.At the end we remove all trailing zeros.If the two strings happen to be equal be just return 0.

4.intal_multiply
The intal_multiply  function takes two char array as input.It processes intal1 from the least siginificant digit and multiplies each element by the an element(controlled by for loop) of intal2.
And then shifts the product and performs addition to the previous result.

5.intal_mod
The intal_mod  function takes two char array as input.It applies a divide and conquer approach here(Some thing like binary search).We take 0 to be start and intal1 to be end.This is because the quotient can never exceed intal1.Now we calculate the mid this is multiplied to intal2.
If this product-intal1>=0 and the remainder falls between 0 and intal2-1 we return the remainder.
IF product-intal1>=0 and remainder isnt in the specified range then we do start=mid+1.Else
we do end=mid-1.

6.intal_pow
If the exponent is even we implement (a^n/2)^2 as intal_pow(intal_pow(a,n/2),2)
If the exponent is odd we implement a*(a^(n-1)/2)^2 as intal_multiply(a,intal_pow(intal_pow(a,(n-1)/2),2)).
As base cases we return
1 if n =0
intal_multiply(a,a) if n=2

7.intal_gcd
The approach we are using here is, to follow standard euclidean algorithm
gcd(a,b)=gcd(b,a%b) with the base case if b==0 return 0.


8.intal_fibonacci
We use dynamic programming here and do
dp[0]=”0”
dp[1]=”1”
dp[i]=intal_add(dp[i-1],dp[i-2])
finally we return dp[n]

9.intal_factorial
The approach we are using here is, recursively where unitll n becomes 1 it keeps on calling funtions and calculation of n*(n-1)*...1 is done

10.intal_bincoeff

The approach we are using here is, dyamic approach where we create a array of size of product of 2 coeeficient of binomial so that we can store all corresponding values and later return required value

11.intal_max

We keep iterating over the array and keep comparing the elements using intal_compare.The max_element is updated as and when required and finlly returned.

12.intal_min

We keep iterating over the array and keep comparing the elements using intal_compare.The min_element is updated as and when required and finlly returned.


13.intal_search
The approach we are using here is, O(n) where the key is compared with every large array if the key is found that index is returned else -1 is returned.

14.intal_binsearch
The approach we are using here is, O(logn) where array is sorted and we find key in 2 halfs of arrays recursively...if found index is returned else -1 is returned.

15.void intal_sort
The approach we are using here is, using quick sort we take the last elemet put it at its appropriate position and then call intal_sort again on the two halves.



16.coin_row_problem

We use dynamic programming here and use a array dp of size 3.
We intitialize dp as follows:-
dp[0]=array[0]
dp[1]=array[1]

now we iterate over the array and  do:-
dp[2]=max(array[i]+dp[0],dp[1])
shift dp right so as to create room for dp[2]

finally return dp[2]


FUTURE WORK:

1)Some more functions which could have been added is sorting in decreasing order,approximate division,approximate square root etc
2)If no restrictions are there just these things in the library and they can be used as basic operations of math are done on integers but this on large numbers
