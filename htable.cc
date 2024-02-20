//***************************************************************************
//
// Jose Barron
// Z02013735
// Fall 2023 CSCI 340 - PE1 Data Struct Algorithm Analysis
// Assignment 09: This program is intended to define the definitions
// given in "htable.h".
// Due Date: 11/20/23
// I certify that this is my own work and where appropriate an extension
// of the starter code provided for the assignment.
//
//***************************************************************************

#include "htable.h"

#define N1 10  // num of decimal digits
#define N2 26  // num of upper-case letters

// Hash function, you may NOT modify this function
int HT::hash(const string &s) {
  int n = (N2 * N1) * (s[0] - 'A') + N1 * (s[1] - 'A') + (s[2] - '0');

  return n % hsize;
}

// You will complete the code below ...

HT::HT(const unsigned &hs) 
{
    hTable.resize(hs); 
    hsize = hs;
    pTable.clear();
}

HT::~HT()
{
    for (auto& l : hTable) // frees memory of each list
    {
        l.clear();
    }
    hTable.clear(); // ensures all memory is freed

    for (auto entryptr : pTable) // frees memory of each pointer
    {
        delete entryptr;
    }
    pTable.clear(); // ensures all memory is freed
}


void HT::insert(const Entry &e) 
{
    int pos = hash(e.key); // usage of hash function to get the position of entry
    string key = e.key;
    bool found = false;

    // This loop searches the Hash Table and ensures that the string key 
    // is unique
    for (size_t i = 0; i < hTable.size(); ++i)
    {
        list<Entry> &l = hTable[i];
        auto p = find_if(l.begin(), l.end(), [key](Entry s) { return s.key == key; });
        if (p != l.end()) // the key was found
        {
            found = true;
            break;
        }
    }
    
    // if it is not unique then an error message is displayed
    if (found)
    {
        cout << " not inserted - duplicate key!!!\n";
        return;  // ensures that the duplicate key is not inserted
    }
    else
    {
        cout << " entry =  " << pos << endl;

        if (!hTable[pos].empty()) // if collisions then entry is added to the top of the exisiting list
        {
            hTable[pos].push_front(e);
        }
        else // no collisions then a new list is created.
        {
            hTable[pos] = list<Entry>{e};
        }
        // a new pointer is added for the address of the entry
        pTable.push_back(&hTable[pos].front()); 

    }
}

void HT::search(const string &key) 
{
    // used find_if to find if there exist an entry than matches the key
    // searched for
    auto p = find_if(pTable.begin(), pTable.end(), [key](Entry *entry) { return entry->key == key; });
    
    if (p != pTable.end())  // the key is found
    {
        Entry *entry_found = *p;
        cout << " ==> number: " << setw(4) << entry_found->num << " - item:" << entry_found->desc << '\n';
    } 
    else 
    {
        cout << " not in table!!\n";
    }
}


void HT::hTable_print() // prints HashTable according to the instructions
{
    for( size_t l = 0; l != hTable.size(); ++l)
    {
        for ( auto e : hTable[l])
        {
            cout << '\n';
            cout << left << setw(4) << l  << ":";
            cout << left << setw(7) << e.key << "- ";
            cout << left << setw(7) << e.num << "-  " << e.desc; 
        }
    }
    cout << '\n';
}

void HT::pTable_print() // prints PointerTable according to instructions
{
    sort(pTable.begin(), pTable.end(), [](Entry *p, Entry *q) { return p->key < q->key; });
    for ( auto it = pTable.begin(); it != pTable.end(); ++it)
    {
        Entry* e = *it;
        cout << '\n'; 
        cout << right << setw(6) << e->key << " - ";
        cout << right << setw(6) << e->num << "  -  " << e->desc;
    }
}

