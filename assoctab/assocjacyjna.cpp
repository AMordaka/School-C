#include "assocjacyjna.h"
#include <cctype>
#include <iostream>

asoctab::asoctab()
{
	head = NULL;
}

asoctab::asoctab(const asoctab & l)
{
	this->head = NULL;
	
	node *src;
	node **dst;
	
	src = l.head;
	dst = &head;
	

        *dst = new node(*src);
        src = src -> next;
        dst = &((*dst)->next);

}

asoctab::~asoctab ()
{
	clear ();
}

void asoctab::clear ()
{
  while (head)
    {
      node *t = head->next;
      delete head;
      head = t;
    };
}

int asoctab::zmienwielkosc(const char* key, const char* keyx) const
{
    return strcmp(key,keyx);
    
}

int asoctabnowa::zmienwielkosc(const char* key, const char* keyx) const
{
    return strcasecmp(key,keyx);
    
}

void asoctab::insert (const char *key, int value)
{
	node *nowy = new node (key);
	nowy->next = head;
	head = nowy;
	head->val = value;
}

void asoctab::swap (asoctab & l)
{
	node *t = head;
	head = l.head;
	l.head = t;
}

asoctab::node * asoctab::find (const char *key) const
{
	node *c = head;
	while (c)
	{
		if (!zmienwielkosc (c->key, key))
		{
			return c;
		}
		
		c = c->next;
	};
	
	return NULL;
}


int & asoctab::operator[] (const char *key)
{
	node *c = find (key);
	if (!c)
	{
		insert (key, 0);
		c = head;
	};
	
	return c->val;
}

asoctab & asoctab::operator= (const asoctab & l)
{
	if (&l == this)
	{
	return *this;
	}

	asoctab t (l);
	swap (t);
	return *this;
}




