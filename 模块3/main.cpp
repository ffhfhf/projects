#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define maxvalue 100
int n=9;
int dist[100];
int path[100];
struct link2
{
    string i;//路由名称
    int j;//权值
    link2 * link=NULL;
};
struct link1
{
    string i;//路由名称
    string s;//路由ip
    int flag;//删除位
    link2*link=NULL;
};
link1 main1[100];
int getweight(int i,int j)//取权值
{
  if(i==j)
  {
      return 0;
  }
  if(main1[i].flag==1)
  {
      return maxvalue;
  }
  if(main1[j].flag==1)
  {
      return maxvalue;
  }
  link2 *current=main1[i].link;
  while(current!=NULL)
  {
      if(current->i==main1[j].i)
      {
          break;
      }
      current=current->link;
  }
  if(current==NULL)
  {
      return maxvalue;
  }
  return current->j;
}
void prinluyou()//生成路由表
{
   string g;
   cout<<"输入要生成的路由表的名称"<<endl;
   cin>>g;
   int count1;
   for(count1=0;count1<n;count1++)
   {
       if(main1[count1].i==g)
       {
           break;
       }
   }
   bool *s=new bool[n];
   int i,j,k;
   int min1,w;
   for(i=0;i<n;i++)
   {
       dist[i]=getweight(count1,i);
       s[i]=false;
       if(i!=count1&&dist[i]<min1)
       {
           path[i]=count1;
       }
       else
       {
           path[i]=-1;
       }
   }
   s[count1]=true;
   dist[count1]=0;
   for(i=0;i<n-1;i++)
   {
       min1=maxvalue;
       int u=count1;
       for(j=0;j<n;j++)
       {
           if(s[j]==false&&dist[j]<maxvalue)
           {
               u=j;
               min1=dist[j];
           }
           s[u]=true;
           for(k=0;k<n;k++)
           {
               w=getweight(u,k);
               if(s[k]==false&&w<maxvalue&&dist[u]+w<dist[k])
               {
                   dist[k]=dist[u]+w;
                   path[k]=u;
               }
           }
       }
   }
   cout<<"------------------------------------"<<endl;
   cout<<"      目的ip               下一跳   "<<endl;
   for(k=0;k<n;k++)
   {
       if(k==count1)
       {
           continue;
       }
       if(path[k]==-1)
       {
           continue;
       }
       if(main1[k].flag==1)
       {
           continue;
       }
       j=k;
       while(path[j]!=count1)
       {
           j=path[j];
       }
    cout<<"     "<<main1[k].s<<"                  "<<main1[j].i<<endl;
   }
    cout<<"------------------------------------"<<endl;
}
