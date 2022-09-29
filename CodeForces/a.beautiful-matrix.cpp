// https://codeforces.com/contest/263/problem/A

#include <bits/stdc++.h>
 using namespace std;

int main() {
	int arr[5][5];
	int i ,j,count=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
cin >> arr[i][j];
		}
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(arr[i][j]!=0)
			goto go;
		}
 
	}
 
 go :
    while(i!=2||j !=2)
	{
		if(i>2)
		{
			i--;
			count++;
		}
		if(i<2)
		{
			i++;
			count++;
		}
		 if(j>2)
		{
			j--;
			count++;
		}
		if(j<2)
		{
			j++;
			count++;
		}
	}
cout << count;
	return 0;
}
 