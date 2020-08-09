
%{ 
  #include<bits/stdc++.h>
  #include<iostream>
  #include<cstring>
  #include "node.h"
  
  using namespace std;

  extern int yylex();

    void yyerror(char *); 
    int yylex(void); 
    stack<string>stk;
    map <string,string>typecheck;
  vector<char *>vars;
  map<string,string> values;
    int tc=1,lc=1,casef=0;
    string t;
    string begin1;
string getassignop(int a)
{ 
	string ss;
   switch(a)
  {
  case 1:{ss="=";break;}
  case 2:{ss="+=";break;}
  case 3:{ss="-=";break;}
  case 4:{ss="*=";break;}
  case 5:{ss="/=";break;}

  }
  return ss;
}

string gen(string s1,string s2)
{
	string temp="";
	temp.append(s1);
	temp.append(s2);
	temp.append("\n");
	return temp;
}

string gen(string s1,string s2,string s3,string s4,string s5)
{
	string temp="";
	temp.append(s1);
	temp+=s2;
	temp.append(s3);
	temp+=s4;
	temp.append(s5);
	temp+=";";
	temp+="\n";
	return temp;
}

string gen(string s1,string s2,string s3,string s4)
{
	string temp="";
	temp.append(s1);
	temp.append(s2);
	temp.append(s3);
	temp.append(s4);
	temp.append("\n");
	return temp;
}

int isdeclared(char *a, char *b)
{
	
	string sa,sb;
	sa="";sb="";
	sa.append(a);sb.append(b);
	
	if(typecheck.find(sa)==typecheck.end())
	{cout<<"the variable "<<a<<" is not declared "<< endl;exit(0);}
	if(typecheck.find(sb)==typecheck.end())
	{cout<<"the variable "<<b<<" is not declared "<< endl;exit(0);}
	string ta=typecheck[sa];
	string tb=typecheck[sb];
		if(ta=="bool" && tb=="bool")return 0;
		if(ta=="bool" || tb=="bool"){cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
		if(ta=="int"&&tb=="float")return 1;
		if(ta=="float"&&tb=="int")return 1;
		if(ta=="float"&&tb=="float")return 1;
		if(ta=="int" && tb=="int")return 2;
	
}

int iscompatible(char *a,char *b)
{
	string ta,tb;
	if(typecheck.find(a)==typecheck.end())
	{cout<<"the variable "<<a<<" is not declared "<< endl;exit(0);}
	if(typecheck.find(b)==typecheck.end())
	{cout<<"the variable "<<b<<" is not declared "<< endl;exit(0);}
	ta=typecheck[a];
	tb=typecheck[b];
	if(ta=="bool"&&(tb=="int"||tb=="float")){cout<<"incompatible type conversion"<<endl;exit(0);}
	if(tb=="bool"&&(ta=="int"||ta=="float")){cout<<"incompatible type conversion"<<endl;exit(0);}
}
 
%} 

%union{    
    DATA d;
}

%left '|'
%left '^'
%left '&' 
%left '>' '<'
%left '+' '-' 
%left '*' '/'
%right '@' '~'
%left NOT
%left OR
%left AND

%token <d> op
%token <d> VARIABLE INTEG WHILE FOR IF THEN ELSE  BOOL INT FLOAT AND OR NOT SWITCH CASE BREAK
%type <d> program statement expr newline decl type vals decls cases 


%%

program: 
       	decls  program statement '#' newline{
        									
        									   cout<<"end of the input"<<endl;
        									   cout<<$1.code<<endl;

        									   cout<<$3.code<<endl<<endl;
                     
                                }
        |  {}
        ;
type	:INT {		string code1="int";
					$$.code=new char[code1.length()];
                    strcpy($$.code,code1.c_str());
              }
		|FLOAT	{		string code1="float";
					$$.code=new char[code1.length()];
                    strcpy($$.code,code1.c_str());
              	}
		|BOOL	{		string code1="bool";
					$$.code=new char[code1.length()];
                    strcpy($$.code,code1.c_str());
              	}
		;

decls	: decls  decl '\n'{string code1="";
								code1.append($1.code);
								code1.append("\n");
								code1.append($2.code);
								code1.append("\n");
								$$.code=new char[code1.length()];
                       			strcpy($$.code,code1.c_str());
                       			}
		|	decl '\n' {string code1="";
					code1.append($1.code);
					$$.code=new char[code1.length()];
                    strcpy($$.code,code1.c_str());
                  }
		;
decl	: 
			type vals ';' {
								
								string code1="";string ty="";ty.append($1.code);
								code1.append($1.code);
								code1.append(" ");
								code1.append($2.code);
								code1.append("; ");

								//cout<<ty<<endl;
								
								$$.code=new char[code1.length()];
                        strcpy($$.code,code1.c_str());
                        map<string, string>::iterator it;
                        //for(it=typecheck.begin();it!=typecheck.end();it++)
                        //	cout<<it->first<<" "<<it->second<<endl;
                        for(int i=0;i<vars.size();i++)
                        { 
                        	string ss="";
                        	ss.append(vars[i]);
                        	if(typecheck.find(ss)==typecheck.end())
                        	typecheck[ss]=ty;
                        	else
                        		{cout<<ss<<" variable has been declared more than once"<<endl;exit(1);}
                        	
                        }
                        
                        
						vars.clear();		
						 }
		
			;
vals:	expr  {				
								if($1.flag==2)
								{cout<<"error in declaration!! :("<<endl;exit(0);}
								string code1="";
								vars.push_back($1.place);
								code1.append($1.place);
								
								$$.code=new char[code1.length()];
                        strcpy($$.code,code1.c_str());
          	}
		|expr ',' vals	{
								if($1.flag==2)
								{cout<<"error in declaration!! :("<<endl;exit(0);}
								string code1="";
								vars.push_back($1.place);
								
								code1.append($1.place);
								code1.append(", ");
								code1.append($3.code);
								$$.code=new char[code1.length()];
                        strcpy($$.code,code1.c_str());
							}
		;
newline: 
		  '\n'{}
		  | { }
		  ;
statement:   
		
		IF '(' expr ')' '{' newline statement '}' newline statement{
																
																string snext="l"+to_string(lc++);
																string code1="";
																code1.append($3.code);
																code1+=gen("if ",$3.place," = ","0 ");
																code1+=gen("goto ",snext);
																code1.append($7.code);
																code1.append("\n");
																code1+=gen(snext,":");
																code1.append($10.code);
																$$.code=new char[code1.length()];
			                                    				strcpy($$.code,code1.c_str());
			                                    				
															}
															
		| IF '(' expr ')'  '{' newline statement '}' newline ELSE '{' newline statement '}' newline statement {
																
																string s2next="l"+to_string(lc++);
																string snext="l"+to_string(lc++);
																string code1="";
																code1.append($3.code);
																code1+=gen("if ",$3.place," = ","0 ");
																code1+=gen("goto ",s2next);
																code1.append($7.code);
																code1.append("\n");
																code1+=gen("goto",snext);
																code1+=gen(s2next,":");
																//code1.append("\n");
																code1.append($13.code);
																code1.append("\n");
																code1+=gen(snext,":");
																code1.append($16.code);
																$$.code=new char[code1.length()];
                                    							strcpy($$.code,code1.c_str());
															}
			
		| FOR '(' statement ';' expr ';' statement ')' '{' newline statement '}' newline statement{
		  														
		  														string sbegin="l"+to_string(lc++);
																string safter="l"+to_string(lc++);
																string ebegin="l"+to_string(lc++);
																string code1="";
																code1+=gen(sbegin,":");
																code1.append($3.code);
																code1.append("\n");
																code1+=gen(ebegin,":");
																code1.append($5.code);
																code1+=gen("if ",$5.place," = ","0 ");
																code1+=gen("goto ",safter);
																code1.append($11.code);
																code1.append("\n");
																code1.append($7.code);
																code1.append("\n");
																code1+=gen("goto ",ebegin);
																code1+=gen(safter,":");
																code1.append($14.code);
																$$.code=new char[code1.length()];
                                    				strcpy($$.code,code1.c_str());

		  														}
		
		| WHILE '(' expr ')' '{' newline statement '}' newline statement   {
																

																
																string begin="l"+to_string(lc++);
																string after="l"+to_string(lc++);
																string code1="";
																code1+=gen(begin,":");
																code1.append($3.code);
																code1+=gen("if ",$3.place," = ","0 ");
																code1+=gen("goto ",after);
																code1.append($7.code);
																//code1.append(";");
																code1.append("\n");
																code1+=gen("goto ",begin);
																code1+=gen(after," :");
																code1.append($10.code);
																
																
																$$.code=new char[code1.length()];
                                    				strcpy($$.code,code1.c_str());
                                    							
														  }
		|SWITCH '(' expr ')' '{' '\n' cases '}' '\n' {
															
															//string place1="t"+to_string(tc++);
															string code1="";
															
															code1.append($3.code);
															code1.append("\n");
															map<string,string>::iterator it;
															for(it=values.begin();it!=values.end();it++){
																code1+=gen("\nif ",$3.place," = ",it->first);
																code1+=gen("goto ",it->second);
															}
															
															code1.append($7.code);
															code1.append("\n");
															code1.append(begin1);
															code1.append(": \n");
															$$.code=new char[code1.length()];
															strcpy($$.code,code1.c_str());


															}
         | expr op expr ';' newline statement    { 
         									
         							int x=iscompatible($1.place,$3.place);
                                       
                                    string code1="";
                                    code1.append($3.code);
                                    code1.append($1.place);
                                    code1.append(getassignop($2.val));
                                    code1.append($3.place);
                                    code1.append(";\n");
                                    code1.append($6.code);
                                    $$.code=new char[code1.length()];
                                    strcpy($$.code,code1.c_str());
                                    
                                    
                                  }
         | {
         	string code1="";
         	$$.code=new char[code1.length()];
          	strcpy($$.code,code1.c_str());
           }
        ;
/*casess		:casess '\n' cases '\n' {

									}
			|cases '\n'				{

									}
			;*/
cases 		:cases newline CASE expr ':' '{' newline statement BREAK ';' newline '}' '\n' {
													string code1="";
													code1.append($1.code);
													if(casef==0){
														begin1="l"+to_string(lc++);
														casef=1;

													}
													string begin="l"+to_string(lc++);
													code1+=gen(begin,":");
													code1.append($8.code);
													
													
													code1+=gen("goto ",begin1);
													code1.append("\n");
												    $$.code=new char[code1.length()];
                                    				strcpy($$.code,code1.c_str());
													values[$4.place]=begin;
													}  
			|	{string code1="";$$.code=new char[code1.length()];strcpy($$.code,code1.c_str());}
			;
expr: 
          expr '+' expr           {   	$$.flag=2; 
                                       string code1="";
													string place1="";
													int x=isdeclared($1.place,$3.place);
													$$.place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy($$.place,place1.c_str());
                                       $$.code=new char[code1.length()];
                                       code1.append($1.code);
                                       code1.append($3.code);
                                       code1+=gen($$.place," = ",$1.place," + ",$3.place);
                                       if(x==1)
                                       typecheck[$$.place]="float";
                                       else if(x==2)
                                       typecheck[$$.place]="int";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       $$.code=new char[code1.length()];
													strcpy($$.code,code1.c_str());
                                  }

         | expr '-' expr           {	$$.flag=2;
         										string code1="";
													string place1="";
													int x=isdeclared($1.place,$3.place);
													$$.place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy($$.place,place1.c_str());
                                       $$.code=new char[code1.length()];
                                       code1.append($1.code);
                                       code1.append($3.code);
                                       code1+=gen($$.place," = ",$1.place," - ",$3.place);
                                       if(x==1)
                                       typecheck[$$.place]="float";
                                       else if(x==2)
                                       typecheck[$$.place]="int";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       $$.code=new char[code1.length()];
													strcpy($$.code,code1.c_str());
                                      
                                   } 
         | expr '*' expr           { 	$$.flag=2; 
                                       string code1="";
													string place1="";
													int x=isdeclared($1.place,$3.place);
													$$.place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy($$.place,place1.c_str());
                                       $$.code=new char[code1.length()];
                                       code1.append($1.code);
                                       code1.append($3.code);
                                       code1+=gen($$.place," = ",$1.place," * ",$3.place);
                                       if(x==1)
                                       typecheck[$$.place]="float";
                                       else if(x==2)
                                       typecheck[$$.place]="int";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       $$.code=new char[code1.length()];
													strcpy($$.code,code1.c_str());
                                   } 
         | expr '/' expr           {	$$.flag=2;
                                       string code1="";
													string place1="";
													int x=isdeclared($1.place,$3.place);
													$$.place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy($$.place,place1.c_str());
                                       $$.code=new char[code1.length()];
                                       code1.append($1.code);
                                       code1.append($3.code);
                                       code1+=gen($$.place," = ",$1.place," / ",$3.place);
                                       if(x==1)
                                       typecheck[$$.place]="float";
                                       else if(x==2)
                                       typecheck[$$.place]="int";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       $$.code=new char[code1.length()];
													strcpy($$.code,code1.c_str());
                                   }  
         | expr '@' expr           {	$$.flag=2;
                                       string code1="";
													string place1="";
													int x=isdeclared($1.place,$3.place);
													
													$$.place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy($$.place,place1.c_str());
                                       $$.code=new char[code1.length()];
                                       code1.append($1.code);
                                       code1.append($3.code);
                                       code1+=gen($$.place," = ",$1.place," @ ",$3.place);
                                       if(x==1)
                                       typecheck[$$.place]="float";
                                       else if(x==2)
                                       typecheck[$$.place]="int";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       $$.code=new char[code1.length()];
													strcpy($$.code,code1.c_str());
                                   }  
         | expr '|' expr           {	$$.flag=2;
         										string code1="";
													string place1="";
													int x=isdeclared($1.place,$3.place);
													$$.place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy($$.place,place1.c_str());
                                       $$.code=new char[code1.length()];
                                       code1.append($1.code);
                                       code1.append($3.code);
                                       code1+=gen($$.place," = ",$1.place," | ",$3.place);
                                       if(x==1)
                                       typecheck[$$.place]="float";
                                       else if(x==2)
                                       typecheck[$$.place]="int";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       $$.code=new char[code1.length()];
													strcpy($$.code,code1.c_str());
                                      
                                   }  
        | expr '&' expr           {		$$.flag=2;
                                       string code1="";
													string place1="";
													int x=isdeclared($1.place,$3.place);
													$$.place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy($$.place,place1.c_str());
                                       code1.append($1.code);
                                       code1.append($3.code);
                                       code1+=gen($$.place," = ",$1.place," & ",$3.place);
                                       if(x==1)
                                       typecheck[$$.place]="float";
                                       else if(x==2)
                                       typecheck[$$.place]="int";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       $$.code=new char[code1.length()];
													strcpy($$.code,code1.c_str());
                                  }  

        | expr '^' expr           {		$$.flag=2;
                                       string code1="";
													string place1="";
													int x=isdeclared($1.place,$3.place);
													$$.place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy($$.place,place1.c_str());
                                       code1.append($1.code);
                                       code1.append($3.code);
                                       code1+=gen($$.place," = ",$1.place," ^ ",$3.place);
                                       if(x==1)
                                       typecheck[$$.place]="float";
                                       else if(x==2)
                                       typecheck[$$.place]="int";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       $$.code=new char[code1.length()];
													strcpy($$.code,code1.c_str());
                                  }  
        | expr '>' expr				 {		$$.flag=2;
        										   string code1="";
													string place1="";
													int x=isdeclared($1.place,$3.place);
													$$.place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy($$.place,place1.c_str());
													code1.append($1.code);
                                       code1.append($3.code);
                                       code1+=gen($$.place," = ",$1.place," > ",$3.place);
                                       if(x==1 && x==2)
                                       typecheck[$$.place]="bool";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       $$.code=new char[code1.length()];
                                       strcpy($$.code,code1.c_str());
        									 }
   	| expr '<' expr				 {		$$.flag=2;
        										   string code1="";
													string place1="";
													
													int x=isdeclared($1.place,$3.place);
													$$.place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy($$.place,place1.c_str());
													code1.append($1.code);
                                       code1.append($3.code);
                                       code1+=gen($$.place," = ",$1.place," < ",$3.place);
                                       if(x==1 && x==2)
                                       typecheck[$$.place]="bool";
                                       else if(x==0)
                                       {cout<<"boolean variable used in arithematic expression"<<endl;exit(0);}
                                       $$.code=new char[code1.length()];
                                       strcpy($$.code,code1.c_str());
        									 }
        | '~' expr                {		$$.flag=2;
        											string code1="";
													string place1="";
													
                                    	place1="t"+to_string(tc++);
                                    	strcpy($$.place,place1.c_str());
                                    	code1.append($$.place);
                                    	code1+=" = ~";
                                    	code1+=$2.place;
                                    	code1+="\n";
                                    	if(typecheck.find($2.place)!=typecheck.end())
                                    	typecheck[$$.place]=typecheck[$2.place];
                                    	else
                                    	{cout<<"Not declared !!"<<endl;exit(0);}
                                    	$$.code=new char[code1.length()];
                                    	strcpy($$.code,code1.c_str());
                                   }  
          | '(' expr  ')'          {	$$.flag=2;
													string code1="";
                                       $$.code=new char[code1.length()];
                                       strcpy($$.code,code1.c_str());
                                       $$.place=new char[strlen($2.place)];
                                    	strcpy($$.place,$2.place);
                                    	if(typecheck.find($2.place)!=typecheck.end())
                                    	typecheck[$$.place]=typecheck[$2.place];
                                    	else
                                    	{cout<<"Not declared !!"<<endl;exit(0);}
                                   }
        	| expr AND expr           {	$$.flag=2;
         										string code1="";
													string place1="";
													int x=isdeclared($1.place,$3.place);
													$$.place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy($$.place,place1.c_str());
                                       $$.code=new char[code1.length()];
                                       code1.append($1.code);
                                       code1.append($3.code);
                                       code1+=gen($$.place," = ",$1.place," AND ",$3.place);
                                       if(x==0 && x==1 && x==2)
													typecheck[$$.place]="bool";
                                       $$.code=new char[code1.length()];
													strcpy($$.code,code1.c_str());
                                      
                                   }  
         | expr OR expr           {	$$.flag=2;
         										string code1="";
													string place1="";
													int x=isdeclared($1.place,$3.place);
													$$.place=new char[place1.length()];
													place1="t"+to_string(tc++);
													strcpy($$.place,place1.c_str());
                                       $$.code=new char[code1.length()];
                                       code1.append($1.code);
                                       code1.append($3.code);
                                       code1+=gen($$.place," = ",$1.place," OR ",$3.place);
                                       if(x==0 && x==1 && x==2)
													typecheck[$$.place]="bool";
                                       $$.code=new char[code1.length()];
													strcpy($$.code,code1.c_str());
                                      
                                   } 
         | NOT expr                {		$$.flag=2;
        											string code1="";
													string place1="";
                                    	place1="t"+to_string(tc++);
                                    	strcpy($$.place,place1.c_str());
                                    	code1.append($$.place);
                                    	code1+=" = NOT";
                                    	code1+=$2.place;
                                    	code1+="\n";
                                    	$$.code=new char[code1.length()];
                                    	strcpy($$.code,code1.c_str());
                                   }   

         |VARIABLE              {	
         									$$.flag=1;
                                    string code1;
                                    string place1;
                                    code1.append("");
                                    place1.append($1.place);
                                    
                                    $$.code=new char[code1.length()];
                                    strcpy($$.code,code1.c_str());
                                    $$.place=new char[strlen($1.place)];
                                    strcpy($$.place,$1.place);
												
                                }
        |INTEG                 {		$$.flag=2;
                                    string code1;
                                    string place1;
                                    code1.append("");
                                    place1.append($1.place);
                                    $$.code=new char[code1.length()];
                                    strcpy($$.code,code1.c_str());
                                    $$.place=new char[place1.length()];
                                    strcpy($$.place,place1.c_str());
                               }
        
        ;


%% 



void yyerror(char *s) {
    cout<<"error"<<endl;fprintf(stderr, "%s\n", s);
} 
int main(void) { 
  cout<<"in main"<<endl;return yyparse(); 
} 													

