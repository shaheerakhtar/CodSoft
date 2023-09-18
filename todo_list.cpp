#include<iostream>
#include<string>
static int val=0;
using namespace std;
class Task{
    private:
    string *task; 
    string *status; 
    public:
    Task(){
        task=new string[val];
        status=new string[val];
        cin.ignore();
        for (int i = 0; i < val; i++)
        {
            cout<<endl<<"Enter Name of Task "<<i+1<<":";
            getline(cin,task[i]);
            status[i]="Pending";
        }  
    }
    Task(Task &dummy){
        task= new string[val];
        for (int i = 0; i < val; i++)
        {
            task[i]=dummy.task[i];
        }  
    }
    void addTask(string Task){
        val=val+1;
        string *ptr= new string[val];
        string *ptr2= new string[val];
        for (int i = 0; i < val-1; i++)
        {
            ptr[i]=task[i];
            ptr2[i]=status[i];
        }
        ptr[val-1]=Task;
        ptr2[val-1]="Pending";
        delete [] status;
        delete [] task;
        task=ptr;
        status=ptr2;
        cout<<endl<<"Task has been added!"<<endl;
    }
    void updateTask(int taskNum){
        int option;
        cout<<endl<<"1. Completed"<<endl<<"2. Pending"<<endl<<endl<<"Enter Option: ";
        cin>>option;
        if (option==1)
        {
            status[taskNum-1]="Completed";
        }
        else if (option==2)
        {
            status[taskNum-1]="Pending";
        }
        else{
            cout<<endl<<"Invalid Input!"<<endl;
        }
        cout<<endl<<"Task has been updated!"<<endl;
    }
    void deleteTask(int taskNum){
        int count=val,check=0;
            if (taskNum<=val&&taskNum>0)
            {
                check=1;
                val=val-1;
                string *ptr2= new string[val];
                string *ptr3=new string[val];
                int counter=0;
                for (int j = 0; j < count ; j++)
                {
                    if (taskNum-1==j)
                    {
                        j=j+1;
                    }
                    if(j<count){
                    ptr2[counter]=task[j];
                    ptr3[counter]=status[j];
                    }
                    counter=counter+1;
                }
                delete [] task;
                delete [] status;
                task=ptr2;
                status=ptr3;
                cout<<endl<<"Task has been deleted!"<<endl;
            }
        if (check==0)
        {
            cout<<endl<<"Task Not Found"<<endl;
        }
    }
    void displayTask(void){
        for (int i = 0; i < val; i++)
        {
            cout<<i+1<<". "<<task[i]<<endl<<"Status: "<<status[i]<<endl<<endl;
        }
    }
    ~Task(){
        delete [] task;
        delete [] status;
    }
};
int main(){
    int option;
    cout<<endl<<"Enter Number Of Task: ";
    cin>>val;
    Task taskObj;
        while (true){
        cout<<endl<<"1. Add Task"<<endl<<"2. Delete Task"<<endl<<"3. Update Task"<<endl<<"4. Print all Task"<<endl<<"5. Exit"<<endl<<endl;
        cout<<"Select Option: ";
        cin>>option;
        if (option==1)
        {
            string taskName;
            cout<<endl<<"Enter Task Name: ";
            cin.ignore();
            getline(cin,taskName);
            taskObj.addTask(taskName);
        }
        else if (option==2)
        {
            int taskNum;
            cout<<endl<<"Enter Task Number to Delete: ";
            cin>>taskNum;;
            taskObj.deleteTask(taskNum);
        }
        else if (option==3)
        {
            int taskNum;
            cout<<endl<<"Enter Task Number to Update: ";
            cin>>taskNum;
            taskObj.updateTask(taskNum);
        }
        else if (option==4)
        {
            cout<<endl;
            taskObj.displayTask();
        }
        else if (option==5)
        {
            break;
        } 
        else{
            cout<<endl<<"Invalid Input!"<<endl;
        }
    }
}