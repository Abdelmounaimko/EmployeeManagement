#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

typedef struct employes{
    int EmplID;
    char name[50];
    int age ;
    float salary ;
    struct employes * next ;
}employes;

employes *Head = NULL;

void SaveToFile(employes *Emp){
    std::ofstream file("Employees.csv", std::ios::app);
    if(file.is_open()){
        file << Emp->EmplID << "," << Emp->name << "," << Emp->age << "," << Emp->salary << std::endl;
        file.close();
    }
}
void LoadFromFile(){
    std::ifstream file("Employees.csv");
    if(file.is_open()){
        std::string line;
        while(std::getline(file, line)){
            employes *Emp = new employes;
            size_t pos = 0;
            std::string token;
            
            pos = line.find(",");
            Emp->EmplID = std::stoi(line.substr(0,pos));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            strcpy(Emp->name, line.substr(0,pos).c_str());
            line.erase(0,pos+1);
            
            pos = line.find(",");
            Emp->age = std::stoi(line.substr(0,pos));
            line.erase(0,pos+1);
            
            Emp->salary = std::stof(line);

            Emp->next = Head;
            Head = Emp;
        }
        file.close();
    }
}
void AddEmpl(){
    employes * Empl = new employes;
    if(Empl == NULL){
        cout << "Memory allocation failed" << endl;
        return;
}
    cout << "enter ID of employee " << endl;
    cin >> Empl->EmplID ;
    cout << "enter the name of the employee" << endl;
    cin >> Empl->name ;
    cout << "enter age" << endl;
    cin >> Empl->age;
    cout << "enter the salary" << endl;
    cin >> Empl->salary;
    Empl->next = Head;
    Head = Empl;
    SaveToFile(Empl);
}
void DeleteEmpl(){
    int NumDelEmpl ;
    employes *DeleteEmp = Head;
    employes *PrevEmp = NULL;
    cout << "Enter ID of Employee" <<endl ; 
    cin >> NumDelEmpl ;
    if(Head != NULL && Head->EmplID == NumDelEmpl){
        employes *temp = Head;
        Head = Head->next;
        delete temp;
    }
    while(DeleteEmp != NULL && NumDelEmpl != DeleteEmp->EmplID){
        PrevEmp = DeleteEmp;
        DeleteEmp = DeleteEmp->next;
    }
    if (DeleteEmp == NULL){
        cout << "There is no employee with this ID" <<endl;
        return;
    }
    PrevEmp->next = DeleteEmp->next;
    delete DeleteEmp;
}
void SearchEmp(){
    int SearchByID;
    employes * Search = Head;
    if(Head == NULL){
        cout <<endl;
        cout << "-----------------" << endl;
        cout << "the list is empty" << endl;
        cout << "-----------------" << endl;
        return;
    }
    cout << "enter the ID of The employee: " ;
    cin >> SearchByID ;
    while(Search != NULL && Search->EmplID != SearchByID){
        Search = Search->next;
    }
    if(Search == NULL){
        cout << "There is no employee for this ID" << endl;
        return;
    }
    cout << "EmployeeID: " << Search->EmplID << endl;
    cout << "Name: " << Search->name <<endl;
    cout << "Age: " << Search->age <<endl;   
    cout << "Salary: " << Search->salary <<endl;
    cout << "---------------"<<endl;
}
 void DisplayEmpl(){
    employes *Disp;
    Disp = Head ;
    if (Disp == NULL){
        cout << "The list is empty" << endl;
        return;
    }
    cout << "Registred employees" << endl;
    cout << "-------------------" << endl;

    while(Disp != NULL){
        cout << "EmployeeID: " << Disp->EmplID << endl;
        cout << "Name: " << Disp->name <<endl;
        cout << "Age: " << Disp->age <<endl;   
        cout << "Salary: " << Disp->salary <<endl;
        cout << "---------------"<<endl;
        Disp = Disp->next;
        
    }
 }

 int main(){
    LoadFromFile();
    int choice;
    do{
        cout << "\n--- Employee Management System ---" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Delete Employee" << endl;
        cout << "3. Search Employee" << endl;
        cout << "4. Display Employees" << endl;
        cout << "5. Exit Program" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter your choice (1-5): "; 
        cin >> choice;
        switch (choice)
        {
        case 1:
            AddEmpl();
            break;
        case 2:
            DeleteEmpl();
            break;
        case 3:
            SearchEmp();
            break;
        case 4:
            DisplayEmpl();
            break;
        case 5:
            cout << "the program exiting ..." <<endl;
            exit(0);
        default: cout << "Enter your choice (1-5)" <<endl;
            break;
        }
    }while(choice != 5);
    return 0;
 }
