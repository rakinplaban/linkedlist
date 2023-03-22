#include <iostream>

using namespace std;

class Linked_list
{
    struct NodeType{
        int data;
        NodeType *next;
    };

    private:
        NodeType *head;
        NodeType *tail;

    public:
//        Linked_list();
//        virtual ~Linked_list();
    void insert_first(int val){
        NodeType* location;
        location = new NodeType;
        location->data = val;
        location->next = head;
        head = location;
    }
    void insert_middle();
    void insert_end();

    void display(){
        NodeType *temp = new NodeType;
        temp = head;
        while(temp!=NULL){
            while(temp!=NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }

    Linked_list(){
        head = NULL;
        tail = NULL;
    }

//    protected:


};

int main()
{
//    cout << "Hello world!" << endl;
    Linked_list obj;
    obj.insert_first(98);
    obj.insert_first(48);
    obj.insert_first(78);
    obj.insert_first(68);
    obj.display();
    return 0;
}
