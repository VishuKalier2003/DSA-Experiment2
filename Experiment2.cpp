/*You are making an ipod playlist to hear the songs... Assuming that the shuffle functions are not capable, choose a Data Structure that will add and delete
songs onto your ipod in such a way that the recently inserted song will always be the first song currently on the Ipod...*/
#include <iostream>
using namespace std;
class Node 
{
    public:
    string song;
    Node* next;
    public:
    Node (string name)
    {
        song = name;
        next = NULL;
    }
};
class Stack
{
    public:
    Node* top;
    Stack ()
    {
        top = NULL;
    }
    public:
    void AddSongs(string s)
    {
        Node* n = new Node(s);
        if(top == NULL)
        {
            top = n;
            return;
        }
        n -> next = top;
        top = n;
    }
    public:
    void RemoveSongs()
    {
        if(top == NULL)
        {
            cout << "The Playlist is empty hence no song can be removed !!" << endl;
            return;
        }
        Node* temp = top;
        top = temp -> next;
        delete temp;
    }
    public:
    void DisplaySongs()
    {
        Node* temp = top;
        int t = 0;
        for(; temp != NULL; temp = temp -> next)
        {
            if(temp -> next == NULL)
            {
                t = 1;
                cout << temp -> song << " \t\t---> Base" << endl;
            }
            else if(temp == top && t == 0)
                cout << temp -> song << "\t\t ---> Top" << endl;
            else
            {
                cout << "    ^ " << endl;
                cout << temp -> song << endl;
                cout << "    ^ " << endl;
            }
        }
    }
};
int main()
{
    Stack stack;
    string str = "";
    string st1 = "";
    do
    {
        cout << "Do you want to enter the Song in the playlist (Y/N) : ";
        cin >> str;
        if(str == "Y" || str == "y")
        {
            cout << "Enter the song name : ";
            cin >> str;
            stack.AddSongs(str);
            stack.DisplaySongs();
        }
        cout << "Do you want to remove Song from the Playlist (Y/N) : ";
        cin >> str;
        if(str == "Y" || str == "y")
        {
            stack.RemoveSongs();
            stack.DisplaySongs();
        }
        cout << " ========================================================================" << endl;
        cout << "Do you want to Destroy the Playlist? (Y/N) : ";
        cin >> st1;
        cout << " ========================================================================" << endl;
    }while(st1 == "No" || st1 == "NO" || st1 == "no" || st1 == "n" || st1 == "N");
    return 0;
}