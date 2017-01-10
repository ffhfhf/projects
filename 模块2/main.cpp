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
void operdepo()//删除结点操作
{
  string i;
  int k;
  cout<<"输入要删除的结点名称"<<endl;
  cin>>i;
  for(k=0;k<n;k++)
  {
      if(main1[k].i==i)
      {
          break;
      }
  }
  main1[k].flag=1;
}
void operdepa()//删除边操作
{
    string i,j;
    int k;
    link2 *temp;
    link2 *current;
    cout<<"输入边的起点终点"<<endl;
    cin>>i>>j;
    for(k=0;k<n;k++)
    {
        if(main1[k].i==i)
        {
            break;
        }
    }
    current=main1[k].link;
    while(current->link->i!=j)
    {
        current=current->link;
    }
    temp=current->link;
    current->link=current->link->link;
    delete temp;
    for(k=0;k<n;k++)
    {
        if(main1[k].i==j)
        {
            break;
        }
    }
    current=main1[k].link;
    while(current->link->i!=i)
    {
        current=current->link;
    }
    temp=current->link;
    current->link=current->link->link;
    delete temp;
}
void operaddpo()//增加结点
{
   string s,i,h;
   int j,count1;
   int k;
   link2*current,*temp,*current1;
   cout<<"输入添加结点名称和ip"<<endl;
   cin>>i>>s;
   n=n+1;
   main1[n-1].flag=0;
   main1[n-1].i=i;
   main1[n-1].s=s;
   cout<<"输入关联结点个数"<<endl;
   cin>>count1;//循环插入算法
   cout<<"按格式依次输入关联结点名称和权值中间以空格分开"<<endl;
   temp=new link2;
   cin>>h;
   cin>>j;
   temp->i=h;
   temp->j=j;
   main1[n-1].link=temp;
   current1=temp;
    for(k=0;k<n;k++)
    {
        if(main1[k].i==h)
        {
            break;
        }
    }
    current=main1[k].link;
    cout<<current->i<<endl;
    while(current->link!=NULL)
    {
        current=current->link;
    }
    temp=new link2;
    temp->i=i;
    temp->j=j;
    current->link=temp;
    for(int g=0;g<count1-1;g++)
    {
   temp=new link2;
   cin>>h;
   cin>>j;
   temp->i=i;
   temp->j=j;
   current1->link=temp;
   current1=temp;
    for(k=0;k<n;k++)
    {
        if(main1[k].i==h)
        {
            break;
        }
    }
    current=main1[k].link;
    while(current->link!=NULL)
    {
        current=current->link;
    }
    temp=new link2;
    temp->i=i;
    temp->j=j;
    current->link=temp;
    }
}
void operaddpa()//增加边
{
  link2 *current,*temp;
  string i,j;
  int gh,k;
  cout<<"输入插入边的两个结点"<<endl;
  cin>>i>>j;
  cout<<"输入权值"<<endl;
  cin>>gh;
  for(k=0;k<n;k++)
    {
        if(main1[k].i==i)
        {
            break;
        }
    }
    current=main1[k].link;
    while(current->link!=NULL)
    {
        current=current->link;
    }
    temp=new link2;
    temp->i=j;
    temp->j=gh;
    current->link=temp;
    for(k=0;k<n;k++)
    {
        if(main1[k].i==j)
        {
            break;
        }
    }
    current=main1[k].link;
    while(current->link!=NULL)
    {
        current=current->link;
    }
    temp=new link2;
    temp->i=j;
    temp->j=gh;
    current->link=temp;
}
