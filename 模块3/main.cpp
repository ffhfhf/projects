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
