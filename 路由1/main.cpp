#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<windows.h>

using namespace std;

#define maxvalue 100
int n=9;
int dist[100];
int path[100];
struct link2
{
    string i;//·������
    int j;//Ȩֵ
    link2 * link=NULL;
};
struct link1
{
    string i;//·������
    string s;//·��ip
    int flag;//ɾ��λ
    link2*link=NULL;
};
struct binary
{
    int pre;
    int next[100];
    int nwei=0;
};
binary create[100];
link1 main1[100];
int count1;
void primary1()//��ʼ��·�ɽ��
{
    string s;
    int i=0;
    fstream out("e://14-���//1.txt");
    for(i=0;i<9;i++)
    {
        out>>main1[i].i;
        out>>main1[i].s;
        main1[i].flag=0;
    }
}
void primary2()//��ʼ�����Ĺ������
{
    link2*temp,*current;
    int sum;
    int i;
    fstream out1("e://14-���//2.txt");
    char s;
    string gh;
    for( i=0;i<9;i++)
    {
        temp=new link2;
        out1>>gh;
        temp->i=gh;
        out1>>s;
        sum=s-'0';
        temp->j=sum;
        main1[i].link=temp;
        current=temp;
        while(1)
        {
            out1>>gh;
            if(gh[0]=='#')
            {
                break;
            }
            temp=new link2;
            temp->i=gh;
            out1>>s;
            sum=s-'0';
            temp->j=sum;
            current->link=temp;
            current=current->link;
        }
    }
}
void operdepo()//ɾ��������
{
  string i;
  int k;
  cout<<"����Ҫɾ���Ľ������"<<endl;
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
void operdepa()//ɾ���߲���
{
    string i,j;
    int k;
    link2 *temp;
    link2 *current;
    cout<<"����ߵ�����յ�"<<endl;
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
void operaddpo()//���ӽ��
{
   string s,i,h;
   int j,count1;
   int k;
   link2*current,*temp,*current1;
   cout<<"������ӽ�����ƺ�ip"<<endl;
   cin>>i>>s;
   n=n+1;
   main1[n-1].flag=0;
   main1[n-1].i=i;
   main1[n-1].s=s;
   cout<<"�������������"<<endl;
   cin>>count1;//ѭ�������㷨
   cout<<"����ʽ�����������������ƺ�Ȩֵ�м��Կո�ֿ�"<<endl;
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
void operaddpa()//���ӱ�
{
  link2 *current,*temp;
  string i,j;
  int gh,k;
  cout<<"�������ߵ��������"<<endl;
  cin>>i>>j;
  cout<<"����Ȩֵ"<<endl;
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
int getweight(int i,int j)//ȡȨֵ
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
void dex(int i)
{
    int count2=0;
    int fg=0;
    int k=create[i].nwei;
    if(k==0)
    {
        cout<<endl;
        cout<<endl;
        return;
    }
    while(k--)
    {
        fg=create[i].next[k];
        while(path[fg]!=count1)
        {
            ++count2;
            fg=path[fg];
        }
        for(int i=0;i<count2;i++)
        {
            cout<<"-----"<<" ";
        }
        cout<<main1[create[i].next[k]].i;
        dex(create[i].next[k]);
    }
}
void prinluyou()//����·�ɱ�
{
   string g;
   cout<<"����Ҫ���ɵ�·�ɱ������"<<endl;
   cin>>g;
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
   for(i=0;i<n;i++)//�洢��һ������һ��
   {
       if(i==count1)
       {
           create[i].pre=-1;
       }
       else
       {
           create[i].pre=path[i];
           k=path[i];
           create[k].next[create[k].nwei]=i;
           create[k].nwei++;
       }
   }
   dex(count1);
   cout<<endl;
   cout<<"------------------------------------"<<endl;
   cout<<"      Ŀ��ip               ��һ��   "<<endl;
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
void memory()//�����޸�
{
   DeleteFile("e://14-���//1.txt");
   DeleteFile("e://14-���//2.txt");
   int i,j,k;
   link2 *current;
   fstream out("e://14-���//1.txt",ios::out);
   for(i=0;i<n;i++)
   {
       if(main1[i].flag==1)
       {
           continue;
       }
       out<<main1[i].i<<" "<<main1[i].s<<endl;
   }
   fstream out1("e://14-���//2.txt",ios::out);
   for(j=0;j<n;j++)
   {
       if(main1[j].flag==1)
       {
           continue;
       }
       current=main1[j].link;
       while(current!=NULL)
       {
           for(k=0;k<n;k++)
           {
               if(main1[k].i==current->i)
               {
                   break;
               }
           }
           if(main1[k].flag==1)
           {
               current=current->link;
           }
           out1<<current->i<<" "<<current->j<<" ";
           current=current->link;
       }
       out1<<'#'<<endl;
   }
}
int main()
{
    int weight;
    int chose;
    primary1();
    primary2();
    cout<<"                         ============================ "<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                               ���·��ѡ��           "<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                         ============================="<<endl;
    cout<<"                                 1 ������           "<<endl;
    cout<<"                                 2 �߹���             "<<endl;
    cout<<"                                 3 ·�ɱ����         "<<endl;
    cin>>weight;
    while(1)
    {
    switch(weight)
    {
    case 1:
          cout<<"1 ���ӽ�� 2ɾ�����"<<endl;
          cin>>chose;
          if(chose==1)
          {
             operaddpo();
          }
          else
          {
              operdepo();
          }
          cout<<"�Ƿ񱣴��޸�������0"<<endl;
          cin>>chose;
          if(chose==0)
          {
              memory();
          }
          break;
    case 2:
           cout<<"1 ���ӱ� 2ɾ����"<<endl;
           cin>>chose;
           if(chose==1)
           {
               operaddpa();
           }
           else
           {
               operdepa();
           }
          cout<<"�Ƿ񱣴��޸�������0"<<endl;
          cin>>chose;
          if(chose==0)
          {
              memory();
          }
          break;
    case 3:
        prinluyou();
        break;
    }
    cout<<"��ֹ��������3"<<endl;
    cin>>chose;
    if(chose==3)
    {
        break;
    }
    cout<<"                         ============================="<<endl;
    cout<<"                                 1 ������           "<<endl;
    cout<<"                                 2 �߹���             "<<endl;
    cout<<"                                 3 ·�ɱ����         "<<endl;
    cout<<"                         ============================="<<endl;
    cin>>weight;
  }
}
