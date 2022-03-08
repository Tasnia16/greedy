#include <bits/stdc++.h>
using namespace std;
bool finish_time_sort(const pair<int,int>&a1,
              const pair<int,int>&a2)
{
    return (a1.second<a2.second);
}
void maximum_activities(int s[], int f[], int n)
{
    cout <<"Selected activities are : "<< endl;
     int i=0, j,k=1;
    cout <<" "<< i<<":"<<" "<<s[i]<<" "<<f[i]<<endl;
    for (j = 1; j < n; j++)
    {
      if (s[j] >= f[i])
      {
          cout <<" " << j << ":" <<" " <<s[j]<<" "<<f[j]<<endl;
          i = j;
          k++;
      }
    }
    cout<<"Total activities : "<<k;
}

int main(void)
{
  int arr[500],s[500],f[500];
  int i = 0,c=0 ,j;
  FILE *file;
  if (file = fopen("input1.txt", "r"))
  {
    while (fscanf(file, "%d", &arr[i]) != EOF)
    {
      i++;
    }
    fclose(file);
    arr[i] = '\0';
    vector<pair<int,int>>v ;

       for (int l = 0; l<i; l=l+2)
       {
           v.push_back(make_pair(arr[l],arr[l+1]));
           c++;
       }

     sort(v.begin(), v.end(),finish_time_sort);

     cout<<"starting time"<<"\t"<<"finishing time"<<endl;
     for (int j=0; j<c;j++)
    {

        cout << v[j].first << "\t\t"
             << v[j].second << endl;

    }

     for (int k=0; k<c;k++)
    {

        s[k]=v[k].first;
        f[k]=v[k].second;

    }

    maximum_activities(s, f, c);
    return 0;

}

  }


