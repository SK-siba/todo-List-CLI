#include <iostream>
using namespace std;
#include<string>
#include<fstream>
#include <ctime>
int main(int argc, char* argv[])
{
    
    ofstream fout;
    ifstream fin;
    if(argc>1)
    {
    string s=argv[1];
    if(s=="help")
    {
        cout<<"Usage :-"<<endl;
        cout<<"$ ./todo add ";
        cout<<"\"todo item\"";
        cout<<"  # Add a new todo";
        cout<<endl;
        cout<<"$ ./todo ls               # Show remaining todos";
        cout<<endl;
        cout<<"$ ./todo del NUMBER       # Delete a todo\n";
        cout<<"$ ./todo done NUMBER      # Complete a todo\n";
        cout<<"$ ./todo help             # Show usage\n";
        cout<<"$ ./todo report           # Statistics\n";
    }
    else if(s=="add")
    {
        if(argc==3)
        {
        fout.open ("todo.txt",ios::app); // Append mode
        string line=argv[2];
        fout<<line+"\n";
        line="\""+line+"\"";
        fout.close();
        cout<<"Added todo:"<<" "<<line<<endl;
        }
        else
        {
            cout<<"Error: Missing todo string. Nothing added!"<<endl;
        }
        
    }
    else if(s=="ls")
    {
       fin.open("todo.txt"); 
        int c=1;
        string line="";
        string final="";
    // Execute a loop until EOF (End of File) 
        while (fin) { 
  
        // Read a Line from File 
            getline(fin, line); 
  
        // Print line in Console
            if(line!="") 
            final="["+to_string(c)+"]" +" "+line+"\n"+final;
            c++; 
        } 
        if(final!="")
        cout<<final;
        else
        {
            cout<<"There are no pending todos!"<<endl;
        }
        
  
    // Close the file 
        fin.close(); 
    }
    else if(s=="del")
    {
        if(argc==3)
        {
        int del=atoi(argv[2]);
        fin.open("todo.txt"); 
        int c=1;
        if(del==0)
        cout<<"Error: todo #0 does not exist. Nothing deleted."<<endl;
        else
        {
        string line="";
        fout.open ("todo_temp.txt",ios::app); // Append mode
    // Execute a loop until EOF (End of File) 
        while (fin) { 
  
        // Read a Line from File 
            getline(fin, line); 
            if(line!="")
            {
                if(c!=del)
                {
                    
                    fout<<line+"\n";
                    
                }
            }
           
            c++; 
        }
        if(del>=c-1)
        cout<<"Error: todo #"<<del<<" does not exist. Nothing deleted."<<endl;
        else
        {
            cout<<"Deleted todo #"<<del<<endl;
        }
        
        fin.close();
        fout.close();
        remove("todo.txt");
        rename("todo_temp.txt","todo.txt"); 
    }
    }
    else
    {
        cout<<"Error: Missing NUMBER for deleting todo."<<endl;
    }
    
    }
    else if(s=="done")
    {
        if(argc==3)
        {
        int done=atoi(argv[2]);
        fin.open("todo.txt"); 
        int c=1;
        if(done==0)
        cout<<"Error: todo #0 does not exist."<<endl;
        else
        {
        string line="";
        fout.open ("done.txt",ios::app); // Append mode
    // Execute a loop until EOF (End of File) 
        while (fin) { 
  
        // Read a Line from File 
            getline(fin, line); 
            if(line!="")
            {
                if(c==done)
                {
                    
                    fout<<line+"\n";
                    cout<<"Marked todo #"<<done<<" as done."<<endl;
                    
                }
        
                
            }
           
            c++; 
        }
   
       
            
        
        
        fin.close();
        fout.close();




        fin.open("todo.txt");
        c=1;
         line="";
        fout.open ("todo_temp.txt",ios::app); 
        while (fin) { 
  
        // Read a Line from File 
            getline(fin, line); 
            if(line!="")
            {
                if(c!=done)
                {
                    
                    fout<<line+"\n";
                    
                }
            }
           
            c++; 
        }
   
        fin.close();
        fout.close();
        remove("todo.txt");
        rename("todo_temp.txt","todo.txt"); 
    }
        }
        else
        {
            cout<<"Error: Missing NUMBER for marking todo as done."<<endl;
        }
        
    }
    else if(s=="report"){
        fin.open("todo.txt"); 
        int c=0;
        string line="";
        
    // Execute a loop until EOF (End of File) 
        while (fin) { 
  
        // Read a Line from File 
            getline(fin, line); 
            c++; 
        } 
        fin.close();
        fin.open("done.txt");
        int c2=0;
        line="";
        while(fin)
        {
            getline(fin,line);
            c2++;
        }
        fin.close();

        //time
        time_t now = time(0);

        tm *ltm = localtime(&now);
        if(c2&&c)
        cout<<1900 + ltm->tm_year<<"-"<<1 + ltm->tm_mon<<"-"<<ltm->tm_mday<<" Pending : "<<c-1<<" Completed : "<<c2-1<<endl;
        else
        {
            if(c==0 && c2==0)
            cout<<1900 + ltm->tm_year<<"-"<<1 + ltm->tm_mon<<"-"<<ltm->tm_mday<<" Pending : "<<c<<" Completed : "<<c2<<endl;
            else if(c==0&&c2!=0)
            {
                cout<<1900 + ltm->tm_year<<"-"<<1 + ltm->tm_mon<<"-"<<ltm->tm_mday<<" Pending : "<<c<<" Completed : "<<c2-1<<endl;
            }
            else
            cout<<1900 + ltm->tm_year<<"-"<<1 + ltm->tm_mon<<"-"<<ltm->tm_mday<<" Pending : "<<c-1<<" Completed : "<<c2<<endl;
            
        }
        


    }
    }
    else
    {
        
       {
        cout<<"Usage :-\n";
        cout<<"$ ./todo add ";
        cout<<"\"todo item\"";
        cout<<"  # Add a new todo";
        cout<<endl;
        cout<<"$ ./todo ls               # Show remaining todos";
        cout<<endl;
        cout<<"$ ./todo del NUMBER       # Delete a todo\n";
        cout<<"$ ./todo done NUMBER      # Complete a todo\n";
        cout<<"$ ./todo help             # Show usage\n";
        cout<<"$ ./todo report           # Statistics\n";
       }
    
    }
    

    
    
    return 0;
}
