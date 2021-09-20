/*
4.4 Oppgaver
4.4.1
List opp minst to ulike innsettings-rekkef�lger for de bin�re s�ketr�rne p� fi -
gur 4.1 og figur 4.2.
Inorder, postorder og preorder.

4.4.2
Skriv opp rekkef�lgen ved preorder traversering av de bin�re s�ketr�rne p�
figur 4.1 og figur 4.2.
h, d, a, f, g, y, n, p.
5, 3, 2, 4, 3, 7, 6, 5, 5, 9.

4.4.3
Hvilke noder i treet p� figur 4.1 er indre noder, og hvilke er blader? Hvor mange
noder er det p� hvert niv�? Hva er dybden d til treet? Hvor mange noder er det
plass til i et bin�rt tre med dybde d?
3, 7, 4, 6 og 5 er indre noder.
2, 3, 5, og 9 er blader.
niv� 1 har 2 noder. niv� 2 har 4 noder. niv� 3 har 2 noder. niv� 4 har 1 node.
treet har dybde 4. og det er plass til 2^(4 + 1) - 1 noder.

4.4.4
Skriv opp rekkef�lgen ved postorder traversering av de bin�re s�ketr�rne p�
figur 4.1 og figur 4.2.
p, n, y, g, f, a, d, h.
9, 5, 5, 6, 7, 3, 4, 2, 3, 5.

4.4.5
Skriv og test en ikke - rekursiv inorder traversering for bin�rt tre.
4.4.6
Skriv og test en ikke - rekursiv postorder traversering for bin�rt tre.
4.4.7
Skriv en funksjon som returnerer antall noder i et bin�rt s�ketre.
4.4.8
Skriv en funksjon som returnerer antall niv�er i et bin�rt s�ketre.
4.4.9
Et bin�rt s�ketre kan sies � v�re balansert dersom det ikke er st�rre niv�forskjell
enn 1 mellom venstre og h�yre subtre.Skriv en funksjon som finner ut om et
bin�rt s�ketre balansert.
4.4.10
Lag et testprogram for oppgavene ovenfor.
4.4.11
Endre insert i avsnitt 4.1.9 slik at det g�r an � sette inn duplikater.
*/

#include "binarytree.h"
#include <iostream>
#include <stack>

using namespace std;

template<typename T>
void ikke_rekursiv_inorder(BinaryNode<T>* btre)
{
	stack<decltype(btre)> s;
	do
	{
		while (btre != nullptr)
		{
			s.push(btre);
			btre = btre->left();
		}
		if (!s.empty())
		{
			cout << s.top()->get();
			btre = s.top()->right();
			s.pop();
		}
	} while (!s.empty() || btre != nullptr);
}

template<typename T>
void ikke_rekursiv_postorder(BinaryNode<T>* btre)
{
	stack<decltype(btre)> ts;
	stack<decltype(btre)> s;
	do
	{
		while (btre != nullptr)
		{
			ts.push(btre);
			s.push(btre);
			btre = btre->right();
		}
		if (!ts.empty())
		{
			btre = ts.top()->left();
			ts.pop();
		}
	} while (!ts.empty() || btre != nullptr);
	while (!s.empty())
	{
		cout << s.top()->get();
		s.pop();
	}
}

template<typename T>
bool is_balanced_tree(BinaryNode<T>* btre)
{
	auto left = btre->left();
	auto right = btre->right();
	if (left && right)
	{
		auto left_depth = left->depth();
		auto right_depth = right->depth();

		auto balance = abs(left_depth - right_depth);

		if (balance > 1)
			return false;
		else 
			return true;
	}
	return false;
}

int main()
{
	std::cout << "lol\n";

	using BinaryNode = BinaryNode<char>;

	BinaryNode* h = new BinaryNode('d');
	BinaryNode* v = new BinaryNode('a');
	v = new BinaryNode('b', v, h);
	// peker h er ledig
	BinaryNode* btre = new BinaryNode('g');
	h = new BinaryNode('p');
	btre = new BinaryNode('i', btre, h);
	btre = new BinaryNode('f', v, btre);

	/*
			   f
			/	  \
		   b	   i
		 /  \	  /  \
		a    d	 g	  p
	*/

	cout << "rekursiv inorder:\t\t";
	btre->intrav();
	cout << endl;

	// oppgage 4.4.5
	cout << "ikke rekursiv inorder:\t\t";
	ikke_rekursiv_inorder(btre);
	cout << endl;

	cout << endl;

	cout << "rekursiv postorder:\t\t";
	btre->postorder();
	cout << endl;

	// oppgage 4.4.6
	cout << "ikke rekursiv postorder:\t";
	ikke_rekursiv_postorder(btre);
	cout << endl;

	cout << endl;

	// oppgave 4.4.7
	cout << "Antall noder: " << btre->size() << endl;

	// oppgave 4.4.8
	cout << "dybde i tre: " << btre->depth() << endl;

	cout << endl;
	cout << "not cursed versions" << endl;
	cout << "Antall noder: " << btre->not_cursed_size() << endl;
	cout << "dybde i tre: " << btre->not_cursed_depth() << endl;

	// oppgave 4.4.9
	cout << boolalpha << endl << "balansert: " << is_balanced_tree(btre) << endl;

}