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
link1 main1[100];
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


