#include <bits/stdc++.h>
using namespace std;
//========================================================
//---------------------Data storage-----------------------
string name_patient[25][10];
int stat_patient[25][10];
//========================================================
void Print_Select_a_Specialization(){
    cout << "Select a Specialization:\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "[01] : Internal Medicine" <<" [06] : Endocrinology"<<"         [11] : Cardiology"<<"                  [16] : Gastroenterology\n";
    cout << "[02] : Ophthalmology"<<"     [07] : Pediatrics"<<"            [12] : Ear, nose and throat (ENT)"<<"  [17] : Neurology\n";
    cout << "[03] : Oncology"<<"          [08] : Urology"<<"               [13] : Dermatology"<<"                 [18] : Oncology\n";
    cout << "[04] : Hematology"<<"        [09] : General Practitioner"<<"  [14] : Emergency medicine"<<"          [19] : Dentistry\n";
    cout << "[05] : Obstetrics"<<"        [10] : Nephrology" <<"            [15] : Allergy and immunology" <<"      [20] : Hepatology\n";
}
//========================================================
void pop_patients(int num_of_patients, int specialization){
    for(int i=1; i <= num_of_patients; i++){
        stat_patient[specialization][i]=stat_patient[specialization][i+1];
        name_patient[specialization][i]=name_patient[specialization][i+1];
    }
}
//===========================================================
void Get_Next_Patient(){
    int specialization;
    //===================================================================
    Print_Select_a_Specialization();
    //-----------------------------------------------------------------
    cin >> specialization;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    int num_of_patients=stat_patient[specialization][0];
    if(num_of_patients==0){
        cout << "NO Patients at the moment, Have rest Doctor\n";
    }
    else{
        cout << name_patient[specialization][1] << " Please go with the Doctor\n";
        //===================================================================
        //----------------pop patients -------------------------------------
        pop_patients(num_of_patients, specialization);
        //=============================================
        //--------------------------Update--------------
        stat_patient[specialization][0]--;
    }
}
//========================================================
void Print_All_Patients(){
    int specialization;
    //===================================================================
    Print_Select_a_Specialization();
    //-----------------------------------------------------------------
    cin >> specialization;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    //-----------------------------------------------------------------
    int num_of_patients=stat_patient[specialization][0];
    if(num_of_patients==0){
        cout << "Sorry we cannot add more patients for this specialization\n";
    }
    else{
        cout << "There are " << num_of_patients << " patients in specialization " << specialization << "\n";
        for(int i=1;i<=num_of_patients;i++){
            cout << name_patient[specialization][i] <<"                    "<< (stat_patient[specialization][i]? "Urgent\n" : "Regular\n");
        }
    }
}
//========================================================
void move_patients(int num_of_patients, int specialization){
    for(int i= num_of_patients + 1; i >= 2; i--){
        stat_patient[specialization][i]=stat_patient[specialization][i-1];
        name_patient[specialization][i]=name_patient[specialization][i-1];
    }
}
//========================================================
void Add_New_Patient(){
    //===================================================================
    //-------------------Data input from user-----------------------------
    int status,specialization;
    string name;
    //===================================================================
    Print_Select_a_Specialization();
    //-----------------------------------------------------------------
    cin >> specialization;
    int num_of_patients=stat_patient[specialization][0];
    if(stat_patient[specialization][0]==5){
        cout << "\nWe apologize, there are no empty places in this section.\n";
        return;
    }
    //-----------------------------------------------------------------
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Please enter the Patient's Name : ";
    //-----------------------------------------------------------------
    cin >> name;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    //-----------------------------------------------------------------
    cout << "Please enter the Patient's Status : \n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "[0] : Regular\n";
    cout << "[1] : Urgent\n";
    //---------------------------------------------------------------------------
    cin >> status;
    //==========================================================================
    if(status){
        //===================================================================
        //----------------move patients to add new urgent in first-----------
        move_patients(num_of_patients, specialization);
        //=============================================
        //--------------------------Update--------------
        stat_patient[specialization][1]=status;
        name_patient[specialization][1]=name;
        stat_patient[specialization][0]++;
    }
    else{
        //=============================================
        //--------------------------Update--------------
        stat_patient[specialization][num_of_patients + 1]=status;
        name_patient[specialization][num_of_patients + 1]=name;
        stat_patient[specialization][0]++;
    }
}
//========================================================
void Hospital_System (){
    while (true){
        int category = 0;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Select a Option:\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "[01] : Add New Patient\n";
        cout << "[02] : Print All Patients\n";
        cout << "[03] : Get Next Patient\n";
        cout << "[-1] : EXIT\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Enter your choice:";
        cin >> category;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        //==========================================================================
        if (category == -1)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "Shutting Down System...\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            break;
        }
        else if(category == 1){
            Add_New_Patient();
        }
        else if(category == 2){
            Print_All_Patients();
        }
        else {
            Get_Next_Patient();
        }
    }
}
//========================================================
int main()
{
    Hospital_System ();
    return 0;
}