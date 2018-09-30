/*Amir Yousef
 Homework2-Stats
 COP3330-Fall 2011
 */
#include <iostream>
#include <cstdlib>

float Mean(const int* a, size_t size); // calculates mean of data in a       
float Median(int* a, size_t size);     // calculates median of data in a         
void Sort(int* a, size_t size);        // sorts the data in a     
void Swap(int& x, int& y);             // interchanges values of x and y      

int main()
{
int *a;
a=new int[100];
size_t j, size=0;
double mean;
std::cout<<"Enter integers ('x' to quit): ";
std::cin>>a[size];
size++;
while(std::cin&&size<99)
      {
      std::cin>>a[size];
      size++;    
      }
size--;
std::cout<<"\nData as entered:";
for(j=0;j<size;j++)
      {
	  std::cout<<a[j]<<"  ";
       if((j+1)%20==0)    //20 numbers per line
       std::cout<<std::endl;
       }
std::cout<<std::endl;

mean=Mean(a,size);
std::cout<<"Mean: "<<mean<<"\n";
std::cout<<"Median: "<<Median(a,size);
Sort(a, size);         // sort the numbers
   std::cout<<std::endl;
   std::cout<<"Data after sort: ";
   for(size_t count=0; count<size; count++)            // loop to print the values       
     {
       std::cout<<*(a+count);
       if(count!=(size-1))                      // display the numbers
         std::cout<<", ";
       else
         std::cout<<std::endl<<std::endl;
     }

return 0;
}

      
void Sort(int* a, size_t size)
{ 
int min; 
size_t i,j,index;
    for(i=0;i<size-1; i++)
    {
	index=i;
    min=a[i];
    for(j=i+1;j<size;j++)
    {
    if(min>a[j])   
    {
	index=j;  
    min=a[j];
    }
    }
    Swap(a[i],a[index]);

    }
 
}

void Swap(int &x, int &y)
 {
 int z;
 z=x;
 x=y;
 y=z;
 } 


float Mean(const int* a, size_t size)
{
size_t sum=0,i;
for(i=0;i<size;i++)
    sum+=a[i];
return (float)sum/size;
}

float Median(int* a, size_t size)
   {
   float mid;
   Sort(a,size);

    if(size%2==1)
        mid=a[size/2];
       
    else
       {mid=a[size/2]+a[size/2-1];
       mid=mid/2.;
       }
    return mid;
       
   }

