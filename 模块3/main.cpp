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
