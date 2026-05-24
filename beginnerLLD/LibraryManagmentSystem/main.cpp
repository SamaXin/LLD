

#include<bits/stdc++.h>
using namespace std;

// class LibManager{
// public:

// };
static map<string,int>books;// name, count
// static map<string,int>bookIds;// name, count
// static int counterId=0;


class Lib{
public:
    // Lib(){}
    Lib(const string&name="", const int quantity=0){}
    virtual void operation(const string& name, const int quantity=0)=0;
};
//Operations 
class OperationLib: public Lib{
    public:
    OperationLib(){}
    OperationLib(const string&name, const int quantity=0):Lib(name, quantity){}
    virtual void operation(const string& name, const int quantity=0)=0;
};
class createBook: public OperationLib{
public:
    createBook(const string& name, const int quantity=0):OperationLib(name){}
    void operation(const string& name, const int quantity=0){
        if(!quantity)books[name]++;
        else books[name]+=quantity;
    }
};
class searchBook:public OperationLib{
public:
    searchBook(const string& name, const int quantity=0):OperationLib(name){}
    void operation(const string& name, const int quantity) override{
        if(books.find(name)!=books.end()){
            cout<<name<<" is available, Quantity: "<<books[name]<<endl;
        }
        else cout<<"Book is not available at a moment :("<<endl;
        cout<<"------------------------"<<endl<<endl;
    }
};
class returnBook:public OperationLib{
public:
    returnBook(const string& name, const int quantity=0):OperationLib(name){}
    void operation(const string& name, const int quantity) override{
        if(books.find(name)!=books.end()){
            books[name]++;
        }
        else books[name]=1;
        cout<<"Book has been returned successfully!!!"<<endl;
        cout<<"------------------------"<<endl<<endl;
    }
};
class buyBook:public OperationLib{
public:
    buyBook(const string& name, const int quantity=0):OperationLib(name){}
    void operation(const string& name, const int quantity) override{
        if(books.find(name)!=books.end() && books[name]>=quantity){
            books[name]-=quantity;
            cout<<"buy Sucessfully :),  "<<quantity<<": stocks"<<endl;
        }
        else cout<<"Book is not available at a moment or quantity is too much you are asking for :("<<endl;
        cout<<"------------------------"<<endl<<endl;
    }
};
class availableBook:public OperationLib{
public:
    availableBook():OperationLib(){}
    void operation(const string& name="", const int quantity=0) override{
        cout << "Available Books:\n";
        cout << "----------------------\n";
        for(auto& book : books) {
            cout << "Book Name: "
                << book.first
                << " | Quantity: "
                << book.second
                << endl;
        }
        cout << "----------------------\n\n";
    }
};


class Factory{
public:
    // const string typeOp;
    // const string name;
    // const int qua;
    // Factory(const string& name="",const int qua=0, const string& typeOp=""):name(name),qua(qua),typeOp(typeOp){}
    static Lib* returnOp(const string& typeOp="",const string& name="",const int qua=0){
        if(typeOp=="Create"){
            Lib* l=new createBook(name, qua);
            return l;
        }
        if(typeOp=="Available"){
            Lib* l=new availableBook();
            return l;
        }
        if(typeOp=="Return"){
            Lib* l=new returnBook(name, qua);
            return l;
        }
        if(typeOp=="Buy"){
            Lib* l=new buyBook(name, qua);
            return l;
        }
        if(typeOp=="Search"){
            Lib* l=new searchBook(name, qua);
            return l;
        }
        return nullptr;
    }
};

int main(){
    // books["Harry Potter"] = 10;
    // books["C++ Primer"] = 5;
    // books["Clean Code"] = 7;
    cout<<"Welcome Sir"<<endl;
    cout<<"-----------------------"<<endl;
     Lib* create =
        Factory::returnOp(
            "Create",
            "Black Warrent",
            5
        );

    create->operation("Black Warrent");

    Lib* search =
        Factory::returnOp(
            "Search",
            "Black Warrent"
        );

    search->operation("Black Warrent");

    Lib* buy =
        Factory::returnOp(
            "Buy",
            "Black Warrent",
            2
        );

    buy->operation("Black Warrent",2);

    Lib* available =
        Factory::returnOp(
            "Available"
        );

    available->operation("");
    // Lib* b = new searchBook("Harry Potter");
    // Lib* b3=new createBook("Black Warrent");
    // b3->operation("Black Warrent");
    // Lib* check= new availableBook();
    // check->operation("");
    


    
}