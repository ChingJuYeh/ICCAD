#include <iostream>
using namespace std;

bool same(int arr[],int A3=5,int A2=5,int A1=5,int A0=5,int N1=5,int N2=5,int N3=5,int y=5){
	int n1=!(arr[0] && arr[1]);
	int n2=!arr[2];
	int n3=!(n2 || arr[3]);
	int Y=!(n1 && n3);
	//
	if(A3==0||A3==1)
	{
		N1=!(A3&&arr[1]);
		y=!(N1&&n3);
		if(y==Y) return true;
	}
	else if(A2==0 ||A2==1)
	{
		N1=!(A2&&arr[0]);
		y=!(N1&&n3);
		if(y==Y) return true;
	}
	else if(A1==0 ||A1==1)
	{
		N3=!(!A1||arr[3]);
		y=!(n1&&N3);
		if(y==Y) return true;
	}
	else if(A0==0 ||A0==1)
	{
		N3=!(n2||A0);
		y=!(n1&&N3);
		if(y==Y) return true;
	}
	else if(N1==0 ||N1==1){
		y=!(N1&&n3);
		if(y==Y) return true;
	}	
	else if(N2==0 ||N2==1)
	{	
		N3=!(N2||arr[3]);
		y=!(n1&&N3);
		if(y==Y) return true;
	}
	else if(N3==0||N3==1){
		y=!(n1&&N3);
		if(y==Y) return true;
	}	
	else if(Y==y)	return true;	
	
//	cout<<"y="<<y<<",Y="<<Y<<"	";
	return false;	
}

int IsOver(int S[]){
	for(int i=0;i<16;i++){
		if(S[i]==0)
		{
			return 0;
		}
	}	
	return 1;
}
int main(){

	int arr[4];
	int arr2[16][16]={0};
	system("pause");
	//A3 SA1
	cout<<"A3 SA1:\n";
	for(int i=0;i<16;i++)
	{
		int j=i;
		for(int k=3;k>=0;k--)
		{
			arr[k]=j%2;
			j=j/2;
		}		
		if(same(arr,1,5,5,5,5,5,5,5)==false)
		{
			cout<<"{ "<<i<<" } ";
		
			//count
			arr2[0][i]++;
		}
	}
	//A3 SA0
	cout<<"\nA3 SA0:\n";
	for(int i=0;i<16;i++)
	{
		int j=i;
		for(int k=3;k>=0;k--)
		{
			arr[k]=j%2;
			j=j/2;
		}
		
		if(same(arr,0,5,5,5,5,5,5,5)==false)
		{
			cout<<"{ "<<i<<" } ";	
			//count
			arr2[1][i]++;
		}
		
	}
	//A2 SA1
	cout<<"\nA2 SA1:\n";
	for(int i=0;i<16;i++)
	{
		int j=i;
		for(int k=3;k>=0;k--)
		{
			arr[k]=j%2;
			j=j/2;
		}
		
		if(same(arr,5,1,5,5,5,5,5,5)==false)
		{
			cout<<"{ "<<i<<" } ";	
			//count
			arr2[2][i]++;
		}
		
	}
	//A2 SA0
	cout<<"\nA2 SA0:\n";
	for(int i=0;i<16;i++)
	{
		int j=i;
		for(int k=3;k>=0;k--)
		{
			arr[k]=j%2;
			j=j/2;
		}
		
		if(same(arr,5,0,5,5,5,5,5,5)==false)
		{
			cout<<"{ "<<i<<" } ";	
			//count
			arr2[3][i]++;
		}
		
	}
	//A1 SA1
	cout<<"\nA1 SA1:\n";
	for(int i=0;i<16;i++)
	{
		int j=i;
		for(int k=3;k>=0;k--)
		{
			arr[k]=j%2;
			j=j/2;
		}
		
		if(same(arr,5,5,1,5,5,5,5,5)==false)
		{
			cout<<"{ "<<i<<" } ";	
			//count
			arr2[4][i]++;
		}
		
	}
	//A1 SA0
	cout<<"\nA1 SA0:\n";
	for(int i=0;i<16;i++)
	{
		int j=i;
		for(int k=3;k>=0;k--)
		{
			arr[k]=j%2;
			j=j/2;
		}
		
		if(same(arr,5,5,0,5,5,5,5,5)==false)
		{
			cout<<"{ "<<i<<" } ";	
			//count
			arr2[5][i]++;
		}
		
	}
	//A0 SA1
	cout<<"\nA0 SA1:\n";
	for(int i=0;i<16;i++)
	{
		int j=i;
		for(int k=3;k>=0;k--)
		{
			arr[k]=j%2;
			j=j/2;
		}
		
		if(same(arr,5,5,5,1,5,5,5,5)==false)
		{
			cout<<"{ "<<i<<" } ";	
			//count
			arr2[6][i]++;
		}
		
	}
	//A0 SA0
	cout<<"\nA0 SA0:\n";
	for(int i=0;i<16;i++)
	{
		int j=i;
		for(int k=3;k>=0;k--)
		{
			arr[k]=j%2;
			j=j/2;
		}
		
		if(same(arr,5,5,5,0,5,5,5,5)==false)
		{
			cout<<"{ "<<i<<" } ";	
			//count
			arr2[7][i]++;
		}
		
	}
	//n1 SA1
	cout<<"\nn1 SA1:\n";
	for(int i=0;i<16;i++)
	{
		int j=i;
		for(int k=3;k>=0;k--)
		{
			arr[k]=j%2;
			j=j/2;
		}
		
		if(same(arr,5,5,5,5,1,5,5,5)==false)
		{
			cout<<"{ "<<i<<" } ";	
			//count
			arr2[8][i]++;
		}
		
	}
	//n1 SA0
	cout<<"\nn1 SA0:\n";
	for(int i=0;i<16;i++)
	{
		int j=i;
		for(int k=3;k>=0;k--)
		{
			arr[k]=j%2;
			j=j/2;
		}
		
		if(same(arr,5,5,5,5,0,5,5,5)==false)
		{
			cout<<"{ "<<i<<" } ";	
			//count
			arr2[9][i]++;
		}
		
	}
	//n2 SA1
	cout<<"\nn2 SA1:\n";
	for(int i=0;i<16;i++)
	{
		int j=i;
		for(int k=3;k>=0;k--)
		{
			arr[k]=j%2;
			j=j/2;
		}
		
		if(same(arr,5,5,5,5,5,1,5,5)==false)
		{
			cout<<"{ "<<i<<" } ";	
			//count
			arr2[10][i]++;
		}
		
	}
	//n2 SA0
	cout<<"\nn2 SA0:\n";
	for(int i=0;i<16;i++)
	{
		int j=i;
		for(int k=3;k>=0;k--)
		{
			arr[k]=j%2;
			j=j/2;
		}
		
		if(same(arr,5,5,5,5,5,0,5,5)==false)
		{
			cout<<"{ "<<i<<" } ";	
			//count
			arr2[11][i]++;
		}
		
	}
	//n3 SA1
	cout<<"\nn3 SA1:\n";
	for(int i=0;i<16;i++)
	{
		int j=i;
		for(int k=3;k>=0;k--)
		{
			arr[k]=j%2;
			j=j/2;
		}
		
		if(same(arr,5,5,5,5,5,5,1,5)==false)
		{
			cout<<"{ "<<i<<" } ";	
			//count
			arr2[12][i]++;
		}
		
	}
	//n3 SA0
	cout<<"\nn3 SA0:\n";
	for(int i=0;i<16;i++)
	{
		int j=i;
		for(int k=3;k>=0;k--)
		{
			arr[k]=j%2;
			j=j/2;
		}
		
		if(same(arr,5,5,5,5,5,5,0,5)==false)
		{
			cout<<"{ "<<i<<" } ";	
				//count
			arr2[13][i]++;
		}
	
	}
	//Y SA1
	cout<<"\nY SA1:\n";
	for(int i=0;i<16;i++)
	{
		int j=i;
		for(int k=3;k>=0;k--)
		{
			arr[k]=j%2;
			j=j/2;
		}
		
		if(same(arr,5,5,5,5,5,5,5,1)==false)
		{
			cout<<"{ "<<i<<" } ";	
			//count
			arr2[14][i]++;
		}
		
	}
	//Y SA0
	cout<<"\nY SA0:\n";
	for(int i=0;i<16;i++)
	{
		int j=i;
		for(int k=3;k>=0;k--)
		{
			arr[k]=j%2;
			j=j/2;
		}
		
		if(same(arr,5,5,5,5,5,5,5,0)==false)
		{
			cout<<"{ "<<i<<" } ";	
			//count
			arr2[15][i]++;
		}
		
	}
	cout<<endl;
	//cout min set
	int re[16]={0},S[16]={0},temp; //re:紀錄 Test Pattern Set  //S:紀錄16個defalt被處理了沒 
	for(int i=0;i<16;i++)//找出只有一組數字的 
	{
		int count=0;
		for(int j=0;j<16;j++)
		{
			if(arr2[i][j]!=0)
			{
				count++;
				temp=j;
			}	
		}
		if(count==1)
			re[temp]++;
		
	}
	for(int j=0;j<16;j++)
	{
		if(re[j]!=0)
		{
			for(int i=0;i<16;i++)
			{
				if(arr2[i][j]!=0)
				{
					S[i]=1;
					for(int k=0;k<16;k++)
						arr2[i][k]=0;
				}
			}	
		}
	}
	//由剩下未記錄的S找0-15出現頻率
	while(IsOver(S)==0){
		int max=0,count=0,tempM; 
		for(int j=0;j<16;j++)
		{
			for(int i=0;i<16;i++)
			{
				if(S[i]==0&&arr2[i][j]!=0)
				{
					count++;
				}
			}	
			if(count>max)
			{
				max=count;
				tempM=j;
			}	
		}
		re[tempM]++;
		for(int i=0;i<16;i++)
		{
			if(arr2[i][tempM]!=0)
			{
				S[i]=1;
				for(int k=0;k<16;k++)
					arr2[i][k]=0;
			}
		}
	}
	cout<<"Min set = { ";
	for(int i=0;i<16;i++)
		if(re[i]!=0)
			cout<<i<<" ";
	cout<<"}"<<endl;
	

	return 0;
}

	
