#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <ctime>
using namespace std;
class snode{
	public:
		string data;
		snode *next;
		snode()
		{
			next = NULL;
		}
		snode(string x)
		{
			data = x;
			next = NULL;
		}
};
class stackll
{
	public:
		snode *top;
		stackll()
		{
			top = NULL;
		}
		void push(string x)
		{
			snode *n = new snode(x);
			if(top == NULL)
			{
				top = n;
				return;
			}
			n->next = top;
			top = n;
		}
		string pop()
		{
			if(top == NULL)
			{
				cout << "Top is Empty!" << endl;
				return 0;
			}
			string temp = top->data;
			snode *t = top;
			top = top->next;
			delete t;
			return temp;
		}
		string peek()
		{
			if(top == NULL)
			{
				cout << "Top is Empty!" << endl;
				return 0;
			}
			string temp = top->data;
			return temp;
		}
		bool isEmpty()
		{
			return(top==NULL);
		}
};
class Node
{
	public:
		string str;
		Node* next;
		Node(string str)
		{
			this->str = str;
			this->next = NULL;
		}
};

class LinkedList
{
	public:
		Node* head = NULL;
		int length;
		LinkedList()
		{
			length = 0;
		}
		void insert(string data)
		{
			Node *NextNode = new Node(data);
			if(head == NULL)
			{
				head = NextNode;
				length++;
			}
			else
			{
				Node *temp = head;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = NextNode;
				length++;
			}
		}
        void Delete(int index)
		{
			int count=1;
			Node *temp = head;
			if(count==index)
			{
				head = temp->next;
				length--;
			}
			else if(index<length)
			{
				Node *temp1;
				while(temp->next!=NULL)
				{
					if(count==index-1)
					{
						temp1 = temp->next;
						temp->next = temp1->next;
						length--;
						break;
					}
					temp = temp->next;
					count++;
					
				}
			}
			else if(index==length)
			{
				while(temp->next!=NULL)
				{
					if(count==index-1)
					{
						temp->next = NULL;
						length--;
						break;
					}
					temp = temp->next;
					count++;
					
				}
			}
			else
			{
				cout<<"Index Not Found"<<endl;
			}
		}
		void reverse()
		{
			Node *curent = head;
			Node *prev = NULL;
			Node *nextnode = head;
			
			if(nextnode==NULL)
			{
				cout<<"there is No node \n";
			}
			else
			{
				while(nextnode != NULL)
				{
					nextnode = nextnode->next;
					curent->next = prev;
					prev = curent;
					curent = nextnode;
				}
				head = prev;
			}	
		}
		void print()
		{
			Node* temp = head;
			while(temp!=NULL)
			{
				cout<<temp->str<<endl;
				temp = temp->next;
			}
			cout<<endl;
		}
        void savedata()
        {
            Node * temp = head;
            fstream os,ob;
            ob.open("Routes.txt");
                os.open("Routes.txt",ios::app);
                while (temp->next!=NULL)    
                {
                    os<<temp->str<<"-";
                    temp = temp->next;
                }
                os<<temp->str<<endl;
                os.close();
        }
};

class Dijistra
{
    public:
        int a;
        string names[100];
        int size;
        float** arr;
        float* dist;
        int* distance;
        Dijistra()
        {

        }
        
        void Safearray(float **arr,string names[])
        {
            for(int i=0;i<size;i++)
            {
                arr[i] =new float[size];
                cout<<"Enter the Name of the Stop: ";
                cin>>names[i];
            }
            cout<<"\nEnter the Adjacent Matrix for Stops: \n";
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    // if(i==j)
                    // {
                    //     *(*(arr+i)+j) = 0;
                    //     continue;
                    // }
                    // else
                    // {
                    //     cin>>*(*(arr+i)+j);
                    // }
                    cin>>*(*(arr+i)+j);
                }
            }
        }
        int verifyarray(float **arr)
        {
            int flag=0;
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    if(*(*(arr+i)+j)==0)
                    {
                        continue;
                    }
                    else
                    {
                        if(*(*(arr+i)+j)==*(*(arr+j)+i))
                        {
                            flag = 0;
                        }
                        else
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag == 1)
                {
                    break;
                }
            }
            if(flag==1)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        int minDistance(float dist[], bool sptSet[])
        {
            float min = 1000, min_index;
        
            for (int v = 0; v < size; v++)
                if (sptSet[v] == false && dist[v] <= min)
                    min = dist[v], min_index = v;
        
            return min_index;
        }
        int printSolution(float dist[])
        {	
        	distance = new int[size];
            printf("Vertex \tDistance from Source\n");
            for (int i = 0; i < size; i++){
                printf("%d \t\t %.1f\n", i, dist[i]);
                distance[i] = (int)dist[i];
            }
        }
        void setSeats()
        {
            fstream ob;
            ob.open("Seats.txt",ios::app);
            ob<<60<<endl;
        }
//         void showmap(){
//        	int gd = DETECT, gm;
//    		initwindow(1000,1000);
////    		int distance[size];
////    		for(int i=0;i<size;i++)
////    			distance[i] = (int)dist[i];
//			for(int i=0; i<size/2;i++){
//					cout<<"Stop#"<<i;
//					line(distance[i],distance[i],distance[i+1],distance[i+1]);
//					cout<<"Stop#"<<i+1;
//			}
//    		_getch();
//   	 		closegraph();
//		}
        void setRoute(float dist[],bool ptr1[],int arr[],int index)
        {
            LinkedList ob,Tob;
            float *ptr = dist;
            for (int i = 0; i < size; i++)
            {
                ptr1[i] = false;
            }
            ptr1[index] = true;
            int ind = index;
            ob.insert(names[index]);
            for(int i=0;i<size;i++)
            {
                if(i==index)
                {
                    continue;
                }
                float min = 1000;
                int index1;
                for (int j = 0; j < size; j++)
                {
                    if(ptr[j]==0 || ptr1[j] == true)
                    {
                        continue;
                    }
                    if(min>ptr[j])
                    {
                        min = ptr[j];
                        index1 = j;
                    }
                }
                ptr1[index1] = true;
                ob.insert(names[index1]);
            }
            ob.print();
            int number;
            int k=0;
            float Time1,Time2=0,Time22=0;
            char str[20];
			Node* temp = ob.head;
			string time;
			cout<<"Enter the Time in 24 hour Format: \n";
            cout<<"Enter the arrival time for Stop "<<temp->str<<": ";
			cin>>time;
            Tob.insert(time);
            temp = temp->next;
			while (temp!=NULL)
			{
                for (int  j = 0; j < size; j++)
                {
                    if(temp->str==names[j])
                    {
                        number = j;
                        break;
                    }
                }
                Time22 = Time2;
                Time1 = (dist[number])*1.5;
                Time1 -= Time2;
				Time2 = Time1;
                arr[k] = Time1;
                k++;
                int c = time[3] - 48;
                c*=10;
                c += time[4] - 48;
                int d = Time1 + c;
                if(d>59)
                {
                    int mod = d/60;
                    int z = d;
                    int mod1 = z%60;
                    int a = time[0] - 48;
                    a *= 10;
                    a += time[1] - 48;
                    a += mod;
                    time[0] = a/10 + 48;
                    time[1] = a%10 + 48;
                    time[3] = mod1/10 + 48;
                    int b = mod1;
                    time[4] = b%10 + 48;
                }
                else
                {
                    time[3] = d/10 + 48;
                    int b = d;
                    time[4] = b%10 + 48;
                }
				Tob.insert(time);
				temp = temp->next;
			}
            ob.savedata();
			Tob.savedata();
            setSeats();
			ob.reverse();
			// Tob.reverse();
            LinkedList Tob1;
            
            int number1;
            float Time11;
            char str1[20];
			Node* temp1 = ob.head;
			string time1 = time;
			// cin>>time1;
            Tob1.insert(time1);
            temp1 = temp1->next;
			while (temp1!=NULL)
			{
                k--;
                Time11 = arr[k];
                // Time22 = Time11;
                int c = time1[3] - 48;
                c*=10;
                c += time1[4] - 48;
                int d = Time11 + c;
                if(d>59)
                {
                    int mod = d/60;
                    int z = d;
                    int mod1 = z%60;
                    int a = time1[0] - 48;
                    a *= 10;
                    a += time1[1] - 48;
                    a += mod;
                    time1[0] = a/10 + 48;
                    time1[1] = a%10 + 48;
                    time1[3] = mod1/10 + 48;
                    int b = mod1;
                    time1[4] = b%10 + 48;
                }
                else
                {
                    time1[3] = d/10 + 48;
                    int b = d;
                    time1[4] = b%10 + 48;
                }
				Tob1.insert(time1);
				temp1 = temp1->next;
			}
            setSeats();
			ob.savedata();
			Tob1.savedata();
        }
        void Shortest_path(float dist[],bool sptSet[],float **arr,bool ptr1[],int arr1[],int src)
        {
            for (int i = 0; i < size; i++)
            dist[i] = 1000, sptSet[i] = false;
            dist[src] = 0;
            for (int count = 0; count < size- 1; count++) 
            {
                int u = minDistance(dist, sptSet);
                sptSet[u] = true;
                for (int v = 0; v < size; v++)
                    if (!sptSet[v] && arr[u][v] && dist[u] != 1000
                        && dist[u] + arr[u][v] < dist[v])
                        dist[v] = dist[u] + arr[u][v];
            }
            printSolution(dist);
            setRoute(dist,ptr1,arr1,src);
        }
        void DijistraAlgo()
        {
            int size1;
            cout<<"Enter Number of Stops :";
            cin>>size1;
            size = size1;
            arr = new float*[size1];
            dist = new float[size1];  
            bool *sptSet = new bool[size1];
            bool *ptr1 = new bool[size];
            int *arr1 = new int[size];
            Safearray(arr,names);
            if(verifyarray(arr)==1)
            {
                string a;
                int index;
                cout<<"Enter the Starting position: ";
                cin>>a;
                for(int i=0;i<size;i++)
                {
                    if(a==names[i])
                    {
                        index = i;
                        break;
                    }
                }
                Shortest_path(dist,sptSet,arr,ptr1,arr1,index);
            }
            else
            {
                cout<<"Wrong Input of Routes' Distance: \n";
            }
        }
       
        void choice()
		{
			system("CLS");
			cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t       Karachi Metro \n\n";
   			cout<<"\t\t\t\t\t------------------------------";
   			cout<<"\n\t\t\t\t\t    1.Add Route \n";		
   			cout<<"\n\t\t\t\t\t    2.Delete Route \n";
   			cout<<"\n\t\t\t\t\t    3.Print all Routes \n";
   			cout<<"\n\t\t\t\t\t    4.Revenue \n";
   			cout<<"\n\t\t\t\t\t    5.Records \n";
   			cout<<"\n\t\t\t\t\t    6.Back \n";
   			cout<<"\t\t\t\t\t------------------------------";
			cout<<"\n\t\t\t\t\t-> : ";
			cin>>a;
		}
        int geta()
		{
			return a;
		}
};

char *current_time()
{
	time_t curr_time;
	curr_time = time(NULL);

	char *tm = ctime(&curr_time);
	
	return tm;
}

class login
{
    char ch;
    int a,tickets,bill;
    public:
        login()
        {
            bill = 0;
        }
		void choice()
		{
			cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t       Karachi Metro  \n\n";
   			cout<<"\t\t\t\t\t------------------------------";
   			cout<<"\n\t\t\t\t\t    1.See The Routes \n";		
   			cout<<"\n\t\t\t\t\t    2.Book the Tickets \n";
   			cout<<"\n\t\t\t\t\t    3.Back \n";
   			cout<<"\t\t\t\t\t------------------------------";
			cout<<"\n\t\t\t\t\t-> : ";
			cin>>a;
		}
        int geta()
		{
			return a;
		}
        void choice1()
        {
            cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t       Karachi Metro \n\n";
            cout<<"\t\t\t\t\t------------------------------";
            cout<<"\n\t\t\t\t\t    1.Employee \n";		
            cout<<"\n\t\t\t\t\t    2.Customer \n";
            cout<<"\t\t\t\t\t------------------------------";
            cout<<"\n\t\t\t\t\t-> : ";
            cin>>a;
        }
        void PrintALLRoutes()
        {
        	stackll st2;
            int i=1;
            string str1,str2;
            fstream ob;
            ob.open("Routes.txt",ios::in);
            cout<<"Routes and their Timings: \n";
            while (!ob.eof())
            {   
                getline(ob,str1);
                getline(ob,str2);
                if(ob.eof()==1)
                {
                    break;
                }
//                cout<<i<<"."<<str1<<endl;
//                cout<<"  "<<str2<<endl;
//                i++;
				st2.push(str2);
				st2.push(str1);
            }
            
            while(!(st2.isEmpty())){
            	cout<<"\n"<<i<<st2.pop()<<"\t"<<st2.pop();
			}
        }
        void BookTickets()
        {
            string str1,str2,str3,str4,str5;
            string str6[10],time3[10];
            string time1,time2;
            int j=0,k=0,count=0,index=0,flag=0,index1=0,ss=0;
            cout<<"From which Stop you want to pick the Metro Bus: ";
            cin>>str1;
            cout<<"At which Stop you want to leave: ";
            cin>>str2;
            fstream ob;
            ob.open("Routes.txt",ios::in);
            while(!ob.eof())
            {
                ss++;
                j=0;
                count=0;
                getline(ob,str3);
                getline(ob,str4);
                if(ob.eof()==1)
                {
                    break;
                }
                int size = str3.size();
                int size2 = str4.size();
                for (int i = 0; i < size; i++)
                {
                    if(str3[i]=='-')
                    {
                        str6[j] = str5;
                        str5.clear();
                        j++;
                        count++;
                    }
                    else
                    {
                        str5 += str3[i];
                    }
                    if(i==size-1)
                    {
                        str6[j] = str5;
                        j++;
                        count++;
                        str5.clear();
                        break;
                    }
                }
                j=0;
                k=0;
                for (int i = 0; i < size2; i++)
                {
                    if(str4[i]=='-')
                    {
                        time3[j] = time1;
                        j++;
                        time1.clear();
                    }
                    else
                    {
                        time1  += str4[i];
                    }
                    
                    if(i==size2-1)
                    {
                        time3[j] = time1;
                        j++;
                        time1.clear();
                        break;
                    }
                }
                
                for (int i = 0; i < count-1; i++)
                {
                    if(str1==str6[i])
                    {
                        index = i;
                        flag=1;
                        break;
                    }
                    else
                    {
                        flag = 0;
                    }
                }
                if(flag==0)
                {
                    continue;
                }
                for (int i = index+1; i < count; i++)
                {
                    if(str2==str6[i])
                    {
                        index1 = i;
                        flag=1;
                        break;
                    }
                    else
                    {
                        flag = 0;
                    }
                }
                if(flag==1)
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
            if(flag==1)
            {
                fstream os,ox;
                string seats;
                os.open("Seats.txt",ios::in);
                ox.open("Records.txt",ios::app);
                string bill1;
                int size3,i=1;
                string name3;
                cout<<"Enter your Name: ";
                cin>>name3;
                cout<<"How many Tickets do you need: ";
                cin>>tickets;
                ox<<name3<<endl<<tickets<<endl<<current_time();
                ox.close();
                for (int i = 1;!os.eof(); i++)
                {
                    getline(os,seats);
                    if(i==ss)
                    {
                        break;
                    }
                }
                os.close();
                int a = seats.size(),Se=0;
                int we = 10;
                for (int b = 0; b < a; b++)
                {
                    Se += (seats[b] - 48)*we;
                    we/=10;
                }
                if(tickets<=Se)
                {
                    fstream ob2,ob1,os1,os2,os3,os4;
                    ob1.open("Revenu.txt",ios::in);
                    ob2.open("Revenu.txt",ios::out);
                    os2.open("SeatsDuplicate.txt",ios::out);
                    os1.open("Seats.txt",ios::in);
                    getline(ob1,bill1);
                    ob1.close();
                    size3 = bill1.size();
                    i=1;
                    for (int x = 0; x < size3-1; x++)
                    {
                        i*=10;
                    }
                    
                    for (int j = 0; j < size3; j++)
                    {
                        bill += (bill1[j] - 48)*i;
                        i/=10;
                    }
                    bill += tickets*100;
                    ob2<<bill;
                    cout<<"The bill is "<<tickets*100<<endl;
                    Se -= tickets;
                    string str10,str11;
                    cout<<"\nYour Route: "<<str3<<" "<<str4;
                    for (int z = 1; !os1.eof(); z++)
                    {
                        getline(os1,str10);
                        if(z==ss)
                        {
                            os2<<Se<<endl;
                        }
                        else
                        {
                            os2<<str10<<endl;
                        }
                    }
                    os1.close();
                    os2.close();
                    ob2.close();
                    os3.open("SeatsDuplicate.txt",ios::in);
                    os4.open("Seats.txt",ios::out);
                    for (int z = 1;!os3.eof(); z++)
                    {
                        getline(os3,str10);
                        if(str11==str10)
                        {
                            break;
                        }
                        os4<<str10<<endl;
                    }
                    os3.close();
                    os4.close();
                
				}
                else
                {
                    cout<<"Seats Are not available that you need: \n";
                }
            }
            else
            {
                cout<<"Metro Bus Doesn't follow Route accordinly your input\n";
            }

        }
};

class MangeRoutes
{
    public:
        MangeRoutes()
        {

        }
        void DeleteRoute()
        {
            int a;
            fstream ob1,ob2,os1,os2;
            string str,str2;
            ob1.open("Routes.txt",ios::in);
            os1.open("Seats.txt",ios::in);
            ob2.open("RoutesDuplicate.txt",ios::out);
            os2.open("SeatsDuplicate.txt",ios::out);
            PrintALLRoutes();
            cout<<"Enter the Route Number That you want to delete: ";
            cin>>a;
            for(int i=1;!ob1.eof();)
			{
				if(i==a)
				{
					i++;
					getline(ob1,str);
					getline(ob1,str);
					getline(ob1,str);
					getline(ob1,str);
                    getline(os1,str);
					continue;
				}
                if(ob1.eof()==1)
                {
                    break;
                }
				else if(i!=a)
				{
                    i++;
                    getline(os1,str);
                    os2<<str<<endl;
					getline(ob1,str);
					ob2<<str<<endl;
					getline(ob1,str);
					ob2<<str<<endl;
					getline(ob1,str);
					ob2<<str<<endl;
					getline(ob1,str);
					ob2<<str<<endl;
                    str2 = str;
				}

			}
			ob1.close();
			ob2.close();
			os1.close();
			os2.close();
            fstream ob3,ob4,os3,os4;
            ob3.open("RoutesDuplicate.txt",ios::in);
            os3.open("SeatsDuplicate.txt",ios::in);
            ob4.open("Routes.txt",ios::out);
            os4.open("Seats.txt",ios::out);
            for(int i=1;!ob3.eof();i++)
			{
				getline(ob3,str);
                if(str==str2)
                {
                    break;
                }
				ob4<<str<<endl;
			}
            for(int i=1;!os3.eof();i++)
			{
				getline(os3,str);
                if(str==str2)
                {
                    break;
                }
				os4<<str<<endl;
			}
			ob3.close();
			ob4.close();
			os3.close();
			os4.close();
        }
        void PrintALLRoutes()
        {
            int i=1;
            string str1,str2,str3,str4;
            fstream ob;
            ob.open("Routes.txt",ios::in);
            while (!ob.eof())
            {   
                getline(ob,str1);
                getline(ob,str2);
                getline(ob,str3);
                if(ob.eof()==1)
                {
                    break;
                }
                getline(ob,str4);
                cout<<i<<"."<<str1<<" And ";
                cout<<str3<<endl;
                i++;
            }
            
        }
        void PrintRoutesWithSeatsRem()
        {
            int i=1;
            string str1,str2,str3,str4,str5;
            fstream ob,os;
            ob.open("Routes.txt",ios::in);
            os.open("Seats.txt",ios::in);
            while (!ob.eof())
            {   
                getline(ob,str1);
                getline(ob,str2);
                getline(ob,str3);
                if(ob.eof()==1)
                {
                    break;
                }
                getline(ob,str4);
                getline(os,str5);
                cout<<i<<"."<<str1<<" With Remaining Seats: "<<str5<<" And ";
                getline(os,str5);
                cout<<str3<<" With Remaining Seats: "<<str5<<endl;
                i++;
            }
            ob.close();
            os.close();
        }
};

class Employee_Login
{
    string name1,pass1;
    char ch;
    int a;
	public:
		int b;
		Employee_Login()
		{
            name1 = "admin";
            pass1 = "admin";
		}
        int signin()
		{
			int i=0,j=0,k=0,l=0;
			string name,psd;
			char pass[100],c;
			cout<<"Enter the username: ";
			cin>>name;
			cout<<"Enter the password: ";
   			for(int l=0;;)
	    	{
	    		char a;
			   	a= _getch();
		       	if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
			    {
				   	pass[l]=a;
			    	++l;
			    	cout<<"*";
			    }
				if(a=='\b'&&l>=1)
			    {
			       	cout<<"\b \b";
			        --l;
				}
			    if(a=='\r')
			    {
			        pass[l]='\0';
		           	break;
		       	}            	
            }
            cout<<endl;
            string str1,str2;
			if(name==name1)
			{
				if(pass==pass1)
               {
					cout<<"\nLogin Successful";
					cout<<"\nPress any key to move forward!";
					ch = _getch();
					cout<<endl;
					return 1;
				}
				else
                {
					cout<<"\nIncorrect Password!";
					return 0;
				}
			}
			cout<<"Username doesn't Match"<<endl;
			return 0;
		}
		void choice()
        {
            system ("CLS"); 
            cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t       Karachi Metro  \n\n";
            cout<<"\t\t\t\t\t------------------------------";		
            cout<<"\n\t\t\t\t\t    1.Login \n";
            cout<<"\n\t\t\t\t\t    2.Back \n";
            cout<<"\t\t\t\t\t------------------------------";
            cout<<"\n\t\t\t\t\t-> : ";
            cin>>a;
        }
		int geta()
		{
			return a;
		}
        void RevenuGenerated()
        {
            fstream ob;
            ob.open("Revenu.txt");
            string str;
            getline(ob,str);
            cout<<"Revenu Generated: "<<str<<endl;
        }
        void ViewRecords()
        {
        	stackll st;
            fstream ob;
            string str1,str2,str3;
            ob.open("Records.txt",ios::in);
            for (int i = 1; !ob.eof() ; i++)
            {
                getline(ob,str1);
                if(str1=="")
                {
                    break;
                }
                getline(ob,str2);
                getline(ob,str3);
//                cout<<i<<". "<<" Name: "<<str1<<endl;
//                cout<<"No of Tickets: "<<str2<<endl;
//                cout<<"Time: "<<str3<<endl;
				st.push(str3);
				st.push(str2);
				st.push(str1);
            }
            ob.close();
            while(!(st.isEmpty())){
            	cout<<"\n";
            	cout<<"User: ";
				cout<<st.pop();
				cout<<"\nTickets: ";
            	cout<<st.pop();
            	cout<<"\nTime of booking: ";
            	cout<<st.pop();
            	cout<<"\n---------------------";
			}
        }
};

int main()
{
    int a,i=0,b,in;
    char ch;
	login ob1;
    Employee_Login ob2;
	Dijistra ob;
    MangeRoutes ob3;
    go1:
    ob1.choice1();
    system ("CLS");
    if(ob1.geta()==2)
	{
		go:
		system ("CLS"); 
		ob1.choice();
		if(ob1.geta()==1)
		{
			// ob1.create_account();
			 system ("CLS");
            ob1.PrintALLRoutes();
            cout<<"\nPress any key to move forward!";
			ch = _getch();
			cout<<endl; 
			goto go;
		}
		else if(ob1.geta()==2)
		{
			system ("CLS");
            ob1.BookTickets();
            cout<<"\nPress any key to move forward!";
			ch = _getch();
			cout<<endl;
            goto go;
        }
        else if(ob1.geta()==3)
		{
			system ("CLS");
			goto go1;
		}
    }
    else if(ob1.geta()==1)
    {
        so:
        ob2.choice();
        if(ob2.geta()==1)
        {
            if(ob2.signin()==1)
			{
				system ("CLS");
                Su:
                ob.choice();
                if(ob.geta()==1)
                {
                	system ("CLS");
                    ob.DijistraAlgo();
                    cout<<"\nPress any key to move forward!";
					ch = _getch();
					cout<<endl;
                    goto Su;
                }
				else if(ob.geta()==2)
                {
                	system ("CLS");
                    ob3.DeleteRoute();
                    cout<<"\nPress any key to move forward!";
					ch = _getch();
					cout<<endl;
                    goto Su;
                }
                else if(ob.geta()==3)
                {
                	system ("CLS");
                    ob3.PrintRoutesWithSeatsRem();
                    cout<<"\nPress any key to move forward!";
					ch = _getch();
					cout<<endl;
                    goto Su;
                }
                else if(ob.geta()==4)
                {
                	system ("CLS");
                    ob2.RevenuGenerated();
                    cout<<"\nPress any key to move forward!";
					ch = _getch();
					cout<<endl;
                    goto Su;
                }
                else if(ob.geta()==5)
                {
                	system ("CLS");
                    ob2.ViewRecords();
                    cout<<"\nPress any key to move forward!";
					ch = _getch();
					cout<<endl;
                    goto Su;
                }
                else if(ob.geta()==6)
                {
                	system ("CLS");
                    goto so;
                }
			}
        }
        else
        {
            system ("CLS");
            goto go1;
        }
    }
    return 0;
    
}
