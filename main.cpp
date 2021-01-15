#include <iostream>
#include <string>
using namespace std;

struct node{
    char val;
    struct node *next;
};

bool IsEmpty(node *head);
char menu();
void FirstItem(node *&head, node *&last, char val);
void push(node *&head, node *&last, char val);
//void pull(node *&head, node *&last);
void ShowList(node *current);
void ReverseCard(node *&head);
int CountFreq(string &val, string &tempstring);
int Ctrl_F(node *current, string Search);
int Remove_By_Index(node *&head, int n);
int* occurrenceIndexLocation(string &val, string &tempstring);
void deletes(node *current, string Search);

bool IsEmpty(node *head){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}
char menu(){
    char pick;
    cout << "MENU" << endl;
    cout << "1. Add Items" << endl;
    cout << "2. Remove Items" << endl;
    cout << "3. Show List" << endl;
    cout << "4. Reverse Mode" << endl;
    cout << "5. Find Word" << endl;
    cout << "6. Exit" << endl;

    cin >> pick;
    return pick;
}
void FirstItem(node *&head, node *&last, char val){
    node *temp = new node;
    temp->val = val;
    temp->next = NULL;
    head = temp;
    last = temp;
}
void push(node *&head, node *&last, char val){
    if(IsEmpty(head)){
        FirstItem(head, last, val);
    }
    else{
        node *temp = new node;
        temp->val = val;
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
/*void pull(node *&head, node *&last){
    if(IsEmpty(head)){
        cout << "List is Empty" << endl;
    }
    else{

    }
}*/
void ShowList(node *current){
    if(IsEmpty(current)){
        cout << "List is empty" << endl;
    }
    else{
        cout << "Here Yah go" << endl;
        while(current != NULL){
            cout << current->val << endl;
            current = current->next;
        }
    }
}

void ReverseCard(node *&head){
    if(IsEmpty(head)){
        cout << "List is empty" << endl;
    }
    else{
        //cout << "Here Yah go: " << endl;

        ReverseCard(head->next);
        cout << head->val << endl;
    }
}

int CountFreq(string &val, string &tempstring){
    int M = val.length();
    int N = tempstring.length();
    int count = 0;

    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++) {
            if (tempstring[i + j] != val[j])
                break;
        }
        if (j == M){
            count++;
            j = 0;
        }
    }
    return count;
}

int Ctrl_F(node *current, string Search) {
    string tempstring;
    int wordcounter =0;
    if(IsEmpty(current)){
        cout << "List is empty" << endl;
    }
    else{
        cout << "Here Yah go" << endl;
        while(current != NULL){
            //cout << current->val << endl;
            tempstring.push_back(current->val);
            current = current->next;

        }
        wordcounter = CountFreq(Search, tempstring);
        cout << wordcounter << ": Occurrences" << endl;
        //cout << tempstring << endl;
    }
    return wordcounter;
}

int Remove_By_Index(node *&head, int n) {
    int retval = -1;
    node *current = head;
    node *temp = NULL;
    if (IsEmpty(head)) {
        cout << "List is empty" << endl;
    }
    else {
        for (int i = 0; i < n - 1; i++) {
            if (current->next == NULL) {
                return -1;
            }
        }
        current = current->next;
    }
    temp = current->next;
    retval = temp->val;
    current->next = temp->next;
    free(temp);
    return retval;
}

int* occurrenceIndexLocation(string &val, string &tempstring){
    const int ArraySize = val.length();
    int end = 0;
    int start = 0;
    int M = val.length();
    int N = tempstring.length();
    int *tempArray[ArraySize];
    int LengthOfArray;
    //int revtempArray[ArraySize];
    int currrentSize = ArraySize;

    for (int i = 0; i <= N - M; i++){
        int j;
        for (j = 0; j < M; j++)
            if (tempstring[i+j] != val[j]) {
                break;
            }
        if (j == M){
            if (sizeof(tempArray) / sizeof(int) == currrentSize) {
                int *arr = new int [currrentSize];
                LengthOfArray =  sizeof(&arr)/sizeof(int);
                if (val.length() == LengthOfArray) {
                    int *temp = (int*) malloc(sizeof(int) * currrentSize *2);
                    for (int k = 0; k < currrentSize; k++) {
                        temp[k] = arr[k];
                    }
                    currrentSize = currrentSize * 2;
                    arr = temp;
                    free(temp);
                }
            }
            else {
                *tempArray[i] = i;
            }
            cout << "current index: " << i << endl;
            j = 0;
        }
    }
    //free(tempArray);
    end = sizeof(tempArray)/sizeof(int);
    int temp;
    while(start < end){
        temp = *tempArray[start];
        *tempArray[start] = *tempArray[end];
        *tempArray[end] = temp;
        start++;
        end--;
        //cout << "rev cur index: " << tempArray[start] <<endl;
    }
    int tempSize = sizeof(tempArray)/sizeof(int);
    for (int i =0; i < tempSize; i++) {
        cout << "rev cur Index: " << tempArray[i] << endl;
    }
    return *tempArray;
}

void deletes(node *current, string Search){
    string tempstring;
    if(IsEmpty(current)){
        cout << "List is empty" << endl;
    }
    else{
        cout << "Here Yah go" << endl;
        while(current != NULL){
            //cout << current->val << endl;
            tempstring.push_back(current->val);
            current = current->next;

        }
        //cout << tempstring << endl;
        int* Array = occurrenceIndexLocation(Search,tempstring);
        int mySize = sizeof(Array) / sizeof(int);
        for(int i = 0; i < mySize; i++){
            Remove_By_Index(current ,Array[i]);
        }
    }
}

int main(){
    node *head = NULL;
    node *last = NULL;
    char pick;
    char valconvo;
    string val;
    do{
        pick = menu();
        switch(pick) {
            case '1':
                cout << "Enter a string: ";
                //cin >> val;
                cin.ignore();
                getline(cin, val);
                for(int i=0; i < val.length(); i++){
                    valconvo = val.at(i);
                    push(head, last, valconvo);
                }
                //push(head, last, val);
                break;
            case '2':
                cout << " Enter a string: ";
                cin.ignore();
                getline(cin, val);
                deletes(head, val);
                break;
            case '3':
                ShowList(head);
                break;
            case '4':
                ReverseCard(head);
                break;
            case '5':
                cout << "Enter word you want to find: ";
                //cin >> val;
                cin.ignore();
                getline(cin, val);
                Ctrl_F(head, val);
                break;
            default:
                cout << "Exit" << endl;
        }
    }while(pick !='6');

    return 0;
}