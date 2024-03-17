#include<iostream>
#include<cstring>
using namespace std;
int size,a[20],mid;
struct d3{
	int low,high,mid;
	d3(){}
	d3(int a,int b,int c)
	{
		low=a,high=b,mid=c;
	}
};
	void newd(d3 da,int a,int b,int c)
	{
		da.low=a;da.high=b;da.mid=c;
	}
d3 crossing(d3 da)
{
	int leftsum=-1000000,rightsum=-1000000,sum=0,maxleft,maxright;
	for(int i=da.high;i>da.low;i--)
	{
		sum=sum+a[i];
		if(sum>leftsum)
		{
			leftsum=sum;
			maxleft=i;
		}
	}
	sum=0;
	for(int i=da.high+1;i<da.mid;i++)
	{
		sum=sum+a[i];
		if(sum>rightsum)
		{
			rightsum=sum;
			maxright=i;
		}
	}
	d3 d(maxleft,leftsum+rightsum,maxright);
	return d;
}
d3 maxsub(d3 da)
{
	if(da.high==da.low)
	{
		mid=a[da.low];
		d3 dr(dr.high,dr.low,mid);
		return dr;
	}
	else
	{
		mid=(da.low+da.high)/2;
		d3 left,right,cross;
		d3 ds(da.low,mid,0);
		left=maxsub(ds);newd(ds,mid+1,da.high,0);
		right=maxsub(ds);newd(ds,da.low,mid,da.high);
		cross=crossing(ds);
		if(left.mid>=right.mid&&left.mid>=cross.mid)
		return left;
		else if(right.mid>=left.mid&&right.mid>=cross.mid)
		return right;
		else cross;	
	}
}

int main()
{
	cout<<"hai\n";
	memset(a,0,sizeof(a));
	int len;
	cout<<"length\n";
	cin>>len;
	for(int i=0;i<len;i++)
	cin>>a[i];
	d3 da(0,len-1,0),dr;
	dr=maxsub(da);
	cout<<"\n"<<dr.low<<" "<<dr.high<<" "<<dr.mid;
}
