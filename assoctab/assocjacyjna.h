#ifndef __ASSOCJACYJNA_H__
#define __ASSOCJACYJNA_H__
#include <cstring>



class asoctab
{
protected:
	
	struct node
	{
            node *next;
            char* key;
            int val;
            
            node(const char *wyraz):next (NULL)
            {
                key = new char[strlen (wyraz) + 1];
                strcpy (key, wyraz);
            };
        
            node(const node & s):next(NULL)
            {
                key = new char[strlen(s.key) + 1];
                strcpy(key, s.key);
                val = s.val;
            };
            
            ~node()
            {
                delete[] key;   
            }
	};

	
	
	node *head;
	virtual void insert (const char* key, int value);
	void clear();
	void swap (asoctab & l);
	virtual	node *find (const char* key) const;
	
public:
	asoctab();
	asoctab(const asoctab & l);
	virtual ~asoctab();
	virtual int zmienwielkosc(const char* key, const char* keyx) const;
	asoctab & operator=(const asoctab & l);
	int& operator[](const char* key);
	
};

class asoctabnowa : public asoctab
{
public:
        virtual int zmienwielkosc(const char* key, const char* keyx) const;
};


#endif
