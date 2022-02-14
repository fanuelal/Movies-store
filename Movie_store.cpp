#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>

using namespace std;
//structure named movies
struct movies{
  char title[50];
  char gener[30];
  char type[30];
  int id;
  int rate;
  int price;
  movies *next;
};
struct movies *end = NULL;
struct movies *start = NULL;
//global variable
int countter=0;
int year = 14;

string attr[] = {"title","id","gener","rate","type","price"};
void insert_val(int);
void str_search(int j);
void int_search(int catagory);
void max_val();
void min_val();
void del_node(int);//processing
float sum();
void avarage();
void display();
void sort(int j);
int counter();
void home();
void insert_iterate();

int main(){
  //main function 
  home();
  getch();
}

void home(){
// home display the menu function  
int n,srch,srt,del,avg,key_i;
char key[30];
  system("cls");
  system("color 9b");
  cout<<"\t\t\tWelcome to movies center\n";
  i:
  cout<<"\n\t1. Insert Movie list\n\t2. Display List\n\t3. Search Movie \n\t4. Sort Movies \n\t5. Delete movie \n\t6. Calculate Avarage \n\t7. Minimum Rate \n\t8. Maximum Price\n\t9. Exit\t\nEnter your number: ";
  cin>>n;
  system("cls");
  //switch cases for the user choice 
  switch (n){
    case 1:
      insert_iterate();
      break;
    case 2:
      display();
      break;
      
    case 3:
      system("color 9b");
      cout<<"\n\n\t\t\t Search By: \n\t 1. Title\n\t 2. ID\n\t3. Gener \n\t4. Rate\n\t5. Back\n: ";
      cin>>srch;
      if (srch == 5){
        system("cls");
        goto i;
      }
      else{
      if(srch == 1 || srch == 3){
        str_search(srch); 
        }
      else if(srch == 2 || srch == 4){
          int_search(srch);
          
        }
        
      }
        
      break;
    case 4:
      system("color 9b");
      cout<<"\n\n\t\t\t Sort By:  \n\t 1. Title\n\t 2. ID\n\t3. Back\n: ";
      cin>>srt;
      if (srt == 3){
        system("cls");
        goto i;
      }
      else if (srt == 1 || srt == 2){
      	sort(srt);
	  }
     
      break;
    case 5:
      system("color 9b");
      cout<<"\n\n\t\t\t Delete : \n 1. First Element \n 2. Last Element \n 3. Minimum Rate \n 4. Maximum price\n5. Back\n: ";
      cin>>del;
      if (del == 5){
        system("cls");
        goto i;
      }
      else if(del == 1){
      	del_node(del);
	  }
	  else if (del == 2){
	  	del_node(del);
	  }
	  else if(del == 3){
	  	del_node(del);
	  }
	  else if(del==4){
	  	del_node(del);
	  }
      break;
    case 6:
      system("color 9b");
      avarage();
      break;
    case 7:
      system("color 9b");
      cout<<"Minimum rate value is: ";
      min_val();
      break;
    case 8:
      system("color 9b");
      cout<<"Maximmum price value is: ";
      max_val();
      break;
    case 9:
      system("color 9b");
      system("exit");
      break;
    default:
      cout<<"Incorrect input";
      system("color 4b");
      goto i;
      
  }
}
void insert_iterate(){
  system("color 9b");
  int size,i=1;
  cout<<"\n\t\t Number of movies to Insert\n:- ";
  cin>>size;
  while (i <= size){
  cout<<"============== Enter Movie "<<i<<" =============\n";
  insert_val(i);
  i++;
}
  char close_key;
  cout<<"\t\tFinished Inserting \n\t\t Back to Menu(Enter Any Letter): ";cin>>close_key;
  system("cls");
  home();
}
void insert_val(int i){
  system("color 9b");
  movies *a = new movies;

  //string ard[]={"First","Second","Third","Forth","Fiveth"}
    cout<<"Title: ";cin>>a->title;
    cout<<"Gener: ";cin>>a->gener;
    cout<<"Price: ";cin>>a->price;
    cout<<"Rate: ";cin>>a->rate;
    a->id = i;
    cout<<"Type (press 'f' for Fictional or 'n' for Non fictional movies): ";
    cin>>a->type;
    
    if (start==NULL){
    start = a;
    }
    else{
      movies *j = start;
      while(j->next != NULL){
        j = j->next;
      }
      j->next = a;
    }
    a->next = NULL;
    
    system("cls");
}
void display(){
  char chose;
  if (start == NULL)
    cout<<"Empty List";
  else{
    cout<<"\n\n\t\t\tShowing all\n";
    cout<<"\tTitle   | Gener | Price | Rate\t |    Id\t | Type\n";
  for(movies *node = start;node != NULL;node = node->next){
    cout<<"\t  "<<node->title<<"\t  "<<node->gener<<"\t  "<<node->price<<"\t  "<<node->rate<<"  \t   "<<"mv-"<<year<<"-"<<node->id<<"\t    "<<node->type<<"\n";
    
  }
  
  }
  cout<<"\nEnter any letter for Back: ";cin>>chose;
  system("cls");
  home();
}
void str_search(int j){
  movies *i;
  bool check=false;
  char key[40];
  cout<<"Enter your keyword: ";
  cin>>key;
  if (j == 1){
  for(i=start;i != NULL;i=i->next){
    int res = strcmp(i->title,key);
    if( res == 0){
      check = true;
    cout<<"Title: "<<i->title<<"\n";
    cout<<"Gener: "<<i->gener<<"\n";
    cout<<"Price: "<<i->price<<"\n";
    cout<<"Rate: "<<i->rate<<"\n";
    cout<<"Id: mv-"<<year<<"-"<<i->id<<endl;
    cout<<"Type: "<<i->type<<"\n";
    cout<<"--------------------------------------\n";
    }
  }}
  else if (j == 3){
    for(i=start;i != NULL;i=i->next){
    int res = strcmp(i->gener,key);
    if( res == 0){
      check = true;
    cout<<"Title: "<<i->title<<"\n";
    cout<<"Gener: "<<i->gener<<"\n";
    cout<<"Price: "<<i->price<<"\n";
    cout<<"Rate: "<<i->rate<<"\n";
    cout<<"Id: mv-"<<year<<"-"<<i->id<<endl;
    cout<<"Type: "<<i->type<<"\n";
    cout<<"--------------------------------------\n";
    }
  }
  }
    if(check == false){
    cout<<"'"<<key<<"'"<<" Not found!\n";}
    char back;
    cout<<"Back to main Menu(press any key): ";cin>>back;
    home();
}
void int_search(int j){
    movies *i;
  bool check=false;
  int key;
  cout<<"Enter your keyword: ";
  cin>>key;
  if (j == 2){
  for(i=start;i != NULL;i=i->next){
    
    if( i->id == key){
      check = true;
    cout<<"Title: "<<i->title<<"\n";
    cout<<"Gener: "<<i->gener<<"\n";
    cout<<"Price: "<<i->price<<"\n";
    cout<<"Rate: "<<i->rate<<"\n";
    cout<<"Id: mv-"<<year<<"-"<<i->id<<endl;
    cout<<"Type: "<<i->type<<"\n";
    cout<<"--------------------------------------\n";
    }
  }}
  else if (j == 4){
    for(i=start;i != NULL;i=i->next){
    
    if(i->rate == key){
      check = true;
    cout<<"Title: "<<i->title<<"\n";
    cout<<"Gener: "<<i->gener<<"\n";
    cout<<"Price: "<<i->price<<"\n";
    cout<<"Rate: "<<i->rate<<"\n";
    cout<<"Id: mv-"<<year<<"-"<<i->id<<endl;
    cout<<"Type: "<<i->type<<"\n";
    cout<<"--------------------------------------\n";
    }
  }
  }
    if(check == false){
    cout<<"'"<<key<<"'"<<" Not found!\n";}
    char back;
    cout<<"Back to main Menu(press any key): ";cin>>back;
    home();
}
void sort(int j){
	char c;
	if (j == 1){
		for(movies *i = start;i != NULL;i=i->next){
			for(movies *k = start;k != NULL;k=k->next){
			int res = strcmp(i->title,k->title);
			if(res < 0){
			movies *z;
			strcpy(z->title,i->title);
				strcpy(z->title, i->title);
				strcpy(i->title,k->title);
				strcpy(k->title,z->title);
			}
			}
		
		}
		cout<<"\n\t\t\tSorted Successfully\n";
		display();
		cout<<"Enter any letter: ";
		cin>>c;
		
	}
	else if(j == 2){
		for(movies *i = start;i != NULL;i=i->next){
			for(movies *k = start->next;k != NULL;k=k->next){
			
			if(i->id < k->id){
				movies *z;
				z->id=i->id;
				i->id=k->id;
				k->id=z->id;
			}
			}
		
		}
		cout<<"\n\t\t\tSorted Successfully\n";
		display();
		cout<<"Enter any letter: ";
		cin>>c;
	}
}
void del_node(int i){
	//delete the node what min val,nth node, searched item
	switch (i){
	case 1:
		if(start == NULL){
			cout<<"Empty lIST FOUND";
		}
		else {
		movies *i = NULL;
		i = start;
		start = i->next;
		i->next = NULL;
		i = NULL;
		display();
	}
	break;
	case 2:
		movies *i;
		movies *j;
		if(start == NULL){
			cout<<"Empty lIST FOUND";
		}
		else{
		
		for(i=start,j=start->next;j!=NULL;i=i->next,j=j->next){
			if(j->next == NULL){
				i->next = NULL;
				j = NULL;
				break;
			}
			end = end->next;
		}
		display();
		}
	break;
	case 3:
	movies *index;
	movies *min=start;
	movies *jval;
	int val;
	char c;
	char close;

for(index=start;index!=NULL;index=index->next){
		
		if(min->rate > index->rate){
			min = index;
		}
}	


/*if (min->next == NULL){
	min = NULL;
	cout<<min;
	cout<<"you have deleted node with rate value: "<<min->rate<<endl;
	char close;
	cout<<"\nTO return press any key: ";cin>>close;
	display();}*/
	
		for(movies *j=start;j!=NULL;j=j->next){
		cout<<"dersual j\n";	
		if(j->next == min){
			cout<<"dersual if statement\n";
			j->next = NULL;
			j->next = min->next;
			min->next = NULL;
			//cout<<"dersual final if sta\n";
			min = NULL;
	//cout<<"you have deleted node with rate value: "<<min->rate<<endl;
	cout<<"TO return press any key: ";cin>>close;
	display();
			break;
		}
		
	}

	
break;
//case 4:
//	cout<<"case 4";	
//	break;
//default:
		
	//break;
	
}}
//counter function
int counter(){
	for(movies *i = start; i!=NULL;i=i->next){
	countter+=1;
	}
	return countter;
}
//sum return function
float sum(){
	int result=0l;
	for(movies *i = start; i!=NULL;i=i->next){
		result+=i->price;
	}
	return result;
}
//avarage function
void avarage(){
	char c;
	float avg;
	float total= sum(),num=counter();
	avg = total/num;
	cout<<"\n\n\t\t\tAverage of Movies: "<<avg<<"\n";
	cout<<"Press any key for back: ";cin>>c;
	home();
}
//mac value of the list
void max_val(){
	movies *i;
	movies *j;
	movies *max=start;
	//movies *z;
	int val=0;
	char c;
	for(i=start->next;i!=NULL;i=i->next){
		if(max->price < i->price){
			val = i->price;
			max = i;
		}
		val = max->price;
	}
	
	cout<<val<<"$\n";
	cout<<"Press any key for back: ";cin>>c;
	home();
}
void min_val(){
	movies *i;
	movies *j;
	movies *min=start;
	//movies *z;
	int val=0;
	char c;
	for(i=start->next;i!=NULL;i=i->next){
		if(min->rate > i->rate){
			val = i->rate;
			min = i;
		}
		/*else if (i->rate < j->rate){
			val = i->rate;
			min = i;
		}*/
		val = min->rate;
	}
	cout<<val<<" \n";
	cout<<"Press any key for back: ";cin>>c;
	home();
}
