#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#define Size 200
using namespace std;
struct cdfg{
       int op;
       int op1;
	   float op2; 
       int result;
       int mulL;
       }sample1[Size];

struct readylist{
       int state;
       int op;
       int num;
       int dis;
       }list1[Size],temp;
       
struct alu{
       int mult;
       int add;
       }alulist[Size];

void list_Scheduling(int end);
int readIn();

int main()
{

    int end;

    end=readIn();

    list_Scheduling(end);

	return 0;
}
int readIn()
{
	ifstream fptr_in;

    int step=0,op=0,op1=0,result=0,count=0,end;
    float op2=0;
	char  In_FileName[20]; 
	int i;

	int c;
    cout<<"\n欲選擇 DFG1.txt，請輸入 1 \n欲選擇 DFG2.txt，請輸入 2\n欲選擇 RGBtoYUV.txt，請輸入 3\n";    
    cout<<"\n Enter choice : ";
	cin>>c;
	switch(c){
		case 1:
			{
				fptr_in.open("DFG1.txt");
				break;
			}
		case 2:
			{
				fptr_in.open("DFG2.txt");
				break;
			}
		case 3:
			{
				fptr_in.open("RGBtoYUV.txt");
				break;
			}
		default:
			{
				printf("Error\n");
				break;
			}
	}
    if( fptr_in.fail() )
	{
		printf("Error!!can not open file!! \nPress any key to exit. \n");
    	exit(1); 
	}
	
	fptr_in>>end;
	
	
    while( fptr_in>>op>>op1>>op2>>result ){

                         sample1[count].op=op;

                         sample1[count].op1=op1;

                         sample1[count].op2=op2;

                         sample1[count].result=result;
                         
 	if(c==3||c==2)
		sample1[count].mulL=0;
	else
		sample1[count].mulL=1;
		
    count++;
    
    if(end==count)   //終止用 
    break;

    }

	fptr_in.close();
	return end;
}


void list_Scheduling(int end)
{


     int opmult,opadd;
     int i,j,state=1,opstate=1;
     int signal=0;
     int breakpoint=1;
     
     ofstream fptr_out;
     fptr_out.open( "Outcome.txt" );     
     
     do{
     cout<<"\n 輸入限制的乘法器個數...";
     cin>>opmult;
     cout<<"\n 輸入限制的加法器個數...";
     cin>>opadd;
     
     cout<<"\n乘法器個數:"<<opmult<<",加法器個數："<<opadd<<"\n";
     signal=0;
     state=1;
     opstate=1;
     for(i=0;i<Size;i++)                                //alulist 初始化 
     {
     alulist[i].add=opadd;     
     alulist[i].mult=opmult;
     }    
         
     for(i=0;i<end;i++)
     {
          signal=0;
        /*檢查現在的op1 op2是不是前三個的結果(相依性)*/ 
         if((i>0)&&(state==list1[i-1].state)&&((sample1[i].op1==sample1[i-1].result)||(sample1[i].op2==sample1[i-1].result)))
         {
                 state=state+1;                             //如果前面一個state的result 跟現在的op1 op2重複 就直接跳到下一個state 
         }
         if((i>1)&&(state==list1[i-2].state)&&((sample1[i].op1==sample1[i-2].result)||(sample1[i].op2==sample1[i-2].result)))
         {
                 state=state+1;                             //如果前面兩個state的result 跟現在的op1 op2重複 就直接跳到下一個state
         }
         if((i>2)&&(state==list1[i-3].state)&&((sample1[i].op1==sample1[i-3].result)||(sample1[i].op2==sample1[i-3].result)))
         {
                 state=state+1;                             //如果前面三個state的result 跟現在的op1 op2重複 就直接跳到下一個state
         }         
        /*如果前面的所有式子中有相依性，找opstate*/  
         for(j=0;j<i;j++)                                  //尋找op1 跟 op2 最後出現的state 
         {
            if((sample1[j].op==1)&&((sample1[i].op1==sample1[j].result)||(sample1[i].op2==sample1[j].result)))
            {
            signal=1;
            opstate=list1[j].state;
            }
            
            if((sample1[j].op==2)&&((sample1[i].op1==sample1[j].result)||(sample1[i].op2==sample1[j].result)))
            {
            signal=1;
            opstate=list1[j].state+sample1[i].mulL;
            }
         }
       
         if((i>0)&&(signal==1))                                      //state改為result最後出現後的下一筆 
         state=opstate+1;
         

         if(sample1[i].op==2)                                      //決定此運算要在哪一個state執行 
         do{
         if(alulist[state].mult==0)                                //此state乘法器已經用完 找下一個  
         state++;
         if(alulist[state].mult>0)
         break;
         }while(1);
         
         if(sample1[i].op==1)                                     //決定此運算要在哪一個state執行 
         do{
         if(alulist[state].add==0)                                //此state加法器已經用完 找下一個 
         state++;
         if(alulist[state].add>0)                               
         break;
         }while(1);

             if( sample1[i].op==2 ){
  
               list1[i].op=sample1[i].op;                        //把乘法器 或加法器 儲存起來 
               list1[i].state=state;                             //紀錄它的state 
               list1[i].num=i;                                   //紀錄它的運算編號 
                                              
               
               alulist[state].mult=alulist[state].mult-1; 
			   if(sample1[i].mulL==1)       
               	alulist[state+1].mult=alulist[state+1].mult-1;
               
              }
             else       //如果加法器還沒用完 且裡面需要加法運算
             {
               list1[i].op=sample1[i].op;                        //把乘法器 或加法器 儲存起來 
               list1[i].state=state;                             //紀錄它的state 
               list1[i].num=i;                                   //紀錄它的運算編號 
               
               
               alulist[state].add=alulist[state].add-1; 
        
             } 

     }
     //將資料排序進去list1[] 
          for(i=0;i<end;i++)
          {
             for(j=i;j<end;j++)
             {
                if(list1[i].state>list1[j].state)
                {
                    temp.state=list1[j].state;
                    temp.op=list1[j].op;
                    temp.num=list1[j].num;
                    list1[j].state=list1[i].state;
                    list1[j].op=list1[i].op;
                    list1[j].num=list1[i].num;
                    list1[i].state=temp.state;
                    list1[i].op=temp.op;
                    list1[i].num=temp.num;
                }
             }
          }
          

    fptr_out<<"*****************************\n";
    fptr_out<<"*    Resource Constraint    *\n";
    fptr_out<<"*                           *\n";
    fptr_out<<"*     Mult Constraint:"<<opmult<<"     *\n";
    fptr_out<<"*     Add  Constraint:"<<opadd<<"     *\n";
    fptr_out<<"*                           *\n";
    fptr_out<<"*****************************\n";
    for(i=0;i<end;i++)
    {
        if(sample1[list1[i].num].op==1)
        {
               cout<<"State:"<<left<<setw(5)<<list1[i].state<<"v"<<left<<setw(5)<<sample1[list1[i].num].result<<"=	"<<"v"<<left<<setw(8)<<sample1[list1[i].num].op1<<"+	"<<"v"<<sample1[list1[i].num].op2<<endl;
               fptr_out<<"State:"<<left<<setw(5)<<list1[i].state<<"v"<<left<<setw(5)<<sample1[list1[i].num].result<<"=	"<<"v"<<left<<setw(8)<<sample1[list1[i].num].op1<<"+	"<<"v"<<sample1[list1[i].num].op2<<endl;
        }      
        else
        {
               cout<<"State:"<<left<<setw(5)<<list1[i].state<<"v"<<left<<setw(5)<<sample1[list1[i].num].result<<"=	"<<"v"<<left<<setw(8)<<sample1[list1[i].num].op1<<"*	"<<"v"<<sample1[list1[i].num].op2<<endl;
               fptr_out<<"State:"<<left<<setw(5)<<list1[i].state<<"v"<<left<<setw(5)<<sample1[list1[i].num].result<<"=	"<<"v"<<left<<setw(8)<<sample1[list1[i].num].op1<<"*	"<<"v"<<sample1[list1[i].num].op2<<endl;
		}
    }
    fptr_out<<"\n\n\n\n";     
    
    cout<<"\n繼續使用       Yes(輸入1) No(輸入2) ";
    cin>>breakpoint;

    printf("\n\n");
    
    }while(breakpoint==1);
    
   	fptr_out.close();     
          
}//list_Scheduling
