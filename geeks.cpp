#include <iostream>
#include<stack>
#include<vector>
#include<cmath>
#include <string.h>
using namespace std;

int getPrecedence(char c)
{
	if(c=='+'||c=='-')
	{
		return 1;
	}
	else if(c=='*' || c=='/')
	{
		return 2;
	}
	else if(c=='^')
	{
		return 3;
	}
	
	return -1;
}

int applyOperator(char oprtr,int op1,int op2)
{
	switch(oprtr)
	{
		case '+':
			return op1+op2;
		case '-':
			return op2-op1;
		case '*':
			return op1*op2;
		case '/':
			return op2/op1;
		case '^':
			return pow(op2,op1);
	}
}

//check if char is an operator or not
bool isOperator(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
	{
		return true;
	}
	return false;
}
int charToInt(char a)
{
	switch(a)
	{
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case '0':
			return 0;
		
	}
		
}
int convertToInt(char str[])
{
	int num=0;
	int l=strlen(str);
	for(int i=0;i<l;i++)
	{
		num=num*10+charToInt(str[i]);
	}
	return num;
	
}



int evaluateInfix(vector<char *> toks,stack<int>* vs,stack<char>* os)
{
	for(auto i: toks)
	{
		if(i[0]>='0' && i[0]<='9')
		{
			vs->push(convertToInt(i));
		}
		else if(isOperator(i[0]))
		{
			while(!os->empty() && getPrecedence(i[0])<=getPrecedence(os->top()))
			{
				// cout<<"In while & top :"<<os->top()<<endl;
				int op1=vs->top();
				vs->pop();
				int op2=vs->top();
				vs->pop();
				int res=applyOperator(os->top(),op1,op2);
				// cout<<"op1: "<<op1<<" op2: "<<op2<<" res: "<<res<<endl;
				vs->push(res);
				os->pop();
			}
			// cout<<"Pushing "<<i[0]<<endl;
			os->push(i[0]);
		}
		
		else if(i[0]=='(')
		{
			// cout<<"Pused ( to OS"<<endl;
			os->push(i[0]);
		}
		
		else if(i[0]==')')
		{
			while(os->top()!='(')
			{
				int op1=vs->top();
				vs->pop();
				int op2=vs->top();
				vs->pop();
				char oprtr=os->top();
				os->pop();
				vs->push(applyOperator(oprtr,op1,op2));
			}
			
			os->pop();
		}
	}
	
	return 0;
}

int main() 
{
	stack<int> vs;//vs stands for value stack
	stack<char> os;//os stands for Operation stack
	vector<char *> toks;
	
	char ip[1000];

	char * pch;
	cin.getline(ip,sizeof(ip));	

	  pch = strtok (ip," ,.-");
	  while (pch != NULL)
	  {
	    toks.push_back(pch);
	    pch = strtok (NULL, " ");
	  }
	  
	  evaluateInfix(toks,&vs,&os);
	  
	 
	  while(!os.empty())
	  {
	  	int op1=vs.top();
		vs.pop();
		int op2=vs.top();
		vs.pop();
		char oprtr=os.top();
		os.pop();
		vs.push(applyOperator(oprtr,op1,op2));	
	  }
	  
	  cout<<"Value of Infix Expression: ";
	  
	  while(!vs.empty())
	  {
	  	cout<<vs.top()<<endl;
	  	vs.pop();
	  }
	 
	
	return 0;
}