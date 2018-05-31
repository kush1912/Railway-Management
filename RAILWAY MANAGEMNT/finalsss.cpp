#include<iostream>
#include<windows.h>

#include<bits/stdc++.h>
using namespace std;
int convert(string s)
{
    int t=0;
    for(int i=0;i<s.length();i++)
    {
        char x=s[i];
        int x1=x-48;
        t=t*10+x1;
    }
    return t;
}
string convert1(int n)
{
    string s="";
    while(n!=0)
    {
        int a=n%10;
        s=char(a+48)+s;
        n=n/10;
    }
    return s;
}
int reduce(string name,int num)
{
    int flag=0;
    ifstream myReadFile;
    myReadFile.open("test.txt");
    string output1;
    string output2;
    string arr1[100];

    map<string,string>lists;
    int k=0;
    if (myReadFile.is_open())
    {
        while (!myReadFile.eof())
        {
            myReadFile >> output1;
            myReadFile >> output2;
            int t=0;
            if(output1==name)
            {
                t=convert(output2);
                t=t-num;
                output2=convert1(t);
                flag=1;
            }
            lists[output1]=output2;
            arr1[k++]=output1;
        }
        myReadFile.close();
    }
    if(flag==1)
    {
        ofstream fout;
        fout.open("test.txt");
        for(int i=0;i<k;i++)
        {
            fout<<arr1[i]<<"\t\t"<<lists[arr1[i]]<<"\n";
        }
        fout.close();
    }
    return flag;
}
//Function to print a string in the middle of the screen
int space(string &s1)
{
    int l=s1.length();
    int pos=(int)((180-l)/2);
    for(int i=0;i<pos;i++)
    cout<<" ";
    cout<<s1<<endl;
}
//Function to get a line break
int line_break()
{
    for(int i=0;i<180;i++)
    {
        cout<<"-";
    }
    cout<<endl;
}
//Function to print the heading
int heading()
{
    system("color B");
    string s="T.R.A.I.N.S";
    string s1="THE RAILWAY APPLICATION WITH INTEGRATED NEW SELF-HELP";
    line_break();
    space(s);
    cout<<"\n";
    space(s1);
    cout<<"\n";
    cout<<"Submitted to: DR. VIKAS SAXENA"<<endl;
    cout<<"Submitted by: "<<endl<<"Skandha Choudhry     16104012"<<endl<<"Ajay Kumar Kushwaha  16104013"<<endl<<"Umang Rastogi        16104037"<<endl<<"Samyak Jain          16104047"<<endl;
    line_break();
}
//Main reservation function
struct ticket
{
    string passenger_name;
    int passenger_age;
};
int train_schedules()
{
    system("cls");
    heading();
    ifstream myReadFile;
    myReadFile.open("test1.txt");
    char output1[10000];
    char output2[10000];
    char output3[10000];
    if (myReadFile.is_open())
    {
        while (!myReadFile.eof())
        {
            myReadFile >> output1;
            myReadFile >> output2;
            myReadFile >> output3;
            cout<<output1<<"\t\t"<<output2<<"\t\t"<<output3<<endl;
        }
        myReadFile.close();
    }
    system("pause");
    system("cls");
    heading();
}
int check_avalibility()
{
    system("cls");
    heading();
    string name;
    int n;
    string tick_req;
    cout<<"ENTER TRAIN NAME"<<endl;
    cin>>name;
    cout<<"ENTER NUMBER OF TICKETS REQUIRED"<<endl;
    cin>>tick_req;
    ifstream myReadFile;
    myReadFile.open("test.txt");
    string output1;
    string output2;
    map<string,string> avalibility;
    string train_list[100];
    int k=0;
    int flag=0;
    if (myReadFile.is_open())
    {
        while (!myReadFile.eof())
        {
            myReadFile >> output1;
            myReadFile >> output2;
            avalibility[output1]=output2;
            train_list[k++]=output1;
        }
    }
    int av=0;
    for(int i=0;i<k;i++)
    {
        if(name==train_list[i])
        {
            av=1;
        break;
        }
    }
    if (av==1)
    {
        //if(convert(avalibility[name])>=convert(tick_req))
        if((avalibility[name])>=(tick_req))
        {
            cout<<"TICKETS AVALIABLE"<<endl;
            flag=1;
        }
        else
        {
            cout<<"TICKETS NOT AVALIABLE"<<endl;
            flag=0;
        }
    }
    else
    {
        cout<<"Train not found"<<endl;
        myReadFile.close();
    }
    system("pause");
    system("cls");
    heading();
    return flag;
}
int book_ticket()
{
    system("cls");
    heading();
    string name;
    string tick_req;
    cout<<"ENTER THE TRAIN NAME"<<endl;
    cin>>name;
    cout<<"ENTER THE NUMBER OF TICKETS REQUIRED"<<endl;
    cin>>tick_req;
    //CHANGE HERE
    int n=convert(tick_req);
    //DECREASE THE NUMBER OF TICKETS HERE
    int t=reduce(name,n);
    if(t==1)
    {
        struct ticket book[n];
        cout<<"ENTER THE PASSENGERS NAMES AND AGE"<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>book[i].passenger_name;
            cin>>book[i].passenger_age;
        }
        ofstream myfile;
        string pnr="";
        for (int i = 0; i < n; ++i)
        {
            pnr += book[i].passenger_name[0];
        }
        //myfile.open(pnr+".txt");
        myfile.open(pnr.c_str());
        myfile <<"TRAIN_NAME :"<<name<<endl;
        myfile <<"NAME\t\t:AGE"<<endl;
        for(int i=0;i<n;i++)
        {
            myfile << book[i].passenger_name<<"\t\t:"<<book[i].passenger_age<<endl;
        }
        myfile.close();
        cout<<endl<<"YOUR PNR NUMBER IS : "<<pnr<<endl;
        cout<<"TICKET SUCESSFULLY BOOKED!!"<<endl;
    }
    else
    {
        cout<<"NO TRAIN FOUND"<<endl;
    }
    system("pause");
    system("cls");
    heading();
    return 0;
}
int check_PNR()
{
    system("cls");
    heading();
    string pnr="";
    cout<<"ENTER PNR NUMBER"<<endl;
    cin>>pnr;
    ifstream myReadFile;
    //myReadFile.open(pnr+".txt");
    myReadFile.open(pnr.c_str());
    char output1[10000];
    char output2[10000];
    if (myReadFile.is_open())
    {
        while (!myReadFile.eof())
        {
            myReadFile >> output1;
            myReadFile >> output2;
            cout<<output1<<"\t"<<output2<<endl;
        }
        myReadFile.close();
    }
    system("pause");
    system("cls");
    heading();
}
int reservation()
{
    system("cls");
    heading();
    //space(u_c);
    int ch=10;
    while(ch)
    {
        cout<<"1.Train Schedules\n2.Check Avalibility\n3.Book Ticket\n4.Check PNRStatus\n0.Exit"<<endl;
        cin>>ch;
        if(ch==1)
            train_schedules();
        else if(ch==2)
            check_avalibility();
        else if(ch==3)
            book_ticket();
        else if(ch==4)
            check_PNR();
        else if(ch==0)
            cout<<"\nTHANKYOU FOR USING OUR APPLICATION"<<endl;
        else
        {
            cout<<"\n\nINVALID INPUT"<<endl;
            Sleep(2000);
            system("cls");
            heading();
        }
    }
    system("pause");
    system("cls");
    heading();
    return 0;
}
//Main cancellation function
int cancellation()
{
    system("cls");
    heading();
    //space(u_c);
    char pnr[100];
    cout<<"ENTER THE PNR NUMBER OF THE TICKET YOU WANT TO CANCEL"<<endl;
    cin>>pnr;
    ifstream myxfile;
    myxfile.open(pnr);
    int pin;
    myxfile>>pin;
    if(pin!=0)
    {
        const int result =remove(pnr);
        cout<<"Your ticket has been successfully cancelled !!"<<endl;
        system("pause");
        system("cls");
        heading();
    }
    else
    {
        cout<<"You need to book the ticket to cancel!"<<endl;
        system("pause");
        system("cls");
        heading();
    }
    myxfile.close();
    return 0;
}
//Get Route function
#define V 10
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}
void printPath(int parent[], int j)
{
    map<int,string>cities_1;
    cities_1[0]="amritsar";
    cities_1[1]="delhi";
    cities_1[2]="kanpur";
    cities_1[3]="kolkata";
    cities_1[4]="ahemdabad";
    cities_1[5]="mumbai";
    cities_1[6]="bhopal";
    cities_1[7]="hyderabad";
    cities_1[8]="banglore";
    cities_1[9]="chennai";
    if (parent[j]==-1)
        return;
    printPath(parent, parent[j]);
    cout<<" "<<cities_1[j];
}
int printSolution(int dist[], int n, int parent[],int src, int ch)
{
    map<int,string>cities_1;
    cities_1[0]="amritsar";
    cities_1[1]="delhi";
    cities_1[2]="kanpur";
    cities_1[3]="kolkata";
    cities_1[4]="ahemdabad";
    cities_1[5]="mumbai";
    cities_1[6]="bhopal";
    cities_1[7]="hyderabad";
    cities_1[8]="banglore";
    cities_1[9]="chennai";
    if(ch==1){
        cout<<"Distance\tPath";
    }else{
        cout<<"Cost\t\tPath";
    }
    for (int i = 0; i < V; i++)
    {
        cout<<"\n"<<dist[i]<<"\t\t"<<cities_1[src]<<" ";
        printPath(parent, i);
    }
}
void dijkstra(int graph[10][10], int src, int ch)
{
    int dist[V];
    bool sptSet[V];
    int parent[V];
    for (int i = 0; i < V; i++)
    {
        parent[src] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V-1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    printSolution(dist, V, parent,src, ch);
}
int get_route()
{
    system("cls");
    heading();
    int graph1[10][10]={{0,450,0,0,0,0,0,0,0,0},
                        {450,0,497,0,0,1415,784,0,0,0},
                        {0,497,0,1000,0,0,0,0,0,0},
                        {0,0,1000,0,0,1942,0,0,0,1669},
                        {0,0,0,0,0,523,584,0,0,0},
                        {0,1415,0,1942,523,0,0,0,983,0},
                        {0,784,0,0,584,0,0,850,0,0},
                        {0,0,0,0,0,0,850,0,0,0},
                        {0,0,0,0,0,983,0,0,0,346},
                        {0,0,0,1669,0,0,0,0,346,0}};
                        // distance
    int graph[10][10]={{0,970,0,0,0,0,0,0,0,0},
                        {970,0,855,0,0,2765,1765,0,0,0},
                        {0,855,0,1628,0,0,0,0,0,0},
                        {0,0,1628,0,0,3470,0,0,0,2565},
                        {0,0,0,0,0,1005,950,0,0,0},
                        {0,2765,0,3470,1005,0,0,0,2065,0},
                        {0,1765,0,0,950,0,0,1720,0,0},
                        {0,0,0,0,0,0,1720,0,1690,0},
                        {0,0,0,0,0,2065,0,1690,0,815},
                        {0,0,0,2565,0,0,0,0,815,0}};
                        // cost

    map<string,int>city;
    city["amritsar"]=0;
    city["delhi"]=1;
    city["kanpur"]=2;
    city["kolkata"]=3;
    city["ahemdabad"]=4;
    city["mumbai"]=5;
    city["bhopal"]=6;
    city["hyderabad"]=7;
    city["banglore"]=8;
    city["chennai"]=9;
    int ch=0;
    cout<<"1.BY DISTANCE\n2.BY MONEY"<<endl;
    cin>>ch;
    cout<<"Enter the source node\n";
    int src=0;
    string city_name="";
    cin>>city_name;
    cout<<"\n\n\n\n";
    src=city[city_name];
    if(ch==1)
        dijkstra(graph, src, ch);
    else
        dijkstra(graph1, src, ch);
    cout<<endl;
    system("pause");
    system("cls");
    heading();
    return 0;
}

//MAIN FUNCTION
int main()
{
    heading();
    int ch=10;
    while(ch)
    {
        cout<<"1.RESERVATION\n2.CANCELLATION\n3.GET A ROUTE\n0.EXIT\nENTER YOUR CHOICE : ";
        cin>>ch;
        if(ch==1)
            reservation();
        else if(ch==2)
            cancellation();
        else if(ch==3)
            get_route();
        else if(ch==0)
           {
               cout<<"\nTHANKYOU FOR USING OUR APPLICATION"<<endl;
               exit(0);
           }
        else
        {
            cout<<"\n\nINVALID INPUT"<<endl;
            Sleep(2000);
            system("cls");
            heading();
        }
    }
    system("pause");
}
