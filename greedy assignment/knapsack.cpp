#include<bits/stdc++.h>
using namespace std;
void KnapSack(int n, float w[], float p[], float capacity) {
   float f[500], mx = 0;
   int i, j, k;
   k = capacity;
   for (i = 0;i< n;i++)
      f[i] = 0.0;
   for (i = 0;i <n;i++)
    {
       if (w[i]>k)
         break;
       else
            {
             f[i]=1.0;
             mx= mx+p[i];
             k=k-w[i];
      }
   }

   if (i<n)
      f[i]=k/w[i];
     mx=mx+(f[i]*p[i]);

   cout<<"\nThe unit proft: ";
   for (i=0; i<n;i++)
      cout<<f[i]<<" ";
   cout<<"\nMaximum profit : "<<mx;

}



int main(void)
{
    float ratio[500],arr[500],w[500],p[500],capacity;
  int i = 0,c=0 ,j;
  FILE *file;

  if (file = fopen("input2.txt", "r"))
  {
    while (fscanf(file, "%f", &arr[i]) != EOF)
    {
      i++;
    }
    fclose(file);

    arr[i] ='\0';
    capacity=arr[i-1];

    vector<pair<int,int>>v ;


       for (int l=0;l<i-1;l=l+2)
       {
           v.push_back(make_pair(arr[l],arr[l+1]));
           c++;
       }
     for (int k=0; k<c;k++)
    {
        w[k]=v[k].first;
        p[k]=v[k].second;
    }
    cout<<"Weight"<<"\t"<<"profit"<<endl;

     for (int k=0; k<c;k++)
    {
        cout<<w[k]<<"\t";
        cout<<p[k]<<"\n";
    }

    cout<<"Capacity of knapsack is : "<<capacity;
    for (i=0;i<c;i++) {
      ratio[i] =p[i]/w[i];
   }

     for (i=0;i<c;i++)
        {
          for (j=i+1;j<c;j++)
           {
             if (ratio[i]<ratio[j])
              {
               swap(ratio[i],ratio[j]);
               swap(w[j],w[i]);
               swap(p[j],p[i]);
         }
      }
   }

   KnapSack(c,w,p,capacity);
   return 0;

}
}
