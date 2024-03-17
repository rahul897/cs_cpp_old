#include<iostream>
#inlcude("stack.cpp")
using namespace std;
int main()
{
	stack s(20);char c[20],x,y,a[]={'[','{','(',')','}',']'};int l;
	cout<<"enter equation\n";cin>>c;
	for(l=0;c[l]!='\0';l++);
	for(int i=0;i<l;i++)
	{for(int j=0;j<6;j++)
	if(c[i]==a[j])
	{s.push(a[j]);
	if(j>2){
	x=s.pop();
	if(s.isempty())s.push(x);
	else  
	{y=s.pop();if(y==a[5-j]);else s.push(y);}}
    }}
	if(s.isempty())cout<<"balanced eqn.\n";
	else cout<<"unbalanced eqn.\n";	
}
