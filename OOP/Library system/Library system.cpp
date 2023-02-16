#include <bits/stdc++.h>
using namespace std;
//========================================================
//---------------------Data storage-----------------------
struct books {
    int id_book=0;
    int total_quantity=0;
    int total_borrowed=0;
    int cnt_users_borrow_book=0;
    string name_book ="";
    string users_borrow_book[2001];
};
struct users{
    string name_user="";
    int id_user=0;
    int cnt_id_book_borrow=0;
    int id_book_borrow[2001]={0};
};
int cnt_books=0;
int cnt_users=0;
books arr_book[2001];
users arr_users[2001];
//========================================================
// 1
void add_book(){
    //--------------------------------
    //----------count of books--------
    ++cnt_books;
    //-------------------------------
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Enter book information:\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "[01] Enter book name : \n";
    cin >> arr_book[cnt_books].name_book;
    cout << "[02] Enter book id : \n";
    cin >> arr_book[cnt_books].id_book;
    cout << "[03] Enter book quantity : \n";
    cin >> arr_book[cnt_books].total_quantity;
    //-----------------set data----------------------
    arr_book[cnt_books].total_borrowed=0;
    arr_book[cnt_books].cnt_users_borrow_book=0;
}
//========================================================
//2-1
bool in_prefix(string pfx ,string temp ){
    if(pfx.size()>temp.size()){
        return false;
    }
    else if(temp.substr(0,(int)pfx.size())==pfx){
        return true;
    }
    else{
        return false;
    }
}
//========================================================
//2
void search_books_by_prefix(){
    string pfx;
    int n=cnt_books;
    bool ok= false;
    //------------------------------------
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Enter book name prefix:\n";
    cin >> pfx;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    //-------------------------------------------
    for(int i=1;i<=n;i++){
        if(in_prefix(pfx , arr_book[i].name_book)){
            cout << arr_book[i].name_book << "\n";
            ok= true;
        }
    }
    //-------------------------------------------
    if(!ok){
        cout << "NO books such prefix\n";
    }
}
//========================================================
//3
void print_who_borrowed_book_by_name(){
     string name_book;
     //--------------------------------
     cout << "Enter name book :\n";
     cin >> name_book;
     //-------------------------------
     for(int i=1;i<=cnt_books;i++){
         if(arr_book[i].name_book==name_book){
             if(arr_book[i].cnt_users_borrow_book==0){
                 cout << "No people have borrowed this book\n";
                 return;
             }
             for(int j=1;j<=arr_book[i].cnt_users_borrow_book;j++){
                 cout << arr_book[i].users_borrow_book[j] << "\n" ;
             }
             return;
         }
     }
     cout << "Invalid book name\n";
}
//========================================================
//4-1
bool cmp_id(books& a,books& b){
    return a.id_book < b.id_book;
}
//========================================================
//4
void print_library_by_id(){
    if(cnt_books==0){
        cout << "NOT books in library";
        return;
    }
    sort(arr_book+1,arr_book+1+cnt_books, cmp_id);
    //----------------------------------------------------------------
    for(int i=1;i<=cnt_books;i++){
        cout << "ID : " << arr_book[i].id_book << " Name : " << arr_book[i].name_book << " Total Quantity : " << arr_book[i].total_quantity << " Total Borrowed : " << arr_book[i].total_borrowed << "\n";
    }
}
//========================================================
//5-1
bool cmp_na(books& a,books& b){
    return a.name_book < b.name_book;
}
//========================================================
//5
void print_library_by_name(){
    if(cnt_books==0){
        cout << "NOT books in library";
        return;
    }
    sort(arr_book+1,arr_book+1+cnt_books, cmp_na);
    //----------------------------------------------------------------
    for(int i=1;i<=cnt_books;i++){
        cout << "ID : " << arr_book[i].id_book << " Name : " << arr_book[i].name_book << " Total Quantity : " << arr_book[i].total_quantity << " Total Borrowed : " << arr_book[i].total_borrowed << "\n";
    }
}
//========================================================
//10
int git_id_book(string name_book){
    for(int i=1;i<=cnt_books;i++){
        if(arr_book[i].name_book==name_book){
             return arr_book[i].id_book;
        }
    }
}
//========================================================
//7-2
void add_user_in_book_borrow(string name_book,string name_user){
    for(int i=1;i<=cnt_books;i++){
        if(arr_book[i].name_book==name_book){
            //-------------up data---------
            arr_book[i].total_borrowed++;
            arr_book[i].cnt_users_borrow_book++;
            //----------new data-----------
            arr_book[i].users_borrow_book[arr_book[i].cnt_users_borrow_book]=name_user;
            //-----------exit-----------
            break;
        }
    }
}
//========================================================
//7-1
void add_id_book_in_user_borrow(string name_book,string name_user){
    for(int i=1;i<=cnt_users;i++){
        if(arr_users[i].name_user==name_user){
            //-------------up data----------------
            arr_users[i].cnt_id_book_borrow++;
            //---------new data-----------------
            arr_users[i].id_book_borrow[arr_users[i].cnt_id_book_borrow]= git_id_book(name_book);
        }
    }
}
//========================================================
//7
void user_borrow_book(){
    string name_user,name_book;
    //-----------------------------
    cout << "[01] Enter user name :\n";
    cin >> name_user;
    cout << "[02] Enter book name :\n";
    cin >> name_book;
    //---------------------------------------
    bool ok= false;
    for(int i=1;i<=cnt_books;i++){
        if(arr_book[i].name_book==name_book && arr_book[i].total_quantity-arr_book[i].total_borrowed>0){
            add_user_in_book_borrow(name_book,name_user);
            add_id_book_in_user_borrow(name_book,name_user);
            ok= true;
        }
    }
    //------------------------------
    if(!ok){
       cout << "we apologize !! --> this book not available now\n";
    }
}
//========================================================
//6
void add_user(){
    string name_user;
    int id;
    //--------------------------------------------
    cout << "[01] Enter user name :\n";
    cin >> name_user;
    cout << "[02] Enter national id :\n";
    cin >> id;
    //------------------------------------------
    //-------------up data----------------------
    cnt_users++;
    //-----------------new data------------------
    arr_users[cnt_users].name_user=name_user;
    arr_users[cnt_users].id_user=id;
}
//===========================================================
//8-1-1
void remove_data_user(int start , int arr[],int cnt){
    for(int i=start;i<=cnt;i++){
        swap(arr[i],arr[i+1]);
    }
    arr[cnt+1]=0;
}
//===========================================================
//8-2-1
void remove_data_book(int start , string arr[],int cnt){
    for(int i=start;i<=cnt;i++){
        swap(arr[i],arr[i+1]);
    }
    arr[cnt+1]="";
}
//===========================================================
//8-1
void user_return_proper(string name_book,string name_user){
    int id= git_id_book(name_book);
    for(int i=1;i<=cnt_users;i++){
        if(arr_users[i].name_user==name_user){
            for(int j=1;j<=arr_users[i].cnt_id_book_borrow;j++){
                if(arr_users[i].id_book_borrow[j]==id){
                    remove_data_user(j,arr_users[i].id_book_borrow,arr_users[i].cnt_id_book_borrow);
                    //------------up data------------------------
                    arr_users[i].cnt_id_book_borrow--;
                    return;
                }
            }
        }
    }
}
//========================================================
//8-2
void book_return_proper(string name_book,string name_user){
    for(int i=1;i<=cnt_books;i++){
        if(arr_book[i].name_book==name_book){
            for(int j=1;j<=arr_book[i].cnt_users_borrow_book;j++){
                if(arr_book[i].users_borrow_book[j]==name_user){
                    remove_data_book(j,arr_book[i].users_borrow_book,arr_book[i].cnt_users_borrow_book);
                    //------------------up data----------------------
                    arr_book[i].cnt_users_borrow_book--;
                    arr_book[i].total_borrowed--;
                    return;
                }
            }
        }
    }
}
//========================================================
//8
void user_return_book(){
    string name_user,name_book;
    //-----------------------------
    cout << "[01] Enter user name :\n";
    cin >> name_user;
    cout << "[02] Enter book name :\n";
    cin >> name_book;
    //------------------------------------
    book_return_proper(name_book,name_user);
    user_return_proper(name_book,name_user);
}
//========================================================
//9
void print_users(){
    for(int i=1;i<=cnt_users;i++){
        cout << "Name user : ";
        cout << arr_users[i].name_user;
        cout << "\n";
        cout << "National id : ";
        cout << arr_users[i].id_user;
        cout << "\n";
        //---------------------------------------
        if(arr_users[i].cnt_id_book_borrow==0){
            cout << "He did not borrow any books\n";
        }
        else{
            cout << "borrowed books : ";
            for(int j=1;j<=arr_users[i].cnt_id_book_borrow;j++){
                cout << arr_users[i].id_book_borrow[j] << " ";
            }
        }
        cout << "\n\n";
    }
}
//=======================================================
void print_Menu(){
    cout << "[01] : Add Book\n";
    cout << "[02] : Search Books By Prefix\n";
    cout << "[03] : Print Who Borrowed Book By Name\n";
    cout << "[04] : Print Library By Id\n";
    cout << "[05] : Print Library By Name\n";
    cout << "[06] : Add User\n";
    cout << "[07] : User Borrow Book\n";
    cout << "[08] : User Return Book\n";
    cout << "[09] : Add New Patient\n";
    cout << "[10] : EXIT\n";
}
//========================================================
void Library_System (){
    while (true){
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
        if (category == 10)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "Shutting Down System...\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            break;
        }
        else if(category == 1){
            add_book();
        }
        else if(category == 2){
            search_books_by_prefix();
        }
        else if(category == 3){
            print_who_borrowed_book_by_name();
        }
        else if(category == 4){
            print_library_by_id();
        }
        else if(category == 5){
            print_library_by_name();
        }
        else if(category == 6){
            add_user();
        }
        else if(category == 7){
            user_borrow_book();
        }
        else if(category == 8){
            user_return_book();
        }
        else if(category == 9){
           print_users();
        }
        else{
            cout << "Your selection is not in the menu\n";
        }
    }
}
//========================================================
int main()
{
    freopen("input.txt", "r", stdin);
    Library_System ();
    return 0;
}