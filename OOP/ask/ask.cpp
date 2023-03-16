#include <bits/stdc++.h>
using namespace std;
//========================================================

//========================================================
//--------------------Read File Input data----------------
vector<string> ReadFileLines(string path) {
    vector<string>lines;
    //=====================================
    fstream from_file(path.c_str());
    if(from_file.fail()){
       cout << "\nERROR(404!!): Cannot open the file\n";
        return lines;
    }
    //===================================
    string line;
    while(getline(from_file,line)){
        if(line.size()==0){
            continue;
        }
        lines.push_back(line);
    }
    from_file.close();
    //=====================================
    return lines;
}
//=======================================================
//--------------Write File Output data-------------------
void WriteFileLines(string path,vector<string>lines){
    auto status=ios::in|ios::out|ios::trunc;
    fstream to_file(path.c_str(),status);
    if(to_file.fail()){
        cout << "\nERROR(404!!): Cannot open the file\n";
        return;
    }
    //============================================
    for(auto line:lines){
        to_file<<line<<"\n";
    }
    //=======================================
    to_file.close();
}
//========================================================
vector<string>SplitString(string s){
    //-------------we cut in this point-------------
    string cut_point =",";
    //=====================================
    vector<string> data;
    //-----------------------------------
    int pos=0;
    string temp;
    while((pos=(int)s.find(cut_point)) != -1){
        temp=s.substr(0,pos);
        data.push_back(temp);
        s.erase(0,pos+1);
    }
    //==========================================
    return data;
}
//=======================================================
int ToInt(string str) {
    istringstream iss(str);
    int num;
    iss >> num;
    //=====================================
    return num;
}
//=======================================================
string Tostring_User(int user_id,string user_name,string password,string name,string email,bool allow_anonymous_questions){
    ostringstream oss;
    oss << user_id << "," << user_name << "," << password << "," << name << "," << email << "," << allow_anonymous_questions<<",";
    return oss.str();
}
string Tostring_Question(int question_id,int parent_question_id,int from_user_id,int to_user_id,bool is_anonymous_questions,string question_text,string answer_text){
    ostringstream oss;
    oss << question_id << "," << parent_question_id << "," << from_user_id << "," << to_user_id << "," << is_anonymous_questions << "," << question_text << "," << answer_text<<",";
    return oss.str();
}
//=======================================================
//---------------------Data type-------------------------
struct User{
    int user_id;
    string user_name;
    string name;
    string password;
    string email;
    bool allow_anonymous_questions;
    //============================================
    User(){
        user_id=0;
        user_name=password=name=email="";
        allow_anonymous_questions=1;
    }
};
struct Question{
    int question_id;
    int parent_question_id;
    int from_user_id;
    int to_user_id;
    bool is_anonymous_questions;
    string question_text;
    string answer_text;
    unordered_set<int>thread;
    //=======================================
    Question() {
        question_id = from_user_id = to_user_id = 0;
        parent_question_id = -1;
        is_anonymous_questions = 1;
        question_text=answer_text="";
    }
};
//=======================================================
//---------------------Data storage-----------------------
map<string,User>User_in_Ask;
map<int,Question>Question_in_Ask;
map<string,bool>email;
unordered_set<int>Question_From_me; // Question from me by order
unordered_set<int>Question_To_me;  // Question to me by order
int id_user; // id for user in Ask
//========================================================
void UpdateDatabase_Q() {
    vector<string> lines;
    for(auto it : Question_in_Ask){
        lines.push_back(Tostring_Question(it.second.question_id,it.second.parent_question_id,it.second.from_user_id,it.second.to_user_id,it.second.is_anonymous_questions,it.second.question_text,it.second.answer_text));
    }
    WriteFileLines("questions.txt",lines);

}
void UpdateDatabase_U() {
    vector<string> lines;
    for(auto it : User_in_Ask){
        lines.push_back(Tostring_User(it.second.user_id,it.second.name,it.second.password,it.second.user_name,it.second.email,it.second.allow_anonymous_questions));
    }
    WriteFileLines("users.txt",lines);

}
//========================================================
void LoadDatabase_User() {
    vector<string>Uesr_data= ReadFileLines("users.txt");
    for(auto it : Uesr_data){
        vector<string>temp= SplitString(it);
        User_in_Ask[temp[3]].user_id=ToInt(temp[0]);
        User_in_Ask[temp[3]].name=temp[1];
        User_in_Ask[temp[3]].password=temp[2];
        User_in_Ask[temp[3]].user_name=temp[3];
        User_in_Ask[temp[3]].email=temp[4];
        User_in_Ask[temp[3]].allow_anonymous_questions=ToInt(temp[5]);
        email[User_in_Ask[temp[3]].email]= true;
    }
}
void LoadDatabase_Question() {
    vector<string>Uesr_data= ReadFileLines("questions.txt");
    for(auto it : Uesr_data){
        vector<string>temp= SplitString(it);
        int id= ToInt(temp[0]);
        Question_in_Ask[id].question_id=ToInt(temp[0]);
        Question_in_Ask[id].parent_question_id=ToInt(temp[1]);
        Question_in_Ask[id].from_user_id=ToInt(temp[2]);
        Question_in_Ask[id].to_user_id=ToInt(temp[3]);
        Question_in_Ask[id].is_anonymous_questions=ToInt(temp[4]);
        Question_in_Ask[id].question_text=temp[5];
        //===========================================
        if(temp.size()==7)
            Question_in_Ask[id].answer_text=temp[6];
        else
            Question_in_Ask[id].answer_text="";
        //=========================================
        if(ToInt(temp[1])!=-1)
           Question_in_Ask[ToInt(temp[1])].thread.insert(ToInt(temp[0]));
        //========================================================================
        if(ToInt(temp[2])==id_user){
            Question_From_me.insert(id);
        }
        if(ToInt(temp[3])==id_user){
            Question_To_me.insert(id);
        }
    }
}
//=======================================================
void Print_Questions_to_me(){
    unordered_set<int>print=Question_To_me;
    if(print.empty()){
        cout << "\nThere are no questions for you at this time\n";
    }
    else{
          while(!print.empty()){
              cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
              int it=*print.begin();
              if(Question_in_Ask[it].parent_question_id!=-1){
                  print.erase(print.begin());
                  continue;
              }
              //=================================================
              cout << "\nQuestion Id (" << Question_in_Ask[it].question_id << ") " << "Form user Id(" << Question_in_Ask[it].from_user_id <<")\n";
              cout << "Question: " <<Question_in_Ask[it].question_text << "\n";
              if(Question_in_Ask[it].answer_text.size()==0){
                  cout << "NOT Answered YET\n";
              }
              else{
                  cout << "Answer: " <<Question_in_Ask[it].answer_text <<"\n";
              }
              if(!Question_in_Ask[it].thread.empty()){
                  cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
                  unordered_set<int>temp=Question_in_Ask[it].thread;
                  int id=temp.size();
                  while(!temp.empty()){
                      int idx=*temp.begin();
                      cout <<  "----->"<< setw(5) << "Thread(" <<id-- <<")\n";
                      cout <<  "----->"<< setw(10) <<"Question Id (" << Question_in_Ask[idx].question_id << ") " << "Form user Id(" << Question_in_Ask[idx].from_user_id <<")\n";
                      cout <<  "----->"<< setw(10) <<"Question: " <<Question_in_Ask[idx].question_text << "\n";
                      if(Question_in_Ask[idx].answer_text.size()==0){
                          cout <<  "----->"<< setw(10) <<"NOT Answered YET\n";
                      }
                      else{
                          cout << "----->"<<setw(10) <<"Answer: " <<Question_in_Ask[idx].answer_text.size() <<"\n";
                      }
                      //======================================================
                      temp.erase(temp.begin());
                  }
              }
              //===============================================
              print.erase(print.begin());
              cout << "\n";
          }
    }
}
//=========================================================
void Print_Questions_from_me(){
    unordered_set<int>print=Question_From_me;
    if(print.empty()){
        cout << "\nThere are no questions from you at this time\n";
    }
    else{
        while(!print.empty()){
            int it=*print.begin();
            cout << "\nQuestion Id (" << Question_in_Ask[it].question_id << ") " << ((Question_in_Ask[it].is_anonymous_questions)? "!AQ":"") << "to user Id(" << Question_in_Ask[it].to_user_id <<")\n";
            cout << "Question: " <<Question_in_Ask[it].question_text << "\n";
            if(Question_in_Ask[it].answer_text.empty()){
                cout << "NOT Answered YET\n";
            }
            else{
                cout << "Answer: " <<Question_in_Ask[it].answer_text <<"\n";
            }
            cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
            print.erase(print.begin());
        }
    }
}
//=======================================================
void Listing_system_users(){
    if(User_in_Ask.empty()){
        cout << "\nNOT User in Ask\n";
    }
    else{
        for(auto it : User_in_Ask){
            cout << "ID: " << it.second.user_id << setw(10) <<"Name: " << it.second.name << "\n";
        }
    }
}
//=================================================================
void Feed(){
    if(Question_in_Ask.empty()){
        cout << "\nNOT Question in Ask\n";
    }
    else{
        for(auto it : Question_in_Ask){
            if(it.second.parent_question_id!=-1){
                continue;
            }
            cout << "\nQuestion Id (" << it.second.question_id << ") " << "Form user Id(" << it.second.from_user_id <<")\n";
            cout << "Question: " <<it.second.question_text << "\n";
            if(it.second.answer_text.size()==0){
                cout << "NOT Answered YET\n";
            }
            else{
                cout << "Answer: " <<it.second.answer_text <<"\n";
            }
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            if(!it.second.thread.empty()){
                cout << "thread" << it.second.thread.size() << endl;
                unordered_set<int>temp=it.second.thread;
                int id=temp.size();
                while(!temp.empty()){
                    int idx=*temp.begin();
                    cout << "----->"<< setw(5 ) << "Thread(" <<id-- <<")\n";
                    cout << "----->"<< setw(10) <<"Question Id (" << Question_in_Ask[idx].question_id << ") " << "Form user Id(" << Question_in_Ask[idx].from_user_id <<")\n";
                    cout << "----->"<< setw(10) <<"Question: " <<Question_in_Ask[idx].question_text << "\n";
                    if(Question_in_Ask[idx].answer_text.size()==0){
                        cout << "----->"<< setw(10) <<"NOT Answered YET\n";
                    }
                    else{
                        cout << "----->"<< setw(10) <<"Answer: " <<Question_in_Ask[idx].answer_text <<"\n";
                    }
                    //======================================================
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                    temp.erase(temp.begin());
                }
            }
        }
    }
}
void Ask_qu(int id,int stat,int parent=-1){
    //==============================================
    fstream from_file("questions_id.txt");
    string num_id;
    getline(from_file,num_id);
    from_file.close();
    //==============================================
    int num= ToInt(num_id);
    num++;
    //=============================================
    auto status=ios::in|ios::out|ios::trunc;
    fstream to_file("questions_id.txt",status);
    to_file << num << "\n";
    to_file.close();
    //================================================
    cout << "Enter question text: ";
    string input_qu;
    getline(cin,input_qu);
    getline(cin,input_qu);
    //===============================================
    Question_in_Ask[num].question_id=num;
    Question_in_Ask[num].parent_question_id=parent;
    Question_in_Ask[num].from_user_id=id_user;
    Question_in_Ask[num].to_user_id=id;
    Question_in_Ask[num].is_anonymous_questions=stat;
    Question_in_Ask[num].question_text=input_qu;
    Question_in_Ask[num].answer_text="";
    //=================================================
    Question_From_me.insert(num);
    //=================================================
    UpdateDatabase_Q();
}
//========================================================================
void Ask_question(){
    int id;
    cout << "\nEnter User Id or [-1] to cancel :\n";
    cin >> id;
    //==================================================
    bool ok=0;
    bool stat;
    for(auto it : User_in_Ask){
        if(it.second.user_id==id){
            stat=it.second.allow_anonymous_questions;
            ok=1;
            break;
        }
    }
    //=================================================
    if(ok){
        if(stat){
            cout << "\nNote: Anonymous questions are not allowed for this user\n";
        }
        //==================================================
        cout << "\nFor thread question: Enter Question id or -1 for new question: \n";
        int qu;
        cin >> qu;
        if(qu==-1){
            Ask_qu(id,stat);
        }
        else{
            if(Question_in_Ask.count(qu)){
                Ask_qu(id,stat,qu);
            }
            else{
                cout << "\nQuestion Not founded in Ask !!!\n";
            }
        }
    }
    else{
        cout << "\nQuestion Not founded in Ask !!!\n";
    }
}
//========================================================================
void Answer(){
    int id;
    cout << "\nEnter Question Id or [-1] to cancel :\n";
    cin >> id;
    //=================================================
    if(Question_in_Ask.count(id)&&Question_in_Ask[id].to_user_id==id_user){
        cout << setw(10) <<"Question Id (" << Question_in_Ask[id].question_id << ") " << "Form user Id(" << Question_in_Ask[id].from_user_id <<")\n";
        cout << setw(10) <<"Question: " <<Question_in_Ask[id].question_text << "\n";
        if(Question_in_Ask[id].answer_text.size()==0){
            cout << setw(10) <<"NOT Answered YET\n";
        }
        else{
            cout << setw(10) <<"Answer: " <<Question_in_Ask[id].answer_text <<"\n";
        }
        //=================================================================
        if(Question_in_Ask[id].answer_text.size()!=0){
            cout << "Warning: Already answered. Answer Will be UP>>dated!!\n";
        }
        //====================================================================
        string ans;
        cout << "Enter answer : " ;
        cin >> ans;
        cout << "\n";
        Question_in_Ask[id].answer_text=ans;
        UpdateDatabase_Q();
    }
    else{
        cout << "\nQuestion Not founded in Ask !!!\n";
    }

}
//==========================================================================
void Delete(){
    int id;
    cout << "\nEnter Question Id or [-1] to cancel :\n";
    cin >> id;
    if(Question_in_Ask.count(id)&&Question_in_Ask[id].from_user_id==id_user){
        Question_in_Ask.erase(id);
        UpdateDatabase_Q();
    }
    else{
        cout << "\nQuestion Not founded in your Questions Ask !!!\n";
    }
}
//========================================================================
void sign(){

    User input;
    cout << "Enter user name. (No spaces): ";
    cin >> input.user_name;
    cout << "\nEnter password: ";
    cin >> input.password;
    cout << "\nEnter name: ";
    cin >> input.name;
    cout << "\nEnter email: ";
    cin >> input.email;
    cout << "\nAllow anonymous questions?: (0 or 1): ";
    cin >> input.allow_anonymous_questions;
    //==================================================
    if(User_in_Ask.count(input.user_name)&&email.count(input.email)){
        cout << "\n(user name or email) Already used!!!-->Try again....\n";
        while (true) {
            cout << "\nEnter user name. (No spaces): ";
            cin >> input.user_name;
            cout << "\nEnter email: ";
            cin >> input.email;
            if (User_in_Ask.count(input.user_name)&&email.count(input.email))
                cout << "\n(user name or email) Already used!!!-->Try again....\n";
            else
                break;
        }
    }
    //================================================================
    fstream from_file("users_id.txt");
    string num_id;
    getline(from_file,num_id);
    from_file.close();
    //==============================================
    int num= ToInt(num_id);
    num++;
    //=============================================
    auto status=ios::in|ios::out|ios::trunc;
    fstream to_file("users_id.txt",status);
    to_file << num << "\n";
    to_file.close();
    //================================================================
    User_in_Ask[input.user_name].user_id=num;
    User_in_Ask[input.user_name].name=input.name;
    User_in_Ask[input.user_name].password=input.password;
    User_in_Ask[input.user_name].user_name=input.user_name;
    User_in_Ask[input.user_name].email=input.email;
    User_in_Ask[input.user_name].allow_anonymous_questions=input.allow_anonymous_questions;
    id_user=num;
    UpdateDatabase_U();
}
//========================================================================
void log_in(){
    User input;
    while (true) {
        cout << "Enter user name. (No spaces): ";
        cin >> input.user_name;
        cout << "\nEnter password: ";
        cin >> input.password;
        if (!User_in_Ask.count(input.user_name)) {
            cout << "\nInvalid user name or password. Try again\n\n";
            continue;
        }
        User user_exist = User_in_Ask[input.user_name];
        if (input.password != user_exist.password) {
            cout << "\nInvalid user name or password. Try again\n\n";
            continue;
        }
        input = user_exist;
        break;
    }
    id_user=User_in_Ask[input.user_name].user_id;
}
//========================================================================
void print_Menu(){
    cout << "[01] : Print Questions To Me\n";
    cout << "[02] : Print Questions From Me\n";
    cout << "[03] : Answer Question\n";
    cout << "[04] : Delete Question\n";
    cout << "[05] : Ask Question\n";
    cout << "[06] : List System Users\n";
    cout << "[07] : Feed\n";
    cout << "[08] : Logout\n";
}
//========================================================
void Ask_System (){


    cout << "\n 1: Login\n";
    cout << "\n 2: Sign Up\n";
    int n;
    cin >> n;
    if(n==1)log_in();
    else sign();
    while (true){
        LoadDatabase_User();
        LoadDatabase_Question();
        int category = 0;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Select a Option:\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        print_Menu();
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Enter your choice:";
        cin >> category;
        cout << "\n";
        //==========================================================================
        if (category == 8)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "Shutting Down System...\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            break;
        }
        else if(category == 1){
            LoadDatabase_User();
            LoadDatabase_Question();
            Print_Questions_to_me();
        }
        else if(category == 2){
            LoadDatabase_User();
            LoadDatabase_Question();
            Print_Questions_from_me();
        }
        else if(category == 3){
            Answer();
        }
        else if(category == 4){
            Delete();
        }
        else if(category == 5){
            Ask_question();
        }
        else if(category == 6){
            LoadDatabase_User();
            LoadDatabase_Question();
            Listing_system_users();
        }
        else if(category == 7){
            LoadDatabase_User();
            LoadDatabase_Question();
            Feed();
        }
        else{
            cout << "\n ERROR: invalid number...Try again\n";
        }
    }
}
//========================================================
int main()
{
    LoadDatabase_User();
    LoadDatabase_Question();
    Ask_System ();
    return 0;
}