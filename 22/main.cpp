#include<iostream>
#include<fstream>
#include<string>
using namespace std;
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
