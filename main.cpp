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
    // Insert first
    void insert_first(int val){
        NodeType* location;        // defining NodeType data pointer called location
        location = new NodeType;   // memory allocation with new command.
        location->data = val;
        location->next = head;
        head = location;
    }
    // Insert middle
    void insert_middle(int target,int val){
        // target is the node data after which I'll add my new node.
        NodeType* temp = new NodeType;
        NodeType* location = new NodeType;
        temp = head;

        while(temp->next != NULL){
            if(temp->data == target){
                break;
            }
            temp = temp->next;
        }

        location->data = val;
        location->next = temp->next;
        temp->next = location;

    }
    // Insert last
    void insert_end(int val){
        NodeType* location;
        location = new NodeType;
        NodeType* temp = new NodeType;
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        if(temp->next==NULL)
            tail = temp;


        location->data = val;
        tail->next = location;
        tail = location;
        tail->next = NULL; // Why should I define tail->next to null. Shouldn't is be null autometically?
    }
    // Search an item, Linear search.
    int search_item(int target){
        NodeType* temp = new NodeType;
        temp = head;
        int count_ = 0;
        while(temp->next != NULL){
            if(temp->data == target){
                return count_ + 1;
            }
            temp = temp->next;
            count_++;
        }
        // if not found.
        return -1;
    }
    // Delete the first node.
    void delete_first(){
        NodeType* temp;
        temp = head;
        head = temp->next;
        delete temp;

    }
    // Delete a node from the middle.
    void delete_middle(int val){
        NodeType* temp;
        NodeType* temp1;
        temp = head;
        int flag = 0;
        while(temp->next != NULL){
            if(temp->next->data == val){
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag==1){
            temp1 = temp->next->next;
            delete temp->next;
            temp->next = temp1;
        }
    }

    // Delete the last node.
    void delete_last(){
        NodeType* temp;
        temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next->next;
        }
        tail = temp;
        delete tail->next;
        tail->next = NULL;
    }

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
    obj.insert_end(63);
    obj.insert_end(65);
    obj.insert_end(63);
    obj.insert_middle(78,52);
    obj.insert_middle(98,82);
    obj.display();
    cout << endl;
    cout <<obj.search_item(52)<<endl;
    obj.delete_first();
    obj.display();
    cout << endl;
    obj.delete_last();
    obj.display();
    cout << endl;
    obj.delete_middle(98);
    obj.display();
    cout << endl;
    return 0;
}
