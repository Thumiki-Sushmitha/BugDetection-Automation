# BugDetection-Automation
 Enhancing Nopol Bug detection Program with an appropriate test-suite

Nopol(Spanish Word): “no moth anymore”
NOPOL was the tool used to automatically patch the bugs in the conditional statements.

The tool was enhanced by providing number of test cases as the cyclomatic complexity obtained from building the cyclomatic-graph of 3-AddressCode Generator.

Steps Involved in Enhancing:
1. Use lex, yaac code for 3-Address code generator.
2. Building Cyclomatic graph from step1.
3. Calculate Cyclomatic complexity of graph in Step2.

4. Integrating Code with TRGeneration (Test Requirement Code Generation) to generate test cases.
<a href="https://github.com/evplatt/TRGeneration">

5. Passing the test-suite of Step-4 as an input to Nopol.
<a href="https://github.com/SpoonLabs/nopol">

This allows the bug patch to be more accurate than the random test-suite. You can try to improvise the code further.

Example:

Sample Input 1:

int a,b,c,d,e,r;

a=2;

while(a<b){

a=b+d*e*r;

}

c=d*e+a*b;

#


Sample Output 1:

end of the input

int a, b, c, d, e, r;

a=2;

l1:

t1 = a < b;

if t1 = 0

goto l2

t2 = d * e;

t3 = t2 * r;

t4 = b + t3;

a=t4;

goto l1

l2 :

t5 = d * e;

t6 = a * b;

t7 = t5 + t6;

c=t7;


Sample Input 2:

int a,b,c,d,e,r;

float p,q;

switch(a+b){

case 1:{

while(a<b){

if(a<b){

c=d*e+a*b;

}

else{

a=b;

for(r=b;;r<c;r=r+e;){

a=b+c;

}

}

a=b+d*e*p;

}

break;

}

case 2:{b=b+a;break;}

}

#


Sample Output 2:

end of the input

int a, b, c, d, e, r;

float p, q;


t1 = a + b;

if t1 = 1

goto l9

if t1 = 2

goto l10

l9:

l6:

t2 = a < b;

if t2 = 0

goto l7

t3 = a < b;

if t3 = 0

goto l4

t4 = d * e;

t5 = a * b;

t6 = t4 + t5;

c=t6;

gotol5

l4:

a=b;

l1:

r=b;

l3:

t7 = r < c;

if t7 = 0

goto l2

t9 = b + c;

a=t9;

t8 = r + e;

r=t8;

goto l3

l2:

l5:

t10 = d * e;

t11 = t10 * p;

t12 = b + t11;

a=t12;

goto l6

l7 :

goto l8

l10:

t13 = b + a;

b=t13;

goto l8

l8:
