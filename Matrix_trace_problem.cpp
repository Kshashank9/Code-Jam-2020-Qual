#include<iostream>
using namespace std;
void refresh(int b[],int N)
{
    for(int i=0;i<N+1;i++)
    {
        b[i]=0;
    }
}

bool check(int b[],int N)
{
	for(int i=0;i<N+1;i++)
	{
		if(b[i]>1)
			return true;
	}
	return false;
}

int func(int r[],int c[],int T)
{
    int N;
    cin>>N;
    int a[N][N],trace=0;
    int rows=0,col=0;
    int b[N+1];
    refresh(b,N);
    for(int i=0;i<N;i++)
    {
        for( int j=0;j<N;j++)
        {
            cin>>a[i][j];
            if(i==j)
            {
                trace+=a[i][j];
            }
        }
    }
    for(int j=0;j<N;j++)
    {
    	for( int i=0;i<N;i++)
    	{
        	b[a[i][j]] += 1;
    	}
    	bool t=check(b,N);
    	if(t==true)
    		col+=1;
    	refresh(b,N);
	}
	for(int i=0;i<N;i++)
    {
    	for(int j=0;j<N;j++)
    	{
        	b[a[i][j]] += 1;
    	}
    	bool t=check(b,N);
    	if(t==true)
    		rows+=1;
    	refresh(b,N);
	}
	r[T]=rows;
	c[T]=col;
	return trace;
}

int main()
{
     int T;
     int r[T],c[T],trace[T];
    cin>>T;
    for(int i=0;i<T;i++)
    {
       trace[i] = func(r,c,i);
    }
    for(int i=0;i<T;i++)
    {
    	cout<<"Case #"<<i+1<<": "<<trace[i]<<" "<<r[i]<<" "<<c[i]<<endl;
	}
}

