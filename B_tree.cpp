#include<iostream>
using namespace std;
#define N 5
#include <algorithm>
class Btree;

typedef struct
{
	int key;
	Btree  *left;
	Btree  *right;
}node;
class Btree
{
	
public:
	
	node dot[N];
	int key_index = 0;
	int hasson = 0;
	int hasfa = 0;
	
	Btree* father = NULL;
	
	Btree();  // 这是构造函数

	
	void insert(node a);
	void _delete();
private:
	double length;
	void  Btree::dotsort();
	
};
Btree::Btree()
{


}


void  Btree::dotsort()
{
	


	for (int i = 0; i < this->key_index; i++)
		for (int j = 0; j < this->key_index-1; j++)
		{
			node k;
			if (dot[j].key > dot[j + 1].key)
			{
				k = dot[j];
				
				dot[j] = dot[j + 1];
				dot[j + 1] = k;
			}
		}
		

}

void Btree::insert(node a)
{
		

		if (this->hasson == 0||(a.left!=NULL &&a.right!=NULL))
		{
			if (this->key_index == 0)
			{
		
			this->dot[0] = a;
			this->key_index++;
			}
			else if (this->key_index < N-1)
			{
				this->dot[this->key_index] = a;
				
				this->key_index++;

				dotsort();
			
			}
			else if (this->hasfa==0)
			{
				this->dot[this->key_index] = a;
				this->key_index++;
				dotsort();
				Btree *leftnode=new Btree();
				Btree *rightnode=new Btree() ;
				(*rightnode).hasfa = 1;
				(*leftnode).hasfa = 1;
				(*rightnode).father= this;
				(*leftnode).father = this;
				
				this->key_index = 0;
				for (int i = 0; i <= int(N / 2) - 1; i++)
					(*leftnode).insert(this->dot[i]);
			
				

				
				this->dot[int(N / 2)].left = leftnode;
				this->dot[int(N / 2)].right = rightnode;
				this->insert(this->dot[int(N / 2)]);
				
				for (int i =int( N / 2) + 1 ; i <=N - 1; i++)
			
					(*rightnode).insert(this->dot[i]);
				this->hasson = 1;
		
			}
			else if (this->hasfa == 1)
			{
				this->dot[this->key_index].key = a.key;
				this->key_index++;
				dotsort();
		
				Btree* rightnode = new Btree();
				(*rightnode).hasfa = 1;
				
				(*rightnode).father = this->father;
			
				
				this->key_index = int(N / 2);
				
					




				this->dot[int(N / 2)].left = this;
				this->dot[int(N / 2)].right = rightnode;
				this->father->insert(this->dot[int(N / 2)]);
				
				for (int i = int(N / 2) + 1; i <= N - 1; i++)

					(*rightnode).insert(this->dot[i]);
				
			}
		}
		else
		{
			int i;
			for (i = 0; i < this->key_index; i++)
				if (a.key < this->dot[i].key )
					break;
			if (i==0)
				this->dot[0].left->insert(a);
			else
			this->dot[i-1].right->insert(a);
			

		//比较插入

		}


}
void Btree::_delete()
{
}
	int main()
{
	node a;
	Btree Btree;
	for (int i = 45; i >=0; i--)
	{
		a.key = i;
		a.left = NULL;
		a.right = NULL;
		Btree.insert(a); 
	}

	return 0;
}