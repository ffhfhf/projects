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
    cout<<"                               最佳路由选择           "<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                         ============================="<<endl;
    cout<<"                                 1 结点管理           "<<endl;
    cout<<"                                 2 边管理             "<<endl;
    cout<<"                                 3 路由表输出         "<<endl;
    cin>>weight;
    while(1)
    {
    switch(weight)
    {
    case 1:
          cout<<"1 增加结点 2删除结点"<<endl;
          cin>>chose;
          if(chose==1)
          {
             operaddpo();
          }
          else
          {
              operdepo();
          }
          cout<<"是否保存修改是输入0"<<endl;
          cin>>chose;
          if(chose==0)
          {
              memory();
          }
          break;
    case 2:
           cout<<"1 增加边 2删除边"<<endl;
           cin>>chose;
           if(chose==1)
           {
               operaddpa();
           }
           else
           {
               operdepa();
           }
          cout<<"是否保存修改是输入0"<<endl;
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
    cout<<"终止程序输入3"<<endl;
    cin>>chose;
    if(chose==3)
    {
        break;
    }
    cout<<"                         ============================="<<endl;
    cout<<"                                 1 结点管理           "<<endl;
    cout<<"                                 2 边管理             "<<endl;
    cout<<"                                 3 路由表输出         "<<endl;
    cout<<"                         ============================="<<endl;
    cin>>weight;
  }
}
