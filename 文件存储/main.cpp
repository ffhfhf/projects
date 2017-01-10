#include<windows.h>

using namespace std;

void memory()//保存修改
{
   DeleteFile("e://14-李浩//1.txt");
   DeleteFile("e://14-李浩//2.txt");
   int i,j,k;
   link2 *current;
   fstream out("e://14-李浩//1.txt",ios::out);
   for(i=0;i<n;i++)
   {
       if(main1[i].flag==1)
       {
           continue;
       }
       out<<main1[i].i<<" "<<main1[i].s<<endl;
   }
   fstream out1("e://14-李浩//2.txt",ios::out);
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
