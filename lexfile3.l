%{ 
    #include<bits/stdc++.h>
    #include <stdlib.h> 
    void yyerror(char *); 
    #include "node.h"
    #include "y.tab.h" 
    char s[]="invalid character";
    using namespace std;
    extern map<char,int >mp;
    int inputfunc(){
    	yyin=fopen("code.txt","r");
    }
%} 

%% 

int			{ cout<<"here"; return INT;}
float			{return FLOAT;}
bool			{return BOOL;}
and			{return AND;}
or				{return OR;}
not			{return NOT;}

break       {return BREAK;}

if          {
					yylval.d.place=yytext;
					return IF;
				}
else        {
					yylval.d.place=yytext;
					return ELSE;
				}
then        {
					yylval.d.place=yytext;
					return THEN;
				}
while       {
					yylval.d.place=yytext;
					return WHILE;
				}
case        {
                    yylval.d.place=yytext;
                    return CASE;       
                }
switch      {
                yylval.d.place=yytext;
                return SWITCH;
            }
for			{
					yylval.d.place=yytext;
					return FOR;
				}
[a-z]       { 
                yylval.d.place = yytext;  
                return VARIABLE; 
            }
[0-9]+      { 
                yylval.d.place = yytext; 
                return INTEG; 
            }
 "+=" 		{yylval.d.val=2;return op;}
 "-=" 		{yylval.d.val=3;return op;}
 "*=" 		{yylval.d.val=4;return op;}
 "/=" 		{yylval.d.val=5;return op;}
 "="    		{yylval.d.val=1;return op;}
[-+*/&|~^<>@{};]  {     
              yylval.d.place=yytext;
              return *yytext;   
        		}

[()\n#,:] 		{ return *yytext;} 
 

 [ \t]      {;} 
 


.          {cout<<"came to error"<<endl; yyerror(s); } 
%% 

int yywrap(void) { 
    return 1; 
} 
